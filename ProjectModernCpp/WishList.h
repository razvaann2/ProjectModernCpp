#pragma once
class WishList
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
	WishList(int MovieID = 0, int UserID = 0);
	WishList(const WishList& a);
	WishList operator=(const WishList& wishlist);
	~WishList();
};
