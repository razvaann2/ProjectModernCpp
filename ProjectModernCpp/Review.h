#pragma once
class Review
{
private:
	int ID, UserID, MovieID, Status;
public:
	Review();
	Review(int MovieID, int UserID, int Status);
	Review(const Review& aux);
	~Review();
	int GetID()const;
	int GetUserID()const;
	int GetMovieID()const;
	int GetStatus()const;
	void SetID(int ID);
	void SetUserID(int UserID);
	void SetMovieID(int MovieID);
	void SetStatus(int Status);

};