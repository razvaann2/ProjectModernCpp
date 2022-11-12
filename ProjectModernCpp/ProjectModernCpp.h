#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProjectModernCpp.h"

class ProjectModernCpp : public QMainWindow
{
    Q_OBJECT

public:
    ProjectModernCpp(QWidget *parent = nullptr);
    ~ProjectModernCpp();

private:
    Ui::ProjectModernCppClass ui;
private slots:
    void on_LoginButton_released();
    void on_RegisterButton_released();
    void on_LoginButton_clicked();
    void on_RegisterButton_clicked();
  
};
