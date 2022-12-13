#include "User.h"

/*User User::operator=(User&& aux)
{
	User user;
	user.SetID(aux.GetID());
	user.SetUserName(aux.GetUserName());
	aux.SetID('-1');
	aux.SetUserName("");
	return user;
}*/
/*User User::operator=(const User& aux)
{
	User user;
	user.SetID(aux.GetID());
	user.SetUserName(aux.GetUserName());
	return user;
}*/
User::User()
{
	this->userName = "";
	this->ID = -1;
}

User::~User()
{
	
}

/*User::User(User&& aux)
{
	this->ID = aux.GetID();
	this->userName = aux.GetUserName();
	aux.SetID(NULL);
	aux.SetUserName(nullptr);
}*/

User::User(const User& x)
{
	this->userName = x.GetUserName();
	this->ID = x.GetID();

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
