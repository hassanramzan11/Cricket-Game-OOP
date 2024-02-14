#include"Team.h"
#include<string>
using namespace std;
//Default Constructor 
Team::Team() {
		for (int i = 0; i < 11; i++) {
				teamMembers[i].playerName = " ";
		}
		teamId = 0;
		numberOfWickets = 10;
		balls = 18;
		score = 0;
}

//Static player on strike
int Team::currentPlayer;

// Adding Players
void Team::addPlayerName(int index, string name) {
		teamMembers[index].playerName = name;
		teamMembers[index].playerID = index + 1;
}

// Get Player
string Team::getPlayerName(int index) const {
		return teamMembers[index].playerName;
}

//Modify Order
void Team::modifyOrder(int i, int j) {
		string temp = teamMembers[i].playerName;
		teamMembers[i].playerName =teamMembers[j].playerName;
		teamMembers[j].playerName = temp;
}

// Displaying team members
void Team::displayTeam() {
		for (int i = 0; i < 11; i++) {
				cout << "Player " << i + 1 << ". " << teamMembers[i].playerName << endl;
		}
}

//Decrement number of wickets when out 
void Team::out() {
		numberOfWickets--;
		currentPlayer++;
}

// Set team id
void Team::setTeamId(int id) {
		teamId = id;
}

// Decreament in balls when it is a fair delivery
void Team::fairBall() {
		balls--;
}

//Set score
void Team::setScore(int scor) {
		score += scor;
		teamMembers[currentPlayer].playerScore += scor;
}

// Get Score
int Team::getScore() const {
		return score;
}

//Get Player Score
int Team::getPlayerScore() const {
		return teamMembers[currentPlayer].playerScore;
}
//Get current Player name
string Team::getCurrentPlayerName() const {
		return teamMembers[currentPlayer].playerName;
}


//Get Balls
int Team::getBalls() const {
		return balls;
}

// When it is a wide
void Team::wide() {
		score++;
}

//No ball
void Team::noBall(int scor) {
		score++;
		score += scor;
		teamMembers[currentPlayer].playerScore += scor;
}

// Status Win
int Team::winStatus(int oponentScore) {
		if (oponentScore > score) {
				statusWin = 0;
		}
		else if(oponentScore < score){
				statusWin = 1;
		}
		else {
				statusWin = 2;
		}
		return statusWin;
}

// Wickets
int Team::getWickets() const {
		return numberOfWickets;
}
