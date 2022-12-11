#pragma once

#include <QMainWindow>
#include "ui_HomePage.h"
#include"User.h"

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
private slots:
	void on_Search_released();
	void on_Search_clicked();
	void on_LogOut_released();
	void on_LogOut_clicked();
	void on_Comedy_released();
	void on_Comedy_clicked();
	void on_SF_released();
	void on_SF_clicked();
};
