#ifndef LIBRARY_BOOK
#define LIBRARY_BOOK

#include "libraryitem.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LibraryBook: public LibraryItem {

 
   public:
   	LibraryBook();
	LibraryBook(int id, double cost, string status, int loanPeriod, string title, string author, int isbn, string cat);

	void SetTitle(string title);
	string GetTitle() const;

	void SetAuthor(string author);
	string GetAuthor() const;
	
	void SetIsbn(int isbn);
	int GetIsbn() const;

	void SetCategory(string cat);
	string GetCategory() const;

	void AddItem();
	
	void EditItem (int isbn);
	void DeleteItem(int isbn);
	

	void displayDetails() const;

 private:
	string title;
	string author;
	int isbn;
	string cat;
	

};

#endif
 
