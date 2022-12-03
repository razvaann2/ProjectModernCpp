#pragma once

#include <QMainWindow>
#include <QString>
#include "ui_SignUpWindow.h"
#include "User.h"
#include "DataBase.h"
#include <QMessageBox>

class SignUpWindow : public QMainWindow
{
	Q_OBJECT

public:
	SignUpWindow(QWidget *parent = nullptr);
	~SignUpWindow();

private:
	Ui::SignUpWindowClass ui;
	QMessageBox box;

private slots:
	void on_SignUpButton_released();
	void on_SignUpButton_clicked();
};
