#include "UI.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void UI::printInitialMenu() {
	cout << "1- Administrator Mode\n";
	cout << "2- User Mode\n";
	cout << "0- Exit\n";
}

void UI::printAdministratorMenu() {
	cout<<"1- Add movie\n";
	cout<<"2- Display all\n";
	cout<<"3- Delete movie\n";
	cout<<"4- Update movie\n";
	cout<<"0- Exit\n";
}

void UI::printUserMenu() {
	cout << "1- See movies by genre\n";
	cout << "2- Delete movie from watchlist\n";
	cout << "3- See watchlist\n";
	cout << "0- Exit\n";
}

int UI::addMovieToRepo() {
	cout<<"Enter the title: ";
	string title;
	getline(cin,title);
	cout<<"Enter the genre: ";
	string genre;
	getline(cin, genre);
	cout<<"Enter the trailer link: ";
	string trailer;
	getline(cin,trailer);
	cout<<"Enter the year: ";
	string year;
	getline(cin,year);
	cout<<"Enter the likes: ";
	string likes;
	getline(cin,likes);
	if(isValid(title, genre, year, likes, trailer,0) == true)
		return this->ctrl.addMovieToRepo(title, genre, stoi(year), stoi(likes), trailer,0);
	else {
		cout<<"Movie data not valid\n";
		return 0;
	}

}

int UI::deleteMovieFromRepo() {
	cout<<"Enter the title: ";
	string title;
	getline(cin, title);
	return this->ctrl.deleteMovieFromRepo(title);
}

void UI::showAllMoviesRepo() {
	DynamicVector<Movie> v = this->ctrl.getRepo().getMovies();
	Movie *movies = v.getAllElems();
	if (movies == NULL)
		return;
	if (v.getSize() == 0) {
		cout << "There are no movies in the database\n";
		return;
	}
	for(int i = 0; i < v.getSize(); i++) {
		Movie m = movies[i];
		cout<< m.getTitle() << ", Genre- "<< m.getGenre()<< ", Year- "<< m.getYear()<< ", Likes- "<< m.getLikes()<< ", Trailer- "<< m.getTrailer()<< endl;
	}
}

void UI::listMoviesGenre() {
	DynamicVector<Movie> v = this->ctrl.getRepo().getMovies();
	Movie *movies = v.getAllElems();
	cout << "Enter the genre: ";
	string genre;
	getline(cin, genre);
	if (movies == NULL)
		return;
	if (v.getSize() == 0) {
		cout << "There are no movies in the database\n";
		return;
	}
	int cmd;
	for (int i = 0; i < v.getSize(); i++) {
		if (movies[i].getGenre() == genre) {
			cout << movies[i].getTitle() << ", Genre- " << movies[i].getGenre() << ", Year- " << movies[i].getYear() << ", Likes- " << movies[i].getLikes() << endl;
			movies[i].show();
			printGenreMenu();
			cin >> cmd;
			if (cmd == 1) {
				this->ctrl.addMovieToWatchlist(movies[i]);
			}
			else if (cmd == 2)
				continue;
			else if (cmd == 3)
				break;
		}
	}
}

void UI::filterByDuration() {
	DynamicVector<Movie> v = this->ctrl.getRepo().getMovies();
	Movie *movies = v.getAllElems();
	if (movies == NULL)
		return;
	if (v.getSize() == 0) {
		cout << "There are no movies in the database\n";
		return;
	}
	int x;
	cout << "Give number";
	cin >> x;
	for (int i = 0; i < v.getSize(); i++) {
		Movie m = movies[i];
		if(m < x)
			cout << m.getTitle() << ", Genre- " << m.getGenre() << ", Year- " << m.getYear() << ", Likes- " << m.getLikes() << ", Trailer- " << m.getTrailer() <<",Duration- "<<m.getDuration()<< endl;
	}
}

void UI::listWatchlist() {
	DynamicVector<Movie> v = this->ctrl.getWatchlist().getMovies();
	Movie *movies = v.getAllElems();
	if (movies == NULL)
		return;
	if (v.getSize() == 0) {
		cout << "There are no movies in the watchlist\n";
		return;
	}
	for (int i = 0; i < v.getSize(); i++) {
		Movie m = movies[i];
		cout << m.getTitle() << ", Genre- " << m.getGenre() << ", Year- " << m.getYear() << ", Likes- " << m.getLikes() << ", Trailer- " << m.getTrailer() << endl;
	}
}

void UI::printGenreMenu() {
	cout << "1- Add movie to watchlist\n";
	cout << "2- Go to the next movie\n";
	cout << "0- Exit\n";
}

int UI::updateMovieRepo() {
	cout<<"Enter the title of the movie you want to update: ";
	string title1;
	getline(cin, title1);
	cout<<"Enter the title: ";
	string title;
	getline(cin,title);
	cout<<"Enter the genre: ";
	string genre;
	getline(cin, genre);
	cout<<"Enter the trailer link: ";
	string trailer;
	getline(cin, trailer);
	cout<<"Enter the year: ";
	string year;
	getline(cin, year);
	cout<<"Enter the likes: ";
	string likes;
	getline(cin, likes);
	if(isValid(title, genre, year, likes, trailer,0) == true)
		return this->ctrl.updateMovieRepo(title1, title, genre, stoi(year), stoi(likes), trailer,0);
	else {
		cout<<"Movie data not valid\n";
		return 0;
	}
}

void UI::deleteMovieFromWatchlist() {
	cout << "Enter the title of the movie you want to delete: ";
	string title;
	getline(cin, title);
	if (this->ctrl.deleteMovieWatchlist(title) == 1) {
		cout << "1- Like Movie\n";
		cout << "2- No Like";
		int cmd;
		cout << ">> ";
		cin >> cmd;
		if (cmd == 1) {
			this->ctrl.increaseMovieLikes(title);
		}
	}
}

void UI::run() {
	while (true) {
		UI::printInitialMenu();
		int cmd;
		cout<< ">> ";
		cin>> cmd;
		cin.ignore();
		if(cmd == 0)
			break;
		if (cmd == 1) {
			while (true) {
				UI::printAdministratorMenu();
				int cmd1;
				cout << ">> ";
				cin >> cmd1;
				cin.ignore();
				if (cmd1 == 0)
					break;
				if (cmd1 == 1) {
					int res = this->addMovieToRepo();
					if (res == 1)
						cout << "Movie was added\n";
					else
						cout << "Movie was not added\n";
				}
				if (cmd1 == 2)
					this->showAllMoviesRepo();
				if (cmd1 == 3) {
					int res = this->deleteMovieFromRepo();
					if (res == 1)
						cout << "Movie was deleted\n";
					else
						cout << "Movie was not deleted\n";
				}
				if (cmd1 == 4) {
					int res = this->updateMovieRepo();
					if (res == 1)
						cout << "Movie was updated\n";
					else
						cout << "Movies was not updated\n";
				}
				if (cmd1 == 5)
					this->filterByDuration();
			}
		}
		if (cmd == 2) {
			while (true) {
				UI::printUserMenu();
				int cmd2;
				cout << ">> ";
				cin >> cmd2;
				cin.ignore();
				if (cmd2 == 0)
					break;
				if (cmd2 == 1)
					this->listMoviesGenre();
				if (cmd2 == 2)
					this->deleteMovieFromWatchlist();
				if (cmd2 == 3)
					this->listWatchlist();
				
			}
		}
	}
}

bool UI::isValid(const string &title, const string &genre, const string &year, const string &likes, const string &trailer, const int duration) {
	int i;
	const char *y = year.c_str();
	for(i = 0; i < strlen(y); i++) {
		if(y[i] < '0' || y[i] > '9')
			return false;
	}
	if(atoi(y) < 1900 || atoi(y) > 2018)
		return false;
	const char *l = likes.c_str();
	for(i = 0; i < strlen(y); i++)
		if(y[i] < '0' || y[i] > '9')
			return false;
	const char *t = trailer.c_str();
	if(strstr(t, "http://www.imdb.com/title") == NULL)
		return false;
	return true;
}