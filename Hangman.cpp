// Hangman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Allen.h" //My useful library
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

string usedWords[];
bool usedLetters[26];
char underscores[15];


﻿bool checkIfAlpha(char value)
{
    if ((value >= 65) &&
        (value <= 90))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printUsedLetters()
{
    char print = ' ';

    for (int i = 0; i < 26; i++)
    {
        if (usedLetters[i] == true)
        {
            print = (char)(i + 65);
            cout << print;
            cout << " ";
        }
    }

    cout << "\n";
}

void printWelcomeMessage() //PRINTS WELCOME MESSAGE
{
	cout << "Welcome To Hangman v 1.0 . . . \n\n";
}

void printDirections() //PRINTS DIRECTIONS
{
	cout << "\nThis Program Will Randomly Select A Word.\n";
	cout << "You Will Guess Letters To Try And Solve The Word.\n";
	cout << "You Can Only Have 6 Wrong Guesses.\n";
	cout << "Good Luck!\n\n";
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

char getUserGuess() //GETS USER GUESS
{
	writeLine("");
	writeLine("Please enter your guess:");
	char guess = inputFirstOne();
	return guess;
}

void initializeUnderscores(int length) //INITIALIZES UNDERSCORES
{
	for (int i = 0; i < length; i++)
	{
		underscores[i] = '_';
	}
}

void printUnderscores(int length) //PRINTS UNDERSCORES ON THE CONSOLE WINDOW
{

	for (int i = 0; i < length; i++)
	{
		write(underscores[i]);
		write(" ");
	}

	writeLine("");
}

bool checkWord(string selectedWord) //CHECKS IF WORD HAS BEEN GUESSED
{
	bool isGuessed = true;

	for (int i = 0; i < selectedWord.size(); i++)
	{
		if (underscores[i] == '_')
		{
			isGuessed = false;
		}
	}

	return isGuessed;
}

void addLimbsForWrongGuess(int guessCount) //ADDS LIMBS FOR EACH WRONG GUESS
{
	if (guessCount == 1)
	{
		cout << "       " << endl;
		cout << "       " << endl;
		cout << "   \\  " << endl;

	}
	else if (guessCount == 2)
	{
		cout << "       " << endl;
		cout << "       " << endl;
		cout << " / \\  " << endl;
	}
	else if (guessCount == 3)
	{
		cout << "       " << endl;
		cout << "  |   " << endl;
		cout << " / \\  " << endl;
	}
	else if (guessCount == 4)
	{
		cout << "       " << endl;
		cout << " /|   " << endl;
		cout << " / \\  " << endl;
	}
	else if (guessCount == 5)
	{
		cout << "       " << endl;
		cout << " /|\\ " << endl;
		cout << " / \\  " << endl;
	}
	else if (guessCount == 6)
	{
		cout << "  O   " << endl;
		cout << " /|\\ " << endl;
		cout << " / \\  " << endl;
	}
}


void hangman() //HANGMAN GAME
{
	int boolIndex = 0;
	char userGuess = ' ';
	bool usedGuess = false;
	bool isCompleteGuessed = false;
        bool letIsAlpha = false;
	int numOfGuesses = 0;
	int numWrong = 0;
	int userDumbOrSmart;

        

	printWelcomeMessage(); //PRINTS WELCOME MESSAGE

	cout << "Please Enter 1 To View Directions, Or Enter 2 To Skip . . . \n"; //PROMPTS FOR DIRECTIONS, ERROR CHECKS
	userDumbOrSmart = inputFirstOne();

	while ((userDumbOrSmart != '1') && (userDumbOrSmart != '2'))
	{
		cout << "\nYour Entry Is Not Valid, Try Again . . . \n";
		userDumbOrSmart = inputFirstOne();
	}

	if (userDumbOrSmart == '1')
	{
		printDirections(); //PRINTS OPTIONAL DIRECTIONS FOR USER	
	}
	else if(userDumbOrSmart == '2')
	{
		cout << "\nSkipping Directions . . . \n";
	}

	string selectedWord = selectRandomWord(); //GETS RANDOM WORD
	int length = selectedWord.size(); //GETS LENGTH OF SELECTED WORD
	selectedWord = toUpper(selectedWord); // MAKE IT ALL CAPS, for failsafe

	initializeUnderscores(length);

	while ((!isCompleteGuessed) &&
		(numWrong < 6))
	{
		usedGuess = false;

		printUnderscores(length);

		userGuess = getUserGuess();
                userGuess = toUpper(userGuess);
		
	        boolIndex = ((int)userGuess - 65);
                letIsAlpha = checkIfAlpha(userGuess);

                while ((letIsAlpha) && //ERROR CHECKING TO MAKE SURE THE ENTRY IS A LETTER AND NOT USED
                       (usedLetters[boolIndex]))
                {
                    if (letIsAlpha)
                    {
                        cout << "\nYou Must Enter A Letter That Has Not Been Used . . .\n";
                    }
                    else
                    {
                        cout << "\nYou Must Enter A Letter From A - Z . . .\n";
                    }

                    userGuess = getUserGuess();
                    userGuess = toUpper(userGuess);
                    boolIndex = ((int)userGuess - 65);
		}

		numOfGuesses = numOfGuesses + 1;

		userGuess = toUpper(userGuess);
		boolIndex = ((int)userGuess - 65 ); //Convert char to int, use ASCII for index number

                cout << "\n\nUsed Letters:\n";
                cout << "-----------------\n";
                usedLetters[boolIndex] = true;
                printUsedLetters();

		for (int i = 0; i < length; i++)
		{
			if (userGuess == selectedWord[i])
			{
				underscores[i] = userGuess;
				usedGuess = true;
			}
		}

                if (!usedGuess)
                {
                    numWrong++;
		    addLimbsForWrongGuess(numWrong);
		}

		isCompleteGuessed = checkWord(selectedWord);
	}

}

void playAgain()
{
    bool playOnceMore = false;
    char answer = ' ';

    cout << "Would you like to play again (Y/N)?\n";
    answer = inputFirstOne();
    answer = toUpper(answer);

    while ((answer != 'Y') && (answer != 'N'))
    {
        cout << "I'm sorry, i did not undersand.\n";
        cout << "\nWould you like to play again (Y/N)?\n";
        answer = inputFirstOne();
        answer = toUpper(answer);
    }

    if (answer == 'Y')
    {
        hangman();
    }
    else
    {
        cout << "\nThanks For Playing!!";
    }
}

int main()
{
	hangman();
        playAgain();

	return 0;
}
