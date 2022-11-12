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

QString Movie::GetMovieId()
{
	return MovieId;
}

QString Movie::GetType()
{
	return Type;
}

QString Movie::GetTitle()
{
	return Title;
}

QString Movie::GetDirector()
{
	return Director;
}

QString Movie::GetCast()
{
	return Cast;
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
