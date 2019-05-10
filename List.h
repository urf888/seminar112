#pragma once
#include"Movie.h"
#include"DynamicVector.h"

class Watchlist
{
private:
	DynamicVector<Movie> movies;
	int current;
public:
	/// The default constructor of a watch list
	//input: 
	//	 -
	//output: 
	//	a watchlist will be created
	Watchlist();

	/// Adds a movie to the watch list
	//input: 
	//	 givenMovie - a reference to a constant movie
	//output: 
	//	 -
	void addToWatchlist(const Movie& givenMovie);

	/// Returns the current movie from the watch list
	//input: 
	//	 -
	//output: 
	//	 a movie
	Movie getCurrentMovie();

	/// Plays the current movie from the watchlist
	//input: 
	//	 -
	//output: 
	//	 the current movie from the watch list will be played in the browser
	void playCurrent();

	/// Plays the next movie from the watch list
	//input: 
	//	 -
	//output: 
	//	the next movie will be played in the browser
	void next();

	/// Determines if the watch list is empty
	//input: 
	//	 -
	//output: 
	//	true/false
	bool isEmpty() { return this->movies.getSize() == 0; }

	/// Deletes a movie from the watch list
	//input: 
	//	 givenTitle - a reference to a constant string - the title of the movie to be deleted
	//output: 
	//	 true - if the delete was successful
	//	 false - otherwise
	bool delFromWL(const string& givenTitle);

	/// Tests the functions from Watchlist
	//input: 
	//	 -
	//output: 
	//	 if a function doesn't function properly, an exception will be thrown
	void watchlistTests();
};