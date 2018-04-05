#pragma once
#include "DynamicVector.h"

class Watchlist {
private:
	DynamicVector<Movie> movies;
	int current;
public:
	Watchlist();
	void add(const Movie &movie);
	Movie Watchlist::getCurrentMovie();
	void play();
	bool isEmpty();
	int deleteMovie(const Movie & m);
	DynamicVector<Movie> getMovies() const {
		return movies;
	}
};