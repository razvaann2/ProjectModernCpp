#include "SignUpWindow.h"
#include "ProjectModernCpp.h"

SignUpWindow::SignUpWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowState(Qt::WindowMaximized);

	this->setStyleSheet(
		"background-image:url(../Files/archive/RegisterImage.jpg); background-position: center;");
	SignUpButton = new QPushButton("SignUp", this);
	lineEdit = new QLineEdit(this);
	Label = new QLabel(this);
	connect(SignUpButton, &QPushButton::clicked, this, &SignUpWindow::on_SignUpButton_clicked);
	SignUpButton->setAutoFillBackground(true);
	SignUpButton->setStyleSheet("color: white; background: rgb(40,40,40) ; pressed { border - style: inset;}");
	lineEdit->setStyleSheet("color: black; background: white");
	int button_width = width() / 3.6;
	int button_height = height() / 30;
	QFont font("Segoe Print");
	font.setPointSize(height() / 50);// de mofif
	font.setBold(true);
	Label->setFont(font);
	Label->setGeometry(width() / 2 + button_width , height() / 6, button_width, button_height * 2);
	Label->setText(Label->text() + "Enter username here:");
	SignUpButton->setGeometry(width() / 2 + button_width  ,height() / 3.4, button_width, button_height);
	lineEdit->setGeometry(width() / 2 + button_width , height() / 4, button_width, button_height);
	SignUpButton->setCursor(QCursor(Qt::PointingHandCursor));
	lineEdit->setPlaceholderText("User Name");
	Label->setStyleSheet("color:white;background:rgb(40,40,40); border: 2px solid #111; border - radius: 20px; border-style: outset; padding: 5px; ");

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
	QString name = lineEdit->text();
	std::string aux = name.toStdString();
	if (aux.size() >= 5 && aux.size() <= 20)
	{
		bool VerifyCharacters = true;
		int check = 0;
		for (int i = 0; i < aux.size(); i++)
		{
			check = isalpha(aux[i]);
			
			if (!check)
			{
				VerifyCharacters = false;
			}
		}
		if (VerifyCharacters == true) {
			User x(aux);

			if (bazaDeDate.m_db.get_all<User>(sql::where(sql::like(&User::GetUserName, aux))).size() == 0)
			{
				bazaDeDate.initializeUser(x);
				this->close();
			}
			else
			{
				QMessageBox::StandardButton reply;
				reply = box.warning(this, "Warning", "The username is taken! Do you want to login? ", QMessageBox::Yes | QMessageBox::No);
				if (reply == QMessageBox::Yes) {
					this->close();
				}
				else {
					
					this->close();
					ProjectModernCpp a;
					a.show();
					a.close();
				}
			}
		}
		else {
			QMessageBox::StandardButton arply;
			arply = box.warning(this, "Warning", "Your username has characters that are not accepted \n          Your username must contain only letters");
		}
	}
	else {
		if (aux.size() < 5) {
			QMessageBox::StandardButton rply;
			rply = box.warning(this, "Warning", "Your username needs to have more than 4 characters");
		}
		if(aux.size()>20) {
			QMessageBox::StandardButton rply;
			rply = box.warning(this, "Warning", "Your username needs to have less than 20 characters");
		}
	}
}
void SignUpWindow::on_Back_released()
{

}
void SignUpWindow::on_Back_clicked()
{
	this->close();
}

