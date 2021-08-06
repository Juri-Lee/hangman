#ifndef SECDIALOG_H
#define SECDIALOG_H
#include <QDialog>
#include <QFileDialog>
#include <QDebug>
#include <vector>


using namespace  std;

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

private slots:

    void on_exit_clicked();
    //connect to the message box, so that the box user ask to exit

    void letter_pressed();
    //letter checked position and replace, return images or warning in the label

    //void SecDialog::letter_changed();

    void hint_pressed();
    //When the user input the letter "hint", then this function will oprate.
    //this function fills one # which is most front and unfilled blank.
    //This funtion doesn't consider the amount of letter originally placed in the word. just display one letter

    void on_tabWidget_currentChanged(int index);
    //generated random word and save in the variable
    //index 0 : fruits, index 1: animals, index2 : movies, index 3: movie characters

    void letter_to_vector(QString selectedWord, vector<QChar>& blankgameWord);
    //Change selected word to vector

    void Openfile (QString filename, int RandNum);
    //Input file opening
    //If input file opening failed. exit(1)

    void sortNcount (QString word, int wordcount[], QChar wordArray[], int& used);
    //save the letter count in two arrays.

    int Search( int& start, QChar wordArray[], QChar letter, int& used);
    //find the position of the target letter in the selected word
    //if find success, return the index. Else return -1
    //This function find the position in word Array. the position is not actually position of the letter in the word.

    bool finish (QString labelTEXT, int size);
    //Check the finish. If the blankarray is filled or user incorrect 8 times, this program will end.
    //If the program considered finish, return true
    //else return false

    void replace (int index,int start, QString& labelTEXT, QString word, int& count);
    //replace the letter with found position(index)

    int findPosition ( int& start, QString word, QString letter);
    //find the inputted letter from start until the letter was founded
    //if there is letter, return index
    //if there is no letter, return -1
    //This function will cound the actual position of the letter in the word.

    void on_restart_clicked();
    //reset the value of hint, incorrect number and return push button color


private:
    Ui::SecDialog *ui;
};

#endif // SECDIALOG_H
