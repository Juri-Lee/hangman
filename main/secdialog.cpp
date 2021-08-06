#include "secdialog.h"
#include "mainwindow.h"
#include "ui_secdialog.h"
#include <iostream>
#include <cstdlib>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include <fstream>
#include <vector>

using namespace std;


QString line;
QString labelTEXT;
int OPTION;

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

    srand(time(NULL));

   connect(ui->pushButton_A, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_A, SIGNAL(clicked()),this, SLOT(letter_changed()));
   connect(ui->pushButton_B, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_C, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_D, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_E, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_F, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_G, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_H, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_I, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_J, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_K, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_L, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_M, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_N, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_O, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_P, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_Q, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_R, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_S, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_T, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_U, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_V, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_W, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_X, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_Y, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_Z, SIGNAL(clicked()),this, SLOT(letter_pressed()));
   connect(ui->pushButton_Hint, SIGNAL(clicked()),this, SLOT(hint_pressed()));

}
SecDialog::~SecDialog()
{
    delete ui;
}


void SecDialog::on_exit_clicked()
{

    QMessageBox::StandardButton exit;

    exit = QMessageBox::warning (this, "Test", "Do you want to close this game?", QMessageBox::Yes|QMessageBox::No);

     if (exit == QMessageBox::Yes)
       QApplication::quit();

}

int hint(0);
int incorrectunmber(0);
int HINTNUM;

void SecDialog::hint_pressed()
{
    if(hint<HINTNUM)
      {
          for(int i = 0 ; i< line.length() ; i++ )
          {
              if( labelTEXT[i] == '#')
              {
                  labelTEXT[i] = line[i];
                  ui->warning->setText("Hint used");
                  break;
              }
          }
          hint++;
      }

    else if(hint>=HINTNUM)
    {
      ui->warning->setText("Hint is not available");
    }

    switch (OPTION)
    {
    case 0 :
            ui->Word->setText(labelTEXT);
            break;
    case 1 :
            ui->Word_2->setText(labelTEXT);
            break;
    case 2 :
            ui->Word_3->setText(labelTEXT);
            break;
    case 3 :
            ui->Word_4->setText(labelTEXT);
            break;
    }

    if(finish(labelTEXT,line.length()))
   {
       switch (OPTION)
       {
       case 0 :
               ui->Word->setText(line);
               break;
       case 1 :
               ui->Word_2->setText(line);
               break;

       case 2 :
               ui->Word_3->setText(line);
               break;

       case 3 :
               ui->Word_4->setText(line);
               break;
       }
           ui->warning->setText("Finish");

               if(incorrectunmber != 8)
               {
                       QPixmap pix(":/tree/alive.jpg");
                       ui->image->setPixmap(pix);
                       ui->warning->setText(Username + " is going back to his work!");
                       ui->timeamount->setText("You win :)");

               }
               else
               {
                       QPixmap tree(":/tree/deadpicture.png");
                       ui->image->setPixmap(tree);
                       ui->warning->setText(Username + " is Dead!");
                       ui->timeamount->setText(" You lose ;(");
               }
    }

}

void SecDialog::letter_pressed()
{
    QPushButton *button = (QPushButton*)sender();

    QString pushed;
     QString time;

       pushed = button -> text();
       int start(0);
       int index;
       do
       {
           index = findPosition(start, line, pushed);
           replace(index,start, labelTEXT, line,incorrectunmber);
           start = index +1;

       }while(index != -1 && !finish(labelTEXT, line.length()));


        QString styleSheet("color: white;\n background : gray;\n "
                           "border: 2px solid white;\n border-radius: 20px;\n "
                           "font: 20pt \"Chalkboard\"; \n");

       if( pushed == "A")
       {
        ui->pushButton_A->setStyleSheet(styleSheet);
       }
       else if(pushed == "B")
       {
        ui->pushButton_B->setStyleSheet(styleSheet);
       }
       else if(pushed == "C")
       {
        ui->pushButton_C->setStyleSheet(styleSheet);
       }
       else if(pushed == "D")
       {
        ui->pushButton_D->setStyleSheet(styleSheet);
       }
       else if(pushed == "E")
       {
        ui->pushButton_E->setStyleSheet(styleSheet);
       }
       else if(pushed == "F")
       {
        ui->pushButton_F->setStyleSheet(styleSheet);
       }
       else if(pushed == "G")
       {
        ui->pushButton_G->setStyleSheet(styleSheet);
       }
       else if(pushed == "H")
       {
        ui->pushButton_H->setStyleSheet(styleSheet);
       }
       else if(pushed == "I")
       {
        ui->pushButton_I->setStyleSheet(styleSheet);
       }
       else if(pushed == "J")
       {
        ui->pushButton_J->setStyleSheet(styleSheet);
       }
       else if(pushed == "K")
       {
        ui->pushButton_K->setStyleSheet(styleSheet);
       }
       else if(pushed == "L")
       {
        ui->pushButton_L->setStyleSheet(styleSheet);
       }
       else if(pushed == "M")
       {
        ui->pushButton_M->setStyleSheet(styleSheet);
       }
       else if(pushed == "N")
       {
        ui->pushButton_N->setStyleSheet(styleSheet);
       }
       else if(pushed == "O")
       {
        ui->pushButton_O->setStyleSheet(styleSheet);
       }
       else if(pushed == "P")
       {
        ui->pushButton_P->setStyleSheet(styleSheet);
       }
       else if(pushed == "Q")
       {
        ui->pushButton_Q->setStyleSheet(styleSheet);
       }
       else if(pushed == "R")
       {
        ui->pushButton_R->setStyleSheet(styleSheet);
       }
       else if(pushed == "S")
       {
        ui->pushButton_S->setStyleSheet(styleSheet);
       }
       else if(pushed == "T")
       {
        ui->pushButton_T->setStyleSheet(styleSheet);
       }
       else if(pushed == "U")
       {
        ui->pushButton_U->setStyleSheet(styleSheet);
       }
       else if(pushed == "V")
       {
        ui->pushButton_V->setStyleSheet(styleSheet);
       }
       else if(pushed == "W")
       {
        ui->pushButton_W->setStyleSheet(styleSheet);
       }
       else if(pushed == "X")
       {
        ui->pushButton_X->setStyleSheet(styleSheet);
       }
       else if(pushed == "Y")
       {
        ui->pushButton_Y->setStyleSheet(styleSheet);
       }
       else if(pushed == "Z")
       {
        ui->pushButton_Z->setStyleSheet(styleSheet);
       }

       time = (7-incorrectunmber)+48 ;

        if(finish(labelTEXT,line.length()))
       {
           switch (OPTION)
           {
           case 0 :
                   ui->Word->setText(line);
                   break;
           case 1 :
                   ui->Word_2->setText(line);
                   break;

           case 2 :
                   ui->Word_3->setText(line);
                   break;

           case 3 :
                   ui->Word_4->setText(line);
                   break;
           }


               if(incorrectunmber != 8)
               {
                   QPixmap pix(":/tree/alive.jpg");
                   ui->image->setPixmap(pix);
                   ui->warning->setText(Username + " is going back to his work!");
                   ui->timeamount->setText("You win :)");
               }
               else
               {
               QPixmap tree(":/tree/deadpicture.png");
               ui->image->setPixmap(tree);
               ui->warning->setText(Username + " is Dead!");
               ui->timeamount->setText(" You lose ;(");
               }
        }

       else
       {
           switch (OPTION)
           {
           case 0 :
                   ui->Word->setText(labelTEXT);
                   break;
           case 1 :
                   ui->Word_2->setText(labelTEXT);
                   break;
           case 2 :
                  ui->Word_3->setText(labelTEXT);
                   break;
           case 3 :
                   ui->Word_4->setText(labelTEXT);
                   break;
           }

           ui->timeamount->setText(time+" chances left");

        //image connect
           switch(incorrectunmber)
           {
            case 1 :
           {
               QPixmap pix(":/tree/b0.jpg");
               ui->image->setPixmap(pix);
               break;
           }
           case 2:
           {
               QPixmap pix(":/tree/b1.jpg");
               ui->image->setPixmap(pix);
               break;
           }
           case 3:
           {
               QPixmap pix(":/tree/b2.jpg");
               ui->image->setPixmap(pix);
               break;
           }
           case 4:
           {
               QPixmap pix(":/tree/b3.jpg");
               ui->image->setPixmap(pix);
               break;
           }
           case 5:
           {
               QPixmap pix(":/tree/b4.jpg");
               ui->image->setPixmap(pix);

               break;
           }
           case 6:
           {
               QPixmap pix(":/tree/b5.jpg");
               ui->image->setPixmap(pix);
               break;
           }
           case 7:
           {
               QPixmap pix(":/tree/b6.jpg");
               ui->image->setPixmap(pix);
               break;
           }

           }
       }
}

void SecDialog::on_tabWidget_currentChanged(int index)
{

    ui->warning->setText("Hello, "+Username + " :)");
    //file opening and set the word in the text label
        switch (index)
        {
            case 0:
            {
                OPTION=0;
                HINTNUM=1;
                QString file1(":/FileList/FruitsName.txt");
                int randNum=rand()%69+1;
                Openfile(file1,randNum);

                vector<QChar> blank;
                letter_to_vector(line,blank);
                labelTEXT = "";

                for( auto ch : blank)
                {
                    labelTEXT += ch;
                }

                ui->Word->setText(labelTEXT);
                break;
            }
            case 1:
            {
                OPTION =1;
                HINTNUM=2;

                QString file2(":/FileList/AnimalNames.txt");
                int randNum=rand()%50+1;
                Openfile(file2,randNum);

                vector<QChar> blank;
                letter_to_vector(line,blank);
                labelTEXT = "";

                for( auto ch : blank)
                {
                    labelTEXT += ch;
                }

                ui->Word_2->setText(labelTEXT);
                break;
            }
            case 2:
            {
                OPTION=2;
                HINTNUM=3;
                QString file3(":/FileList/Movie.txt");
                int randNum=rand()%75+1;
                Openfile(file3,randNum);

                vector<QChar> blank;
                letter_to_vector(line,blank);
                labelTEXT = "";

                for( auto ch : blank)
                {
                    labelTEXT += ch;
                }

                ui->Word_3->setText(labelTEXT);
                break;
            }
            case 3:
            {
                OPTION=3;
                HINTNUM=4;

                QString file4(":/FileList/Protagonist.txt");
                int randNum=rand()%60+1;
                Openfile(file4,randNum);

                vector<QChar> blank;
                letter_to_vector(line,blank);
                labelTEXT = "";

                for( auto ch : blank)
                {
                    labelTEXT += ch;
                }

                ui->Word_4->setText(labelTEXT);
              break;
            }

        }
        QPixmap tree(":/tree/tree.jpg");
        ui->image->setPixmap(tree);
}

void SecDialog::letter_to_vector(QString selectedWord, vector<QChar>& blankgameWord)
{
    for(int index=0; index< selectedWord.length(); index++)
    {
        if(selectedWord[index]>=65 && selectedWord[index]<=90)
        {
           blankgameWord.push_back('#');
        }

        else
        {
            blankgameWord.push_back(selectedWord.at(index));
        }

    }
    blankgameWord.reserve(blankgameWord.size());

}

void SecDialog::Openfile (QString filename, int RandNum)
{
    QFile file(filename);
    if (! file.open(QIODevice::ReadOnly | QIODevice::Text))
        ui->Word->setText("File Opening Failed");

    QTextStream in(&file);

    int index = 0;

       while (!in.atEnd() && index<=RandNum)
       {
           line = in.readLine();
           index++;
       }

       file.close();

       for(int index = 0 ; index <line.length(); index++)
       {
           line[index]= line[index].toUpper();
       }

}

void SecDialog::sortNcount (QString word, int wordcount[], QChar wordArray[], int& used)
{
   int start = 0;
    used = 0 ;

    for (int i = 0 ; i< word.length() ; i++)
    {
        int position;
        position  = Search(start,wordArray,word[i], used);

        if( position >= 0)
        {
            wordcount[position]++;
        }
        else
        {
            wordArray[used] = word[i];
            wordcount[used] = 1;
            used++;
        }

    }
}
//This function will cound the actual position of the letter in the word.
int SecDialog::findPosition ( int& start, QString word, QString letter)
{
    for(int i = start ; i < word.length() ; i++)
    {
        if( word[i] == letter )
            return i;
    }
        return -1;
}
//This function find the position in word Array. the position is not actually position of the letter in the word.
int SecDialog::Search( int& start, QChar wordArray[], QChar letter, int& used)
{
    for(int i = start ; i < used ; i++)
    {
        if( wordArray[i] == letter )
            return i;
    }
    return -1;
}

void SecDialog::replace (int foundPosition,int start, QString& labelTEXT, QString word, int& count)
{
    if( foundPosition != -1)
    {
        labelTEXT[foundPosition] = word[foundPosition];
        ui->warning->setText("Correct word!");
    }

    else if ( foundPosition == -1 && start == 0)
    {
        ui->warning->setText("No maching letter exist in the word");
        count ++;
    }
}

bool SecDialog::finish (QString labelTEXT, int size)
{
    for(int i =0; i<size; i++)
    {
        if (labelTEXT[i] == '#' && incorrectunmber<=7)
        {
            return false;
        }
    }

   return true;
}


void SecDialog::on_restart_clicked()
{
    incorrectunmber = 0;
    hint = 0;

    ui->warning->setText("");
    ui->timeamount->setText("");

    QPixmap pix(":/tree/tree.jpg");
    ui->image->setPixmap(pix);

            ui->Word->setText("Choose a Category :)");

            ui->Word_2->setText("Choose a Category :)");

            ui->Word_3->setText("Choose a Category :)");

            ui->Word_4->setText("Choose a Category :)");


    QString styleSheet("color: white;\n background :rgb(172, 71, 226);\n "
                       "border: 2px solid white;\n border-radius: 20px;\n "
                       "font: 20pt \"Chalkboard\"; \n");

   // QPushButton *button = (QPushButton*)sender();

    ui->pushButton_A->setStyleSheet(styleSheet);
    ui->pushButton_B->setStyleSheet(styleSheet);
    ui->pushButton_C->setStyleSheet(styleSheet);
    ui->pushButton_D->setStyleSheet(styleSheet);
    ui->pushButton_E->setStyleSheet(styleSheet);
    ui->pushButton_F->setStyleSheet(styleSheet);
    ui->pushButton_G->setStyleSheet(styleSheet);
    ui->pushButton_H->setStyleSheet(styleSheet);
    ui->pushButton_I->setStyleSheet(styleSheet);
    ui->pushButton_J->setStyleSheet(styleSheet);
    ui->pushButton_K->setStyleSheet(styleSheet);
    ui->pushButton_L->setStyleSheet(styleSheet);
    ui->pushButton_M->setStyleSheet(styleSheet);
    ui->pushButton_N->setStyleSheet(styleSheet);
    ui->pushButton_O->setStyleSheet(styleSheet);
    ui->pushButton_P->setStyleSheet(styleSheet);
    ui->pushButton_Q->setStyleSheet(styleSheet);
    ui->pushButton_R->setStyleSheet(styleSheet);
    ui->pushButton_S->setStyleSheet(styleSheet);
    ui->pushButton_T->setStyleSheet(styleSheet);
    ui->pushButton_U->setStyleSheet(styleSheet);
    ui->pushButton_V->setStyleSheet(styleSheet);
    ui->pushButton_W->setStyleSheet(styleSheet);
    ui->pushButton_X->setStyleSheet(styleSheet);
    ui->pushButton_Y->setStyleSheet(styleSheet);
    ui->pushButton_Z->setStyleSheet(styleSheet);

}

