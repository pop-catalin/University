#include "Movie.h"
#include "UI.h"
#include "DynamicVector.h"
#include <Windows.h>
#include "Tests.h"

using namespace std;

int main() {

	//Tests::testAll();
	Repository repo{};

	Movie m1{"Harry Potter and the Half Blood Prince", "Fantasy", 2009, 600, "http://www.imdb.com/title/tt0417741/",50};
	Movie m2{"Fight Club", "Drama", 1999, 500, "http://www.imdb.com/title/tt0137523/",40};
	Movie m3{ "Forrest Gump", "Drama", 1994, 520, "http://www.imdb.com/title/tt0109830/",100 };
	Movie m5{ "The Shawshank Redemption", "Drama", 1994, 419, "http://www.imdb.com/title/tt0111161/", 44};
	Movie m6{ "Schindler's List", "History", 1993, 504, "http://www.imdb.com/title/tt0108052/", 10};
	Movie m7{ "The Shining", "Horror", 1980, 520, "http://www.imdb.com/title/tt0081505/",70};
	Movie m8{ "Madagascar", "Animation", 2005, 214, "http://www.imdb.com/title/tt0351283/", 120};
	Movie m9{ "Scarface", "Drama", 1983, 315, "http://www.imdb.com/title/tt0086250/",110};
	Movie m10{ "Over the Garden Wall", "Animation", 2014, 800, "http://www.imdb.com/title/tt3718778/",15 };

	repo.addMovie(m1);
	repo.addMovie(m2);
	repo.addMovie(m3);
	repo.addMovie(m5);
	repo.addMovie(m6);
	repo.addMovie(m7);
	repo.addMovie(m8);
	repo.addMovie(m9);
	repo.addMovie(m10);

	Controller ctrl{repo};
	UI ui{ctrl};
	ui.run();

	return 0;
	}