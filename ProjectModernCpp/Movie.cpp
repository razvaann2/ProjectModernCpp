#include "Movie.h"

Movie::Movie()
{
	MovieId = "";
	Type = "";
	Title = "";
	Director = "";
	Cast = "";
	Country = "";
	DateAdded = "";
	ReleaseYear = "";
	Rating = "";
	Duration = "";
	ListedIn = "";
	Description = "";
}

Movie::~Movie()
{

}

Movie::Movie(Movie& x)
{
	this->MovieId = x.MovieId;
	this->Type = x.Type;
	this->Title = x.Title;
	this->Director = x.Director;
	this->Country = x.Country;
	this->DateAdded = x.DateAdded;
	this->ReleaseYear = x.ReleaseYear;
	this->Rating = x.Rating;
	this->Duration = x.Duration;
	this->ListedIn = x.ListedIn;
	this->Description = x.Description;
}

void Movie::SetMovieId(QString MovieId)
{
	this->MovieId = MovieId;
}

QString Movie::GetMovieId()
{
	return MovieId;
}

void Movie::SetType(QString Type)
{
	this->Type = Type;
}

QString Movie::GetType()
{
	return Type;
}

void Movie::SetTitle(QString Title)
{
	this->Title = Title;
}

QString Movie::GetTitle()
{
	return Title;
}

void Movie::SetDirector(QString Director)
{
	this->Director = Director;
}

QString Movie::GetDirector()
{
	return Director;
}

void Movie::SetCast(QString Cast)
{
	this->Cast = Cast;
}

QString Movie::GetCast()
{
	return Cast;
}

void Movie::SetCountry(QString Country)
{
	this->Country = Country;
}

QString Movie::GetCountry()
{
	return Country;
}

QString Movie::GetDateAdded()
{
	return DateAdded;
}

QString Movie::GetReleaseYear()
{
	return ReleaseYear;
}

QString Movie::GetRating()
{
	return Rating;
}

QString Movie::GetDuration()
{
	return Duration;
}

QString Movie::GetListedIn()
{
	return ListedIn;
}

QString Movie::GetDescription()
{
	return Description;
}
