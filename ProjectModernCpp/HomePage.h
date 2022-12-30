#pragma once

#include <QMainWindow>
#include "ui_HomePage.h"
#include "User.h"
#include "Movie.h"

class HomePage : public QMainWindow
{
	Q_OBJECT

public:
	HomePage(QWidget *parent = nullptr);
	 void SetUser(User user);
	~HomePage();

private:
	Ui::HomePageClass ui;
	User loggedUser;
	Movie movieSearched;
	void setMovieListVisibility(bool statement);
	void showMovie();
private slots:
	void on_User_released();
	void on_User_clicked();
	void on_Search_released();
	void on_Search_clicked();
	void on_LogOut_released();
	void on_LogOut_clicked();
	void on_Comedy_released();
	void on_Comedy_clicked();
	void on_SF_released();
	void on_SF_clicked();
	void on_Film_to_search_released();
	void on_Film_to_search_clicked();
	void on_AddtoWishlist_released();
	void on_AddtoWishlist_clicked();
	void on_AddtoWatchedlist_released();
	void on_AddtoWatchedlist_clicked();
	void on_ViewMovie_released();
	void on_ViewMovie_clicked();
	void on_see_your_wishlist_released();
	void on_see_your_watchedlist_released();
	void on_All_movies_released();
	void on_All_movies_clicked();
	void on_Horror_movies_clicked();
	void on_Horror_movies_released();
	void on_Action_released();
	void on_Action_clicked();
	void on_Drama_released();
	void on_Drama_clicked();
};
