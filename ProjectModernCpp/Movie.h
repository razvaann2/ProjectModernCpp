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
	void SetMovieId(QString MovieId);
	QString GetMovieId();
	void SetType(QString Type);
	QString GetType();
	void SetTitle(QString Title);
	QString GetTitle();
	void SetDirector(QString Director);
	QString GetDirector();
	void SetCast(QString Cast);
	QString GetCast();
	void SetCountry(QString Country);
	QString GetCountry();
	void SetDateAdded(QString DateAdded);
	QString GetDateAdded();
	void SetReleaseYear(QString ReleaseYear);
	QString GetReleaseYear();
	void SetRating(QString Rating);
	QString GetRating();
	void SetDuration(QString Duration);
	QString GetDuration();
	void SetListedIn(QString ListedIn);
	QString GetListedIn();
	void SetDescription(QString Description);
	QString GetDescription();
};