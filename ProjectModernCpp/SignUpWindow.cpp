#include "SignUpWindow.h"
#include "ProjectModernCpp.h"

SignUpWindow::SignUpWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setStyleSheet("background-color: blue;");
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
	std::string aux = name.toStdString();
	User x(aux);
	if (bazaDeDate.m_db.get_all<User>(sql::where(sql::like(&User::GetUserName, aux))).size() == 0)
	{
		bazaDeDate.initializeUser(x);
		this->close();
	}
	else
	{
		box.information(this, "Warning", "Contul exista deja");
	}
}
