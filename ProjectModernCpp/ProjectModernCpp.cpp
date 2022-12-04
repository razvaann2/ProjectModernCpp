#include "ProjectModernCpp.h"
#include "User.h"
#include <iostream>
#include "HomePage.h"

ProjectModernCpp::ProjectModernCpp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	 this->setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowState(Qt::WindowMaximized);
	this->setStyleSheet(
		"background-image:url(../Files/archive/LoginImage.jpg); background-position: center;");
}

ProjectModernCpp::~ProjectModernCpp()
{}

void ProjectModernCpp::on_LoginButton_released()
{

}

void ProjectModernCpp::on_RegisterButton_released()
{

}

void ProjectModernCpp::on_LoginButton_clicked()
{   
	DataBase bazaDeDate;
	QString name = ui.lineEdit->text();
	std::string aux = name.toStdString();
	User user(aux);
	if (bazaDeDate.m_db.get_all<User>(sql::where(sql::like(&User::GetUserName, aux))).size() == 1)
	{
		this->close();
		HomePage* window = new HomePage();
		window->SetUser(user);
		window->show();
	}
	else
	{
		QMessageBox::StandardButton reply;
		reply = box.warning(this, "Warning", "The account doesn't exist! Do you want to register? ", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes) {
			SignUp = new SignUpWindow();
			SignUp->show();
		}
		else
		{
			this->close();
	    }
	}
}

void ProjectModernCpp::on_RegisterButton_clicked()
{
    SignUp = new SignUpWindow();
    SignUp->show();
}
