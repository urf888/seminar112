#pragma once
#pragma once
#include <iostream>
#include <assert.h>
#include "DynamicVector.h"
using namespace std;

class Movie
{
private:
	string title;
	string genre;
	string year;
	int nrOfLikes;
	string link;
public:

	/// The default constructor of a movie
	//input: 
	//	 -
	//output: 
	//	 an object of type movie will be created
	Movie();

	/// The constructor of a movie with parameters
	//input: 
	//	 givenTitle - a reference to a constant string
	//	 givenGenre - a reference to a constant string
	//	 givenYear  - a reference to a constant string
	//	 givenNrOfLikes - a reference to a constant integer
	//	 givenLink - a reference to a constant string
	//output: 
	//	 an object of type movie will be created
	Movie(const string& givenTitle, const string& givenGenre, const string& givenYear, const int& givenNrOfLikes, const string& givenLink);

	/// Returns the title of a movie
	//input: 
	//	 -
	//output: 
	//	 a string
	string getTitle() const { return title; }

	/// Returns the genre of a movie
	//input: 
	//	 -
	//output:
	//	 a string
	string getGenre() const { return genre; }

	/// Returns the genre of the movie
	//input:
	//   -
	//   a string
	string getYear()const { return year; }
	/// Returns the year of release of a movie
	//input:
	//   -
	// a string
	int getNrOfLikes() const { return nrOfLikes; }

	/// Returns the number of likes of a movie
	//input: 
	//	 -
	//output: 
	//	 an integer
	string getLink() const { return link; }

	/// Sets a new value for the title of the movie
	//input: 
	//	 givenTitle - a reference to a constant string
	//output: 
	//	 -
	void setTitle(const string& givenTitle) { this->title = givenTitle; }

	/// Sets a new value for the genre of the movie
	//input: 
	//	 givenGenre - a reference to a constant string
	//output: 
	//	 -
	void setGenre(const string& givenGenre) { this->genre = givenGenre; }

	
	void setYear(const string& givenYear) { this->year = givenYear; }
	/// Sets a new value for the number of likes of the movie
	//input: 
	//	 givenNrOfLikes - a reference to a constant integer
	//output: 
	//	 -
	void setNrOfLikes(const int& givenNrOfLikes) { this->nrOfLikes = givenNrOfLikes; }

	/// Sets a new value for the link of the movie
	//input: 
	//	 givenLink - a reference to a constant string
	//output: 
	//	 -
	void setLink(const string& givenString) { this->link = givenString; }

	/// Plays a movie  in the browser
	//input: 
	//	 -
	//output: 
	//	the link of the movie will be accessed in Google Chrome
	void play();

	string getDetails();
	/// Returns the dynamic vector obtained by appending the movie that calls this function to the dynamic 
	/// vector taken as an argument
	//input: 
	//	 givenDV - a reference to a constant dynamic vector of movies, in which we want to append the movie
	//output: 
	//	 a dynamic vector of movies
	DynamicVector<Movie> operator+(const DynamicVector<Movie>& givenDV);    // Activity 5

	/// Tests the functions from movie
	//input: 
	//	 -
	//output: 
	//	 if a function doesn't function properly, an exception will be thrown
	void movieTests();
};
