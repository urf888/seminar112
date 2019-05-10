#pragma once
#ifndef CONTROLLER
#define CONTROLLER

#include "Repository.h"
#include "List.h"
class Controller
{
private:
	Repository repo;
	Watchlist wl;
public:

	/// The constructor of a controller with a parameter
	//input: 
	//	 givenRepo - a reference to a constant repository
	//	 givenW - a reference to a constant watchlist
	//output: 
	//	 creates an object of type Controller
	Controller(const Repository& givenRepo, const Watchlist& givenW) : repo(givenRepo), wl(givenW) {}

	/// Returns the repository held in this controller
	//input: 
	//	 -
	//output: 
	//	 an object of type Repository
	Repository getRepo() const { return this->repo; }

	/// Adds a movie to the database
	//input: 
	//	 givenTitle - a reference to a constant string
	//	 givenGenre - a reference to a constant string
	//	 givenYear  - a reference to a constant string
	//	 givenLikes - a constant int
	//	 givenLink - a reference to a constant string
	//output: 
	//	 true - if the movie was added successfully
	//	 false - otherwise
	bool addMovieCtrl(const string& givenTitle, const string& givenGenre,const string& givenYear, const int givenLikes, const string& givenLink);

	/// Deletes a movie from the database
	//input: 
	//	 givenTitle - a reference to a constant string
	//output: 
	//	 true - if the movie was deleted successfully
	//	 false - otherwise 
	bool delMovieCtrl(const string& givenTitle);

	/// Updates a movie from the database
	//input: 
	//	 givenTitle - a reference to a constant string - the title of the tutorial to be updated
	//	 givenNewTitle - a reference to a constant string
	//	 givenNewGenre - a reference to a constant string
	//	 givenNewYear  - a reference to a constant string
	//	 givenNewLikes - a constant int
	//	 givenNewLink - a reference to a constant string
	//output: 
	//	 -1 - if there is no movie with givenTitle
	//	  0 - if there already is a movie with givenNewTitle
	//    1 - if the update was successful
	int updateMovie(const string& givenTitle, const string& givenNewTitle, const string& givenNewPresenter, const string& givenYear, const int givenNewLikes, const string& givenNewLink);

	/// Returns a dynamic vector containing movies of a given genre
	//input: 
	//	 givenGenre - a reference to a constant string
	//output: 
	//	 a dynamic vector of tutorials
	DynamicVector<Movie> getMoviesByGenre(const string& givenGenre);

	/// Adds a movie to the watch list
	//input: 
	//	 givenMovie - a reference to a constant movie
	//output: 
	// 	 -
	void addMovieToWatchlist(const Movie& givenMovie);

	/// Plays the current movie from the watchlist
	//input: 
	//	 -
	//output: 
	//	 the current movie from the watch list will be played in the browser
	void currentMovieWatchList();

	/// Plays the next movie from the watch list
	//input: 
	//	 
	//output: 
	//	the next movie from the watch list will be played in the browser
	void nextMovieWatchlist();

	/// Returns the movie that has a given title
	//input: 
	//	 givenTitle - a reference to a constant string
	//output: 
	//	 a reference to a movie
	Movie& getMovieByTitle(const string& givenTitle);

	/// Increases the number of likes of a movie by one
	//input: 
	//	 givenTitle - a reference to a constant string
	//output: 
	//	 the likes of the movie having givenTitle will be increased
	void increaseLikes(const string& givenTitle);

	/// Returns the current movie from the watch list
	//input: 
	//	 -
	//output: 
	//	 a movie
	Movie getCurrentFromWatchlist();

	/// Deletes a movie from the watch list
	//input: 
	//	 givenTitle - a reference to a constant string - the title of the movie to be deleted
	//output: 
	//	 true - if the delete was successful
	//	 false - otherwise
	bool deleteFromWL(const string& givenTitle) { return this->wl.delFromWL(givenTitle); }

	/// Determines if the watch list is empty
	//input: 
	//	 -
	//output: 
	//	true/false
	bool isWLEmpty() { return this->wl.isEmpty(); }

	/// Tests the functions from controller
	//input: 
	//	 -
	//output: 
	//	 if a function doesn't function properly, an exception will be thrown
	
	
	/////
	Controller initControllerForTests();
	
	
	

	void test_getRepo()
	{

	};

	void test_addMovieCtrl()
	{

	};

	void test_delMovieCtrl()
	{

	};

	void test_updateMovie()
	{

	};

	void test_getMoviesByGenre()
	{

	};

	void test_addMovieToWatchlist()
	{

	};

	void test_getMovieByTitle()
	{

	};

	void test_increaseLikes()
	{


	};

	void test_getCurrentFromWatchlist()
	{

	};

	void test_deleteFromWL()
	{

	};

	void test_isWLEmpty()
	{

	};

	
	void controllerTests();
};
#endif CONTROLLER