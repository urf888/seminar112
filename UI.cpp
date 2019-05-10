#include "UI.h"
#include<iostream>
#include<string>
using namespace std;
void UI::run()
{
	int option{ 1 };
	while (option)
	{
		printMainMenu();
		cout << "\nYour choice:";
		cin >> option;
		switch (option)
		{
		case 1:
		{
			int adminOption{ 1 };
			while (adminOption)
			{
				printAdminMenu();
				cout << "\nYour choice:";
				cin >> adminOption;
				switch (adminOption)
				{
				case 1:
				{
					addMovieUI();
					break;
				}
				case 2:
				{
					delMovieUI();
					break;
				}
				case 3:
				{
					getchar();
					updateMovieUI();
					break;
				}
				case 4:
				{
					displayAllMoviesUI();
					break;
				}
				case 0:
				{
					break;
				}
				default:
				{
					cout << "\nThere is no such option. Try again!\n";
					break;
				}
				}
			}
			break;
		}
		case 2:
		{
			int userOption{ 1 };
			while (userOption)
			{
				printUserMenu();
				cout << "\nYour choice:";
				cin >> userOption;
				switch (userOption)
				{
				case 1:
				{
					this->displayMoviesByGenreUI();
					break;
				}
				case 2:
				{
					this->playWatchlistUI();
					break;
				}
				case 0:
				{
					break;
				}
				default:
				{
					cout << "\nThere is no such option. Try again!\n";
					break;
				}
				}
			}
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "\nThere is no such option. Try again!\n";
			break;
		}
		}
	}
}


void UI::printMainMenu()
{
	cout << "\n>>>>>>>> Main Menu <<<<<<<<";
	cout << "\n1 - Administrator mode\n2 - User mode\n0 - Exit\n";
}

void UI::printAdminMenu()
{
	cout << "\n======== Admin Mode ========";
	cout << "\n1 - Add a movie\n";
	cout << "2 - Delete a movie\n";
	cout << "3 - Update a movie\n";
	cout << "4 - Display all movies\n";
	cout << "0 - Back\n";
}

void UI::printUserMenu()
{
	cout << "\n---------- User Mode ----------";
	cout << "\n1 - See the movies in the database having a given genre";
	cout << "\n2 - See the watch list";
	cout << "\n0 - Back\n";
}



int readLikes(string message)
{
	int likes = -1;
	while (likes < 0)
	{
		cout << message;
		cin >> likes;
		if (likes < 0)
		{
			cout << "\nThe number of likes can't be negative! Try again.\n";
		}
	}
	return likes;
}

void UI::addMovieUI()
{
	string givenTitle, givenGenre, givenLink,givenYear;
	int givenLikes;
	cout << "\nEnter the title of the movie:";
	getchar();
	getline(cin, givenTitle);
	cout << "\nEnter the name of the genre:";
	getline(cin, givenGenre);
	cout << "\nEnter the year:";
	getline(cin, givenYear);
	givenLikes = readLikes("\nEnter the number of likes:");
	cout << "\nEnter the link:";
	getchar();
	getline(cin, givenLink);

	if (this->ctrl.addMovieCtrl(givenTitle, givenGenre, givenYear, givenLikes, givenLink) == false)
	{
		cout << "\nThere already exists a movie with that title! Try again.\n";
		addMovieUI();
	}
	else
	{
		cout << "\nMovie added successfully.\n";
	}
}

void UI::delMovieUI()
{
	string givenTitle;

	if (this->ctrl.getRepo().getMovies().getSize() == 0)
	{
		cout << "\nThere are no movies to delete!\n";
		return;
	}

	cout << "\nEnter the title of the movie you want to delete:";
	getchar();
	getline(cin, givenTitle);

	while (this->ctrl.delMovieCtrl(givenTitle) == false)
	{
		cout << "\nThat movie doesn't exist! Enter another:";
		getline(cin, givenTitle);
	}
	cout << "\nMovie deleted successfully.\n";
}

void UI::updateMovieUI()
{
	string givenTitle, givenNewTitle, givenNewGenre,givenNewYear, givenNewLink;
	int givenNewLikes;
	cout << "\nEnter the title of the movie you want to update:";
	getline(cin, givenTitle);
	cout << "\nEnter the title for the new movie:";
	getline(cin, givenNewTitle);
	cout << "\nEnter the name of the genre:";
	getline(cin, givenNewGenre);
	cout << "\nEnter the year:";
	getline(cin, givenNewYear);
	givenNewLikes = readLikes("\nEnter the number of likes:");
	cout << "\nEnter the link:";
	getchar();
	getline(cin, givenNewLink);

	switch (this->ctrl.updateMovie(givenTitle, givenNewTitle, givenNewGenre, givenNewYear, givenNewLikes, givenNewLink))
	{
	case -1:
	{
		cout << "\nUpdate failed! There is no movie with title " << givenTitle << "! Try again.\n";
		this->updateMovieUI();
		break;
	}
	case 0:
	{
		cout << "\nUpdate failed! There already is a movie with title " << givenNewTitle << "! Try again.\n";
		this->updateMovieUI();
		break;
	}
	case 1:
	{
		cout << "\nUpdate successful.\n";
		break;
	}
	}
}

void UI::displayAllMoviesUI()
{
	DynamicVector<Movie> v = this->ctrl.getRepo().getMovies();
	Movie* movies = v.getElems();
	if (movies == NULL)
	{
		return;
	}
	if (v.getSize() == 0)
	{
		cout << "\nThere are no movies to display.\n";
	}
	else
	{
		for (int i = 0; i < v.getSize(); i++)
		{
			cout << movies[i].getDetails();
			cout << "\n";
		}
	}
}

void UI::displayMoviesByGenreUI()
{
	string givenGenre;
	cout << "\nEnter the genre:";
	getchar();
	getline(cin, givenGenre);
	DynamicVector<Movie> v = this->ctrl.getMoviesByGenre(givenGenre);
	Movie* movies = v.getElems();
	if (movies == NULL)
	{
		return;
	}
	if (v.getSize() == 0)
	{
		cout << "\nThere are no movies to display.\n";
	}
	else
	{
		bool go = true;
		int option = 0;
		for (int i = 0; (i < v.getSize() && go == true); i++)
		{
			cout << movies[i].getDetails();
			movies[i].play();
			bool read = true;
			while (read)
			{
				cout << "\n1 - Next";
				cout << "\n2 - Add movie to watch list";
				cout << "\n0 - Stop";
				cout << "\nYour choice:";
				cin >> option;
				switch (option)
				{
				case 1:
				{
					read = false;
					break;
				}
				case 2:
				{
					read = true;
					int anotherOption = 0;
					this->ctrl.addMovieToWatchlist(movies[i]);
					cout << "\nThe movie was added to the watch list.\n";
					while (read)
					{
						cout << "\n1 - Next";
						cout << "\n0 - Stop";
						cout << "\nYour choice:";
						cin >> anotherOption;
						switch (anotherOption)
						{
						case 1:
						{
							read = false;
							break;
						}
						case 0:
						{
							return;
							break;
						}
						default:
						{
							cout << "\nInvalid option.\n";
							break;
						}
						}
					}
					read = false;
					break;
				}
				case 0:
				{
					return;
					break;
				}
				default:
				{
					cout << "\nInvalid option.\n";
					break;
				}
				}
			}

			if (i == v.getSize() - 1)
				i = -1;
		}
	}
}

void UI::increaseLikesUI(const string & givenTitle)
{
	int option = 1;
	bool go = true;
	while (go)
	{
		cout << "\nWould you like to give this movie a like?\n";
		cout << "1 - Yes\n";
		cout << "2 - No\n";
		cout << "\nYour choice:";
		cin >> option;
		switch (option)
		{
		case 1:
		{
			this->ctrl.increaseLikes(givenTitle);
			cout << "\nThe like was registered.\n";
			go = false;
			break;
		}
		case 2:
		{
			go = false;
			break;
		}
		default:
		{
			cout << "\nInvalid option!\n";
			break;
		}
		}
	}
}

bool UI::playCurrentUI()
{
	if (this->ctrl.isWLEmpty())
	{
		cout << "\nThe watch list is empty.\n";
		return false;
	}
	this->ctrl.currentMovieWatchList();
	cout << "\nPlaying movie: " << this->ctrl.getCurrentFromWatchlist().getTitle() << "\n";
	return true;
}

bool UI::playNextUI()
{
	if (this->ctrl.isWLEmpty())
	{
		cout << "\nThe watch list is empty.\n";
		return false;
	}
	this->ctrl.nextMovieWatchlist();
	cout << "\nPlaying movie: " << this->ctrl.getCurrentFromWatchlist().getTitle() << "\n";
	return true;
}


void UI::playWatchlistUI()
{
	if (!playCurrentUI())
	{
		return;
	}
	while (1)
	{
		int option = 0;
		cout << "1 - Next\n";
		cout << "2 - Delete from the watch list\n";
		cout << "0 - Stop\n";
		cout << "\nYour choice:";
		cin >> option;
		switch (option)
		{
		case 1:
		{
			if (!playNextUI())
			{
				return;
			}
			break;
		}
		case 2:
		{
			increaseLikesUI(this->ctrl.getCurrentFromWatchlist().getTitle());
			this->ctrl.deleteFromWL(this->ctrl.getCurrentFromWatchlist().getTitle());
			cout << "\nThe movie was removed from the watch list.\n";
			if (!playCurrentUI())
			{
				return;
			}
			break;
		}
		case 0:
		{
			return;
		}
		default:
		{
			cout << "\nOption doesn't exist!\n\n";
			break;
		}
		}

	}
}
