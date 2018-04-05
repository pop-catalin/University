#include "Watchlist.h"

Watchlist::Watchlist() {
	this->current = 0;
}

void Watchlist::add(const Movie &movie) {
	this->movies.add(movie);
}

Movie Watchlist::getCurrentMovie() {
	if (this->current == this->movies.getSize())
		this->current = 0;
	Movie *elems = this->movies.getAllElems();
	if (elems != NULL)
		return elems[this->current];
	return Movie{};
}

void Watchlist::play() {
	if (this->movies.getSize() == 0)
		return;
	this->current = 0;
	Movie currentMovie = this->getCurrentMovie();
	currentMovie.show();
}

bool Watchlist::isEmpty() {
	return this->movies.getSize() == 0;
}

int Watchlist::deleteMovie(const Movie &m) {
	int pos = this->movies.find(m);
	if (pos >= 0) {
		this->movies.del(m);
		return 1;
	}
	return 0;
}