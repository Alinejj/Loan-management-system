#include "books.h"
#include "patrons.h"
#include "loans.h"
#include "bookcollection.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

Loans:: Loans() : dueDate(time(nullptr)) {
	this->loanId = 0;
	this->bookId = 0;
	this->patronId = 0;
	this->currentStats = "unknown";
}

Loans::Loans(int loanId, int bookId, int patronId, time_t dueDate, string currentStats){
	this->loanId = loanId;
	this->bookId = bookId;
	this->patronId = patronId;
	this->dueDate = dueDate;
	this->currentStats = currentStats;
}





void Loans::SetLoanId(int loanId){
	this->loanId = loanId;
}
int Loans::GetLoanId() const{
		return loanId;
}


void Loans::SetBookId(int bookId){
	this->bookId = bookId;
}
int Loans::GetBookId() const{
	return bookId;
}


void Loans::SetPatronId(int patronId){
	this->patronId = patronId;
}
int Loans::GetPatronId() const{
	return patronId;
}

void Loans::SetDueDate(time_t dueDate){
	this->dueDate = dueDate;
}
time_t Loans::GetDueDate() const{
	return dueDate;
}

void Loans::SetCurrentStatus(const string& status){
	this->currentStats = status;
}
string Loans::GetCurrentStatus() const{
	return currentStats;
}
