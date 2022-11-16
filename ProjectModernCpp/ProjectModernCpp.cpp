#include "ProjectModernCpp.h"
#include <iostream>

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
    
}
void ProjectModernCpp::on_RegisterButton_clicked()
{
    this->hide();
    SignUp = new SignUpWindow();
    SignUp->show();
}


