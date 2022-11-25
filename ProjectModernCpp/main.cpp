#include "ProjectModernCpp.h"
#include <QtWidgets/QApplication>
#include "DataBase.h"
#include "Movie.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char *argv[])
{
	std::ifstream InFile;
	
	std::vector<Movie> Movies;
	int verifier = 0;
	std::string Line;
	InFile.open("../Files/archive/netflix_titles.csv"); 
	if (InFile.is_open()) {
		verifier = 1;
	}
	else {
		verifier = 2;
	}
	
	std::getline(InFile, Line);
	
	while (std::getline(InFile, Line))
	{
		Movie movieToRead;
		std::stringstream ss(Line);
		std::string substr;
		std::getline(ss, substr, ',');
		movieToRead.SetMovieId(1);
		substr = "";
		std::getline(ss, substr, ',');
		movieToRead.SetType(substr);
		substr = "";
		std::getline(ss, substr, ',');
		movieToRead.SetTitle(substr);
		substr = "";
		std::getline(ss, substr, ',');
		movieToRead.SetDirector(substr);
		substr = "";
		std::getline(ss, substr, ',');
		movieToRead.SetCast(substr);
		substr = "";
		std::getline(ss, substr, ',');
		movieToRead.SetCountry(substr);
		substr = "";
		std::getline(ss, substr, ',');
		movieToRead.SetDateAdded(substr);
		substr = "";
		std::getline(ss, substr, ',');
		movieToRead.SetReleaseYear(substr);
		substr = "";
		std::getline(ss, substr, ',');
		movieToRead.SetRating(substr);
		substr = "";
		std::getline(ss, substr, ',');
		movieToRead.SetDuration(substr);
		substr = "";
		std::getline(ss, substr, ',');
		movieToRead.SetListedIn(substr);
		substr = "";
		std::getline(ss, substr, ',');
		movieToRead.SetDescription(substr);
		substr = "";
		Movies.push_back(movieToRead);
	}
	DataBase bazaDeDate;
    QApplication a(argc, argv);
    ProjectModernCpp w;
    w.show();
	return a.exec();
}
