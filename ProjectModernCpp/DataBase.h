#pragma once
#include <sqlite_orm/sqlite_orm.h>
#include "User.h"
#include "Movie.h"
#include "WatchedList.h"
#include "WishList.h"
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
			sql::make_column("UserID", &WishList::GetUserID, &WishList::SetUserID),
			sql::make_column("MovieID", &WishList::GetMovieID, &WishList::SetMovieID)),
		sql::make_table("WatchedList",
				sql::make_column("UserID", &WatchedList::GetUserID, &WatchedList::SetUserID),
				sql::make_column("MovieID", &WatchedList::GetMovieID, &WatchedList::SetMovieID))
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
};
