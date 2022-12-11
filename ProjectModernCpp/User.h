#pragma once
#include <string>

class User
{
private:
	int ID;
	std::string userName;
	User operator=(User aux);
public:
	User();
	~User();

	User(std::string username);
	User(const User& x);
	void SetID(int id);
	int GetID()const;
	void SetUserName(std::string userName);
	std::string GetUserName()const;
};