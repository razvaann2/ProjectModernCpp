#pragma once

#include <QMainWindow>
#include <QString>
#include "ui_SignUpWindow.h"
#include "User.h"
#include "DataBase.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <regex>

class SignUpWindow : public QMainWindow
{
	Q_OBJECT

public:
	SignUpWindow(QWidget *parent = nullptr);
	~SignUpWindow();

private:
	Ui::SignUpWindowClass ui;
	QMessageBox box;
	QPushButton *SignUpButton;
	std::unique_ptr<QLineEdit> lineEdit;
	std::unique_ptr<QLabel> Label;

private slots:
	void on_SignUpButton_released();
	void on_SignUpButton_clicked();
	void on_Back_released();
	void on_Back_clicked();
};
