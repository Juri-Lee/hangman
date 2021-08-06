#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

using namespace std;

QString Username;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for( int i = 1990 ; i <2011 ; i ++)
    {
       ui->Year->addItem(QString::number(i));
    }
    for( int i = 1 ; i <13 ; i ++)
    {
        ui->Month->addItem(QString::number(i));
    }
    for( int i = 1 ; i <32 ; i ++)
    {
        ui->day->addItem(QString::number(i));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Namebutton_clicked()
{
    QVariant i = ui->Year->currentText();
    int year = (i.toInt()) % 10;

    QVariant j = ui->Month->currentText();
    int month = j.toInt();

    QVariant k = ui->day->currentText();
    int date = k.toInt();
    QString name;

 switch(year)
 {
 case 0:
     name = "Dances with ";
     break;
 case 1:
     name = "See ";
     break;
 case 2:
     name = "Death of ";
     break;
 case 3:
     name = "King of ";
     break;
 case 4:
     name = "Song of ";
     break;
 case 5:
     name = "Angry ";
     break;
 case 6:
     name = "Fat ";
     break;
 case 7:
     name = "Shadow of ";
     break;
 case 8:
     name ="Moves like ";
     break;
 case 9:
     name = "Smelly ";
     break;

 }

    switch (month)
    {
    case 1 :
        name += "Scary ";
        break;
    case 2 :
        name += "Cute ";
        break;
    case 3 :
        name += "Funny ";
        break;
    case 4:
        name += "Creepy ";
        break;
    case 5 :
        name += "Crazy ";
        break;
    case 6 :
        name += "Haunted ";
        break;
    case 7 :
        name += "Terrifying ";
        break;
    case 8 :
        name += "Spooky ";
        break;
    case 9 :
        name += "Cheerful ";
        break;
    case 10 :
        name += "Magical ";
        break;
    case 11 :
        name += "Dead ";
        break;
    case 12 :
        name += "Bloody ";
        break;
    }

    switch (date)
    {
    case 1 :
        name += "Zombie";
        break;
    case 2 :
        name += "Cheerleader";
        break;
    case 3 :
        name += "Ghost";
        break;
    case 4:
        name += "Pirate";
        break;
    case 5 :
        name += "Witch";
        break;
    case 6 :
        name += "Cat";
        break;
    case 7 :
        name += "Pumpkin";
        break;
    case 8 :
        name += "Alien";
        break;
    case 9 :
        name += "Troll";
        break;
    case 10 :
        name += "Princess";
        break;
    case 11 :
        name += "Bride";
        break;
    case 12 :
        name += "Fairy";
        break;
    case 13 :
        name += "Super Hero";
        break;
    case 14 :
        name += "Student";
        break;
    case 15 :
        name += "Devil";
        break;
    case 16 :
        name += "Frankenstein";
        break;
    case 17 :
        name += "Cowgirl";
        break;
    case 18 :
        name += "Red Riding Hood";
        break;
    case 19 :
        name += "Vampire";
        break;
    case 20 :
        name += "Skeleton";
        break;
    case 21 :
        name += "Prom Queen";
        break;
    case 22 :
        name += "Mummy";
        break;
    case 23 :
        name += "Dragon";
        break;
    case 24 :
        name += "Werewolf";
        break;
    case 25 :
        name += "Clown";
        break;
    case 26 :
        name += "Ballerina";
        break;
    case 27 :
        name += "Doll";
        break;
    case 28 :
        name += "Nerd";
        break;
    case 29 :
        name += "Nurse";
        break;
    case 30 :
        name += "Unicorn";
        break;
    case 31 :
        name += "Robot";
        break;
    }

    Username = name;

   ui->Nameshow->setText(Username);

   show();
}

void MainWindow::on_Exit_clicked()
{
    QMessageBox::StandardButton exit;

    exit = QMessageBox::warning (this, "Test", "Do you want to close this game?", QMessageBox::Yes|QMessageBox::No);

     if (exit == QMessageBox::Yes)
       QApplication::quit();
}


void MainWindow::on_Next_clicked()
{
        hide();
        secdialog = new SecDialog(this);
        secdialog->show();

}
