#include "Tests.h"
#include <assert.h>
#include "DynamicVector.h"
#include "Watchlist.h"
#include "Repo.h"
#include "Controller.h"

void Tests::testMovie() {
	Movie m{"Imi plac","Testele",2000,100,"http://www.imdb.com/title/tt0109830/",0};
	assert(m.getTitle() == "Imi plac");
	assert(m.getGenre() == "Testele");
	assert(m.getYear() == 2000);
	assert(m.getLikes() == 100);
	assert(m.getTrailer() == "http://www.imdb.com/title/tt0109830/");
}

void Tests::testDynamicVector() {
	DynamicVector<int> v1{2};
	v1.add(42);
	v1.add(13);
	assert(v1.getSize() == 2);
	assert(v1[0] == 42);
	DynamicVector<int> v2 = v1;
	assert(v2.getSize() == 2);
	DynamicVector<int> v3;
	v3 = v1;
	assert(v3[1] == 13);
}

void Tests::testRepository() {
	Repository repo{};
	Movie m{"Imi plac","Testele",2000,100,"http://www.imdb.com/title/tt0109830/",0};
	Movie n{"Nu Imi plac","Testele",2000,100,"http://www.imdb.com/title/tt0109830/",0};
	repo.addMovie(m);
	repo.addMovie(m);
	DynamicVector<Movie> movies = repo.getMovies();
	assert(movies.getSize() == 1);
	assert(movies[0].getTitle() == "Imi plac");
	movies[0].increaseLikes();
	assert(movies[0].getLikes() == 101);
	repo.updateMovie(m,n);
	repo.deleteMovie(n);
	//assert(movies.getSize() == 0);

}

void Tests::testWatchlist() {
	Watchlist watchlist{};
	Movie m{"Imi plac","Testele",2000,100,"http://www.imdb.com/title/tt0109830/",0};
	Movie n{"Nu Imi plac","Testele",2000,100,"http://www.imdb.com/title/tt0109830/",0};
	watchlist.add(m);
	watchlist.add(n);
	assert(watchlist.isEmpty() == false);
	watchlist.deleteMovie(m);
	watchlist.deleteMovie(n);
	assert(watchlist.isEmpty() == true);

}

void Tests::testController() {
	Repository repo{};
	Controller ctrl{repo};
	ctrl.addMovieToRepo("Imi plac","Testele",2000,100,"http://www.imdb.com/title/tt0109830/",0);
	ctrl.addMovieToRepo("Nu Imi plac","Testele",2000,100,"http://www.imdb.com/title/tt0109830/",0);
	assert(ctrl.getRepo().getMovies().getSize() == 2);
	ctrl.deleteMovieFromRepo("Imi plac");
	ctrl.updateMovieRepo("Imi plac", "Cal", "cal", 2000, 123, "http://www.imdb.com/title/tt0109830/",0);
	Movie m{"Imi plac","Testele",2000,100,"http://www.imdb.com/title/tt0109830/",0};
	ctrl.addMovieToWatchlist(m);
	Watchlist watchlist = ctrl.getWatchlist();
	assert(watchlist.isEmpty() == false);
	assert(watchlist.getCurrentMovie().getTitle() == "Imi plac");
	ctrl.startWatchlist();
	ctrl.deleteMovieWatchlist("Imi plac");
}

void Tests::testAll() {
	testMovie();
	testDynamicVector();
	testRepository();
	testWatchlist();
	testController();
}