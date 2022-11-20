#pragma once
#include <string>
#include <vector>
class User
{
private:
	int ID;
	std::string userName;
	std::vector<int>MoviesWatched;
	std::vector<int>WishList;
public:
	User();
	~User();
	User(std::string username);
	User(const User& x);
	void SetID(int id);
	int GetID()const;
	void SetUserName(std::string userName);
	std::string GetUserName()const;
	void SetWishList(std::vector<int> WishList);
	std::vector<int>GetWishList();
	std::vector<int>GetMoviesWatched();
	void SetMoviesWatched(std::vector<int> MoviesWatched);
};