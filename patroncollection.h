#ifndef PATRONCOLLECTION_H
#define PATRONCOLLECTION_H


#include "patrons.h"
#include "libraryitem.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Patrons;

class PatronCollection{

public:
	PatronCollection();
	void AddPatron();
	void EditPatron();
	void DeletePatron(int isbn);
	Patrons SearchPatron(int patronId);
	void PrintPatron();
	void PrintPatronDetail(const string& patrons);
	void PayFines(int patronId, double amount);
	void UpdateNumLoans(int patronId);
	vector<Patrons>& GetPatrons() {
        return patronCollection;
    }



private:
	vector<Patrons>patronCollection;
};

#endif
