#include "ProjectModernCpp.h"
#include <QtWidgets/QApplication>
#include"Movie.h"
#include<string>
#include<fstream>
#include<iostream>

int main(int argc, char *argv[])
{
	std::ifstream InFile;
	Movie movieToRead;
	std::vector<Movie> Movies;
	int b = 0;
	InFile.open("../Files/archive/netflix_titles.csv"); 
	if (InFile.is_open()) {
		b = 1;
	}
	else {
		b = 2;
	}
    QApplication a(argc, argv);
    ProjectModernCpp w;
    w.show();
    
	
	return a.exec();
}
