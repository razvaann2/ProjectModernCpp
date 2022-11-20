#pragma once
#include <string>

class Movie
{
private:
	std::string MovieId, Type, Title, Director, Cast, Country, DateAdded, ReleaseYear, Rating, Duration, ListedIn, Description;
public:
	Movie();
	~Movie();
	Movie(const Movie& x);
	void SetMovieId(std::string MovieId);
	std::string GetMovieId();
	void SetType(std::string Type);
	std::string GetType();
	void SetTitle(std::string Title);
	std::string GetTitle();
	void SetDirector(std::string Director);
	std::string GetDirector();
	void SetCast(std::string Cast);
	std::string GetCast();
	void SetCountry(std::string Country);
	std::string GetCountry();
	void SetDateAdded(std::string DateAdded);
	std::string GetDateAdded();
	void SetReleaseYear(std::string ReleaseYear);
	std::string GetReleaseYear();
	void SetRating(std::string Rating);
	std::string GetRating();
	void SetDuration(std::string Duration);
	std::string GetDuration();
	void SetListedIn(std::string ListedIn);
	std::string GetListedIn();
	void SetDescription(std::string Description);
	std::string GetDescription();
};