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

void Movie::SetDateAdded(QString DateAdded)
{
	this->DateAdded = DateAdded;
}

QString Movie::GetDateAdded()
{
	return DateAdded;
}

void Movie::SetReleaseYear(QString ReleaseYear)
{
	this->ReleaseYear = ReleaseYear;
}

QString Movie::GetReleaseYear()
{
	return ReleaseYear;
}

void Movie::SetRating(QString Rating)
{
	this->Rating = Rating;
}

QString Movie::GetRating()
{
	return Rating;
}

void Movie::SetDuration(QString Duration)
{
	this->Duration = Duration;
}

QString Movie::GetDuration()
{
	return Duration;
}

void Movie::SetListedIn(QString ListedIn)
{
	this->ListedIn = ListedIn;

}

QString Movie::GetListedIn()
{
	return ListedIn;
}

void Movie::SetDescription(QString Description)
{
	this->Description = Description;
}

QString Movie::GetDescription()
{
	return Description;
}
