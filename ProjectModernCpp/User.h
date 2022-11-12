#pragma once
#include <QString>
#include <vector>
class User
{
private:
	QString userName;
	std::vector<int>MoviesWatched;
	std::vector<int>WishList;
public:
	User();
	~User();
	User(User& x);
	void SetUserName(QString userName);
	QString GetUserName();
	
};