#pragma once

#include <iostream>
#include <string>

using namespace std;

void writeLine(string value)
{
	cout << value << "\n";
}

void writeLine(char value)
{
	cout << value << "\n";
}

void writeLine(int value)
{
	cout << value << "\n";
}

void writeLine(double value)
{
	cout << value << "\n";
}

void write(string value)
{
	cout << value;
}

void write(char value)
{
	cout << value;
}

void write(int value)
{
	cout << value;
}

void write(double value)
{
	cout << value;
}

string toLower(string value)
{
	for (int i = 0; i <= value.size(); i++)
	{
		if (((int)value[i] >= 65) &&
			((int)value[i] <= 90))
		{
			value[i] = (char)((int)value[i] + 32);
		}
	}

	return value;
}

string upperCaseFirst(string value)
{
	for (int i = 0; i < value.size(); i++)
	{
		if (i == 0)
		{
			if (((int)value[i] >= 97) &&
				((int)value[i] <= 112))
			{
				value[i] = (char)((int)value[i] - 32);
			}
		}
	}

	return value;
}

string toUpper(string value)
{
	for (int i = 0; i < value.size(); i++)
	{
		if (((int)value[i] >= 97) &&
			((int)value[i] <= 112))
		{
			value[i] = (char)((int)value[i] - 32);
		}
	}

	return value;
}

char toLower(char value)
{
	if (((int)value >= 65) &&
		((int)value <= 90))
	{
		value = (char)((int)value + 32);
	}

	return value;
}

char toUpper(char value)
{
	if (((int)value >= 97) &&
		((int)value <= 112))
	{
		value = (char)((int)value - 32);
	}
	
	return value;
}
