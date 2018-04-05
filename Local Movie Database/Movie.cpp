#include "Movie.h"
#include <Windows.h>
#include <shellapi.h>
using namespace std;


Movie::Movie(): title(""), genre(""), year(), likes(), trailer("")/*, duration()*/ {}

Movie::Movie(const string &title, const string &genre, const int year, const int likes, const string &trailer, const int duration) {
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
	this->duration = duration;
}

void Movie::show() {
	ShellExecuteA(NULL, NULL, "opera.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}