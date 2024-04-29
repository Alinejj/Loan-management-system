#ifndef LIBRARY_ITEMS
#define LIBRARY_ITEMS


#include <iostream>
#include <string>

using namespace std;


class LibraryItem {

  protected: 
	int id;
	double cost;
	string status;
	int loanPeriod;
  public:
		
	LibraryItem();

LibraryItem(int id, double cost, string status, int loanPeriod);
	
void SetId(int id);
int GetId() const;

void SetCost(double cost);
double GetCost() const;

void SetStatus(string status);
string GetStatus() const;

void SetLoan(int loan);
int GetLoan() const;

	virtual void AddItem() = 0;
    virtual void DeleteItem(int itemId) = 0;
    virtual void EditItem(int itemId) = 0;


virtual void displayDetails() const = 0;

friend ostream& operator<<(ostream& os, const LibraryItem& item);
};

#endif