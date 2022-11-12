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
