// learncpp Chapter2Quiz balldrop 20180521.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "constants.h"

using namespace std;

void intro()
{
	cout << "learncpp.com\nLearn C++ dot com Chapter 2 Quiz\nProblem #4\n";
	cout << "v20180521.1\n\n";
	cout << "\tWrite a program that accounts for the motion of a ball in freefall.\n";
	cout << "\tAcceleration due to gravity is 9.8 meters per second squared.\n";
	cout << "\tStore 9.8 in a symbolic constant in a namespace called \'myConstants\' in a header file called constants.h\n";
	cout << "\tThe user will give the program the initial height where the ball is dropped from.\n";
	cout << "\tThe program should give the position at second 1, 2, 3, 4, and 5.  Do not allow the ball to drop below 0.\n";
	cout << "\tUSEFUL FORMULA: distance fallen == (gravity constant * (# of seconds)^2) / 2\n";
}

double askHeight()
{
	double height{ 0 };
	cout << "\nFrom how high, in meters, does the ball start falling?\n";
	cout << "Please type the initial height:\n";
	cin >> height;
	cout << endl;
	return height;
}

//calculates position after falling a given number of seconds
double position(double time)
{
	return constants::gravity * time * time / 2;
}

//outputs the position of the ball in meters from the ground for each time value in seconds
void falling(double h)
{
	cout << "Starting at a height of " << h << " meters, the ball starts falling at " << constants::gravity << " meters per second squared.\n";
	double time{ 1 };
	while (h > 0)
	{
		h = h - position(time); //use funtion 'position' to solve for height change after a given time
		if (h > 0) 
		{ 
			cout << "At time = " << time << " seconds, the ball is " << h << " meters high.\n"; 
			time = time + 1;
		}
	}
	cout << "The object is on the ground after " << time << " seconds.\n";
}

int main()
{
	intro();
	falling(askHeight());
    return 0;
}

