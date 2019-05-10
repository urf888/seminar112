#include "List.h"

Watchlist::Watchlist()
{
	this->current = 0;
}

void Watchlist::addToWatchlist(const Movie& givenMovie)
{
	this->movies.add(givenMovie);
}

Movie Watchlist::getCurrentMovie()
{
	if (this->current == this->movies.getSize())
		this->current = 0;
	return this->movies.getElems()[this->current];
}

void Watchlist::playCurrent()
{
	if (this->movies.getSize() == 0)
		return;
	this->getCurrentMovie().play();
}

void Watchlist::next()
{
	if (this->movies.getSize() == 0)
		return;
	this->current++;
	getCurrentMovie().play();
}

bool Watchlist::delFromWL(const string & givenTitle)
{
	if (!this->movies.delMovie(givenTitle))
		return false;
	if (this->movies.getSize() == 0)
		return false;
	return true;
}

//-============================================Tests============================================-\\

Watchlist initWLForTests()
{
	Watchlist wl;
	wl.addToWatchlist(Movie("Title1", "Genre1", "Year1", 1, "Link1"));
	wl.addToWatchlist(Movie("Title2", "Genre2", "Year2", 1, "Link2"));
	wl.addToWatchlist(Movie("Title3", "Genre3", "Year3", 1, "Link3"));
	return wl;
}

void test_addToWatchlist()
{
	Watchlist wl;
	wl.addToWatchlist(Movie("Title1", "Genre1", "Year1", 1, "Link1"));
	assert(wl.getCurrentMovie().getTitle() == "Title1");
	assert(wl.isEmpty() == 0);
}
void test_getCurrentMovie()
{
	Watchlist wl = initWLForTests();
	assert(wl.getCurrentMovie().getTitle() == "Title1");
}
void test_isEmpty()
{
	Watchlist wl;
	assert(wl.isEmpty() == 1);
	wl.addToWatchlist(Movie("Title1", "Genre1", "Year1", 1, "Link1"));
	assert(wl.isEmpty() == 0);
}
void test_delFromWL()
{
	Watchlist wl = initWLForTests();
	assert(wl.getCurrentMovie().getTitle() == "Title1");
	wl.delFromWL("Title1");
	assert(wl.getCurrentMovie().getTitle() == "Title2");
	wl.delFromWL("Title2");
	assert(wl.getCurrentMovie().getTitle() == "Title3");
	wl.delFromWL("Title3");
	assert(wl.isEmpty() == 1);
}

void Watchlist::watchlistTests()
{
	test_addToWatchlist();
	test_getCurrentMovie();
	test_isEmpty();
	test_delFromWL();
}


