#ifndef LOANCOLLECTION_H
#define LOANCOLLECTION_H

#include "loans.h"
#include "books.h"
#include "patrons.h"
#include "bookcollection.h"
#include "patroncollection.h"
#include "libraryitem.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Loans;
class Books;
class Patrons;
class BookCollection;
class PatronCollection;
class LoanCollection {

public:
       	void CheckOutBook(PatronCollection allPatrons, BookCollection allBooks);
    	void ReportLost (PatronCollection allPatrons, BookCollection allBooks);
    	void PrintOverdueBooks(BookCollection allBooks, PatronCollection allPatrons);
	void AddLoan();
	void EditLoan();
	void RecheckBook(int patronId, int loanId, int bookIsbn);
	void UpdateLoanStatus();
	void ListAllBooksForPatron(int patronId, BookCollection allBooks);
	void CheckInBook(int bookId);

private:
	vector<Loans>loanCollection;
	
       };

#endif