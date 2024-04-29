#ifndef LIBRARY_AUDIO
#define LIBRARY_AUDIO

#include "libraryitem.h"
#include "librarybook.h"

#include <iostream>
#include <string>

using namespace std;

class LibraryAudio: public LibraryItem{

  private:
	string artist;
	string title;
	int tracks;
	string releaseDate;
	string genre;

  public:
	LibraryAudio();
	LibraryAudio(int id, double cost, string status, int loanPeriod,string artist, string title, int tracks,string releaseDate, string genre);

	void SetArtist(string artist);
	string GetArtist() const;

	void SetTitle(string title);
	string GetTitle() const;
	
	void SetTracks(int tracks);
	int GetTracks() const;

	void SetReleaseDate(string release);
	string GetReleaseDate() const;

	void SetGenre(string genre);
	string GetGenre() const;

	void AddItem();
	void DeleteItem(int itemId);
    void EditItem(int itemId);



	void displayDetails() const;

};

#endif
