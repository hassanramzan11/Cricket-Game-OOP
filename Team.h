#pragma once
#include<iostream>
#include"Player.h"
#include <string>
using namespace std;
class Team {
		Player teamMembers[11];
		int score;
		int teamId;
		int numberOfWickets;
		int balls;
		int playerScore;
		int statusWin;
		static int currentPlayer;
public:
		Team();
		void out();
		void setTeamId(int id);
		void fairBall();
		void wide();
		void noBall(int scor);
		void setScore(int scor);
		int getScore() const;
		int getBalls() const;
		int getPlayerScore() const;
		int getWickets() const;
		void addPlayerName(int index, string name);
		string getPlayerName(int index) const;
		string getCurrentPlayerName() const;
		void modifyOrder(int i, int j);
		void displayTeam();
		int winStatus(int oponentScore);
};