#pragma once
#include <string>

class User
{
private:
	int ID;
	std::string userName;
	std::string MoviesWatched;
	std::string WishList;
public:
	User();
	~User();
	User(std::string username);
	User(const User& x);
	void SetID(int id);
	int GetID()const;
	void SetUserName(std::string userName);
	std::string GetUserName()const;
	void SetWishList(std::string WishList);
	std::string GetWishList()const;
	void SetMoviesWatched(std::string MoviesWatched);
	std::string GetMoviesWatched()const;
	void AddInMoviesWatched(std::string MovieID);
	void AddInWishList(std::string MovieID);
};