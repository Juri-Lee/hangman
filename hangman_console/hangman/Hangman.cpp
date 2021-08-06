//FINAL PROJECT - Hangman

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

int main_menu();
//Ask user to input their selection
//(1)is fruits, (2) is Animals, (3) is Movie characters, (4) is Movie
//return the number user insput <1-4>
void fileOpening (ifstream& instream, string fileName);
//Input file opening
//If input file opening failed. exit(1)
string RandomWord(int option, ifstream& instream);
//Random word selected from the file. The file is opened by user's input(option)
//Return selected word
int findPosition ( int& start, string word, char letter);
int Search( int& start, char wordArray[], char letter, int& used);
//find the position of the target letter in the selected word
//if find success, return the index. Else return -1
void input_letter(char& letter, char blankArr[], char wordarray[], int wordcount[],int used, int size);
void newline ( int num ,  istream& instream = cin );
//get newline from the input file up to num
void display (char blankArr[], int size);
//Display the blankArr, so that user can see what positons are filled and what positions are left
void replace (int index,int start, char blankArr[], string word, int& count);
void sortNcount (string word, int wordcount[], char wordArray[], int& used);
//save the letter count in two arrays.
void blank (int size, char blankArr[], string word);
//If there is space, ', or other sign which is not alphabet in the selected word, fill the blank array with the letters.
//EX) original word= ocean's eleven    then   fill the blankArr[5] = ''' & blankArr[6] = ' '
bool finish (char blankarray[], int size);
//Check the finish. If the blankarray is filled or user incorrect 8 times, this program will end.
//If the program considered finish, return true
//else return false
void hint (char letter, char blankArr[], string word, int size , int& hint, int option);
//When the user input the letter '?', then this function will oprate.
//this function fills one blank which is most front and unfilled blank.
//This funtion doesn't consider the amount of letter originally placed in the word. just display one letter
int main()
{
    const int MAXI_SIZE(50), INCORRECT(8);
    ifstream instream;
    string choosedWord;
    int wordcount[MAXI_SIZE] ={-1};
    int used_wordcount ;
    char blankArr[MAXI_SIZE]={0}, wordArray[MAXI_SIZE] = {0}, letter;
    const char LETTER_FOR_HINT ='?';
    int index = 0, count = 0, size = 0, option, hintnumber=0;
    
    srand(time(0));
    
    option = main_menu();
    choosedWord = RandomWord(option , instream);
    size = choosedWord.length();

   //  cout<< choosedWord<<endl;
    
    sortNcount (choosedWord,wordcount,wordArray, used_wordcount);
//    for(int i=0 ; i <used_wordcount ; i++)
//        cout<<wordArray[i] <<" "<<wordcount[i]<<endl;
    blank(size, blankArr,choosedWord);
    display (blankArr, size);
    
    do{
        input_letter(letter, blankArr, wordArray, wordcount, used_wordcount, size);
     
            if( letter != LETTER_FOR_HINT) //when the user input a letter a-z
            {
                    int start;
                    start = 0;
                do
                {
                    index = findPosition(start, choosedWord, letter);
                    replace(index,start, blankArr, choosedWord,count);
                    start = index +1;
                }while(index != -1);
                    display (blankArr, size);
            }
        
            else //When the user ask for hint
            {
                hint(letter, blankArr, choosedWord, size, hintnumber, option);
                display (blankArr, size);
            }
        
            if(count == INCORRECT) // when user wrong 8 times. program end with letting the user the answer.
            {
                cout<<"The word is <"<<choosedWord<<">."<<endl;
            }
        
        }while(finish(blankArr, size) == false && count <INCORRECT);
    
    return 0;
}

int main_menu()
{
    int option;
    
    cout<<"1. Fruits*"<<endl;
    cout<<"2. Animals **"<<endl;
    cout<<"3. Movie characters ***"<<endl;
    cout<<"4. Movie ****"<<endl;
    
    cout<<"Please choose an option : ";
    cin>>option;
    
    while( option<1 || option >4)
    {
        cout<<"Invalid input. Please input valid number : ";
        cin>> option;
    }
    
    return option ;
}

void fileOpening (ifstream& instream, string fileName)
{
    instream.open(fileName);
    
    if(instream.fail())
    {
        cout<<"Input file opening failed"<<endl;
        exit(1);
    }
}
 string RandomWord(int option, ifstream& instream)
{
    string word, number;
    int num;
    switch(option)
    {
        case 1:
            num = rand()%70;
            fileOpening(instream, "FruitsName.txt");
            newline(num, instream);
            instream>>number>>word;
            instream.close();
            break;
        case 2:
            num = rand()%50;
            fileOpening(instream, "AnimalNames.txt");
            newline(num, instream);
            instream>>number>>word;
            instream.close();
            break;
        case 3:
             num =rand()%60;
            fileOpening(instream, "Protagonist.txt");
            newline(num, instream);
            getline(instream,word);
            instream.close();
            break;
        case 4:
            num =rand()%75;
            fileOpening(instream, "Movie.txt");
            newline(num, instream);
            getline(instream, word);
            instream.close();
            break;
    }
    
    int size = word.length();
    
    for( int i = 0 ; i<size ; i++ )
    {
        word[i] = toupper(word[i]);
    }
    return word;
}

int findPosition ( int& start, string word, char letter)
{
    for(int i = start ; i < word.length() ; i++)
    {
        if( word[i] == letter )
            return i;
    }
        return -1;
}
int Search( int& start, char wordArray[], char letter, int& used)
{
    for(int i = start ; i < used ; i++)
    {
        if( wordArray[i] == letter )
            return i;
    }
    return -1;
}
void input_letter(char& letter, char blankArr[], char wordarray[], int wordcount[],int used, int size)
{
    int letterposition, start = 0;
    
    cout<<"Please input a letter: ";
    cin>>letter;
    letter = toupper(letter);
    
    do{
        
    letterposition = Search(start, wordarray, letter, used);
    if(letterposition>=0)
    {
        for(int i = 0; i <size ; i++)
        {
            if(blankArr[i] == letter)
            {
                wordcount[letterposition]--;
            }
        }
        
            if(wordcount[letterposition] <=0 && letter !='?')
            {
                cout<<"The letter already used at least one time"<<endl;
                cout<<"Please input a different letter: ";
                cin >> letter;
                letter = toupper(letter);
            }
            else
            {
                break;
            }
        }
        else if(letterposition == -1)
        {
            break;
        }
        
    }while(true);
}

void newline ( int num ,  istream& instream  )
{
    string word;
    for( int i = 0 ; i< num ; i++)
    {
        getline(instream, word);
        
    }
}

void display (char blankArr[], int size)
{
    for(int i = 0 ; i<size ; i++)
    {
        if(blankArr[i]==0)
        {
            cout<<setw(3)<<"__";
        }
        else
        {
            cout <<setw(3)<< blankArr[i];
        }
    }
    cout<<endl;
}

void replace (int index,int start, char blankArr[], string word, int& count)
{
    if( index != -1)
    blankArr[index] = word[index];
    else if ( index == -1 && start == 0)
    {
        cout<<"No maching word exist in the word"<<endl;
        count ++;
    }
}
void sortNcount (string word, int wordcount[], char wordArray[], int& used)
{
   int start = 0;
    used = 0 ;
    
    for (int i = 0 ; i< word.length() ; i++)
    {
        int position;
        position  = Search (start, wordArray, word[i], used);
        
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


void blank (int size, char blankArr[], string word)
{
    for(int i = 0 ; i<size ; i++)
    {
        if(word[i]<65 || word[i]>90)
        {
            blankArr[i] = word[i];
        }
    }
}
bool finish (char blankarray[], int size)
{
    for(int i =0; i<size; i++)
    {
        if (blankarray[i] == 0)
        {
            return false;
        }
    }
    
   return true;
}

void hint (char letter, char blankArr[], string word, int size , int& hint, int option)
{
    if(letter == '?' && hint<option)
    {
        for(int i = 0 ; i< size ; i++ )
        {
            if( blankArr[i] == 0)
            {
                blankArr[i] = word[i];
                break;
            }
        }
        hint++;
    }
   
    else if( hint == option)
        cout<<"No hint available anymore."<<endl;
}

/*
 1. Fruits*
 2. Animals **
 3. Movie characters ***
 4. Movie ****
 Please choose an option : 2
 __ __ __ __ __ __ __ __
 Please input a letter: A
 No maching word exist in the word
 __ __ __ __ __ __ __ __
 Please input a letter: k
 No maching word exist in the word
 __ __ __ __ __ __ __ __
 Please input a letter: ?
 M __ __ __ __ __ __ __
 Please input a letter: o
 M  O __ __  O  O __ __
 Please input a letter: s
 M  O __ __  O  O  S __
 Please input a letter: i
 No maching word exist in the word
 M  O __ __  O  O  S __
 Please input a letter: ?
 M  O  N __  O  O  S __
 Please input a letter: u
 No maching word exist in the word
 M  O  N __  O  O  S __
 Please input a letter: a
 No maching word exist in the word
 M  O  N __  O  O  S __
 Please input a letter: ?
 No hint available anymore.
 M  O  N __  O  O  S __
 Please input a letter: g
 M  O  N  G  O  O  S __
 Please input a letter: e
 M  O  N  G  O  O  S  E
 */

/*
 1. Fruits*
 2. Animals **
 3. Movie characters ***
 4. Movie ****
 Please choose an option : 3
 __ __ __ __ __    __ __ __ __ __
 Please input a letter: h
 No maching word exist in the word
 __ __ __ __ __    __ __ __ __ __
 Please input a letter: a
 __ __ __ __ __    __ __ __ __  A
 Please input a letter: ?
 W __ __ __ __    __ __ __ __  A
 Please input a letter: i
 W  I __ __ __    __ __ __ __  A
 Please input a letter: l
 W  I  L  L __    __ __ __ __  A
 Please input a letter: e
 No maching word exist in the word
 W  I  L  L __    __ __ __ __  A
 Please input a letter: ?
 W  I  L  L  Y    __ __ __ __  A
 Please input a letter: w
 The letter already used at least one time
 Please input a different letter: ?
 W  I  L  L  Y     W __ __ __  A
 Please input a letter: o
 W  I  L  L  Y     W  O __ __  A
 Please input a letter: n
 W  I  L  L  Y     W  O  N __  A
 Please input a letter: k
 W  I  L  L  Y     W  O  N  K  A
 Program ended with exit code: 0
 */

