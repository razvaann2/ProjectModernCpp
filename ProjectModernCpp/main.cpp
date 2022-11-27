#include "ProjectModernCpp.h"
#include <QtWidgets/QApplication>
#include "DataBase.h"
#include "Movie.h"

int main(int argc, char *argv[])
{
  
	DataBase bazaDeDate;
    //Movies are addes on time only
    //bazaDeDate.AddMovies();
    QApplication a(argc, argv);
    ProjectModernCpp w;
    w.show();
	return a.exec();
}
