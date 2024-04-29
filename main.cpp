//Aline Jouaidi 11672370 CSCE 1040 Homework3

#include <iostream>
#include <string>
#include "books.h"
#include "bookcollection.h"
#include "patroncollection.h"
#include "loancollection.h"
#include "libraryitem.h"
#include "librarybook.h"
#include "libraryaudio.h"
#include "librarydvd.h"
using namespace std; 

BookCollection allBooks;
PatronCollection allPatrons;
LoanCollection allLoans;
LibraryBook allLibraryBook;
LibraryAudio allLibraryAudio;
LibraryDvd allLibraryDvd;

	void printBook(){
		cout<<"1. Add a Book"<<endl;
		cout<<"2. Edit a book"<<endl;
		cout<<"3. Delete a book"<<endl;
		cout<<"4. Search for a book"<<endl;
		cout<<"5. Print all books"<<endl;
		cout<<"6. Print a book"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"Enter your choice: "<<endl;
}

	void printPatron() {
		cout<<"1. Add a patron"<<endl;
		cout<<"2. Edit a patron"<<endl;
		cout<<"3. Delete a patron"<<endl;
		cout<<"4. Search for a patron"<<endl;
		cout<<"5. Print all patrons"<<endl;
		cout<<"6. Print a patron"<<endl;
		cout<<"7. Pay Fines"<<endl;
		cout<<"8. Exit"<<endl;
		cout<<"Enter your choice: "<<endl;
}

	void printLoan() {
		cout<<"1. Check out a book"<<endl;
		cout<<"2. Check in a book"<<endl;
		cout<<"3. List all overdue"<<endl;
		cout<<"4. List all books for a patron"<<endl;
		cout<<"5. Re-check a book"<<endl;
		cout<<"6. Update loan status based on system clock"<<endl;
		cout<<"7. Edit a loan"<<endl;
		cout<<"8. Add a loan"<<endl;
		cout<<"9. Report lost"<<endl;
		cout<<"10. Exit"<<endl;
		cout<<"Enter your choice: "<<endl;
		
		
}

void printLibraryBook(){
	cout<<"1.Add library Book and display details"<<endl;
	cout<<"2.Edit Library book"<<endl;
	cout<<"3.Delete library book"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"Enter your choice:"<<endl;
}

void printLibraryAudio() {
	cout<<"1.Add library audio and display details"<<endl;
	cout<<"2.Edit Library audio"<<endl;
	cout<<"3.Delete library audio"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"Enter your choice:"<<endl;
}

void printLibraryDvd() {
	cout<<"1.Add library dvd and display details"<<endl;
	cout<<"2.Edit Library dvd"<<endl;
	cout<<"3.Delete library dvd"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"Enter your choice:"<<endl;
}



int main() {
    int choice;
    cout<<"-------------------------------------"<<endl;
    cout<<" WELCOME TO THE LIBRARY MENU SYSTEM"<<endl;
    cout<<"-------------------------------------"<<endl;
    cout << "1. Access Books" << endl;
    cout << "2. Access Patrons" << endl;
    cout << "3. Access Loans" << endl;
    cout<<  "4. Access Library Items"<<endl;
    cout << "5. Exit" << endl;
    cout<<"-------------------------------------"<<endl;

    do {
        cout << "Enter your choice: ";
        cin >> choice;
	cout<<endl;
        cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1:
                do {
                    printBook();
                    cin >> choice;
                    cin.ignore(); // Clear the input buffer

                    switch (choice) {
                        case 1:{
                            allBooks.AddBook();
                            break;
				}
                        case 2: {
                            allBooks.EditBook();
                            break;

				}
                        case 3: {
				int isbn;
				cout<<"Enter the isbn number of the book you want to delete: "<<endl;
				cin>>isbn;
            	            allBooks.DeleteBook(isbn);
                            break;

				}
                        case 4: {
				int bookId;
				cout<<"Enter the isbn number of the book you want to look up: "<<endl;
				cin>>bookId;
                            allBooks.SearchCriteria(bookId);
                            break;
				}
                        case 5: {
                            allBooks.PrintList();
                            break;
				}
                        case 6: {
                            string title;
                            cout << "Enter the title of the book: ";
                            getline(cin, title);
                            allBooks.PrintDetails(title);
                            break;
				}
                        case 7: {
                            cout << "Exiting book menu..." <<endl;
			    cout<<"-------------------------------------"<<endl;
    			    cout<<" WELCOME TO THE LIBRARY MENU SYSTEM"<<endl;
    			    cout<<"-------------------------------------"<<endl;
    			    cout << "1. Access Books" << endl;
    		  	    cout << "2. Access Patrons" << endl;
    			    cout << "3. Access Loans" << endl;
    			    cout<<  "4. Access Library Items"<<endl;
    			    cout << "5. Exit" << endl;
    			    cout<<"-------------------------------------"<<endl;

                            break;
				}
                        default: {
                            cout << "Invalid choice. Try again." <<endl;
                            break;     }
                    }
                } while (choice != 7);
                break;
                       case 2:
                // Patron menu handling
		do{
			
		    printPatron();
		    cin >> choice;
                    cin.ignore();
		    switch(choice){
			case 1:{
                            allPatrons.AddPatron();
                            break;
				}
                        case 2: {
                           allPatrons.EditPatron();
                            break;				
				}
                        case 3: {
                          
		            int isbn;
				cout<<"Enter the ID of the patron you want to delete: "<<endl;
				cin>>isbn;
            	            allPatrons.DeletePatron(isbn);
                            break;

				}
                        case 4: {
				int patronId;
				cout<<"Enter the id number of the patron you want to look up: "<<endl;
				cin>>patronId;

                            allPatrons.SearchPatron(patronId);
                            break;
				}
                        case 5: {
                            allPatrons.PrintPatron();
                            break;
				}
                        case 6: {
                            string patron;
                            cout << "Enter the name of the patron: ";
                            getline(cin, patron);
                            allPatrons.PrintPatronDetail(patron);
                            break;
				}
			case 7: {
			int patronid;
			double amount;
			cout<<"Enter the patron id: "<<endl;
			cin>>patronid;

			cout<<"Enter the amount you want to pay: "<<endl;
			cin>>amount;
		
			allPatrons.PayFines(patronid, amount);
				break;
				}
                        case 8: {
                            cout << "Exiting patron menu..." <<endl;
			 
			    cout<<"-------------------------------------"<<endl;
    			    cout<<" WELCOME TO THE LIBRARY MENU SYSTEM"<<endl;
   			    cout<<"-------------------------------------"<<endl;
    			    cout << "1. Access Books" << endl;
    			    cout << "2. Access Patrons" << endl;
    			    cout << "3. Access Loans" << endl;
    			    cout<<  "4. Access Library Items"<<endl;
    			    cout << "5. Exit" << endl;
    			    cout<<"-------------------------------------"<<endl;

                            break;
				}
                        default: {
                            cout << "Invalid choice. Try again." <<endl;
                            break;     }
                    }
                } while (choice != 8);	
                break;
            case 3:
                // Loan menu handling
		do{
		    printLoan();
		    cin >> choice;
                    cin.ignore();
		    switch(choice){
			case 1:{
                           allLoans.CheckOutBook(allPatrons, allBooks);
                            break;
				}
                        case 2: {
				int bookId;
				cout<<"Enter the id of the book you want to check in: "<<endl;
				cin>>bookId;
                           allLoans.CheckInBook(bookId);
                            break;				
				}
                        case 3: {
                           allLoans.PrintOverdueBooks(allBooks, allPatrons);

		           
                            break;

				}
                        case 4: {
				int patronId;
				cout<<"Enter the id of the patron you want to list all books for: "<<endl;
				cin>>patronId;
                             allLoans.ListAllBooksForPatron(patronId, allBooks);
                            break;
				}
                        case 5: {
                           int patronId, bookId, loanId;
				cout<<"Enter the patron id: "<<endl;
				cin>>patronId;
			
				cout<<"Enter the book id: "<<endl;
				cin>>bookId;
				
				cout<<"Enter loan id: "<<endl;
				cin>>loanId;
		
				allLoans.RecheckBook(patronId, loanId, bookId);
				
                            break;
				}
			case 6:{
			allLoans.UpdateLoanStatus();
				break;
				}
				
                        case 7: {
                           	allLoans.EditLoan();
                            break;
				}
			case 8: {
				allLoans.AddLoan();
				break;
				}
			case 9:
				{
						
				allLoans.ReportLost( allPatrons, allBooks);
				break;
				}
                        case 10: {
                            cout << "Exiting loan menu..." <<endl;
			 
			   cout<<"-------------------------------------"<<endl;
    			   cout<<" WELCOME TO THE LIBRARY MENU SYSTEM"<<endl;
    		           cout<<"-------------------------------------"<<endl;
   			   cout << "1. Access Books" << endl;
      			   cout << "2. Access Patrons" << endl;
    			   cout << "3. Access Loans" << endl;
    			   cout<<  "4. Access Library Items"<<endl;
    			   cout << "5. Exit" << endl;
    			   cout<<"-------------------------------------"<<endl;
                            break;
				}
                        default: {
                            cout << "Invalid choice. Try again." <<endl;
                            break;     }
                    }
                } while (choice != 10);	
                

                break;
	    case 4:
		int userInput;

		do{
		cout<<"Enter the type of item(1: Book, 2:Audio, 3: DVD, 4: Exit):"<<endl;
		cin>>userInput;
		cin.ignore();

		  					
		switch(userInput){
		case 1: { //book
			do{
			 printLibraryBook();
			cin>>userInput;
			cin.ignore();
		switch(userInput){
		case 1:	{
		allLibraryBook.AddItem();
		allLibraryBook.displayDetails();
		break;
		}
		case 2: {
			int isbn;
			cout<<"Enter the isbn of the book:"<<endl;
			cin>>isbn;
			allLibraryBook.EditItem(isbn);
			break;
			}
		case 3: {
		int isbn;
		cout<<"Enter the isbn of the book you want to delete:"<<endl;
		cin>>isbn;
		allLibraryBook.DeleteItem(isbn);
		break;
}
		case 4: {
		cout<<"Exiting library Book menu"<<endl;
		cout<<"1.Add library Book and display details"<<endl;
		cout<<"2.Edit Library book"<<endl;
		cout<<"3.Delete library book"<<endl;
		cout<<"4.Exit"<<endl;
		break;
}
}
	}while(userInput != 4);
		break;
			}
		case 2:{ //audio
	do{
		printLibraryAudio();
		cin>>userInput;
		cin.ignore();

		switch(userInput){

		case 1: {
			 allLibraryAudio.AddItem();
			allLibraryAudio.displayDetails();
			break;
		}
			

		case 2: {
			int tracks;
			cout<<"Enter the # tracks of the audio you want to edit: "<<endl;
			cin>>tracks;

			allLibraryAudio.EditItem(tracks);
			break;
			}

		case 3: {
			int tracks;
			cout<<"Enter the # tracks of the audio you want to delete: "<<endl;
			cin>>tracks;
			allLibraryAudio.DeleteItem(tracks);
		
			break;
			}

		case 4: {
		cout<<"Exiting library Audio menu"<<endl;
		cout<<"1.Add library Book and display details"<<endl;
		cout<<"2.Edit Library book"<<endl;
		cout<<"3.Delete library book"<<endl;
		cout<<"4.Exit"<<endl;
		break;
}
}
}while(userInput != 4);
		break;
}

		
		case 3:{//dvd
		do{
		printLibraryDvd();
		cin>>userInput;
		cin.ignore();

		switch(userInput){

		case 1: {
			 allLibraryDvd.AddItem();
			allLibraryDvd.displayDetails();
			break;
		}
			

		case 2: {
			int run;
			cout<<"Enter the run time of the dvd you want to edit: "<<endl;
			cin>>run;

			allLibraryDvd.EditItem(run);
			break;
			}

		case 3: {
			int run;
			cout<<"Enter the run time of the dvd you want to delete: "<<endl;
			cin>>run;
			allLibraryDvd.DeleteItem(run);
		
			break;
			}

		case 4: {
		cout<<"Exiting library Dvd menu"<<endl;
		cout<<"1.Add library dvd and display details"<<endl;
		cout<<"2.Edit Library dvd"<<endl;
		cout<<"3.Delete library dvd"<<endl;
		cout<<"4.Exit"<<endl;
		break;
}
}
}while(userInput != 4);
		break;
		}
		case 4:{
			cout << "Exiting library menu..." <<endl;
			 
			   cout<<"-------------------------------------"<<endl;
    			   cout<<" WELCOME TO THE LIBRARY MENU SYSTEM"<<endl;
    		           cout<<"-------------------------------------"<<endl;
   			   cout << "1. Access Books" << endl;
      			   cout << "2. Access Patrons" << endl;
    			   cout << "3. Access Loans" << endl;
    			   cout<<  "4. Access Library Items"<<endl;
    			   cout << "5. Exit" << endl;
    			   cout<<"-------------------------------------"<<endl;

			}
	}
}while(userInput!= 4);
     break;
            case 5:
                cout << "Exiting the program..." << endl;
	                        break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 5);



    return 0;
}






