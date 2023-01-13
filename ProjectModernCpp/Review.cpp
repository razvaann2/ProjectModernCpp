#include "Review.h"
Review::Review()
{

}
Review::Review(int MovieID,int UserID,int Status)
{
	this->MovieID = MovieID;
	this->UserID = UserID;
	this->Status = Status;
}

Review::Review(const Review& aux)
{
	this->ID = aux.ID;
	this->MovieID = aux.MovieID;
	this->UserID = aux.UserID;
	this->Status = aux.Status;
}

Review::~Review()
{
}

int Review::GetID() const
{
	return ID;
}

int Review::GetUserID() const
{
	return UserID;
}

int Review::GetMovieID() const
{
	return MovieID;
}

int Review::GetStatus() const
{
	return Status;
}

void Review::SetID(int ID)
{
	this->ID = ID;
}

void Review::SetUserID(int UserID)
{
	this->UserID = UserID;
}

void Review::SetMovieID(int MovieID)
{
	this->MovieID = MovieID;
}

void Review::SetStatus(int Status)
{
	this->Status = Status;
}
