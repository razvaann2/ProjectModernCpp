#include "WishList.h"
int WishList::GetMovieID()const
{
	return this->MovieID;
}
int WishList::GetUserID()const
{
	return this->UserID;
}
void WishList::SetMovieID(int MovieID)
{
	this->MovieID = MovieID;
}
void WishList::SetUserID(int UserID)
{
	this->UserID = UserID;
}
WishList::WishList(int MovieID, int UserID)
{
	this->MovieID = MovieID;
	this->UserID = UserID;
}
WishList::WishList(const WishList& a)
{
	this->MovieID = a.MovieID;
	this->UserID = a.UserID;
}
WishList::~WishList()
{

}