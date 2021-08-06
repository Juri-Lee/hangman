#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secdialog.h"

namespace Ui {
class MainWindow;
}

extern QString Username;
//This variable contains username, and use this variable in the mainwindow.cpp
//and secdialog.cpp

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:


    void on_Namebutton_clicked();
    //Create user name, connect user name to the label

    void on_Exit_clicked();
    //connect to message box, so that the box ask user to quit

    void on_Next_clicked();
    //Go to game page

private:
    Ui::MainWindow *ui;
    SecDialog *secdialog;

};

#endif // MAINWINDOW_H
