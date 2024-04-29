#ifndef LIBRARY_DVD
#define LIBRARY_DVD

#include "libraryitem.h"
#include <iostream>
#include <string>

using namespace std;

class LibraryDvd: public LibraryItem{

   private:
	string title;
	string cat;
	int runTime;
	string studio;
	string release;

public:
	LibraryDvd();
	LibraryDvd(int id, double cost, string status, int loanPeriod, string title, string category, int runTime, string studio, string release);


	void SetTitle(string title);
	string GetTitle() const;

	void SetCategory(string cat);
	string GetCategory() const;

	void SetRunTime(int run);
	int GetRunTime() const;

	void SetStudio(string studio);
	string GetStudio() const;

	void SetRelease(string release);
	string GetRelease() const;

	void AddItem();
	void DeleteItem(int itemId);
    void EditItem(int itemId);


	void displayDetails() const;

};

#endif
	