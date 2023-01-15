#include "ProjectModernCpp.h"
#include "User.h"
#include <iostream>
#include "HomePage.h"
#include <QPainter>

ProjectModernCpp::ProjectModernCpp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	
	 this->setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowState(Qt::WindowMaximized);
	this->setStyleSheet(
		"background-image:url(../Files/archive/LoginImage.jpg); background-position: center;");
		
    LoginButton = new QPushButton("Login", this);
    SignUpButton = new QPushButton("SignUp", this);
    LineEdit = std::make_unique<QLineEdit>(this);
    topLabel = std::make_unique<QLabel>(this);
    bottomLabel = std::make_unique<QLabel>(this);

    connect(LoginButton, &QPushButton::clicked, this, &ProjectModernCpp::on_LoginButton_clicked);
    connect(SignUpButton, &QPushButton::clicked, this, &ProjectModernCpp::on_RegisterButton_clicked);

    SignUpButton->setAutoFillBackground(true);
    LoginButton->setStyleSheet("color: white; background:rgb(40,40,40) ; pressed { border - style: inset;}");
    SignUpButton->setStyleSheet("color: white;background:rgb(40,40,40) ; pressed{ border - style: inset;}");
    LineEdit->setStyleSheet("color: black; background: white");

    int button_width = width() / 3.6;
    int button_height = height() / 30;

    QFont font("Segoe Print");
    font.setPointSize(height() / 35);
    font.setBold(true);
    topLabel->setFont(font);
    font.setPointSize(height() / 80);
    bottomLabel->setFont(font);

    topLabel->setGeometry(width() / 2 - button_width / 2, height() / 2 - height() / 6.5, button_width, button_height * 1.5);
    bottomLabel->setGeometry(width() / 2 - button_width / 2, height() / 2, button_width, button_height);

    topLabel->setText(topLabel->text() + "Enter username here:");
    bottomLabel->setText(bottomLabel->text() + "If you don't have an account register here:");

    LoginButton->setGeometry(width() / 2 - button_width / 2, height() / 2 - button_height * 2, button_width, button_height);
    SignUpButton->setGeometry(width() / 2 - button_width / 2, height() / 2 + button_height, button_width, button_height);
    LineEdit->setGeometry(width() / 2 - button_width / 2, height() / 2 - height() / 10, button_width, button_height / 1.5);

    LoginButton->setCursor(QCursor(Qt::PointingHandCursor));
    SignUpButton->setCursor(QCursor(Qt::PointingHandCursor));
    LineEdit->setPlaceholderText("User Name");
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
	std::string name = LineEdit->text().toStdString();
	if(bazaDeDate.Checkdatabase(name) == true)
	{
        std::vector<User> Users = bazaDeDate.m_db.get_all<User>(sql::where(sql::like(&User::GetUserName, name)));
        HomePage* window = new HomePage();
        window->SetUser(Users[0]);
        window->show();
        this->close();
	}
	else
	{
		QMessageBox::StandardButton reply;
		reply = box.warning(this, "Warning", "The account doesn't exist! Do you want to register? ", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes) {
		
			SignUp->show();
		}
        if (reply == QMessageBox::No)
        {
            this->close();
        }
	}
}

void ProjectModernCpp::on_RegisterButton_clicked()
{
    SignUp = std::make_unique< SignUpWindow>();
    SignUp->show();
}

void ProjectModernCpp::on_Exit_released()
{

}
void ProjectModernCpp::on_Exit_clicked()
{
    this->close();
}