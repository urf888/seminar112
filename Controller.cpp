#include "Controller.h"
#include <string>

bool Controller::addMovieCtrl(const string& givenTitle, const string& givenGenre, const string& givenYear, const int givenLikes, const string& givenLink)
{
	if (this->repo.existsMovie(givenTitle))
	{
		return false;
	}

	Movie movie(givenTitle, givenGenre, givenYear, givenLikes, givenLink);
	this->repo.add(movie);
	return true;

}

bool Controller::delMovieCtrl(const string& givenTitle)
{
	return this->repo.del(givenTitle);
}


int Controller::updateMovie(const string& givenTitle, const string& givenNewTitle, const string& givenNewGenre, const string& givenNewYear, const int givenNewLikes, const string& givenNewLink)
{
	if (this->getRepo().existsMovie(givenTitle) == false)
	{
		return -1;
		// There is no tutorial with givenTitle
	}

	if (givenTitle != givenNewTitle)
	{
		if (this->repo.existsMovie(givenNewTitle))
		{
			return 0;
			// There already is a tutorial with givenNewTitle
		}
	}


	Movie givenNewMovie(givenNewTitle, givenNewGenre,givenNewYear, givenNewLikes, givenNewLink);
	return this->repo.update(givenTitle, givenNewMovie);

	return 1;
	//Update successful
}

DynamicVector<Movie> Controller::getMoviesByGenre(const string& givenGenre)
{
	DynamicVector<Movie> dv = this->getRepo().getMovies();
	if (givenGenre == "")
		return dv;
	for (int i = 0; i < dv.getSize(); i++)
	{
		if (dv.getElems()[i].getGenre() != givenGenre)
		{
			dv.delMovie(dv.getElems()[i].getTitle());
			i--;
		}
	}
	return dv;
}

void Controller::addMovieToWatchlist(const Movie& givenMovie)
{
	this->wl.addToWatchlist(givenMovie);
}

void Controller::currentMovieWatchList()
{
	this->wl.playCurrent();
}

void Controller::nextMovieWatchlist()
{
	this->wl.next();
}

Movie& Controller::getMovieByTitle(const string& givenTitle)
{
	return this->repo.getMovieByTitle(givenTitle);
}

void Controller::increaseLikes(const string& givenTitle)
{
	int likes = this->repo.getMovieByTitle(givenTitle).getNrOfLikes();
	this->repo.getMovieByTitle(givenTitle).setNrOfLikes(likes + 1);
}

Movie Controller::getCurrentFromWatchlist()
{
	return this->wl.getCurrentMovie();
}



//-============================================Tests============================================-\\

Controller initControllerForTests()
{
	Watchlist w;
	Repository repo;
	Controller ctrl(repo, w);
	ctrl.addMovieCtrl("Title1", "Genre1", "Year1", 1, "Link1");
	ctrl.addMovieCtrl("Title2", "Genre2", "Year2", 2, "Link2");
	ctrl.addMovieCtrl("Title3", "Genre3", "Year3", 3, "Link3");
	return ctrl;
}

void test_getRepo()
{
	Controller ctrl = initControllerForTests();
	Repository repo = ctrl.getRepo();
	assert(repo.getMovies().getElems()[0].getTitle() == "Title1");
}

void test_addMovieCtrl()
{
	Controller ctrl = initControllerForTests();
	ctrl.addMovieCtrl("TitleNew", "GenreNew", "YearNew", 444, "LinkNew");
	assert(ctrl.getRepo().getMovies().getElems()[3].getTitle() == "TitleNew");
}

void test_delMovieCtrl()
{
	Controller ctrl = initControllerForTests();
	ctrl.delMovieCtrl("Title3");
	assert(!ctrl.getRepo().existsMovie("Title3"));
}

void test_updateMovie()
{
	Controller ctrl = initControllerForTests();
	ctrl.updateMovie("Title1", "TitleNew", "GenreNew", "Yearr", 444, "LinkNew");
	assert(ctrl.getRepo().getMovies().getElems()[0].getTitle() == "TitleNew");
}

void test_getMoviesByGenre()
{
	Watchlist w;
	Repository repo;
	Controller ctrl(repo, w);
	ctrl.addMovieCtrl("Title1", "Genre11", "Year1", 1, "Link1");
	ctrl.addMovieCtrl("Title2", "Genre22", "Year2", 2, "Link2");
	ctrl.addMovieCtrl("Title3", "Genre11", "Year3", 3, "Link3");
	assert(ctrl.getMoviesByGenre("Genre11").getSize() == 2);
	assert(ctrl.getMoviesByGenre("Genre11").getElems()[0].getTitle() == "Title1");
	assert(ctrl.getMoviesByGenre("Genre11").getElems()[1].getTitle() == "Title3");
}

void test_addMovieToWatchlist()
{
	Controller ctrl = initControllerForTests();
	assert(ctrl.isWLEmpty() == 1);
	ctrl.addMovieToWatchlist(Movie("Title", "Genre", "Year", 1, "Link"));
	assert(ctrl.isWLEmpty() == 0);
}

void test_ctrlgetMovieByTitle()
{
	Controller ctrl = initControllerForTests();
	assert(ctrl.getMovieByTitle("Title2").getTitle() == "Title2");
}

void test_increaseLikes()
{
	Controller ctrl = initControllerForTests();
	ctrl.increaseLikes("Title3");
	assert(ctrl.getMovieByTitle("Title3").getNrOfLikes() == 4);
}

void test_getCurrentFromWatchlist()
{
	Controller ctrl = initControllerForTests();
	ctrl.addMovieToWatchlist(Movie("T1", "P1", "Y1", 1, "L1"));
	ctrl.addMovieToWatchlist(Movie("T2", "P2", "Y2", 2, "L2"));
	ctrl.addMovieToWatchlist(Movie("T3", "P3", "Y3", 3, "L3"));
	assert(ctrl.getCurrentFromWatchlist().getTitle() == "T1");
	ctrl.deleteFromWL("T1");
	assert(ctrl.getCurrentFromWatchlist().getTitle() == "T2");
	ctrl.deleteFromWL("T2");
	assert(ctrl.getCurrentFromWatchlist().getTitle() == "T3");
}

void test_deleteFromWL()
{
	Controller ctrl = initControllerForTests();
	ctrl.addMovieToWatchlist(Movie("T1", "P1", "Y1", 1, "L1"));
	ctrl.addMovieToWatchlist(Movie("T2", "P2", "Y2", 2, "L2"));
	ctrl.addMovieToWatchlist(Movie("T3", "P3", "Y3", 3, "L3"));
	assert(ctrl.getCurrentFromWatchlist().getTitle() == "T1");
	assert(ctrl.deleteFromWL("T1") == 1);
	assert(ctrl.getCurrentFromWatchlist().getTitle() == "T2");
	assert(ctrl.deleteFromWL("T2") == 1);
	assert(ctrl.getCurrentFromWatchlist().getTitle() == "T3");
	assert(ctrl.deleteFromWL("T1") == 0);
}

void test_isWLEmpty()
{
	Controller ctrl = initControllerForTests();
	assert(ctrl.isWLEmpty());
	ctrl.addMovieToWatchlist(Movie("T1", "P1", "Y1", 1, "L1"));
	assert(ctrl.isWLEmpty() == 0);
}

void Controller::controllerTests()
{
	test_getRepo();
	test_addMovieCtrl();
	test_delMovieCtrl();
	test_updateMovie();
	test_getMoviesByGenre();
	test_addMovieToWatchlist();
	test_ctrlgetMovieByTitle();
	test_increaseLikes();
	test_getCurrentFromWatchlist();
	test_deleteFromWL();
	test_isWLEmpty();
}

