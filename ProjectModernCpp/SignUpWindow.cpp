#include "SignUpWindow.h"
#include "ProjectModernCpp.h"

SignUpWindow::SignUpWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowState(Qt::WindowMaximized);

	//this->setStyleSheet(
		//"background-image:url(../Files/archive/RegisterImage.jpg); background-position: center;");
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
		QMessageBox::StandardButton reply;
		reply=box.warning(this, "Warning", "The username is taken! Do you want to login? ", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes) {
			this->close();
		}
		else {
			
		}
	}
}
