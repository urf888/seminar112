#include "Movie.h"
#include <Windows.h>
#include <shellapi.h>
#include <iostream>
#include <string>
using namespace std;

Movie::Movie() : title(""), genre(""), year(""), nrOfLikes(0), link("") {}


Movie::Movie(const string& givenTitle, const string& givenGenre, const string& givenYear, const int& givenNrOfLikes, const string& givenLink)
{
	this->title = givenTitle;
	this->genre = givenGenre;
	this->year = givenYear;
	this->nrOfLikes = givenNrOfLikes;
	this->link = givenLink;
}

void Movie::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
}

string Movie::getDetails()
{
	string details = "";

	details += "\nMovie with title: ";
	details += this->getTitle();
	details += ", presented by: ";
	details += this->getGenre();
	details += ",\nduration: ";
	details += this->getYear();
	details += ", number of likes: ";
	details += to_string(this->getNrOfLikes());
	details += ", link: ";
	details += this->getLink();

	return details;
}

DynamicVector<Movie> Movie::operator+(const DynamicVector<Movie>& givenDV)  //Activity 5
{
	DynamicVector<Movie> d = givenDV;
	Movie m = *this;
	return d + m;
}


//-============================================Tests============================================-\\



Movie initMovieForTests()
{
	Movie m("Title", "Genre","Year", 24, "Link");
	return m;
}

void test_getTitle()
{
	Movie m = initMovieForTests();
	assert(m.getTitle() == "Title");
}

void test_getGenre()
{
	Movie m = initMovieForTests();
	assert(m.getGenre() == "Genre");
}

void test_getYear()
{
	Movie m = initMovieForTests();
	assert(m.getYear() == "Year");
}

void test_getNrOfLikes()
{
	Movie m = initMovieForTests();
	assert(m.getNrOfLikes() == 24);
}

void test_getLink()
{
	Movie m = initMovieForTests();
	assert(m.getLink() == "Link");
}

void test_setTitle()
{
	Movie m = initMovieForTests();
	m.setTitle("n");
	assert(m.getTitle() == "n");
}

void test_setGenre()
{
	Movie m = initMovieForTests();
	m.setGenre("n");
	assert(m.getGenre() == "n");
}
void test_setYear()
{

	Movie m = initMovieForTests();
	m.setGenre("Year");
	assert(m.getGenre() == "Year");

}

void test_setNrOfLikes()
{
	Movie m = initMovieForTests();
	m.setNrOfLikes(4);
	assert(m.getNrOfLikes() == 4);

}

void test_setLink()
{
	Movie m = initMovieForTests();
	m.setLink("n");
	assert(m.getLink() == "n");
}

void test_getDetails()
{
	Movie m = initMovieForTests();
	Movie m1 = initMovieForTests();
	assert(m.getDetails() == m1.getDetails());
	m1.setTitle("SFD");
	assert(!(m.getDetails() == m1.getDetails()));
}

void Movie::movieTests()
{
	test_getTitle();
	test_getGenre();
	test_getYear();
	test_getNrOfLikes();
	test_getLink();
	test_setTitle();
	test_setGenre();
	test_setYear();
	test_setNrOfLikes();
	test_setLink();
	test_getDetails();
}

