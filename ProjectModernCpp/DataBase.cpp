#include "DataBase.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

void DataBase::initializeUser(User a)
{
	m_db.sync_schema();
	m_db.insert(a);
	m_db.sync_schema();
}

void DataBase::initializeMovie(Movie a)
{
	m_db.sync_schema();
	m_db.insert(a);
	m_db.sync_schema();
}

void DataBase::AddMovies()
{
	std::ifstream InFile;
	std::vector<Movie> Movies;
	int verifier = 0;
	std::string Line;
	InFile.open("../Files/archive/netflix_titles.csv");
	std::getline(InFile, Line);
	while (std::getline(InFile, Line))
	{
		Movie movieToRead;
		std::stringstream ss(Line);
		std::string s = ss.str();
		std::string substr, substr2;
		std::getline(ss, substr, ',');
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
		substr2 = "";
		std::getline(ss, substr2, ',');
		substr = substr + ", ";
		substr = substr + substr2;
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
		std::getline(ss, substr);
		movieToRead.SetDescription(substr);
		substr = "";
		initializeMovie(movieToRead);
	}
}

void DataBase::AddWatchedList(int MovieID, int UserID)
{
	WatchedList aux;
	aux.SetMovieID(MovieID);
	aux.SetUserID(UserID);
	m_db.sync_schema();
	m_db.insert(aux);
	m_db.sync_schema();
}

void DataBase::AddWishList(int MovieID, int UserID)
{
	WishList aux;
	aux.SetMovieID(MovieID);
	aux.SetUserID(UserID);
	m_db.sync_schema();
	m_db.insert(aux);
	m_db.sync_schema();
}
