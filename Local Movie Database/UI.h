#pragma once
#include "Controller.h"

class UI {
private:
	Controller ctrl;
public:
	UI(const Controller &c) : ctrl(c) {}
	void run();
private:
	void printInitialMenu();
	static void printAdministratorMenu();
	void printUserMenu();

	int addMovieToRepo();
	int deleteMovieFromRepo();
	void showAllMoviesRepo();
	int updateMovieRepo();
	void deleteMovieFromWatchlist();
	bool isValid(const string &title, const string &genre, const string &year, const string &likes, const string &trailer,const int duration);

	void listMoviesGenre();
	void filterByDuration();
	void listWatchlist();
	void printGenreMenu();
};