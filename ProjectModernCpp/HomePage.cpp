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
	ui.usernamelabel->setText(qstringUser);
}

HomePage::~HomePage()
{}
