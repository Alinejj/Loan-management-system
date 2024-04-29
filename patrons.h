#ifndef PATRONS_H
#define PATRONS_H
#include <iostream>
#include "books.h"
#include "loans.h"
#include "bookcollection.h"
#include <string>

using namespace std;

class Patrons{

public:

	Patrons();
	Patrons(string name, int idNum, double fineBalance, int booksOut);

	void SetName(const string& name);
	string GetName() const;

	void SetIdNum(int idNum);
	int GetIdNum() const;

	void SetFineBalance(double balance);
	double GetFineBalance() const;

	void SetBooksOut(int booksOut);
	int GetBooksOut() const;
	
	void DecrementBooksOut(int change);
	void DeleteAmount(double amount);
	void UpdateAmount(double amount);
	void UpdateBooksOut(int change);
		void SetNumLoans(int loan);
		int GetNumLoans() const;
	void Print();

private:
	string name;
	int idNum;
	double fineBalance;
	int booksOut;
	int numLoans;

};

#endif
