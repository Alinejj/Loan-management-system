#ifndef BOOKSCOLLECTION_H
#define BOOKSCOLLECTION_H

#include "books.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Books;

class BookCollection {


public:
	BookCollection();
	void AddBook();
	void EditBook ();
	void DeleteBook(int bookIsbn);
	Books SearchCriteria(int bookId);
	void PrintList();
	void PrintDetails(const string& title);
	vector<Books>& GetBooks() {
        return bookCollection;
    }

	
private:

vector<Books>bookCollection;

};

#endif
