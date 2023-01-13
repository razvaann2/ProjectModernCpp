#pragma once
#include <sqlite_orm/sqlite_orm.h>
#include "User.h"
#include "Movie.h"
#include "WatchedList.h"
#include "WishList.h"
#include "Review.h"
namespace sql = sqlite_orm;

const std::string dbFile = "DataBase.sqlite";
inline auto createStorage(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table("User",
			sql::make_column("UserID", &User::GetID, &User::SetID, sql::autoincrement(), sql::primary_key()),
			sql::make_column("UserName", &User::GetUserName, &User::SetUserName)),
		sql::make_table("Movies",
			sql::make_column("MovieID", &Movie::GetMovieId, &Movie::SetMovieId, sql::autoincrement(), sql::primary_key()),
			sql::make_column("Type", &Movie::GetType, &Movie::SetType),
			sql::make_column("Title", &Movie::GetTitle, &Movie::SetTitle),
			sql::make_column("Director", &Movie::GetDirector, &Movie::SetDirector),
			sql::make_column("Cast", &Movie::GetCast, &Movie::SetCast),
			sql::make_column("Country", &Movie::GetCountry, &Movie::SetCountry),
			sql::make_column("DateAdded", &Movie::GetDateAdded, &Movie::SetDateAdded),
			sql::make_column("ReleaseYear", &Movie::GetReleaseYear, &Movie::SetReleaseYear),
			sql::make_column("Rating", &Movie::GetRating, &Movie::SetRating),
			sql::make_column("Duration", &Movie::GetDuration, &Movie::SetDuration),
			sql::make_column("ListenIn", &Movie::GetListedIn, &Movie::SetListedIn),
			sql::make_column("Description", &Movie::GetDescription, &Movie::SetDescription)),
		sql::make_table("WishList",
			sql::make_column("ID", &WishList::GetID, &WishList::SetID, sql::autoincrement(), sql::primary_key()),
			sql::make_column("UserID", &WishList::GetUserID, &WishList::SetUserID),
			sql::make_column("MovieID", &WishList::GetMovieID, &WishList::SetMovieID),
			sql::foreign_key(&WishList::SetUserID).references(&User::SetID),
			sql::foreign_key(&WishList::SetMovieID).references(&Movie::SetMovieId)),
		sql::make_table("WatchedList",
			sql::make_column("ID", &WatchedList::GetID, &WatchedList::SetID, sql::autoincrement(), sql::primary_key()),
			sql::make_column("UserID", &WatchedList::GetUserID, &WatchedList::SetUserID),
			sql::make_column("MovieID", &WatchedList::GetMovieID, &WatchedList::SetMovieID),
			sql::foreign_key(&WatchedList::SetUserID).references(&User::SetID),
			sql::foreign_key(&WatchedList::SetMovieID).references(&Movie::SetMovieId)),
		sql::make_table("Review",
			sql::make_column("ID", &Review::GetID, &Review::SetID, sql::autoincrement(), sql::primary_key()),
			sql::make_column("UserID", &Review::GetUserID, &Review::SetUserID),
			sql::make_column("MovieID", &Review::GetMovieID, &Review::SetMovieID),
			sql::make_column("Status",&Review::GetStatus,&Review::SetStatus),
			sql::foreign_key(&Review::SetUserID).references(&User::SetID),
			sql::foreign_key(&Review::SetMovieID).references(&Movie::SetMovieId))
	);
}
using Storage = decltype(createStorage(" "));
//std::string Type, Title, Director, Cast, Country, DateAdded, ReleaseYear, Rating, Duration, ListedIn, Description;
class DataBase
{
public:
	Storage m_db = createStorage(dbFile);
	void initializeUser(User a);
	void initializeMovie(Movie a);
	void AddMovies();
	void AddWatchedList(int MovieID,int UserID);
	void AddWishList(int MovieID ,int UserID );
	bool Checkdatabase(std::string name);
	void AddReview(int MovieID, int UserID, int Status);
	
};
