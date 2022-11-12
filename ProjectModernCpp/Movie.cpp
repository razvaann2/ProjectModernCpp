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
