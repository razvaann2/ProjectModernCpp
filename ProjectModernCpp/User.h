#pragma once
#include <string>

class User
{
private:
	int ID;
	std::string userName;
	
public:
	User();
	~User();
	User(User&& aux);
	User operator=(User&& aux);
	User operator=(const User& aux);
	User(std::string username);
	User(const User& x);
	void SetID(int id);
	int GetID()const;
	void SetUserName(std::string userName); 
	std::string GetUserName()const;
};