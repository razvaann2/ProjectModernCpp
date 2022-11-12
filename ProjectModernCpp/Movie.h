#pragma once
#include <QString>

class Movie
{
private:
	QString MovieId, Type, Title, Director, Cast, Country, DateAdded, ReleaseYear, Rating, Duration, ListedIn, Description;
public:
	Movie();
	~Movie();
	void GetMovieId();
	void GetType();
	void GetTitle();
	void GetDirector();
	void GetCast();
	void GetCountry();
	void GetDateAdded();
	void GetReleaseYear();
	void GetRating();
	void GetDuration();
	void GetListedIn();
	void GetDescription();
};