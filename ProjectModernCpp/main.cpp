#include "ProjectModernCpp.h"
#include <QtWidgets/QApplication>
#include "DataBase.h"
#include "Movie.h"
#include "QFile"
int main(int argc, char *argv[])
{
  
	DataBase bazaDeDate;
    //Movies are addes on time only
    //bazaDeDate.AddMovies();
    QApplication a(argc, argv);
    QFile styleSheelFile("./DeepBox.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readALL());
    a.setStyleSheet(styleSheet);
    ProjectModernCpp w;
    w.show();
	return a.exec();
}
