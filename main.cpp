#include "UI.h"
#include "List.h"
#include<crtdbg.h>
#include<iostream>
#include<string>
using namespace std;

void testEverything()
{
	Movie testMovie;
	DynamicVector<int> testDV;
	Repository testRepo;
	Watchlist testW;
	Controller testCtrl(testRepo, testW);
	testMovie.movieTests();
	testDV.dynamicVectorTests();
	testRepo.repositoryTests();
	testW.watchlistTests();
	testCtrl.controllerTests();
}

int main()
{
	system("color 06");
	{
		testEverything();

		Watchlist w;
		Repository repo;
		Controller ctrl(repo, w);
		ctrl.addMovieCtrl("Terminator", "fiction", "1984", 0, "https://www.imdb.com/title/tt0088247/videoplayer/vi93502489?ref_=tt_ov_vi");
		ctrl.addMovieCtrl("Rambo", "action", "2008", 0, "https://www.imdb.com/title/tt0462499/videoplayer/vi4217092633?ref_=tt_ov_vi");
		ctrl.addMovieCtrl("The Shawshank Redemption", "drama", "1994", 0, "https://www.imdb.com/title/tt0111161/videoplayer/vi3877612057?ref_=tt_ov_vi");
		ctrl.addMovieCtrl("Titanic", "drama", "1997", 0, "https://www.imdb.com/title/tt0120338/videoplayer/vi907189785?ref_=tt_ov_vi");
		ctrl.addMovieCtrl("GodFather", "crime", "1972", 0, "https://www.imdb.com/title/tt0068646/videoplayer/vi1348706585?ref_=tt_ov_vi");
		ctrl.addMovieCtrl("Godfather 2", "crime", "1974", 0, "https://www.imdb.com/title/tt0071562/videoplayer/vi696162841?ref_=tt_ov_vi");
		ctrl.addMovieCtrl("Black Knight", "action", "2008", 0, "https://www.imdb.com/title/tt0468569/videoplayer/vi324468761?ref_=tt_ov_vi");
		ctrl.addMovieCtrl("Schindler List", "historic", "1993", 0, "https://www.imdb.com/title/tt0108052/videoplayer/vi1158527769?ref_=tt_ov_vi");
		ctrl.addMovieCtrl("LOTR :Return of the king", "fiction", "2003", 0, "https://www.imdb.com/title/tt0167260/videoplayer/vi2073101337?ref_=tt_ov_vi");
		ctrl.addMovieCtrl("Pulp Fiction", "crime", "1994", 0, "https://www.imdb.com/title/tt0110912/videoplayer/vi2620371481?ref_=tt_ov_vi");
		UI ui(ctrl);
		ui.run();
	}

	_CrtDumpMemoryLeaks();
	//system("pause");
	return 0;
}

