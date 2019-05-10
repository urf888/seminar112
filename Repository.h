#pragma once

#ifndef	REPOSITORY
#define REPOSITORY
#include "DynamicVector.h"
#include "Movie.h"

class Repository
{
private:
	DynamicVector<Movie> movies;
public:

	///  The default constructor of a repository
	//input: 
	//	 -
	//output: 
	//	 an object of type Repository will be created
	Repository() {}

	/// Verifies if there exists a movie with a given title in the repository
	//input: 
	//	 givenTitle - a reference to a constant string - the title of the movie that needs to be searched
	//output: 
	//	 true or false
	bool existsMovie(const string& givenTitle);

	/// Adds a movie to the repository
	//input: 
	//	 givenTut - a reference to a constant Movie
	//output: 
	//	 -
	void add(const Movie& givenMovie);

	/// Deletes a movie from the repository
	//input: 
	//	 givenTitle - a reference to a constant string - the title of the movie that needs to be deleted
	//output: 
	//	 true - if the movie was successfully deleted
	//	 false - otherwise
	bool del(const string& givenTitle);

	/// Updates a movie from the repository
	//input: 
	//	 givenTitle - a reference to a constant string - the title of the movie that needs to be updated
	//output: 
	//	 true - if the update was successful
	//	 false - otherwise
	bool update(const string& givenTitle, Movie givenNewMovie);

	/// Returns the dynamic vector of the movies from the repository
	//input: 
	//	 -
	//output: 
	//	 an object of type DynamicVector
	DynamicVector<Movie> getMovies() { return this->movies; }

	/// Returns the movie from the repository that has a given title
	//input: 
	//	 givenTitle - a reference to a constant string
	//output: 
	//	 a reference to a movie
	Movie& getMovieByTitle(const string& givenTitle);

	/// Tests the functions from repository
	//input: 
	//	 -
	//output: 
	//	 if a function doesn't function properly, an exception will be thrown
	void repositoryTests();
};
#endif REPOSITORY