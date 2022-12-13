#pragma once
#include <string>

class Movie
{
private:
	int MovieId;
	std::string  Type, Title, Director, Cast, Country, DateAdded, ReleaseYear, Rating, Duration, ListedIn, Description;
public:
	Movie();
	~Movie();
	Movie(Movie&& movtobedeleted);
	Movie operator=(Movie const& object);
	Movie(const Movie& x);
	void SetMovieId(int MovieId);
	int GetMovieId()const;
	void SetType(std::string Type);
	std::string GetType()const;
	void SetTitle(std::string Title);
	std::string GetTitle()const;
	void SetDirector(std::string Director);
	std::string GetDirector()const;
	void SetCast(std::string Cast);
	std::string GetCast()const;
	void SetCountry(std::string Country);
	std::string GetCountry()const;
	void SetDateAdded(std::string DateAdded);
	std::string GetDateAdded()const;
	void SetReleaseYear(std::string ReleaseYear);
	std::string GetReleaseYear()const;
	void SetRating(std::string Rating);
	std::string GetRating()const;
	void SetDuration(std::string Duration);
	std::string GetDuration()const;
	void SetListedIn(std::string ListedIn);
	std::string GetListedIn()const;
	void SetDescription(std::string Description);
	std::string GetDescription()const;
};