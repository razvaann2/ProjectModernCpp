#include "WatchedList.h"
int WatchedList::GetMovieID()const
{
	return this->MovieID;
}
int WatchedList::GetUserID()const
{
	return this->UserID;
}
void WatchedList::SetMovieID(int MovieID)
{
	this->MovieID = MovieID;
}
void WatchedList::SetUserID(int UserID)
{
	this->UserID = UserID;
}
WatchedList::WatchedList(int MovieID , int UserID )
{
	this->MovieID = MovieID;
	this->UserID = UserID;
}
WatchedList::WatchedList(const WatchedList& a)
{
	this->MovieID = a.MovieID;
	this->UserID = a.UserID;
}
WatchedList::~WatchedList() 
{

}