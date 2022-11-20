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