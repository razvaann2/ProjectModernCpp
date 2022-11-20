#include "User.h"

QString User::GetUserName()
{
	return userName;
}

User::User()
{
	userName = "";
}

User::~User()
{
	MoviesWatched.clear();
	WishList.clear();
}

User::User(User& x)
{
	userName = x.GetUserName();
}

void User::SetUserName(QString userName)
{
	this->userName = userName;
}
void User::SetMoviesWatched(std::vector<int> MoviesWatched)
{
	this->MoviesWatched = MoviesWatched;
}
void User::SetWishList(std::vector<int>WishList)
{
	this->WishList = Wishlist;
}

