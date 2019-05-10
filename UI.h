#pragma once
#include "Controller.h"
class UI
{
private:
	Controller ctrl;
public:
	UI(const Controller& givenCtrl) : ctrl(givenCtrl) {}
	void run();
private:

	/// Prints the main menu of the application
	//input: 
	//	 -
	//output:
	//	 the main menu will be displayed in the console
	static void printMainMenu();

	/// Prints the administrator menu
	//input: 
	//	 -
	//output: 
	//	 the administrator menu will be displayed in the console
	static void printAdminMenu();

	/// Prints the user menu
	//input: 
	//	 -
	//output: 
	//	 the user menu will be displayed in the console
	static void printUserMenu();

	/// Interacts with the user aquiring the necessary data in order to add a new movie to the database,
	/// then adds it
	//input (from console): 
	//	 givenTitle - a string
	//	 givenGenre - a string
	//	 givenYear - a string
	//	 givenLikes - an integer
	//	 givenLink - a string
	//output (in console): 
	//	 messages for the user
	void addMovieUI();

	/// Interacts with the user aquiring the necessary data in order to delete a movie from the database,
	/// then deletes it
	//input (from console): 
	//	  givenTitle - a string
	//output (in console): 
	//	  messages for the user
	void delMovieUI();

	/// Interacts with the user aquiring the necessary data in order to update a movie from the database,
	/// then updates it
	//input (from console): 
	//	 givenTitle - a string
	//	 givenNewTitle - a string
	//	 givenNewGenre - a string
	//	 givenNewYear - a string
	//	 givenNewLikes - an integer
	//	 givenNewLink - a string
	//output (in console): 
	//	 messages for the user
	void updateMovieUI();

	/// Displays all movies from the database
	//input (from console): 
	//	 -
	//output (in console):
	//	messages for the user
	void displayAllMoviesUI();

	/// Interacts with the user aquiring the necessary data in order to cycle through the movies
	/// having a given presenter and whether to add them to the watch list or not
	//input (from console): 
	//	 givenPresenter - a string
	//	 menu options - integers
	//output (in console and browser):
	//	 messages for the user and the movies will be played in the browser
	void displayMoviesByGenreUI();

	/// Interacts with the user determining if the likes of a movie should be increased
	//input (from console): 
	//	 menu options - integers
	//output (in console): 
	//	 messages for the user
	void increaseLikesUI(const string& givenTitle);

	/// Plays the current movie from the watch list
	//input: 
	//	 -
	//output: 
	//	prints messages of what is currently happening
	//	true - if the watch list is empty and therefore no movie can be played
	//  false - otherwise
	bool playCurrentUI();

	/// Plays the next movie from the watch list
	//input: 
	//	 -
	//output: 
	//	prints messages of what is currently happening
	//	true - if the watch list is empty and therefore no movie can be played
	//  false - otherwise
	bool playNextUI();

	/// Interacts with the user aquiring the necessary data in order to navigate through the 
	/// movies from the watch list, play them, and whether to delete them and increase 
	/// their likes
	//input (from console): 
	//	 menu options - integers
	//output (in console): 
	//	 messages for the user
	void playWatchlistUI();
};