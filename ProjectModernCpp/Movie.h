#pragma once
#include <QString>

class Movie
{
private:
	QString MovieId, Type, Title, Director, Cast, Country, DateAdded, ReleaseYear, Rating, Duration, ListedIn, Description;
public:
	Movie();
	~Movie();
	Movie(Movie& x);
	QString GetMovieId();
	QString GetType();
	QString GetTitle();
	QString GetDirector();
	QString GetCast();
	QString GetCountry();
	QString GetDateAdded();
	QString GetReleaseYear();
	QString GetRating();
	QString GetDuration();
	QString GetListedIn();
	QString GetDescription();
};