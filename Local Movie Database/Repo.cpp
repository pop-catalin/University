#include "Repo.h"
#include <string>

using namespace std;

int Repository::addMovie(const Movie &m) {
	int pos = this->movies.find(m);
	if (pos == -1) {
		this->movies.add(m);
		return 1;
	}
	return 0;
}

int Repository::deleteMovie(const Movie &m) {
	int pos = this->movies.find(m);
	if (pos >= 0) {
		this->movies.del(m);
		return 1;
	}
	return 0;
}

int Repository::updateMovie(const Movie &m1, const Movie &m2) {
	int pos = this->movies.find(m1);
	if(pos >= 0) {
		this->movies.update(m1, m2);
		return 1;
	}
	return 0;
}

void Repository::increaseLikes(const Movie &m) {
	int pos = this->movies.find(m);
	if (pos >= 0) {
		this->movies[pos].increaseLikes();
	}
}