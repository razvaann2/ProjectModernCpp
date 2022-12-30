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
	ui.AddtoWishlist->setVisible(false);
	ui.AddtoWatchedlist->setVisible(false);
	setMovieListVisibility(false);
	ui.See_your_watchedlist->setVisible(false);
	ui.See_your_wishlist->setVisible(false);
}

void HomePage::SetUser(User user)
{
	this->loggedUser = user;
	QString qstringUser = QString::fromStdString(this->loggedUser.GetUserName());
	ui.HomePage->setText(qstringUser);
	ui.HomePage->setFont(QFont("Times New Roman", 20, QFont::Bold, false));
}

HomePage::~HomePage()
{
}

void HomePage::setMovieListVisibility(bool statement)
{
	ui.MovieList->setVisible(statement);
	ui.ViewMovie->setVisible(statement);
}

void HomePage::showMovie()
{
	std::string text1, text2;
	ui.MovieTitle->setText(QString::fromStdString(movieSearched.GetTitle()));
	ui.MovieTitle->setFont(QFont("Segoe UI", 24, QFont::Bold, false));
	text1 = "Type: ";
	text2 = movieSearched.GetType();
	if (text2 == "")
		text2 = "Unavailable";
	text1 += text2;
	ui.MovieType->setText(QString::fromStdString(text1));
	ui.MovieType->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
	text1 = "Director: ";
	text2 = movieSearched.GetDirector();
	if (text2 == "")
		text2 = "Unavailable";
	text1 += text2;
	ui.MovieDirector->setText(QString::fromStdString(text1));
	ui.MovieDirector->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
	text1 = "Cast: ";
	text2 = movieSearched.GetCast();
	if (text2 == "")
		text2 = "Unavailable";
	text1 += text2;
	ui.MovieCast->setText(QString::fromStdString(text1));
	ui.MovieCast->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
	text1 = "Country: ";
	text2 = movieSearched.GetCountry();
	if (text2 == "")
		text2 = "Unavailable";
	text1 += text2;
	ui.MovieCountry->setText(QString::fromStdString(text1));
	ui.MovieCountry->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
	text1 = "Date Added: ";
	text2 = movieSearched.GetDateAdded();
	if (text2 == "")
		text2 = "Unavailable";
	text1 += text2;
	ui.MovieDateAdded->setText(QString::fromStdString(text1));
	ui.MovieDateAdded->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
	text1 = "Release Year: ";
	text2 = movieSearched.GetReleaseYear();
	if (text2 == "")
		text2 = "Unavailable";
	text1 += text2;
	ui.MovieReleaseYear->setText(QString::fromStdString(text1));
	ui.MovieReleaseYear->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
	text1 = "Rating: ";
	text2 = movieSearched.GetRating();
	if (text2 == "")
		text2 = "Unavailable";
	text1 += text2;
	ui.MovieRating->setText(QString::fromStdString(text1));
	ui.MovieRating->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
	text1 = "Duration: ";
	text2 = movieSearched.GetDuration();
	if (text2 == "")
		text2 = "Unavailable";
	text1 += text2;
	ui.MovieDuration->setText(QString::fromStdString(text1));
	ui.MovieDuration->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
	text1 = "Listed In: ";
	text2 = movieSearched.GetListedIn();
	if (text2 == "")
		text2 = "Unavailable";
	text1 += text2;
	ui.MovieListedIn->setText(QString::fromStdString(text1));
	ui.MovieListedIn->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
	text1 = "Description: ";
	text2 = movieSearched.GetDescription();
	if (text2 == "")
		text2 = "Unavailable";
	text1 += text2;
	ui.MovieDescription->setText(QString::fromStdString(text1));
	ui.MovieDescription->setFont(QFont("Segoe UI", 18, QFont::Bold, false));
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
	ui.AddtoWishlist->setVisible(true);
	ui.AddtoWatchedlist->setVisible(true);
	ui.See_your_watchedlist->setVisible(false);
	ui.See_your_wishlist->setVisible(false);
}

void HomePage::on_User_clicked()
{
	ui.AddtoWatchedlist->setVisible(false);
	ui.AddtoWishlist->setVisible(false);
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
	setMovieListVisibility(false);
	ui.ProfileTitle->setVisible(true);
	ui.See_your_watchedlist->setVisible(true);
	ui.See_your_wishlist->setVisible(true);
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
		ui.ProfileTitle->setVisible(false);
		setMovieListVisibility(false);
		showMovie();
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
	DataBase bazaDeDate;
	std::vector ComedyMovies = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetListedIn, "%Come%")));
	ui.MovieList->clear();
	for (int i = 0; i < ComedyMovies.size(); i++)
	{
		ui.MovieList->addItem(QString::fromStdString(ComedyMovies[i].GetTitle()));
		ui.MovieList->item(i)->setForeground(Qt::white);
	}
	ui.See_your_watchedlist->setVisible(false);
	ui.See_your_wishlist->setVisible(false);
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
	ui.AddtoWishlist->setVisible(false);
	ui.AddtoWatchedlist->setVisible(false);
	setMovieListVisibility(true);
}
void HomePage::on_SF_released()
{
}
void HomePage::on_SF_clicked()
{
	DataBase bazaDeDate;
	std::vector SFMovies = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetListedIn, "%Sci-Fi%")));
	ui.MovieList->clear();
	for (int i = 0; i < SFMovies.size(); i++)
	{
		ui.MovieList->addItem(QString::fromStdString(SFMovies[i].GetTitle()));
		ui.MovieList->item(i)->setForeground(Qt::white);
	}

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
	ui.AddtoWishlist->setVisible(false);
	ui.AddtoWatchedlist->setVisible(false);
	ui.See_your_watchedlist->setVisible(false);
	ui.See_your_wishlist->setVisible(false);
	setMovieListVisibility(true);
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
void HomePage::on_AddtoWishlist_released()
{
}
void HomePage::on_AddtoWishlist_clicked()
{
	DataBase bazaDeDate;
	bazaDeDate.AddWishList(this->movieSearched.GetMovieId(), this->loggedUser.GetID());
	QMessageBox reply;
	QString a = QString::fromStdString(movieSearched.GetTitle()) + " was added to wishlist";
	reply.information(this, "info", a, QMessageBox::Ok);
}
void HomePage::on_AddtoWatchedlist_released()
{
}
void HomePage::on_AddtoWatchedlist_clicked()
{
	DataBase bazaDeDate;
	bazaDeDate.AddWatchedList(this->movieSearched.GetMovieId(),this->loggedUser.GetID());
	QMessageBox reply;
	QString a = QString::fromStdString(movieSearched.GetTitle()) + " was marked as seen";
	reply.information(this, "info",a,QMessageBox::Ok);
}

void HomePage::on_ViewMovie_released()
{
}

void HomePage::on_ViewMovie_clicked()
{
	DataBase bazaDeDate;
	QListWidgetItem* movie_to_search = ui.MovieList->currentItem();
	if (movie_to_search != nullptr)
	{
		movieSearched = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetTitle, movie_to_search->text().toStdString()))).front();
		setMovieListVisibility(false);
		showMovie();
	}
	else
	{
		QMessageBox box;
		box.warning(this, "Warning", "Select a movie first", QMessageBox::Ok);
	}
}

void HomePage::on_see_your_wishlist_released()
{
}

void HomePage::on_see_your_watchedlist_released()
{
}

void HomePage::on_All_movies_released()
{
}

void HomePage::on_All_movies_clicked()
{
	DataBase bazaDeDate;
	std::vector All_movies = bazaDeDate.m_db.get_all<Movie>();
	ui.MovieList->clear();
	for (int i = 0; i < All_movies.size(); i++)
	{
		ui.MovieList->addItem(QString::fromStdString(All_movies[i].GetTitle()));
		ui.MovieList->item(i)->setForeground(Qt::white);
	}
	ui.See_your_watchedlist->setVisible(false);
	ui.See_your_wishlist->setVisible(false);
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
	ui.AddtoWishlist->setVisible(false);
	ui.AddtoWatchedlist->setVisible(false);
	setMovieListVisibility(true);
}

void HomePage::on_Horror_released()
{
}
void HomePage::on_Horror_clicked()
{
	DataBase bazaDeDate;
	std::vector HorrorMovies = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetListedIn, "%Horror%")));
	ui.MovieList->clear();
	for (int i = 0; i < HorrorMovies.size(); i++)
	{
		ui.MovieList->addItem(QString::fromStdString(HorrorMovies[i].GetTitle()));
		ui.MovieList->item(i)->setForeground(Qt::white);
	}
	ui.See_your_watchedlist->setVisible(false);
	ui.See_your_wishlist->setVisible(false);
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
	ui.AddtoWishlist->setVisible(false);
	ui.AddtoWatchedlist->setVisible(false);
	setMovieListVisibility(true);
}


void HomePage::on_Action_released()
{
}

void HomePage::on_Action_clicked()
{
	DataBase bazaDeDate;
	std::vector ActionMovies = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetListedIn, "%Action%")));
	ui.MovieList->clear();
	for (int i = 0; i < ActionMovies.size(); i++)
	{
		ui.MovieList->addItem(QString::fromStdString(ActionMovies[i].GetTitle()));
		ui.MovieList->item(i)->setForeground(Qt::white);
	}
	ui.See_your_watchedlist->setVisible(false);
	ui.See_your_wishlist->setVisible(false);
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
	ui.AddtoWishlist->setVisible(false);
	ui.AddtoWatchedlist->setVisible(false);
	setMovieListVisibility(true);
}

void HomePage::on_Drama_released()
{
}

void HomePage::on_Drama_clicked()
{
	DataBase bazaDeDate;
	std::vector DramaMovies = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetListedIn, "%Drama%")));
	ui.MovieList->clear();
	for (int i = 0; i < DramaMovies.size(); i++)
	{
		ui.MovieList->addItem(QString::fromStdString(DramaMovies[i].GetTitle()));
		ui.MovieList->item(i)->setForeground(Qt::white);
	}
	ui.See_your_watchedlist->setVisible(false);
	ui.See_your_wishlist->setVisible(false);
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
	ui.AddtoWishlist->setVisible(false);
	ui.AddtoWatchedlist->setVisible(false);
	setMovieListVisibility(true);
}
