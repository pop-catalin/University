#pragma once
#include "Movie.h"
#include "DynamicVector.h"

class Repository {
private:
	DynamicVector<Movie> movies;
public:
	Repository() {}

	int addMovie(const Movie &m);
	int deleteMovie(const Movie &m);
	int updateMovie(const Movie &m1, const Movie &m2);

	void increaseLikes(const Movie & m);

	DynamicVector<Movie> getMovies() const {
		return movies;
	}
};