#include"Player.h"
#include<iostream>
using namespace std;
Player::Player() {
		playerID = 0;
		playerScore = 0;
}

void Player::setPlayerName(string name) {
		playerName = name;
}

string Player::getPlayerName() const {
		return playerName;
}

void Player::setPlayerId(int id) {
		playerID = id;
}

int Player::getPlayerId() const {
		return playerID;
}

void Player::setScore(int scor) {
		playerScore = scor;
}

int Player::getScore() const {
		return playerScore;
}