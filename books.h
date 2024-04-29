#ifndef BOOKS_H
#define BOOKS_H
#include "loans.h"
#include "patrons.h"
#include <iostream>
#include <string>
using namespace std;

class Books{

public:
	Books();
	Books(string author, string title, int isbnNum, string libId, double cost, string currStats);
	
	void SetAuthor(const string& author);
	string GetAuthor() const;

	void SetTitle(const string& title);
	string GetTitle() const;

	void SetIsbnNumber(int isbn);
	int GetIsbnNumber()const ;

	void SetLibraryNum(const string& libNum);
	string GetLibraryNum() const;

	void SetCost(double cost);
	double GetCost() const;

	void SetCurrStats(const string& currStats);
	string GetCurrStats() const;

	void print() ;
	
	


private:
	string author;
	string title;
	int isbnNum;
	string libId;
	double cost;
	string currStats;
};

#endif