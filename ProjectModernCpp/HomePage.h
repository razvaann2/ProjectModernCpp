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
};
