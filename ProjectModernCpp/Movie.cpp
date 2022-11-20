#include "Movie.h"

Movie::Movie()
{
	this->MovieId = "";
	this->Type = "";
	this->Title = "";
	this->Director = "";
	this->Cast = "";
	this->Country = "";
	this->DateAdded = "";
	this->ReleaseYear = "";
	this->Rating = "";
	this->Duration = "";
	this->ListedIn = "";
	this->Description = "";
}

Movie::~Movie()
{

}

Movie::Movie(const Movie& x)
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

void Movie::SetMovieId(std::string MovieId)
{
	this->MovieId = MovieId;
}

std::string Movie::GetMovieId()
{
	return this->MovieId;
}

void Movie::SetType(std::string Type)
{
	this->Type = Type;
}

std::string Movie::GetType()
{
	return this->Type;
}

void Movie::SetTitle(std::string Title)
{
	this->Title = Title;
}

std::string Movie::GetTitle()
{
	return this->Title;
}

void Movie::SetDirector(std::string Director)
{
	this->Director = Director;
}

std::string Movie::GetDirector()
{
	return this->Director;
}

void Movie::SetCast(std::string Cast)
{
	this->Cast = Cast;
}

std::string Movie::GetCast()
{
	return this->Cast;
}

void Movie::SetCountry(std::string Country)
{
	this->Country = Country;
}

std::string Movie::GetCountry()
{
	return this->Country;
}

void Movie::SetDateAdded(std::string DateAdded)
{
	this->DateAdded = DateAdded;
}

std::string Movie::GetDateAdded()
{
	return this->DateAdded;
}

void Movie::SetReleaseYear(std::string ReleaseYear)
{
	this->ReleaseYear = ReleaseYear;
}

std::string Movie::GetReleaseYear()
{
	return this->ReleaseYear;
}

void Movie::SetRating(std::string Rating)
{
	this->Rating = Rating;
}

std::string Movie::GetRating()
{
	return this->Rating;
}

void Movie::SetDuration(std::string Duration)
{
	this->Duration = Duration;
}

std::string Movie::GetDuration()
{
	return this->Duration;
}

void Movie::SetListedIn(std::string ListedIn)
{
	this->ListedIn = ListedIn;

}

std::string Movie::GetListedIn()
{
	return this->ListedIn;
}

void Movie::SetDescription(std::string Description)
{
	this->Description = Description;
}

std::string Movie::GetDescription()
{
	return this->Description;
}
