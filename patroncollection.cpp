#include "patrons.h"
#include "patroncollection.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

PatronCollection::PatronCollection() : patronCollection(){ 
}

void PatronCollection::AddPatron() {
	cout<<"ADD A NEW PATRON"<<endl;
	
	string name;
	cout<<"Enter the name of the patron:"<<endl;
	getline(cin, name);

	int id;
	cout<<"Enter the ID number of the patron:"<<endl;
	cin>>id;
	cin.ignore();

	double fine;
	cout<<"Enter the fine balance of the patron:"<<endl;
	cin>>fine;
	
	int books;
	cout<<"Enter the number of books out:"<<endl;
	cin>>books;

	Patrons patron;
	patron = Patrons(name, id, fine, books);
	patronCollection.push_back(patron);
}


void PatronCollection::EditPatron(){
	cout<<"EDIT YOUR PATRONS"<<endl;
	
	string editPatron;
	cout<<"What is the name of the patron you want to edit:"<<endl;
	getline(cin, editPatron);

	for(auto& patron : patronCollection){
	  if(patron.GetName() == editPatron){
		int newID;
		double newFine;
		double newBooks;
	
		cout<<"Enter the new ID of the patron: "<<endl;
		cin>>newID;

		cout<<"Enter the new fine balance of the patron: "<<endl;
		cin>>newFine;

		cout<<"Enter the updated number of books out for the patron: "<<endl;
		cin>>newBooks;

		patron.SetIdNum(newID);
		patron.SetFineBalance(newFine);
		patron.SetBooksOut(newBooks);
		
		cout<<"Patron details updated successfully"<<endl;
		return;
}
}
	cout<<"Patron not found in collection"<<endl;
}

void PatronCollection::DeletePatron(int isbn){
	cout<<"PATRON DELETED"<<endl;
		
	bool found = false;
	for(auto it = patronCollection.begin(); it != patronCollection.end(); ++it){
		if(it->GetIdNum() == isbn){
			patronCollection.erase(it);
			cout<<"Patron has been deleted successfully"<<endl;
			found = true;
			break;
}
}
	if(!found){
		cout<<"Patron was not found."<<endl;
}


	}

Patrons PatronCollection::SearchPatron(int patronId){
	cout<<"SEARCH PATRONS"<<endl;
	Patrons foundPatron;

	for(int i =0; i<patronCollection.size(); i++){
		if(patronCollection.at(i).GetIdNum() == patronId){
		foundPatron = patronCollection.at(i);
		foundPatron.Print();
		return foundPatron ;
}
else{
	
	cout<<"Patron not found in the collection."<<endl;
}
}
return foundPatron ;

	}

void PatronCollection::PrintPatron(){
	cout<<"PRINTING ALL PATRONS"<<endl;
	for(const auto& patron : patronCollection){
		cout<<"Patron name: "<<patron.GetName()<<endl;
		cout<<"Patron ID number: "<<patron.GetIdNum()<<endl;
		cout<<"Patron fine balance: "<<patron.GetFineBalance()<<endl;
		cout<<"Patron's number of books out: "<<patron.GetBooksOut()<<endl;
		cout<<"---------------------------------------------"<<endl;
}
}

void PatronCollection::PrintPatronDetail(const string& patrons){
	
		for(auto& patron : patronCollection){
	   if(patron.GetName() == patrons){
		cout<<"Patron name: "<<patron.GetName()<<endl;
		cout<<"Patron ID number: "<<patron.GetIdNum()<<endl;
		cout<<"Patron fine balance: "<<patron.GetFineBalance()<<endl;
		cout<<"Patron's number of books out: "<<patron.GetBooksOut()<<endl;
		return;
}
}
cout<<"Patron not found."<<endl;
}


void PatronCollection::PayFines(int patronId, double amount){
	for(auto& patron : patronCollection){
		if(patron.GetIdNum() == patronId){
			double newFine = patron.GetFineBalance() - amount;
			patron.SetFineBalance(newFine);
			cout<<"Fine paid successfully"<<endl;
			return;
	}
}
	cout<<"Patron not found"<<endl;
}

void PatronCollection::UpdateNumLoans(int patronId) {
    Patrons patron = SearchPatron(patronId);
    int numLoans = patron.GetNumLoans();
    patron.SetNumLoans(numLoans + 1);
}






