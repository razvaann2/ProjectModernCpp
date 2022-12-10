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
    LineEdit = new QLineEdit(this);
    topLabel = new QLabel(this);
    bottomLabel = new QLabel(this);

    connect(LoginButton, &QPushButton::clicked, this, &ProjectModernCpp::on_LoginButton_clicked);
    connect(SignUpButton, &QPushButton::clicked, this, &ProjectModernCpp::on_RegisterButton_clicked);

    SignUpButton->setAutoFillBackground(true);
    LoginButton->setStyleSheet("color: white; background : rgb(30, 30, 30);");
    SignUpButton->setStyleSheet("color: white; background: black");
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
	QString name = LineEdit->text();
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
