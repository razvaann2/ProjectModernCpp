#pragma once
#include "InitializeStorage.h"

class DataBase
{
public:
	Storage store = initStorage("storage.sqlite");
};