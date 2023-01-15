#include "HomePage.h"
#include"ProjectModernCpp.h"
#include<QString>
#include "DataBase.h"
#include <string>
#include<unordered_set>
using namespace sql;

HomePage::HomePage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowState(Qt::WindowMaximized);
	QIcon icon2("../Files/archive/dislike.png");
	QIcon icon1("../Files/archive/like.png");
	ui.like->setCheckable(true);
	ui.like->setIcon(icon1);
	ui.dislike->setIcon(icon2);
	ui.dislike->setCheckable(true);
	ui.like->setIconSize(QSize(61, 61));
	ui.dislike->setIconSize(QSize(61, 61));
	connect(ui.Watchedlist, &QListWidget::itemClicked, this, &HomePage::selectFromWatchedlist);
	connect(ui.Wishlist, &QListWidget::itemClicked, this, &HomePage::selectFromWishlist);
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
	DataBase bazaDeDate;
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
	std::vector<Review> reviews = bazaDeDate.m_db.get_all<Review>(sql::where(sql::c(&Review::GetMovieID) == movieSearched.GetMovieId() and sql::c(&Review::GetUserID) == this->loggedUser.GetID()));
	ui.like->setChecked(false);
	ui.dislike->setChecked(false);
	if (reviews.size() != 0)
		bazaDeDate.AddReview(reviews[0].GetMovieID(), reviews[0].GetUserID(), reviews[0].GetStatus());
	if (bazaDeDate.m_db.get_all<Review>(sql::where(sql::c(&Review::GetMovieID) == movieSearched.GetMovieId() and sql::c(&Review::GetUserID) == this->loggedUser.GetID())).size() != 0)
	{	
		 Review review = bazaDeDate.m_db.get_all<Review>(sql::where(sql::c(&Review::GetMovieID) == movieSearched.GetMovieId() and sql::c(&Review::GetUserID) == this->loggedUser.GetID())).front();
		int status = review.GetStatus();
		if (status == 1)
		{
			ui.like->setChecked(true);
			QIcon icon1("../Files/archive/liked.png");
			ui.like->setIcon(icon1);
		}
		else {
			QIcon icon2("../Files/archive/disliked.png");
			ui.dislike->setIcon(icon2);
			ui.dislike->setChecked(true);
		}
	}
	SetSimilarMoviesList();
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
	ui.PreviousButton->setVisible(statement);
	ui.NextButton->setVisible(statement);
}

void HomePage::setProfilePageVisible(bool statement)
{
	ui.ProfileTitle->setVisible(statement);
	ui.Watchedlist_label->setVisible(statement);
	ui.Wishlist_label->setVisible(statement);
	ui.Watchedlist->setVisible(statement);
	ui.Wishlist->setVisible(statement);
	ui.ViewListMovie->setVisible(statement);
	ui.DeleteFromList->setVisible(statement);
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
	ui.like->setVisible(statement);
	ui.dislike->setVisible(statement);
	ui.HomePage_6->setVisible(statement);
	ui.SimilarMoviesList->setVisible(statement);
	ui.ViewRecommendedMovie->setVisible(statement);
	ui.SimilarMovies->setVisible(statement);
}

void HomePage::updateWatchedlist(std::vector<Movie> watchedlist)
{
	ui.Watchedlist->clear();
	for (int i = 0; i < watchedlist.size(); i++)
	{
		ui.Watchedlist->addItem(QString::fromStdString((watchedlist[i].GetTitle())));
		ui.Watchedlist->item(i)->setForeground(Qt::white);
	}
}

void HomePage::updateWishlist(std::vector<Movie> wishlist)
{
	ui.Wishlist->clear();
	for (int i = 0; i < wishlist.size(); i++)
	{
		ui.Wishlist->addItem(QString::fromStdString((wishlist[i].GetTitle())));
		ui.Wishlist->item(i)->setForeground(Qt::white);
	}
}

template<typename T>
std::vector<Movie> HomePage::getList(T a)
{
	DataBase bazaDeDate;
	std::vector<T> movies_id = bazaDeDate.m_db.get_all<T>(sql::where(sql::c(&T::GetUserID) == loggedUser.GetID()));
	std::vector<Movie> list;
	for (int i = 0; i < movies_id.size(); i++)
	{
		Movie movie = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::c(&Movie::GetMovieId) == movies_id[i].GetMovieID())).front();
		list.push_back(movie);
	}
	return list;
}

template<typename T>
void HomePage::deleteFromList(T a, QListWidgetItem* selected)
{
	DataBase bazaDeDate;
	Movie movie = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetTitle, selected->text().toStdString()))).front();
	T item_to_delete = bazaDeDate.m_db.get_all<T>(sql::where(sql::c(&T::GetMovieID) == movie.GetMovieId() and sql::c(&T::GetUserID) == this->loggedUser.GetID())).front();
	bazaDeDate.m_db.remove<T>(item_to_delete.GetID());
	bazaDeDate.m_db.sync_schema();
}
void HomePage::DeleteReview(Review aux)
{
	DataBase bazaDeDate;
	Review item_to_delete = bazaDeDate.m_db.get_all<Review>(sql::where(sql::c(&Review::GetMovieID) == aux.GetMovieID() and sql::c(&Review::GetUserID)==this->loggedUser.GetID())).front();
	bazaDeDate.m_db.remove<Review>(item_to_delete.GetID());
	bazaDeDate.m_db.sync_schema();

}

void HomePage::SetSimilarMoviesList()
{
	DataBase bazaDeDate;
	std::unordered_set<int> set;
	set.insert(movieSearched.GetMovieId());
	ui.SimilarMoviesList->clear();
	int number_of_recommended_movies = 12;
	std::string aux = movieSearched.GetListedIn();
	std::vector<std::string>genres;
	std::stringstream ss(aux);
	std::string word;
	while (std::getline(ss, word, ','))
	{
		genres.push_back(word);
	}
	std::string aux1 = "%";
	for (int j = 0; j < genres.size(); j++)
	{
		if (genres[j][0] == ' ')
		{
			genres[j].erase(0, 1);
		}
		aux1 += genres[j] + "%";
	}
	std::vector<Movie> movies = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetListedIn, aux1)));
	for (int j = 0; j < movies.size(); j++)
	{
		if (set.find(movies[j].GetMovieId()) != set.end())
			movies.erase(movies.begin() + j);
	}
	int i = 0;
	while(i<number_of_recommended_movies)
	{
		if (movies.size() == 0)
		{
			int poz = aux1.find('%', 1);
			if (poz != -1)
				aux1.erase(0, poz);
			movies = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetListedIn, aux1)));
			for (int j = 0; j < movies.size(); j++)
			{
				if (set.find(movies[j].GetMovieId()) != set.end())
				{
					movies.erase(movies.begin() + j);
					j--;
				}
			}
		}
		int random_number = std::rand() % movies.size();
		set.insert(movies[random_number].GetMovieId());
		ui.SimilarMoviesList->addItem(QString::fromStdString(movies[random_number].GetTitle()));
		movies.erase(movies.begin() + random_number);
		ui.SimilarMoviesList->item(i)->setForeground(Qt::white);
		i++;
	}
}

void HomePage::on_User_clicked()
{
	WatchedList a;
	WishList b;
	ui.Wishlist->clear();
	ui.Watchedlist->clear();
	std::vector<Movie> watchedlist = getList(a);
	updateWatchedlist(watchedlist);
	std::vector<Movie> wishlist = getList(b);
	updateWishlist(wishlist);
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
	
	
	
	std::vector Movies = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetTitle, "%" + movie_name + "%")));
		
	if (Movies.size() >= 1) {
		ui.MovieList->clear();
		for (int i = 0; i < Movies.size(); i++)
		{
			ui.MovieList->addItem(QString::fromStdString((Movies[i].GetTitle())));
			ui.MovieList->item(i)->setForeground(Qt::white);
		}

		setProfilePageVisible(false);
		setMovieInfoVisible(false);
		setMovieListVisible(true);
	}
	else
	{
		QMessageBox reply;
		QString a = "No movies found";
		reply.information(this, "info", a, QMessageBox::Ok);

	}

	
}
void HomePage::on_Recommend_movie_released()
{
}
void HomePage::on_Recommend_movie_clicked()
{
	int number_of_recommended_movies = 17;
	ui.MovieList->clear();
	srand(std::time(0));
	int random_number;
	std::unordered_set<int> set;
	WatchedList watched;
	WishList wish;
	DataBase bazaDeDate;
	std::vector v1 = getList(watched);
	std::vector v2 = getList(wish);
	std::vector<Review> reviews;
	for (int i = 0; i < v1.size(); i++)
	{
		reviews = bazaDeDate.m_db.get_all<Review>(sql::where(sql::c(&Review::GetMovieID) == v1[i].GetMovieId() and sql::c(&Review::GetUserID) == this->loggedUser.GetID()));
		if (reviews.size() == 0 || reviews[0].GetStatus() == 1)
			set.insert(v1[i].GetMovieId());
	}
	if (set.size() != 0)
	{
		v1.insert(v1.end(), v2.begin(), v2.end());

		for (int i = 0; i < number_of_recommended_movies; i++)
		{
			int random_number = std::rand() % v1.size();
			std::string aux = v1[random_number].GetListedIn();
			std::vector<std::string>genres;
			std::stringstream ss(aux);
			std::string word;
			while (std::getline(ss, word, ','))
			{
				genres.push_back(word);
			}
			std::string aux1="%";
			for (int j = 0; j < genres.size(); j++)
			{
				if (genres[j][0] == ' ')
				{
					genres[j].erase(0, 1);
				}
				aux1 += genres[j]+"%";
			}
			v2.clear();
			while (v2.size() == 0)
			{
				v2 = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetListedIn, aux1)));
				int poz = aux1.find('%', 1);
				if (poz != -1)
					aux1.erase(0, poz);
			}
			DataBase bazaDeDate;
			random_number = std::rand() % v2.size();
			reviews = bazaDeDate.m_db.get_all<Review>(sql::where(sql::c(&Review::GetMovieID) == v2[random_number].GetMovieId() and sql::c(&Review::GetUserID) == this->loggedUser.GetID()));
			if (set.find(v2[random_number].GetMovieId()) == set.end() && (reviews.size() == 0 || reviews[0].GetStatus() == 1))
			{
				ui.MovieList->addItem(QString::fromStdString(v2[random_number].GetTitle()));
				ui.MovieList->item(i)->setForeground(Qt::white);
				set.insert(v2[random_number].GetMovieId());
			}
			else i--;
		}
	}
	else for (int i = 0; i < 10; i++)
	{
		std::vector v1 = bazaDeDate.m_db.get_all<Movie>();
		random_number = std::rand() % v1.size();
		if (set.find(v1[random_number].GetMovieId()) == set.end())
		{
			set.insert(v1[random_number].GetMovieId());
			ui.MovieList->addItem(QString::fromStdString(v1[random_number].GetTitle()));
			ui.MovieList->item(i)->setForeground(Qt::white);
		}
		else i--;
	}
	setProfilePageVisible(false);
	setMovieInfoVisible(false);
	setMovieListVisible(true);
}

void HomePage::on_ViewRecommendedMovie_released()
{
}

void HomePage::on_ViewRecommendedMovie_clicked()
{
	DataBase bazaDeDate;
	QListWidgetItem* movie_to_search = ui.SimilarMoviesList->currentItem();
	if (movie_to_search != nullptr)
	{
		movieSearched = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetTitle, movie_to_search->text().toStdString()))).front();
		setProfilePageVisible(false);
		showMovie();
	}
	else
	{
		QMessageBox box;
		box.warning(this, "Warning", "Select a movie first", QMessageBox::Ok);
	}
}

void HomePage::on_PreviousButton_clicked()
{
}

void HomePage::on_PreviousButton_released()
{
}

void HomePage::on_NextButton_clicked()
{
}

void HomePage::on_NextButton_released()
{
}

void HomePage::on_like_toggled(bool checked)
{
	DataBase bazaDeDate;
	QIcon icon1("../Files/archive/like.png");
	QIcon icon2("../Files/archive/liked.png");
	if (checked)
	{
		
		ui.like->setIcon(icon2);
		bazaDeDate.AddReview(movieSearched.GetMovieId(), loggedUser.GetID(), 1);
		if (ui.dislike->isChecked())
		{
			ui.dislike->setChecked(false);
			on_dislike_toggled(false);
		}
		
	}
	else 
	{
		ui.like->setIcon(icon1);
		std::vector<Review> reviews= bazaDeDate.m_db.get_all<Review>(sql::where(sql::c(&Review::GetMovieID) == movieSearched.GetMovieId() and sql::c(&Review::GetUserID) == this->loggedUser.GetID() and sql::c(&Review::GetStatus) == 1));
		if(reviews.size()>0)
		DeleteReview(reviews[0]);
	}	
	ui.like->repaint();
	
}
void HomePage::on_dislike_toggled(bool checked)
{
	DataBase bazaDeDate;
	QIcon icon1("../Files/archive/dislike.png");
	QIcon icon2("../Files/archive/disliked.png");
	if (checked) {
		ui.dislike->setIcon(icon2);
		bazaDeDate.AddReview(movieSearched.GetMovieId(), loggedUser.GetID(), 2);
		if (ui.like->isChecked())
		{
			ui.like->setChecked(false);
			on_like_toggled(false);
		}
	}
	else
	{
		ui.dislike->setIcon(icon1);
		std::vector<Review> reviews = bazaDeDate.m_db.get_all<Review>(sql::where(sql::c(&Review::GetMovieID) == movieSearched.GetMovieId() and sql::c(&Review::GetUserID) == this->loggedUser.GetID() and sql::c(&Review::GetStatus) == 2));
		if (reviews.size() > 0)
			DeleteReview(reviews[0]);

	}
	ui.dislike->repaint();
}

void HomePage::selectFromWatchedlist(QListWidgetItem* item)
{
	ui.Wishlist->clearSelection();
	ui.Wishlist->setCurrentItem(nullptr);
	item->setSelected(true);
}

void HomePage::selectFromWishlist(QListWidgetItem* item)
{
	ui.Watchedlist->clearSelection();
	ui.Watchedlist->setCurrentItem(nullptr);
	item->setSelected(true);
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

void HomePage::on_ViewListMovie_released()
{
}

void HomePage::on_ViewListMovie_clicked()
{
	DataBase bazaDeDate;
	QListWidgetItem* watchedlist_movie = ui.Watchedlist->currentItem();
	QListWidgetItem* wishlist_movie = ui.Wishlist->currentItem();
	if (watchedlist_movie != nullptr)
	{
		movieSearched = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetTitle, watchedlist_movie->text().toStdString()))).front();
		setMovieListVisible(false);
		showMovie();
	}
	else if (wishlist_movie != nullptr)
	{
		movieSearched = bazaDeDate.m_db.get_all<Movie>(sql::where(sql::like(&Movie::GetTitle, wishlist_movie->text().toStdString()))).front();
		setMovieListVisible(false);
		showMovie();
	}
	else
	{
		QMessageBox box;
		box.warning(this, "Warning", "Select a movie first", QMessageBox::Ok);
	}
}

void HomePage::on_DeleteFromList_released()
{
}

void HomePage::on_DeleteFromList_clicked()
{
	QListWidgetItem* watchedlist_movie = ui.Watchedlist->currentItem();
	QListWidgetItem* wishlist_movie = ui.Wishlist->currentItem();
	if (watchedlist_movie != nullptr)
	{
		WatchedList a;
		deleteFromList(a, watchedlist_movie);
		std::vector<Movie> watchedlist = getList(a);
		updateWatchedlist(watchedlist);
	}
	else if (wishlist_movie != nullptr)
	{
		WishList a;
		deleteFromList(a, ui.Wishlist->currentItem());
		std::vector<Movie> wishlist = getList(a);
		updateWishlist(wishlist);
	}
	else
	{
		QMessageBox box;
		box.warning(this, "Warning", "Select a movie first", QMessageBox::Ok);
	}
}
