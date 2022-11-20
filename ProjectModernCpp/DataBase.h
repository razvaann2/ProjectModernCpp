#pragma once
#include "InitializeStorage.h"

class DataBase
{
public:
	Storage database = initStorage("storage.sqlite");
};