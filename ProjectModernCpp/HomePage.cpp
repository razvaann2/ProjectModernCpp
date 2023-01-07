#include "HomePage.h"
#include"ProjectModernCpp.h"
#include<QString>
#include "DataBase.h"

using namespace sql;

HomePage::HomePage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowState(Qt::WindowMaximized);
	setProfilePageVisible(false);
	setMovieInfoVisible(false);
	setMovieListVisible(false);
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
	setProfilePageVisible(false);
	setMovieInfoVisible(true);
}

void HomePage::showMovieList(std::string movie_genres)
{
	DataBase bazaDeDate;
	std::vector Movies = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetListedIn, "%"+movie_genres+"%")));
	ui.MovieList->clear();
	for (int i = 0; i < Movies.size(); i++)
	{
		ui.MovieList->addItem(QString::fromStdString((Movies[i].GetTitle())));
		ui.MovieList->item(i)->setForeground(Qt::white);
	}
}

void HomePage::setMovieListVisible(bool statement)
{
	ui.MovieList->setVisible(statement);
	ui.ViewMovie->setVisible(statement);
}

void HomePage::setProfilePageVisible(bool statement)
{
	ui.ProfileTitle->setVisible(statement);
	ui.See_your_watchedlist->setVisible(statement);
	ui.See_your_wishlist->setVisible(statement);
	ui.Wishlist->setVisible(statement);
	ui.Watchedlist->setVisible(statement);
	ui.Wishlist->clear();
	ui.Watchedlist->clear();
}

void HomePage::setMovieInfoVisible(bool statement)
{
	ui.MovieTitle->setVisible(statement);
	ui.MovieType->setVisible(statement);
	ui.MovieDirector->setVisible(statement);
	ui.MovieCast->setVisible(statement);
	ui.MovieCountry->setVisible(statement);
	ui.MovieDateAdded->setVisible(statement);
	ui.MovieReleaseYear->setVisible(statement);
	ui.MovieRating->setVisible(statement);
	ui.MovieDuration->setVisible(statement);
	ui.MovieListedIn->setVisible(statement);
	ui.MovieDescription->setVisible(statement);
	ui.AddtoWishlist->setVisible(statement);
	ui.AddtoWatchedlist->setVisible(statement);
}

void HomePage::on_User_clicked()
{
	setMovieInfoVisible(false);
	setMovieListVisible(false);
	setProfilePageVisible(true);
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
		setMovieListVisible(false);
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
	showMovieList("Comedy");
	setProfilePageVisible(false);
	setMovieInfoVisible(false);
	setMovieListVisible(true);
}
void HomePage::on_SF_released()
{
}
void HomePage::on_SF_clicked()
{
	showMovieList("Sci-Fi");
	setProfilePageVisible(false);
	setMovieInfoVisible(false);
	setMovieListVisible(true);
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
	QMessageBox reply;
	if (bazaDeDate.m_db.get_all<WishList>(sql::where(sql::c(&WishList::GetMovieID) == this->movieSearched.GetMovieId() and sql::c(&WishList::GetUserID) == this->loggedUser.GetID())).size() == 0)
	{
		bazaDeDate.AddWishList(this->movieSearched.GetMovieId(), this->loggedUser.GetID());
		QString a = QString::fromStdString(movieSearched.GetTitle()) + " was added to your wishlist";
		reply.information(this, "info", a, QMessageBox::Ok);
	}
	else
	{
		QString a = QString::fromStdString(movieSearched.GetTitle()) + " is already in your wishlist";
		reply.information(this, "info", a, QMessageBox::Ok);
	}
}
void HomePage::on_AddtoWatchedlist_released()
{
}
void HomePage::on_AddtoWatchedlist_clicked()
{
	DataBase bazaDeDate;
	QMessageBox reply;
	if (bazaDeDate.m_db.get_all<WatchedList>(sql::where(sql::c(&WatchedList::GetMovieID) == this->movieSearched.GetMovieId() and sql::c(&WatchedList::GetUserID) == this->loggedUser.GetID())).size() == 0)
	{
		bazaDeDate.AddWatchedList(this->movieSearched.GetMovieId(), this->loggedUser.GetID());
		QString a = QString::fromStdString(movieSearched.GetTitle()) + " was marked as seen";
		reply.information(this, "info", a, QMessageBox::Ok);
	}
	else
	{
		QString a = QString::fromStdString(movieSearched.GetTitle()) + " was already marked as seen";
		reply.information(this, "info", a, QMessageBox::Ok);
	}
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
		setMovieListVisible(false);
		showMovie();
	}
	else
	{
		QMessageBox box;
		box.warning(this, "Warning", "Select a movie first", QMessageBox::Ok);
	}
}

void HomePage::on_See_your_wishlist_released()
{
}

void HomePage::on_See_your_wishlist_clicked()
{
	DataBase bazaDeDate;
	std::vector<WishList> movies_id = bazaDeDate.m_db.get_all<WishList>(sql::where(sql::c(&WishList::GetUserID) == loggedUser.GetID()));
	std::vector<Movie> wishlist;
	for (int i = 0; i < movies_id.size(); i++)
	{
		std::vector<Movie> movie = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::c(&Movie::GetMovieId) == movies_id[i].GetMovieID()));
		wishlist.push_back(movie[0]);
	}
	ui.Wishlist->clear();
	for (int i = 0; i < wishlist.size(); i++)
	{
		ui.Wishlist->addItem(QString::fromStdString((wishlist[i].GetTitle())));
		ui.Wishlist->item(i)->setForeground(Qt::white);
	}
}

void HomePage::on_See_your_watchedlist_released()
{
}

void HomePage::on_See_your_watchedlist_clicked()
{
	DataBase bazaDeDate;
	std::vector<WatchedList> movies_id = bazaDeDate.m_db.get_all<WatchedList>(sql::where(sql::c(&WatchedList::GetUserID) == loggedUser.GetID()));
	std::vector<Movie> watchedlist;
	for (int i = 0; i < movies_id.size(); i++)
	{
		std::vector<Movie> movie = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::c(&Movie::GetMovieId) == movies_id[i].GetMovieID()));
		watchedlist.push_back(movie[0]);
	}
	ui.Watchedlist->clear();
	for (int i = 0; i < watchedlist.size(); i++)
	{
		ui.Watchedlist->addItem(QString::fromStdString((watchedlist[i].GetTitle())));
		ui.Watchedlist->item(i)->setForeground(Qt::white);
	}
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
	setProfilePageVisible(false);
	setMovieInfoVisible(false);
	setMovieListVisible(true);
}

void HomePage::on_Horror_released()
{
}

void HomePage::on_Horror_clicked()
{
	showMovieList("Horror");
	setProfilePageVisible(false);
	setMovieInfoVisible(false);
	setMovieListVisible(true);
}


void HomePage::on_Action_released()
{
}

void HomePage::on_Action_clicked()
{
	showMovieList("Action");
	setProfilePageVisible(false);
	setMovieInfoVisible(false);
	setMovieListVisible(true);
}

void HomePage::on_Drama_released()
{
}

void HomePage::on_Drama_clicked()
{
	showMovieList("Drama");
	setProfilePageVisible(false);
	setMovieInfoVisible(false);
	setMovieListVisible(true);
}
