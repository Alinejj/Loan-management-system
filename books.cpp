#include "books.h"
#include "patrons.h"
#include "loans.h"
#include <iostream>
#include <string>
using namespace std;


Books::Books(){
	this->author = "none";
	this->title = "unknown";
	this->isbnNum = 0;
	this->libId = "none";
	this->cost = 0.0;
	this->currStats = "not known";
}

Books::Books(string author, string title, int isbnNum, string libId, double cost, string currStats){
	this->author = author;
	this->title = title;
	this->isbnNum = isbnNum;
	this->libId = libId;
	this->cost = cost;
	this->currStats = currStats;
}
	


void Books::SetAuthor(const string& author){
	this->author = author;
}
	
string Books::GetAuthor() const {
	return author;
}


void Books::SetTitle(const string& title){
	this->title = title;
}
string Books::GetTitle() const{
	return title;
}


void Books::SetIsbnNumber(int isbn){
	this->isbnNum = isbn;
}
int Books::GetIsbnNumber() const{
	return isbnNum;
}


void Books::SetLibraryNum(const string& libNum){
	this->libId = libNum;
}
string Books::GetLibraryNum() const{
	return libId;
}


void Books::SetCost(double cost){
	this->cost = cost;
}
double Books::GetCost() const{
	return cost;
}


void Books::SetCurrStats(const string& currStats){
	this->currStats = currStats;
}
string Books::GetCurrStats() const{
	return currStats;
}
void Books::print() {
		cout<<"Author: "<<GetAuthor()<<endl;
	cout<<"Title: "<<GetTitle()<<endl;
	cout<<"Library ID: "<<GetLibraryNum()<<endl;
	cout<<"ISBN Number: "<<GetIsbnNumber()<<endl;
	cout<<"Cost: "<<GetCost()<<endl;
	cout<<"Current Status: "<<GetCurrStats()<<endl;
}
	
