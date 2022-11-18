#include "ProjectModernCpp.h"
#include <QtWidgets/QApplication>
#include"Movie.h"
#include<string>
#include<fstream>
#include<iostream>
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
		QString qsubstr = QString::fromStdString(substr);
		movieToRead.SetMovieId(qsubstr);
		substr = "";
		qsubstr = "";
		std::getline(ss, substr, ',');
		qsubstr = QString::fromStdString(substr);
		movieToRead.SetType(qsubstr);
		substr = "";
		qsubstr = "";
		std::getline(ss, substr, ',');
		qsubstr = QString::fromStdString(substr);
		movieToRead.SetTitle(qsubstr);
		substr = "";
		qsubstr = "";
		std::getline(ss, substr, ',');
		qsubstr = QString::fromStdString(substr);
		movieToRead.SetDirector(qsubstr);
		substr = "";
		qsubstr = "";
		std::getline(ss, substr, ',');
		qsubstr = QString::fromStdString(substr);
		movieToRead.SetCast(qsubstr);
		substr = "";
		qsubstr = "";
		std::getline(ss, substr, ',');
		qsubstr = QString::fromStdString(substr);
		movieToRead.SetCountry(qsubstr);
		substr = "";
		qsubstr = "";
		std::getline(ss, substr, ',');
		qsubstr = QString::fromStdString(substr);
		movieToRead.SetDateAdded(qsubstr);
		substr = "";
		qsubstr = "";
		std::getline(ss, substr, ',');
		qsubstr = QString::fromStdString(substr);
		movieToRead.SetReleaseYear(qsubstr);
		qsubstr = "";
		substr = "";
		std::getline(ss, substr, ',');
		qsubstr = QString::fromStdString(substr);
		movieToRead.SetRating(qsubstr);
		qsubstr = "";
		substr = "";
		std::getline(ss, substr, ',');
		qsubstr = QString::fromStdString(substr);
		movieToRead.SetDuration(qsubstr);
		substr = "";
		qsubstr = "";
		std::getline(ss, substr, ',');
		qsubstr = QString::fromStdString(substr);
		movieToRead.SetListedIn(qsubstr);
		substr = "";
		qsubstr = "";
		std::getline(ss, substr, ',');
		qsubstr = QString::fromStdString(substr);
		movieToRead.SetDescription(qsubstr);
		substr = "";
		qsubstr = "";
		Movies.push_back(movieToRead);
	}
    QApplication a(argc, argv);
    ProjectModernCpp w;
    w.show();
    
	
	return a.exec();
}
