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
		std::string substr;
		int poz1 = s.find(',');
		substr = s.substr(0, poz1);
		int poz2 = s.find(',', poz1 + 1);
		substr = s.substr(poz1 + 1, poz2 - poz1 - 1);
		movieToRead.SetType(substr);
		poz1 = poz2;
		if (s[poz1 + 1] == '"')
		{
			poz1 = s.find('"', poz1 + 1);
			poz2 = s.find('"', poz1 + 1);
			substr = s.substr(poz1 + 1, poz2 - poz1 - 1);
			poz2 = s.find(',', poz2 + 1);
		}
		else
		{
			poz2 = s.find(',', poz1 + 1);
			substr = s.substr(poz1 + 1, poz2 - poz1 - 1);
		}
		movieToRead.SetTitle(substr);
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
