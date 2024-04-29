#include "loans.h"
#include "books.h"
#include "patrons.h"
#include "bookcollection.h"
#include "loancollection.h"
#include "patroncollection.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 
#include <ctime>

using namespace std;



void LoanCollection::CheckOutBook(PatronCollection allPatrons, BookCollection allBooks) {
    int patronId, bookId;
    cout << "Enter the id of the patron: ";
    cin >> patronId;
    Patrons patron = allPatrons.SearchPatron(patronId);
    cout << "Patron found " << patron.GetName() << endl;
    unsigned int i;
    int countNumLoans = 0;

    // Change to direct object instead of pointer
    Loans loanToFind;
    for (i = 0; i < loanCollection.size(); i++) {
        // Assign the Loans object directly
        loanToFind = loanCollection.at(i);
        if (loanToFind.GetPatronId() == patron.GetIdNum()) {
            countNumLoans++;
        }
    }

    // Check if the patron has reached the maximum number of allowed loans
    if (countNumLoans >= 6) {
        cout << "Patron has reached the maximum number of books allowed to borrow." << endl;
        return;
    }
	if(patron.GetBooksOut() >= 6){
		cout<<"Cannot check out more books"<<endl;
		return;
}
	if(patron.GetFineBalance () > 0){
		cout<<"Patron has fines. Please pay before checking out."<<endl;
		return;
}

    cout << "Enter the id of the book: ";
    cin >> bookId;
    Books book = allBooks.SearchCriteria(bookId);
    cout << "Book found " << book.GetTitle() << endl;

    // Here, use appropriate function from Books object to get status
    string status = book.GetCurrStats();
    for (char& c : status) {
        c = tolower(c);
    }

    if (status == "out" || status == "repair" || status == "lost") {
        cout << "Book is currently " << status << " and not available to check out." << endl;
        return;
    }

    Loans newLoan;
    newLoan.SetBookId(book.GetIsbnNumber());
    newLoan.SetPatronId(patron.GetIdNum());

    time_t t = time(0);   // get current time
    t += 10 * 24 * 60 * 60;  // 10 days in seconds
    newLoan.SetDueDate(t);

    loanCollection.push_back(newLoan);
    allPatrons.UpdateNumLoans(patronId);
	cout<<"Books checked out successfully"<<endl<<endl;
}





void LoanCollection::PrintOverdueBooks(BookCollection allBooks, PatronCollection allPatrons) {
        cout << "OVERDUE BOOKS:" << endl;


    if (loanCollection.empty()) {
        cout << "No loans in the collection." << endl;
        return;
    }

    for (const Loans& loan : loanCollection) {
        if (loan.GetDueDate() < time(nullptr)) {
            // Retrieve book and patron information
            Books book = allBooks.SearchCriteria(loan.GetBookId());
            Patrons patron = allPatrons.SearchPatron(loan.GetPatronId());

            // Convert due date to a string
            time_t dueDate = loan.GetDueDate();
            tm* dueDateTm = localtime(&dueDate);

            // Print loan details
            cout << "Loan ID: " << loan.GetLoanId() << endl;
            cout << "Book Title: " << book.GetTitle() << endl;
            cout << "Patron Name: " << patron.GetName() << endl;
            cout << "Due Date: " << put_time(dueDateTm, "%Y-%m-%d %H:%M:%S") << endl;
            cout << endl;
        }
		else {
			cout<<"No overdue books"<<endl;
    }
}
}

void LoanCollection::AddLoan() {
    cout << "ADD A NEW LOAN" << endl;

    int loanId; 
    int bookId;
    int patronId;
    time_t dueDate; // Due date in seconds since epoch
    string currentStatus;

    // Prompt user for loan information
    cout << "Enter loan ID: ";
    cin >> loanId;

    cout << "Enter book ID: ";
    cin >> bookId;

    cout << "Enter patron ID: ";
    cin >> patronId;

    cout << "Enter due date : ";
    cin >> dueDate;

    cout << "Enter current status: ";
    cin >> currentStatus;

    // Create a new loan object and add it to the collection
    Loans newLoan(loanId, bookId, patronId, dueDate, currentStatus);
    loanCollection.push_back(newLoan);

    cout << "Loan added successfully." << endl;
}


void LoanCollection::EditLoan(){
	cout<<"EDIT YOUR LOANS"<<endl;
	
	int editLoan;
	cout<<"Enter the loan id of the patron you want to edit: "<<endl;
	cin>>editLoan;

	for(auto& loan : loanCollection){
	   if(loan.GetLoanId() == editLoan){
		
		int bookId;
		cout<<"Enter the isbn number of the book: "<<endl;
		cin>>bookId;

		int patronId;
		cout<<"Enter the patron id: "<<endl;
		cin>>patronId;
		
		time_t dueDate;
		cout<<"Enter the due date: "<<endl;
		cin>>dueDate;

		string status;
		cout<<"Enter current status: "<<endl;
		getline(cin, status);
	
		loan.SetBookId(bookId);
		loan.SetPatronId(patronId);
		loan.SetDueDate(dueDate);
		loan.SetCurrentStatus(status);

		cout<<"Loan details updated successfully"<<endl;
		return;
}
}
cout<<"Loan not found in collection"<<endl;
}

void LoanCollection::ReportLost(PatronCollection allPatrons, BookCollection allBooks) {
    int patronId, bookId;
    cout << "Enter the ID of the patron: ";
    cin >> patronId;
    Patrons patron = allPatrons.SearchPatron(patronId);
    cout << "Patron found: " << patron.GetName() << endl;

    cout << "Enter the ISBN of the lost book: ";
    cin >> bookId;
    Books book = allBooks.SearchCriteria(bookId);
    cout << "Book found: " << book.GetTitle() << endl;

    // Check if the book is already marked as lost
    if (book.GetCurrStats() == "lost") {
        cout << "The book is already marked as lost." << endl;
        return;
    }

    // Update book status to lost
    book.SetCurrStats("lost");
    allBooks.EditBook(); // Call EditBook without parameters

    // Update patron's fine balance
    double newFine = patron.GetFineBalance() + book.GetCost();
    patron.SetFineBalance(newFine);
    allPatrons.EditPatron(); // Call EditPatron without parameters

    cout << "Book reported as lost and fine added to patron." << endl;
}

void LoanCollection::RecheckBook(int patronId, int loanId, int bookIsbn) {
    bool loanFound = false;
    for (auto& loan : loanCollection) {
        if (loan.GetPatronId() == patronId && loan.GetLoanId() == loanId && loan.GetBookId() == bookIsbn) {
            loanFound = true;
            
            // Extend the due date for the book
            time_t newDueDate = loan.GetDueDate() + 10 * 24 * 60 * 60; // Adding 10 days in seconds
            loan.SetDueDate(newDueDate);
            
            cout << "Book rechecked successfully. New due date: " << put_time(localtime(&newDueDate), "%Y-%m-%d %H:%M:%S") << endl;
            return;
        }
    }

    if (!loanFound) {
        cout << "Loan not found" << endl;
    }
}



void LoanCollection::UpdateLoanStatus() {
    time_t currentTime = time(nullptr);

    // Iterate through each loan in the collection
    for (auto& loan : loanCollection) {
        // Check if the current time has exceeded the due date
        if (currentTime > loan.GetDueDate()) {
            // Update the status of the loan to overdue
            loan.SetCurrentStatus("Overdue");
        }
    }
}

void LoanCollection::ListAllBooksForPatron(int patronId, BookCollection allBooks) {
    cout << "Books borrowed by Patron with ID " << patronId << ":" << endl;

    // Iterate through the loan collection
    for (const auto& loan : loanCollection) {
        // Check if the loan is associated with the given patron
        if (loan.GetPatronId() == patronId) {
            // Retrieve the book information from the book collection
            Books book = allBooks.SearchCriteria(loan.GetBookId());
            // Print book details
            cout << "Title: " << book.GetTitle() << endl;
            cout << "Author: " << book.GetAuthor() << endl;
            cout << "ISBN: " << book.GetIsbnNumber() << endl;
            cout << "Status: " << book.GetCurrStats() << endl;
            cout << "---------------------------------" << endl;
        }
    }
}


void LoanCollection::CheckInBook(int bookId) {
    bool found = false;

    // Iterate through the loan collection
    for (auto it = loanCollection.begin(); it != loanCollection.end(); ++it) {
        // Check if the loan is associated with the given book ID
        if (it->GetBookId() == bookId) {
            // Update the loan status to "in"
            it->SetCurrentStatus("in");
            found = true;
            cout << "Book checked in successfully." << endl;
            // Remove the loan from the collection
            loanCollection.erase(it);
            break;
        }
    }

    if (!found) {
        cout << "Book with ISBN " << bookId << " is not currently checked out." << endl;
    }
}



