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
    std::string name;
    name = "andrei";
    User* firstuser = new User(name);
    HomePage* window = new HomePage();
    window->show();
    close();
}
void ProjectModernCpp::on_RegisterButton_clicked()
{
    SignUp = new SignUpWindow();
    SignUp->show();
}
