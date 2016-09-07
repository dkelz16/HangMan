// Hangman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Allen.h" //My useful library
#include <string>
#include <iostream>
using namespace std;

string wordBank[] = { "Joiner", "Network", "Object", "Programming" };
string usedWords[];
bool usedLetters[26];
char underscores[15];

void printDirections()
{
	string moo = "MOO";
	moo = toLower(moo);
}

char getUserGuess()
{
	writeLine("");
	writeLine("Please enter your guess:");
	char guess = getchar();
	return guess;
}

void initializeUnderscores(int length)
{
	for (int i = 0; i < length; i++)
	{
		underscores[i] = '_';
	}
}

void printUnderscores(int length)
{

	for (int i = 0; i < length; i++)
	{
		write(underscores[i]);
		write(" ");
	}

	writeLine("");
}

bool checkWord(string selectedWord)
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

void hangman()
{
	int boolIndex = 0;
	char userGuess = ' ';
	bool usedGuess = false;
	bool isCompleteGuessed = false;
	int numOfGuesses = 0;

	//print welcome message
	printDirections();

	string selectedWord = wordBank[1]; //WILL ADD RANDOM NUMBER for this later...
	int length = selectedWord.size();
	selectedWord = toUpper(selectedWord); // MAKE IT ALL CAPS, for failsafe

	writeLine(selectedWord); //SOMEWHERE ABOUT HERE IT MESSES UP? LOL


	initializeUnderscores(length);

	while ((!isCompleteGuessed) ||
		   (numOfGuesses < 6))
	{
		usedGuess = false;

		printUnderscores(length);

		userGuess = getUserGuess();
		numOfGuesses = numOfGuesses + 1;
		
		writeLine(toUpper("Joiner"));
		writeLine(numOfGuesses);

		userGuess = toUpper(userGuess);
		boolIndex = ((int)userGuess - 97); //Convert char to int, use ASCII for index number

		for (int i = 0; i < length; i++)
		{
			if (userGuess == selectedWord[i])
			{
				underscores[i] = userGuess;
				usedGuess = true;
			}
		}

		isCompleteGuessed = checkWord(selectedWord);
	}

}

int main()
{
	hangman();
    return 0;
}
