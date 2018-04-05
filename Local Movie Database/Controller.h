#pragma once
#include "Repo.h"
#include "Watchlist.h"

using namespace std;

class Controller {
private:
	Repository repo;
	Watchlist watchlist;
public:
	Controller(const Repository &r) : repo{ r } {}

	Repository getRepo() const {
		return repo;
	}

	Watchlist getWatchlist() const {
		return watchlist;
	}

	int addMovieToRepo(const string &title, const string &genre, const int year, const int likes, const string &trailer, const int duration);
	int deleteMovieFromRepo(const string &title);
	int updateMovieRepo(const string &title1, const string &title2, const string &genre2, const int year2, const int likes2, const string &trailer2,const int duration);

	void addMovieToWatchlist(const Movie &movie);
	void startWatchlist();
	int deleteMovieWatchlist(const string & title);
	void increaseMovieLikes(const string & title);
};