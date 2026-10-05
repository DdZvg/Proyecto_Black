#pragma once

#include <iostream>
#include <string>
using namespace std;

class blackJackGame
{
private:
	int playerScore;
	int dealerScore;
	int playerWins;
	int dealerWins;
	int ties;
	string playerName;
	int numero;

public:
	blackJackGame();
	void playGame();
	void displayScores();
	void resetScores();
	void delearScore();

};

