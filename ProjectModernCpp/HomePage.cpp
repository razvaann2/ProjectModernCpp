#include "HomePage.h"
#include"ProjectModernCpp.h"
#include<QString>
#include "DataBase.h"

HomePage::HomePage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowState(Qt::WindowMaximized);
	ui.ProfileTitle->setVisible(false);
	ui.MovieTitle->setVisible(false);
	ui.MovieType->setVisible(false);
	ui.MovieDirector->setVisible(false);
	ui.MovieCast->setVisible(false);
	ui.MovieCountry->setVisible(false);
	ui.MovieDateAdded->setVisible(false);
	ui.MovieReleaseYear->setVisible(false);
	ui.MovieRating->setVisible(false);
	ui.MovieDuration->setVisible(false);
	ui.MovieListedIn->setVisible(false);
	ui.MovieDescription->setVisible(false);
}

void HomePage::SetUser(User user)
{
	this->loggedUser = user;
	QString qstringUser = QString::fromStdString(this->loggedUser.GetUserName());
	//ui.HomePage->setText(qstringUser);
	ui.HomePage->setText(qstringUser);
	ui.HomePage->setFont(QFont("Times New Roman", 20, QFont::Bold, false));
}

HomePage::~HomePage()
{}

void HomePage::on_User_clicked()
{
	ui.MovieTitle->setVisible(false);
	ui.MovieType->setVisible(false);
	ui.MovieDirector->setVisible(false);
	ui.MovieCast->setVisible(false);
	ui.MovieCountry->setVisible(false);
	ui.MovieDateAdded->setVisible(false);
	ui.MovieReleaseYear->setVisible(false);
	ui.MovieRating->setVisible(false);
	ui.MovieDuration->setVisible(false);
	ui.MovieListedIn->setVisible(false);
	ui.MovieDescription->setVisible(false);
	ui.ProfileTitle->setVisible(true);
}

void HomePage::on_User_released()
{
}

void HomePage::on_Search_clicked()
{
	DataBase bazaDeDate;
	std::string movie_name = ui.Film_to_search->text().toStdString();
	
	if (bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetTitle, movie_name))).size() == 1)
	{
		movieSearched = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetTitle, movie_name))).front();
		ui.MovieTitle->setText(QString::fromStdString(movieSearched.GetTitle()));
		ui.MovieTitle->setFont(QFont("Segoe UI", 24, QFont::Bold, false));
		ui.MovieType->setText(QString::fromStdString(movieSearched.GetType()));
		ui.MovieType->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
		ui.MovieDirector->setText(QString::fromStdString(movieSearched.GetDirector()));
		ui.MovieDirector->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
		ui.MovieCast->setText(QString::fromStdString(movieSearched.GetCast()));
		ui.MovieCast->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
		ui.MovieCountry->setText(QString::fromStdString(movieSearched.GetCountry()));
		ui.MovieCountry->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
		ui.MovieDateAdded->setText(QString::fromStdString(movieSearched.GetDateAdded()));
		ui.MovieDateAdded->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
		ui.MovieReleaseYear->setText(QString::fromStdString(movieSearched.GetReleaseYear()));
		ui.MovieReleaseYear->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
		ui.MovieRating->setText(QString::fromStdString(movieSearched.GetRating()));
		ui.MovieRating->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
		ui.MovieDuration->setText(QString::fromStdString(movieSearched.GetDuration()));
		ui.MovieDuration->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
		ui.MovieListedIn->setText(QString::fromStdString(movieSearched.GetListedIn()));
		ui.MovieListedIn->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
		ui.MovieDescription->setText(QString::fromStdString(movieSearched.GetDescription()));
		ui.MovieDescription->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
		ui.ProfileTitle->setVisible(false);
		ui.MovieTitle->setVisible(true);
		ui.MovieType->setVisible(true);
		ui.MovieDirector->setVisible(true);
		ui.MovieCast->setVisible(true);
		ui.MovieCountry->setVisible(true);
		ui.MovieDateAdded->setVisible(true);
		ui.MovieReleaseYear->setVisible(true);
		ui.MovieRating->setVisible(true);
		ui.MovieDuration->setVisible(true);
		ui.MovieListedIn->setVisible(true);
		ui.MovieDescription->setVisible(true);
	}
	else
	{
		QMessageBox reply;
		reply.information(this, "info", "The movie was not found", QMessageBox::Ok);
	}
}
void HomePage::on_Search_released()
{

}
void HomePage::on_LogOut_released()
{
}
void HomePage::on_LogOut_clicked()
{   
	ProjectModernCpp* a = new ProjectModernCpp;
	a->show();
	this->close();
	
}
void HomePage::on_Comedy_released()
{
}
void HomePage::on_Comedy_clicked()
{
	Movie* Comedy = new Movie;
	Comedy->GetType();
}
void HomePage::on_SF_released()
{
}
void HomePage::on_SF_clicked()
{
	Movie* SF = new Movie;
	SF->GetType();
}
void HomePage::on_Film_to_search_released()
{
}
void HomePage::on_Film_to_search_clicked()
{
	DataBase bazaDeDate;
	QString name = ui.Film_to_search->text();
	std::string aux = name.toStdString();
}

