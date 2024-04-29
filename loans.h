#ifndef LOANS_H
#define LOANS_H
#include "books.h"
#include "patrons.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;


class Loans {

public:
	Loans();
	Loans(int loanId, int bookId, int patronId, time_t dueDate, string currentStats);

	void SetLoanId(int loanId);
	int GetLoanId() const;

	void SetBookId(int bookId);
	int GetBookId() const;

	void SetPatronId(int patronId);
	int GetPatronId() const;

	void SetDueDate(time_t dueDate);
	time_t GetDueDate() const;

	void SetCurrentStatus(const string& status);
	string GetCurrentStatus() const;






private:

int loanId;
int bookId;
int patronId;
time_t dueDate;
string currentStats;




};

#endif