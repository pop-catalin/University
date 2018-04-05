#include "Controller.h"

using namespace std;

int Controller::addMovieToRepo(const string &title, const string &genre, const int year, const int likes, const string &trailer, const int duration) {
	Movie m{title, genre, year, likes, trailer, duration};
	return this->repo.addMovie(m);
}

int Controller::deleteMovieFromRepo(const string &title) {
	Movie m{title,"",0,0,"",0};
	return this->repo.deleteMovie(m);
}

int Controller::updateMovieRepo(const string &title1, const string &title2, const string &genre2, const int year2, const int likes2, const string &trailer2, const int duration) {
	Movie m1{title1,"",0,0,"",0};
	Movie m2{title2, genre2, year2, likes2, trailer2, duration};
	return this->repo.updateMovie(m1, m2);
}

void Controller::addMovieToWatchlist(const Movie &movie) {
	this->watchlist.add(movie);
}

void Controller::startWatchlist() {
	this->watchlist.play();
}

int Controller::deleteMovieWatchlist(const string &title) {
	Movie m{ title,"",0,0,"",0 };
	return this->watchlist.deleteMovie(m);
}

void Controller::increaseMovieLikes(const string &title) {
	Movie m{ title,"",0,0,"",0 };
	this->repo.increaseLikes(m);
}