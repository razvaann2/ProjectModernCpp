#include "ProjectModernCpp.h"
#include <QtWidgets/QApplication>
#include "DataBase.h"
#include "Movie.h"

int main(int argc, char *argv[])
{
	DataBase bazaDeDate;
    //Movies are addes one time only
    //bazaDeDate.AddMovies();
    Movie x = bazaDeDate.m_db.get<Movie>(1);
    QApplication a(argc, argv);
    ProjectModernCpp w;
    w.show();
	return a.exec();
}
