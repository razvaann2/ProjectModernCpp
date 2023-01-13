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
		movieToRead.SetDirector(substr);
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
		movieToRead.SetCast(substr);
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
		movieToRead.SetCountry(substr);
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
		movieToRead.SetDateAdded(substr);
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
		movieToRead.SetReleaseYear(substr);
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
		movieToRead.SetRating(substr);
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
		movieToRead.SetDuration(substr);
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
		movieToRead.SetListedIn(substr);
		poz1 = poz2;
		if (s[poz1 + 1] == '"')
		{
			poz1 = s.find('"', poz1 + 1);
			poz2 = s.find('"', poz1 + 1);
			substr = s.substr(poz1 + 1, s.length() - poz1 - 2);
		}
		else
		{
			substr = s.substr(poz1 + 1, s.length() - poz1 - 1);
		}
		poz1 = substr.find('"');
		while (poz1 != std::string::npos)
		{
			if (poz1 < substr.length() - 1 || substr[poz1 + 1] == '"')
			{
				substr.erase(poz1 + 1, 1);
			}
			poz1 = substr.find('"', poz1 + 1);
		}
		movieToRead.SetDescription(substr);
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
bool DataBase::Checkdatabase(std::string name)
{
	User user;
	bool ok = true;
	DataBase bazaDeDate;
	if (m_db.get_all<User>(sql::where(sql::like(&User::GetUserName, name))).size() == 1)
		user = m_db.get_all<User>(sql::where(sql::like(&User::GetUserName, name))).front();
	if (user.GetUserName() == "")
		ok = false;
	return ok;
}

void DataBase::AddReview(int MovieID, int UserID, int Status)
{
	Review aux(MovieID,UserID,Status);
	m_db.sync_schema();
	m_db.insert(aux);
	m_db.sync_schema();
}


