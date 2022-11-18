#pragma once

#include <QMainWindow>
#include "ui_HomePage.h"

class HomePage : public QMainWindow
{
	Q_OBJECT

public:
	HomePage(QWidget *parent = nullptr);
	~HomePage();

private:
	Ui::HomePageClass ui;
};
