
#include "books.h"
#include "bookcollection.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

BookCollection::BookCollection() : bookCollection() {
}

void BookCollection::AddBook(){
	cout<<"\nADD A NEW BOOK"<<endl;
	string name;
	cout<<"Enter the name of the book: "<<endl;
	getline(cin, name);
	

	string author;
	cout<<"Enter the author: "<<endl;
	getline(cin, author);
	


	int isbn;
	cout<<"Enter the isbn number:"<<endl;
	cin>>isbn;
	string temp;
	getline(cin, temp); 



	string lib;
	cout<<"Enter library ID:"<<endl;
	getline(cin, lib);
	
	
	double cost;
	cout<<"Enter cost:"<<endl;
	cin>>cost;
	cin.ignore();

	string status;
	cout<<"Enter current status: "<<endl;
	getline(cin, status);
	


	
	Books book;
	book = Books(name, author,isbn,lib,cost,status);
	bookCollection.push_back(book);
}

void BookCollection::DeleteBook(int bookIsbn) {
    cout << "BOOK DELETED" << endl;
   		
	bool found = false;
	for(auto it = bookCollection.begin(); it != bookCollection.end(); ++it){
		if(it->GetIsbnNumber() == bookIsbn){
			bookCollection.erase(it);
			cout<<"Book has been delete successfully"<<endl;
			found = true;
			break;
}
}
	if(!found){
		cout<<"Book was not found."<<endl;
}

}

void BookCollection::EditBook (){
	cout<<"EDIT YOUR BOOKS"<<endl;

	int isdn;
	cout<<"What is the isbn number of the book you want to edit:"<<endl;
	cin>>isdn;

	for(auto& book : bookCollection){
	    if(book.GetIsbnNumber() ==isdn){
		string newAuthor, newLib, newCurrStatus;
		double newCost;

		cout<<"Enter new author: ";
		getline(cin, newAuthor);
		
		string temp;
	getline(cin, temp); 

		cout<<"Enter new library ID: ";
		getline(cin, newLib);
		
	
		cout<<"Enter new cost:";
		cin>>newCost;
		cin.ignore();

		cout<<"Enter new current status:";
		getline(cin, newCurrStatus);

		book.SetAuthor(newAuthor);
		book.SetLibraryNum(newLib);
		book.SetCost(newCost);
		book.SetCurrStats(newCurrStatus);

	cout<<"Book details updated successfully"<<endl<<endl;
	return;
}
}

cout<<"Book is not found in the collection."<<endl;

}
Books BookCollection::SearchCriteria(int bookId){
	cout<<"SEARCH BOOKS"<<endl;
	Books foundBook;
	for(int i =0; i<bookCollection.size(); i++){
		if(bookCollection.at(i).GetIsbnNumber() == bookId){
		foundBook = bookCollection.at(i);
		foundBook.print();
		return foundBook;
}
else{
	
	cout<<"Book not found in the collection."<<endl;
}
}
return foundBook;

	}
void BookCollection::PrintList(){
	cout<<"PRINTING ALL BOOKS"<<endl;

	for(const auto& book : bookCollection){
		cout<<"Author: "<<book.GetAuthor()<<endl;
		cout<<"Title: "<<book.GetTitle()<<endl;
		cout<<"ISBN Number: "<<book.GetIsbnNumber()<<endl;
		cout<<"Library Number: "<<book.GetLibraryNum()<<endl;
		cout<<"Cost: "<<book.GetCost()<<endl;
		cout<<"Current Status: "<<book.GetCurrStats()<<endl;
		cout<<"-------------------------------------"<<endl;
}

}
void BookCollection::PrintDetails(const string& title){
	
	for( auto& book : bookCollection){
	if( book.GetTitle() == title){
		cout<<"Author: "<<book.GetAuthor()<<endl;
		cout<<"Title: "<<book.GetTitle()<<endl;
		cout<<"ISBN Number: "<<book.GetIsbnNumber()<<endl;
		cout<<"Library Number: "<<book.GetLibraryNum()<<endl;
		cout<<"Cost: "<<book.GetCost()<<endl;
		cout<<"Current Status: "<<book.GetCurrStats()<<endl;
		return;
}
}
cout<<"Book not found."<<endl;	
}
