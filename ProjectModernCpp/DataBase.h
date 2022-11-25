#pragma once
#include <sqlite_orm/sqlite_orm.h>
#include "User.h"
namespace sql = sqlite_orm;

const std::string dbFile = "DataBase.sqlite";
inline auto createStorage(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table("User",
			sql::make_column("UserID", &User::GetID, &User::SetID, sql::autoincrement(), sql::primary_key()),
			sql::make_column("UserName", &User::GetUserName, &User::SetUserName))

		);
}
using Storage = decltype(createStorage(" "));
//std::string Type, Title, Director, Cast, Country, DateAdded, ReleaseYear, Rating, Duration, ListedIn, Description;
class DataBase
{
public:
	Storage m_db = createStorage(dbFile);
	void initializeUser(User a);
};
