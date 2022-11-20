#pragma once
#include <sqlite_orm/sqlite_orm.h>
#include "User.h"

inline auto initStorage(const std::string& path)
{
    using namespace sqlite_orm;
    return make_storage(path,
        make_table("User",
            make_column("ID", &User::GetID, &User::SetID, primary_key()),
            make_column("UserName", &User::GetUserName, &User::SetUserName)));
}

using Storage = decltype(initStorage(""));