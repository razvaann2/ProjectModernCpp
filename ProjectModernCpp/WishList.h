#pragma once
class WishList
{
private:
	int MovieID, UserID;
public:
	int GetMovieID()const;
	int GetUserID()const;
	void SetUserID(int UserID);
	void SetMovieID(int MovieID);
	WishList(int MovieID = 0, int UserID = 0);
	WishList(const WishList& a);
	WishList operator=(const WishList& wishlist);
	~WishList();
};
