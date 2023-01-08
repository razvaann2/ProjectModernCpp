#pragma once
class WatchedList
{
private:
	int ID, MovieID, UserID;
public:
	int GetID()const;
	int GetMovieID()const;
	int GetUserID()const;
	void SetID(int ID);
	void SetUserID(int UserID);
	void SetMovieID(int MovieID);
	WatchedList(int MovieID = 0, int UserID = 0);
	WatchedList(const WatchedList& a);
	WatchedList operator=(const WatchedList& watchedlist);
	~WatchedList();
};