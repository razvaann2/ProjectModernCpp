#include "ProjectModernCpp.h"
#include <QtWidgets/QApplication>
#include "DataBase.h"
#include "Movie.h"
int main(int argc, char *argv[])
{
  
	DataBase bazaDeDate;
    bazaDeDate.m_db.sync_schema();
    QApplication a(argc, argv);
    bazaDeDate.AddMovies();
    ProjectModernCpp w;
    w.show();
	return a.exec();
}
