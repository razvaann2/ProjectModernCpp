#pragma once

#include <QWidget>
#include <QString>
#include "ui_SignUpWindow.h"
#include "User.h"
#include "DataBase.h"

class SignUpWindow : public QWidget
{
	Q_OBJECT

public:
	SignUpWindow(QWidget *parent = nullptr);
	~SignUpWindow();

private:
	Ui::SignUpWindowClass ui;
private slots:
	void on_SignUpButton_released();
	void on_SignUpButton_clicked();
};
