#include "HomePage.h"
#include"ProjectModernCpp.h"
HomePage::HomePage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.usernamelabel->setText("a");
}

HomePage::~HomePage()
{}
