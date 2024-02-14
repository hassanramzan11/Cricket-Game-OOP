#pragma once
#include<iostream>
#include<string>
using namespace std;

class Player {
		int playerScore;
		int playerID;
		string playerName;
public:
		friend class Team;
		Player();
		void setPlayerName(string name);
		string getPlayerName() const;
		void setPlayerId(int id);
		int getPlayerId() const;
		void setScore(int scor);
		int getScore() const;
};