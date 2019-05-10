#include "Repository.h"

bool Repository::existsMovie(const string& givenTitle)
{
	Movie* movies = this->movies.getElems();
	for (int i = 0; i < this->movies.getSize(); i++)
	{
		if (movies[i].getTitle() == givenTitle)
			return true;
	}
	return false;
}

void Repository::add(const Movie & givenTut)
{
	//this->tutorials.add(givenTut);
	this->movies = this->movies + givenTut;		//Assignment 5
}

bool Repository::del(const string & givenTitle)
{
	return this->movies.delMovie(givenTitle);
}

bool Repository::update(const string & givenTitle, Movie givenNewMovie)
{
	return this->movies.update(givenTitle, givenNewMovie);
}

Movie& Repository::getMovieByTitle(const string & givenTitle)
{
	for (int i = 0; i < this->movies.getSize(); i++)
	{
		if (this->movies.getElems()[i].getTitle() == givenTitle)
		{
			return this->movies.getElems()[i];
		}
	}
}


//-============================================Tests============================================-\\

Repository initRepoForTests()
{
	Repository repo;
	repo.add(Movie("Title1", "Genre1", "Year1", 1, "Link1"));
	repo.add(Movie("Title2", "Genre2", "Year2", 2, "Link2"));
	repo.add(Movie("Title3", "Genre3", "Year3", 3, "Link3"));
	return repo;
}

void test_existsMovie()
{
	Repository repo = initRepoForTests();
	assert(repo.existsMovie("Title3") == 1);
}

void test_addRepo()
{
	Repository repo = initRepoForTests();
	repo.add(Movie("Title4", "Genre4", "Year4", 4, "Link4"));
	assert(repo.getMovies().getElems()[3].getTitle() == "Title4");
}

void test_del()
{
	Repository repo = initRepoForTests();
	assert(repo.getMovies().getSize() == 3);
	repo.del("Title2");
	assert(repo.getMovies().getSize() == 2);
}

void test_update()
{
	Repository repo = initRepoForTests();
	repo.update("Title1", Movie("NewTitle", "NewGenre", "YEARR", 111, "NewLink"));
	assert(repo.getMovies().getElems()[0].getTitle() == "NewTitle");
}

void test_getMovies()
{
	Repository repo = initRepoForTests();
	DynamicVector<Movie> dv = repo.getMovies();
	assert(dv.getSize() == 3);
	assert(dv.getElems()[0].getTitle() == "Title1");
	assert(dv.getElems()[1].getTitle() == "Title2");
	assert(dv.getElems()[2].getTitle() == "Title3");
}

void test_getMovieByTitle()
{
	Repository repo = initRepoForTests();
	Movie m("Title2", "Presenter2", "Year2", 2, "Link2");
	assert(repo.getMovieByTitle("Title2").getTitle() == "Title2");
	assert(repo.getMovieByTitle("Title2").getGenre() == "Genre2");
	assert(repo.getMovieByTitle("Title2").getYear() == "Year2");
	assert(repo.getMovieByTitle("Title2").getNrOfLikes() == 2);
	assert(repo.getMovieByTitle("Title2").getLink() == "Link2");
}

void Repository::repositoryTests()
{
	test_existsMovie();
	test_add();
	test_del();
	test_update();
	test_getMovies();
	test_getMovieByTitle();
}
