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

QString SignUpWindow::on_SignUpButton_clicked()
{
	QString name = ui.lineEdit->text();
	this->close();
	return name;

}
