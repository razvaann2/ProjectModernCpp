#include "HomePage.h"
#include"ProjectModernCpp.h"
#include<QString>
#include "DataBase.h"
HomePage::HomePage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowState(Qt::WindowMaximized);
	ui.ProfileTitle->setVisible(false);
	ui.MovieTitle->setVisible(false);
}

void HomePage::SetUser(User user)
{
	this->loggedUser = user;
	QString qstringUser = QString::fromStdString(this->loggedUser.GetUserName());
	//ui.HomePage->setText(qstringUser);
	ui.HomePage->setText(qstringUser);
	ui.HomePage->setFont(QFont("Times New Roman", 16, QFont::Bold, false));
}

HomePage::~HomePage()
{}

void HomePage::on_User_clicked()
{
	ui.MovieTitle->setVisible(false);
	ui.ProfileTitle->setVisible(true);
}

void HomePage::on_User_released()
{
}

void HomePage::on_Search_clicked()
{
	QString movie_name = ui.Film_to_search->text();
	ui.MovieTitle->setText(movie_name);
	ui.MovieTitle->setFont(QFont("Segoe UI", 24, QFont::Bold, false));
	ui.ProfileTitle->setVisible(false);
	ui.MovieTitle->setVisible(true);
}
void HomePage::on_Search_released()
{

}
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
void HomePage::on_Film_to_search_released()
{
}
void HomePage::on_Film_to_search_clicked()
{
	DataBase bazaDeDate;
	QString name = ui.Film_to_search->text();
	std::string aux = name.toStdString();
}

