#include "ProjectModernCpp.h"
#include "User.h"
#include <iostream>
#include "HomePage.h"

ProjectModernCpp::ProjectModernCpp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
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
	User x(aux);
	if (bazaDeDate.m_db.get_all<User>(sql::where(sql::like(&User::GetUserName, aux))).size() == 1)
	{
		this->close();
		HomePage* window = new HomePage();
		window->show();
	}
	else
	{
		box.warning(this, "Warning", "Contul nu exista");
	}
}

void ProjectModernCpp::on_RegisterButton_clicked()
{
    SignUp = new SignUpWindow();
    SignUp->show();
}
