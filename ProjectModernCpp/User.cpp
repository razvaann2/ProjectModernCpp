#include "User.h"

User::User()
{
	this->userName = "";
}

User::~User()
{
	this->MoviesWatched.clear();
	this->WishList.clear();
}

User::User(const User& x)
{
	this->userName = x.userName;
}

int User::GetID()const
{
	return this->ID;
}

User::User(std::string username)
{
	this->userName = username;
}

void User::SetID(int id)
{
	this->ID = id;
}

void User::SetUserName(std::string userName)
{
	this->userName = userName;
}

std::string User::GetUserName()const
{
	return this->userName;
}
void User::SetWishList(std::string WishList)
{
	this->WishList = WishList;
}
std::string User::GetWishList()const
{
	return this->WishList;
}
void User::AddInMoviesWatched(std::string MovieID)
{
	this->MoviesWatched += ",";
	this->MoviesWatched += MovieID;
}
void User::AddInWishList(std::string MovieID)
{
	this->WishList += ",";
	this->WishList += MovieID;
}
std::string User::GetMoviesWatched()const
{
	return this->MoviesWatched;
}
void User::SetMoviesWatched(std::string MoviesWatched)
{
	this->MoviesWatched = MoviesWatched;
}