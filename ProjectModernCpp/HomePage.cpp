#include "HomePage.h"
#include"ProjectModernCpp.h"
#include<QString>
HomePage::HomePage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	User x;
}

void HomePage::SetUser(User user)
{
	this->loggedUser = user;
	QString qstringUser = QString::fromStdString(this->loggedUser.GetUserName());
	ui.HomePage->setText(qstringUser);
}

HomePage::~HomePage()
{}

void HomePage::on_LogOut_released()
{
}
void HomePage::on_LogOut_clicked()
{   
	ProjectModernCpp* a = new ProjectModernCpp;
	a->show();
	this->close();
	
}
