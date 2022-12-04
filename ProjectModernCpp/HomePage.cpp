#include "HomePage.h"
#include"ProjectModernCpp.h"
#include<QString>
#include "DataBase.h"
HomePage::HomePage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowState(Qt::WindowMaximized);

}

void HomePage::SetUser(User user)
{
	this->loggedUser = user;
	QString qstringUser = QString::fromStdString(this->loggedUser.GetUserName());
	//ui.HomePage->setText(qstringUser);
	ui.HomePage->setText(qstringUser);
	ui.HomePage->setFont(QFont("Segoe UI", 16, QFont::Bold, true));
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
void HomePage::on_Comedy_released()
{
}
void HomePage::on_Comedy_clicked()
{
	Movie* Comedy = new Movie;
	Comedy->GetType();
}
void HomePage::on_SF_released()
{
}
void HomePage::on_SF_clicked()
{
	Movie* SF = new Movie;
	SF->GetType();
}
