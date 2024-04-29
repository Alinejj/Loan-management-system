#include "libraryitem.h"
#include <iostream>
#include <string>

using namespace std;

LibraryItem::LibraryItem(){
	this->id = 0;
	this->cost = 0.0;
	this->status = "unknown";
	this->loanPeriod = 0;
}


LibraryItem::LibraryItem(int id, double cost, string status, int loanPeriod){
	this->id = id;
	this->cost = cost;
	this->status = status;
	this->loanPeriod = loanPeriod;
}

void LibraryItem::SetId(int id){
	this->id = id;
}
int LibraryItem::GetId() const{
	return id;
}

void LibraryItem::SetCost(double cost){
	this->cost = cost;
}
double LibraryItem::GetCost() const{
	return cost;
}

void LibraryItem::SetStatus(string status){
	this->status = status;
}
string LibraryItem::GetStatus() const{
	return status;
}

void LibraryItem::SetLoan(int loan){
	this->loanPeriod = loan;
}
int LibraryItem::GetLoan() const{
	return loanPeriod;
}
















ostream& operator<<(ostream& os, const LibraryItem& item) {
        os << "ID: " << item.id << endl;
        os << "Cost: " << item.cost << endl;
        os << "Status: " << item.status << endl;
        os << "Loan Period: " << item.loanPeriod << " days" << endl;
        return os;
    }

