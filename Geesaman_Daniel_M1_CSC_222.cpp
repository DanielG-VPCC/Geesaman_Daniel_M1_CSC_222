#include <iostream>
#include <string>
#include <random>
#include <time.h>
using namespace std;

int computerMove();
int userMove();
int resultsOfGame(int Guess, int CPU);

int main()
{
	int gamesPlayed = 0;
	string names[3] = { "Daniel", "Dave", "Mark" };
	int UserWins = 0;
	int ComputerWins = 0;
	char keepPlaying;
	int winner;

	while (true)
	{
		gamesPlayed++;
		int CPU = computerMove();
		int Guess = userMove();

		while (Guess == CPU)
		{
			cout << "Tie! Must go again to determine a winner." << endl;
			CPU = computerMove();
			Guess = userMove();
		}
		winner = resultsOfGame(Guess, CPU);
		if (winner == 2)
		{
			UserWins++;
		}
		else
		{
			ComputerWins++;
		}
		cout << endl << endl << "would you like to play again? (y or n)" << endl;
		cin >> keepPlaying;
		while (keepPlaying == 'n')
		{
			cout << "user won " << UserWins << " times." << endl << "computer won " << ComputerWins << " times.";
			return false;
		}
	}
}


//random number engine
int computerMove()
{
	int CPU;
	srand(time(NULL));
	CPU = 1 + (rand() % 3);
	return CPU;
}

//user input choice
int userMove()
{
	int Guess;
	cout << "1. Rock" << endl << "2. Paper" << endl << "3. Scissors" << endl;
	cin >> Guess;
	while (Guess < 1 || Guess > 3)
	{
		cout << "Please make a valid selection. " << endl << endl;
		cout << "1. Rock, 2. Paper, 3. Scissors" << endl;
		cin >> Guess;
	}
	return Guess;
}

/*
1. ROCK
2. PAPER
3. SCISSORS
*/

int resultsOfGame(int Guess, int CPU)
{
	if (Guess == 1 && CPU == 2)
	{
		cout << "User played rock, computer played paper." << endl << "Computer wins!";
		return 1;
	}
	else if (Guess == 1 && CPU == 3)
	{
		cout << "User played rock, computer played scissors." << endl << "User wins!";
		return 2;
	}
	else if (Guess == 2 && CPU == 3)
	{
		cout << "User played paper, computer played scissors." << endl << "Computer wins!";
		return 1;
	}
	else if (Guess == 2 && CPU == 1)
	{
		cout << "User played paper, computer played rock." << endl << "User wins!";
		return 2;
	}
	else if (Guess == 3 && CPU == 1)
	{
		cout << "User played scissors, computer played rock." << endl << "Computer wins!";
		return 1;
	}
	else if (Guess == 3 && CPU == 2)
	{
		cout << "User played scissors, computer played paper." << endl << "User wins!";
		return 2;
	}
}
