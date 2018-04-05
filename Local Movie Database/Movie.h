#pragma once
#include <iostream>
using namespace std;

class Movie {
private:
	string title;
	string genre;
	int year;
	int likes;
	string trailer;
	int duration;
public:
	Movie();
	Movie(const string &title, const string &genre, const int year, const int likes, const string &trailer, const int duration);

	string getTitle() const { 
		return title; 
	}
	string getGenre() const { 
		return genre; 
	}
	int getYear() const {
		return year;
	}
	int getLikes() const {
		return likes;
	}
	string getTrailer() const {
		return trailer;
	}
	
	int getDuration() const {
		return duration;
	}

	void increaseLikes() {
		likes += 1;
	}

	bool Movie::operator <(const int x) {
		if (this->getDuration() < x)
			return true;
		return false;
	}

	void show();
};