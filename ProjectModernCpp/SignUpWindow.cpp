#include "SignUpWindow.h"
#include "ProjectModernCpp.h"

SignUpWindow::SignUpWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

SignUpWindow::~SignUpWindow()
{

}

void SignUpWindow::on_SignUpButton_released()
{

}

void SignUpWindow::on_SignUpButton_clicked()
{	
	DataBase bazaDeDate;
	QString name = ui.lineEdit->text();
	this->close();
	std::string aux = name.toStdString();
	User x(aux);
	bazaDeDate.initializeUser(aux);

}
