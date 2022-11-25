#include "User.h"

User::User()
{
	this->userName = "";
	this->ID = -1;
}

User::~User()
{
	
}

User::User(const User& x)
{
	this->userName = x.userName;
	this->ID = x.ID;
}

int User::GetID()const
{
	return this->ID;
}

User::User(std::string username)
{
	this->userName = username;
	this->ID = -1;
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
