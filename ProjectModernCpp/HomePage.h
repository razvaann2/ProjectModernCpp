#pragma once

#include <QMainWindow>
#include "ui_HomePage.h"
#include "User.h"
#include "Movie.h"
#include "Review.h"

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
	std::string movie_genres;
	int nrOfMoviesDisplayed = 10;
	int firstIdSearched = 1;
	int lastIdSearched = 0;
	void showMovie();
	void showMovieList(std::string movie_genres);
	void setMovieListVisible(bool statement);
	void setProfilePageVisible(bool statement);
	void setMovieInfoVisible(bool statement);
	template <typename T> std::vector<Movie> getList(T a);
	template <typename T> void deleteFromList(T a, QListWidgetItem* item_to_delete);
	void updateWatchedlist(std::vector<Movie> watchedlist);
	void updateWishlist(std::vector<Movie> wishlist);
	void DeleteReview(Review aux);
	void SetSimilarMoviesList();
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
	void on_All_movies_released();
	void on_All_movies_clicked();
	void on_Horror_clicked();
	void on_Horror_released();
	void on_Action_released();
	void on_Action_clicked();
	void on_Drama_released();
	void on_Drama_clicked();
	void on_ViewListMovie_released();
	void on_ViewListMovie_clicked();
	void on_DeleteFromList_released();
	void on_DeleteFromList_clicked();
	void on_Recommend_movie_released();
	void on_Recommend_movie_clicked();
	void on_ViewRecommendedMovie_released();
	void on_ViewRecommendedMovie_clicked();
	void on_PreviousButton_clicked();
	void on_PreviousButton_released();
	void on_NextButton_clicked();
	void on_NextButton_released();
	void on_like_toggled(bool checked);
	void on_dislike_toggled(bool checked);
	void selectFromWatchedlist(QListWidgetItem* item);
	void selectFromWishlist(QListWidgetItem* item);
};