#include "DataBase.h"

void DataBase::initializeUser(User a)
{
	m_db.sync_schema();
	m_db.insert(a);
	m_db.sync_schema();
}

void DataBase::initializeMovie(Movie a)
{
	m_db.sync_schema();
	m_db.insert(a);
	m_db.sync_schema();
}