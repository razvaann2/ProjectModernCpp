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
	void on_LogOut_released();
	void on_LogOut_clicked();
};
