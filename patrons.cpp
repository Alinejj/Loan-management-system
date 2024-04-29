#include <iostream>
#include "patrons.h"
#include "books.h"
#include "bookcollection.h"
#include "loans.h"
#include <string>

using namespace std;


Patrons::Patrons(){
	this->name = "none";
	this->idNum = 0;
	this->fineBalance = -1;
	this->booksOut = -1;
}

Patrons::Patrons(string name, int idNum, double fineBalance, int booksOut){
	this->name = name;
	this->idNum = idNum;
	this->fineBalance = fineBalance;
	this->booksOut = booksOut;
}


      void Patrons::SetName(const string& name){
	this->name = name;
}

      string Patrons::GetName() const{
		return name;
}


	void Patrons::SetIdNum(int idNum){
		this->idNum = idNum;
}

	int Patrons::GetIdNum() const{
		return idNum;
}


	void Patrons::SetFineBalance(double balance){
		this->fineBalance = balance;
}
	double Patrons::GetFineBalance() const{
	return fineBalance;
}

void Patrons::DeleteAmount(double amount){
	fineBalance -= amount;
}

void Patrons::UpdateAmount(double amount){
	fineBalance += amount;

}


void Patrons::UpdateBooksOut(int change){
	booksOut += change;
}

void Patrons::DecrementBooksOut(int change){
	booksOut -=change;
}


	void Patrons::SetBooksOut(int booksOut){
		this->booksOut = booksOut;
}
	int Patrons::GetBooksOut() const{
		return booksOut;
}

	void Patrons::SetNumLoans(int loan){
		this->numLoans = loan;
}
	int Patrons::GetNumLoans() const{
		return numLoans;
}


void Patrons::Print(){
	cout<<"Patron: "<<GetName()<<endl;
	cout<<"ID number: "<<GetIdNum()<<endl;
	cout<<"Fine balance: "<<GetFineBalance()<<endl;
	cout<<"Get number of books out: "<<GetBooksOut()<<endl;
}