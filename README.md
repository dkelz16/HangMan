# HangMan
C++ Team Program

// Hangman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Allen.h"
#include <string>
#include <iostream>
using namespace std;

string wordBank[] = { "Joiner", "Network", "Object", "Programming" };
string usedWords[];
bool usedLetters[26];
char underscores[15];

void printWelcomeMessage() //PRINTS WELCOME MESSAGE
{
    cout << "Welcome To Hangman v 1.0 . . . \n";
}

void printDirections()
{
    string moo = "MOO";
    moo = toLower(moo);
}

void createListOfWords() //CREATES A WORDBANK
{
    string listOfWords[6]{ "Programming", "Joiner", "Network", "Object", "Method", "Vector" };
}

string selectRandomWord() //RANDOMLY SELECTS A WORD FROM THE WORDBANK
{
    string randomWord;
    int randomNum;

    srand(time(0));
    randomNum = rand() % 6 + 1;

    if (randomNum == 1)
    {
        randomWord = "Programming";
    }
    else if (randomNum == 2)
    {
        randomWord = "Joiner";
    }
    else if (randomNum == 3)
    {
        randomWord = "Network";
    }
    else if (randomNum == 4)
    {
        randomWord = "Object";
    }
    else if (randomNum == 5)
    {
        randomWord = "Method";
    }
    else if (randomNum == 6)
    {
        randomWord = "Vector";
    }
    else
    {
        cout << "This Should Ever Appear . . .";
    }

    return randomWord;
}

char getUserGuess()
{
    writeLine("");
    writeLine("Please enter your guess:");
    char guess = getchar();
    return guess;
}

void printUnderscores(int length)
{

    for (int i = 0; i < length; i++)
    {
        underscores[i] = '_';
    }

    for (int i = 0; i < length; i++)
    {
        if (underscores[i] == '_')
        {
            write(underscores[i]);
            write(" ");
        }
    }

    writeLine("");
}


void addLimbsForWrongGuess(int guessCount)
{
    if (guessCount == 1)
    {
        cout << "       " << endl;
        cout << "       " << endl;
        cout << "    \  " << endl;

    }
    else if (guessCount == 2)
    {
        cout << "       " << endl;
        cout << "       " << endl;
        cout << "  / \  " << endl;
    }
    else if (guessCount == 3)
    {
        cout << "       " << endl;
        cout << "   |   " << endl;
        cout << "  / \  " << endl;
    }
    else if (guessCount == 4)
    {
        cout << "       " << endl;
        cout << " / |   " << endl;
        cout << "  / \  " << endl;
    }
    else if (guessCount == 5)
    {
        cout << "       " << endl;
        cout << " / | \ " << endl;
        cout << "  / \  " << endl;
    }
    else if (guessCount == 6)
    {
        cout << "   O   " << endl;
        cout << " / | \ " << endl;
        cout << "  / \  " << endl;
    }
}

void hangman()
{
    int boolIndex = 0;
    int wrongGuessCount = 0; //TRACKS WRONG GUESSES
    

    printWelcomeMessage(); //PRINTS WELCOME MESSAGE
    
    printDirections(); //OPTIONAL PRINT DIRECTIONS

    string selectedWord = selectRandomWord(); //SELECTS RANDOM WORD FROM WORD BANK 
    int length = selectedWord.size(); // FIGURES OUT THE LENGTH OF THE WORD

    INSERT WHILE LOOP HERE  ( while guessCount < 6)

    printUnderscores(length);

    char userGuess = getUserGuess();
    wrongGuessCount++; // < ----- ADDED
    userGuess = toUpper(userGuess);

    boolIndex = ((int)userGuess - 97); //Convert char to int, use ASCII for index number

    if(BOOL == false)
    {
        addLimbsForWrongGuess(wrongGuessCount); //←- ADDED
    }


}

int main()
{
    hangman();
    return 0;
}


