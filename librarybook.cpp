#include "libraryitem.h"
#include "librarybook.h"
#include <iostream>
#include <string>

using namespace std;


LibraryBook::LibraryBook(){
	this->title = "unknown";
	this->author = "none";
	this->isbn = 0;
	this->cat = "unknown";
}
LibraryBook::LibraryBook(int id, double cost, string status, int loanPeriod, string title, string author, int isbn, string cat){
	this->id = id;
	this->cost = cost;
	this->status = status;
	this->loanPeriod = loanPeriod;
	this->title = title;
	this->author = author;
	this->isbn = isbn;
	this->cat = cat;
}


void LibraryBook::SetTitle(string title){
	this->title = title;
}
string LibraryBook::GetTitle() const{
	return title;
}

void LibraryBook::SetAuthor(string author){
	this->author = author;
}
string LibraryBook::GetAuthor() const{
 	return author;
}
	
void LibraryBook::SetIsbn(int isbn){
	this->isbn = isbn;
}
	int LibraryBook::GetIsbn() const{
	return isbn;
}

	void LibraryBook::SetCategory(string cat){
		this->cat = cat;
}
	string LibraryBook::GetCategory() const{
	return cat;
}




void LibraryBook::AddItem() {
        cout << "Enter title: ";
    getline(cin, title);
cin.ignore();

       cout << "Enter author: ";
    getline(cin, author);
	cin.ignore();

    cout << "Enter ISBN: ";
    cin >> isbn;
    cout << "Enter category: ";
    cin.ignore();
    getline(cin, cat);
cout<<"Enter ID: "<<endl;
	cin>>id;

cout<<"Enter cost: "<<endl;
cin>>cost;

		cout<<"Enter loan Period: "<<endl;
		cin>>loanPeriod;
		cin.ignore();

		cout<<"Enter status: "<<endl;
		getline(cin, status);
		

   	SetTitle(title);
    SetAuthor(author);
    SetIsbn(isbn);
    SetCategory(cat);

        
    }

    void LibraryBook::DeleteItem(int deleteIsbn) {
        if (GetIsbn() == deleteIsbn) {
        // Delete this item
        SetTitle(""); // Clearing data to indicate deletion
        SetAuthor("");
        SetIsbn(0); // Assuming 0 is not a valid ISBN
        SetCategory("");
        SetId(0); // Assuming 0 is not a valid ID
        SetCost(0.0); // Assuming 0.0 is not a valid cost
        SetLoan(0); // Assuming 0 is not a valid loan period
        SetStatus("");
        cout << "Item deleted successfully." << endl;
    } else {
        cout << "Item not found." << endl;
    }
    }

    void LibraryBook::EditItem(int editIsbn) {
        if (GetIsbn() == editIsbn) {
        // Match found, allow editing
        string newTitle, newAuthor, newCategory, newStatus;
        int newId, newLoanPeriod;
        double newCost;

        cout << "Enter new title: ";
	cin.ignore();
        getline(cin, newTitle);
        cin.ignore();

        cout << "Enter new author: ";
        getline(cin, newAuthor);
       // cin.ignore();

        cout << "Enter new ISBN: ";
        cin >> editIsbn; // Assuming ISBN cannot be edited
        cin.ignore();

        cout << "Enter new category: ";
        getline(cin, newCategory);
        cin.ignore();

        cout << "Enter new ID: ";
        cin >> newId;
        cin.ignore();

        cout << "Enter new cost: ";
        cin >> newCost;
        cin.ignore();

        cout << "Enter new loan period: ";
        cin >> newLoanPeriod;
        cin.ignore();

        cout << "Enter new status: ";
        getline(cin, newStatus);
        cin.ignore();

        // Set new values for the item
        SetTitle(newTitle);
        SetAuthor(newAuthor);
        // Assuming ISBN cannot be edited
        SetCategory(newCategory);
        SetId(newId);
        SetCost(newCost);
        SetLoan(newLoanPeriod);
        SetStatus(newStatus);

        cout << "Item details updated successfully." << endl;
    } else {
        cout << "Item not found." << endl;
    }
}	
	
void LibraryBook::displayDetails() const{
	cout << "Book ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Category: " << cat << endl;
	cout<<"Cost: "<<cost<<endl;
	cout<<"Status: "<<status<<endl;
	cout<<"Loan Period: "<<loanPeriod<<" days"<<endl;
        }
