#include "libraryitem.h"
#include "librarydvd.h"
#include <iostream>
#include <string>

using namespace std;

LibraryDvd::LibraryDvd(){
	this->title = "none";
	this->cat = "unknown";
	this->runTime = 0;
	this->studio = "none";
	this->release = "unknown";
}
LibraryDvd::LibraryDvd(int id, double cost, string status, int loanPeriod, string title, string category, int runTime, string studio, string release){
	this->id = id;
	this->cost = cost;
	this->status = status;
	this->loanPeriod = loanPeriod;
	this->title = title;
	this->cat = category;
	this->runTime = runTime;
	this->studio = studio;
	this->release = release;
}


void LibraryDvd::SetTitle(string title){
	this->title = title;
}
string LibraryDvd::GetTitle() const{
	return title;
}

void LibraryDvd::SetCategory(string cat){
	this->cat = cat;
}
string LibraryDvd::GetCategory() const{
	return cat;
}

void LibraryDvd::SetRunTime(int run){
	this->runTime = run;
}
int LibraryDvd::GetRunTime() const{
	return runTime;
}

void LibraryDvd::SetStudio(string studio){
	this->studio = studio;
}
string LibraryDvd::GetStudio() const{
	return studio;
}

void LibraryDvd::SetRelease(string release){
	this->release = release;
}
string LibraryDvd::GetRelease() const{
	return release;
}

void LibraryDvd::AddItem(){
 	cin.ignore();
	cout<<"Enter the title of the dvd: ";
	getline(cin, title);

	cout<<"Enter the category of the dvd: ";
	getline(cin, cat);

	cout<<"Enter the run time of the dvd: ";
	cin>>runTime;

	cin.ignore();

	cout<<"Enter the studio of the dvd: ";
	getline(cin, studio);
	//cin.ignore();

	cout<<"Enter the release date of the dvd: "<<endl;
	//cin.ignore();
	getline(cin, release);
	//cin.ignore();
	//cin.ignore();

cout<<"Enter ID: "<<endl;
	cin>>id;
//cin.ignore();

cout<<"Enter cost: "<<endl;
cin>>cost;

		cout<<"Enter loan Period: "<<endl;
		cin>>loanPeriod;
		cin.ignore();

		cout<<"Enter status: "<<endl;
		getline(cin, status);


	SetTitle(title);
	SetCategory(cat);
	SetRunTime(runTime);
	SetStudio(studio);
	SetRelease(release);

}

void LibraryDvd::DeleteItem(int run){
	if(GetRunTime() == run){
	
	SetTitle("");
	SetCategory("");
	SetRunTime(0);
	SetStudio("");
	SetRelease("");
	SetId(0); // Assuming 0 is not a valid ID
        SetCost(0.0); // Assuming 0.0 is not a valid cost
        SetLoan(0); // Assuming 0 is not a valid loan period
        SetStatus("");
	
	cout<<"Item deleted successfully"<<endl;
}

else{
	cout<<"Item not found"<<endl;

}
}



    void LibraryDvd::EditItem(int run){
	if(GetRunTime() == run){
	
	string newTitle, newCategory, newStudio, newRelease, newStatus;
	int newRun, newId, newLoan;
	double newCost;

	cout<<"Enter new Title: ";
	cin.ignore();	
	getline(cin, newTitle);
	cin.ignore();

	cout<<"Enter new category: ";
	getline(cin,newCategory);

	cout<<"Enter new studio: ";
	getline(cin, newStudio);
	cin.ignore();

	cout<<"Enter new release date : ";
	getline(cin, newRelease);

	cout<<"Enter new run time :";
	cin>>newRun;
	
	cout<<"Enter new ID: ";
	cin>>newId;
	cin.ignore();

	cout<<"Enter new loan period: ";
	cin>>newLoan;
	cin.ignore();

	cout<<"Enter new cost: ";
	cin>>newCost;
	cin.ignore();

	cout<<"Enter new status: ";
	getline(cin,newStatus);
	cin.ignore();


	SetTitle(newTitle);
	SetCategory(newCategory);
	SetRunTime(newRun);
	SetStudio(newStudio);
	SetRelease(newRelease);
	SetId(newId); 
        SetCost(newCost); 
        SetLoan(newLoan); 
        SetStatus(newStatus);

cout<<"Item details updated! "<<endl;
	}
else{
	cout<<"Item not found"<<endl;
}
}

	






void LibraryDvd::displayDetails() const{
	cout << "DVD ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Category: " << cat << endl;
        cout << "Run Time: " << runTime << " minutes" << endl;
        cout << "Studio: " << studio << endl;
        cout << "Release Date: " << release << endl;
        cout << "Cost: " << cost << endl;
        cout << "Status: " << status << endl;
        cout << "Loan Period: " << loanPeriod << " days" << endl;
}

