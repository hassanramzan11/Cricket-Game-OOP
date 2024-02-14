#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include"Team.h"
using namespace std;

// Function Batting
void batting(Team &team) {
		system("CLS");
		cout << "Batting...\n";
		int ifStrike;
		int score;
		do {
				system("CLS");
				const int distanceV = 50;
				int enteredDistanceV;
				enteredDistanceV = (rand() % 45) + 40;
				const int distanceH = 20;
				int enteredDistanceH;
				enteredDistanceH = (rand() % 20) + 5;
				const int height = 10;
				int enteredHeight;
				enteredHeight = (rand() % 16);
				int enteredAngleOfDeviation;
				enteredAngleOfDeviation = (rand() % 10);
				// Labelling Ball	
				string ballLabel;
				if (enteredDistanceV < distanceV) {
						ballLabel = "noball";
				}
				else if (enteredDistanceH > distanceH) {
						ballLabel = "wide";
				}
				else if (enteredHeight > height) {
						ballLabel = "bouncer";
				}
				else if (enteredAngleOfDeviation > 5) {
						ballLabel = "spin";
				}
				else {
						ballLabel = "normal";
				}
				cout << "Player on Strike: " << team.getCurrentPlayerName() << endl;
				cout << "Do you want to to strike the ball or not\n";
				cout << "1.Strike\n2.Not Strike\n";
				cin >> ifStrike;
				int outCon = rand() % 10;
				// If batsman strikes
				if (ifStrike == 1) {
						if (ballLabel != "noball" && outCon == 5) {
								cout << "That's in the air and caught.\n";
								team.out();
								team.fairBall();
						}
						else if (ballLabel == "noball") {
								cout << "That's a No ball\n";
								score = (rand() % 2 + 2) * 2;
								cout << score << " runs\n";
								team.noBall(score);
						}
						else if (ballLabel == "wide") {
								cout << "That was a wide ball\n";
								cout << "4 runs\n";
								team.setScore(4);
								team.fairBall();
						}
						else if (ballLabel == "bouncer") {
								cout << "Wow That's a great bouncer\n";
								cout << "6 runs\n";
								team.setScore(6);
								team.fairBall();
						}
						else if (ballLabel == "spin") {
								cout << "It's a great spin delivery\n";
								do {
										score = rand() % 7;
								} while (score == 3 || score == 5);
								cout << score << " runs\n";
								team.setScore(score);
								team.fairBall();
						}
						else {
								cout << "That's a straight delivery\n";
								team.setScore(4);
								team.fairBall();
						}
				}
				// If batsman does not strikes
				else {
						if (ballLabel != "noball" && outCon == 5) {
								cout << "That's Hit wicket.\n";
								team.out();
								team.fairBall();
						}
						else if (ballLabel == "noball") {
								cout << "That's a No ball\n";
								cout << "1 score added to team\n";
								team.noBall(0);
						}
						else if (ballLabel == "wide") {
								cout << "Wide ball\n";
								cout << "1 score added to team\n";
								team.wide();
						}
						else if (ballLabel == "bouncer") {
								cout << "Wow That's a great bouncer\n";
								cout << "0 score added to team\n";
								team.setScore(0);
								team.fairBall();
						}
						else if (ballLabel == "spin") {
								cout << "It's a great spin delivery\n";
								cout << "0 score added to team\n";
								team.setScore(0);
								team.fairBall();
						}
						else {
								cout << "That's a straight delivery\n";
								team.setScore(0);
								team.fairBall();
						}
				}
				cout << "Team Score: " << team.getScore() << endl;
				cout << "Player Score: " << team.getPlayerScore() << endl;
				cout << "Number of wickets remaining: " << team.getWickets() << endl;
				cout << "Number of balls remaining: " << team.getBalls() << endl;
				if (team.getBalls() % 6 == 0 && ballLabel != "noball") {
						if (ballLabel == "wide" && ifStrike == 1)
								cout << "Thats the end of the over\n";
						else if (ballLabel != "wide")
								cout << "Thats the end of the over\n";
				}
				system("pause");
		} while (team.getBalls() != 0 && team.getWickets() != 0);
		// End of innings
		system("CLS");
		cout << "--------------Score board----------------" << endl;
		cout << "Team Total Score: " << team.getScore() << endl;
		score = (rand() % team.getScore()) + 2;
		cout << "opponents Score: " << score << endl;
		int win = team.winStatus(score);
		if (win == 0) {
				cout << "You lost the match\n";
		}
		else if (win == 1) {
				cout << "Congratulations!!! You won the match\n";
		}
		else {
				cout << "Match drawn!!!\n";
		}
}


//Function Bowling
void bowling(Team &team) {
		system("CLS");
		cout << "Bowling...\n";
		int ifStrike;
		int score;
		do {
				system("CLS");
				int bowler = 10;
				cout << "Current Bowler: " << team.getPlayerName(bowler) << endl;
				const int distanceV = 50;
				int enteredDistanceV;
				cout << "Enter Distance_V: ";
				cin >> enteredDistanceV;
				const int distanceH = 20;
				int enteredDistanceH;
				cout << "Enter Distance_H: ";
				cin >> enteredDistanceH;
				const int height = 10;
				int enteredHeight;
				cout << "Enter Height: ";
				cin >> enteredHeight;
				int enteredAngleOfDeviation;
				cout << "Enter angle of deviation: ";
				cin >> enteredAngleOfDeviation ;
				string ballLabel;
				if (enteredDistanceV < distanceV) {
						ballLabel = "noball";
				}
				else if (enteredDistanceH > distanceH) {
						ballLabel = "wide";
				}
				else if (enteredHeight > height) {
						ballLabel = "bouncer";
				}
				else if (enteredAngleOfDeviation > 5) {
						ballLabel = "spin";
				}
				else {
						ballLabel = "normal";
				}
				int outCon = rand() % 10;
				ifStrike = rand() % 2 + 1;
				// If batsman strikes
				if (ifStrike == 1) {
						if (ballLabel != "noball" && outCon == 5) {
								cout << "That's in the air and caught.\n";
								team.out();
								team.fairBall();
						}
						else if (ballLabel == "noball") {
								cout << "That's a No ball\n";
								score = (rand() % 2 + 2) * 2;
								cout << score << " runs\n";
								team.noBall(score);
						}
						else if (ballLabel == "wide") {
								cout << "That was a wide ball\n";
								cout << "4 runs\n";
								team.setScore(4);
								team.fairBall();
						}
						else if (ballLabel == "bouncer") {
								cout << "Wow Tha's a great bouncer\n";
								cout << "6 runs\n";
								team.setScore(6);
								team.fairBall();
						}
						else if (ballLabel == "spin") {
								cout << "It's a great spin delivery\n";
								do {
										score = rand() % 7;
								} while (score == 3 || score == 5);
								cout << score << " runs\n";
								team.setScore(score);
								team.fairBall();
						}
						else {
								cout << "That's a straight delivery\n";
								team.setScore(4);
								team.fairBall();
						}
				}
				// if batsman does not strike
				else {
						if (ballLabel != "noball" && outCon == 5) {
								cout << "That's Hit wicket.\n";
								team.out();
								team.fairBall();
						}
						else if (ballLabel == "noball") {
								cout << "That's a No ball\n";
								cout << "1 score added to team\n";
								team.noBall(0);
						}
						else if (ballLabel == "wide") {
								cout << "Wide ball\n";
								cout << "1 score added to team\n";
								team.wide();
						}
						else if (ballLabel == "bouncer") {
								cout << "Wow That's a great bouncer\n";
								cout << "0 score added to team\n";
								team.setScore(0);
								team.fairBall();
						}
						else if (ballLabel == "spin") {
								cout << "It's a great spin delivery\n";
								cout << "0 score added to team\n";
								team.setScore(0);
								team.fairBall();
						}
						else {
								cout << "That's a straight delivery\n";
								team.setScore(0);
								team.fairBall();
						}
				}
				cout << "Team Score: " << team.getScore() << endl;
				cout << "Player Score: " << team.getPlayerScore() << endl;
				cout << "Number of wickets remaining: " << team.getWickets() << endl;
				cout << "Number of balls remaining: " << team.getBalls() << endl;
				if (team.getBalls() % 6 == 0 && ballLabel != "noball") {
						if (ballLabel == "wide" && ifStrike == 1) {
								cout << "Thats the end of the over\n";
								bowler--;
						}
						else if (ballLabel != "wide") {
								cout << "Thats the end of the over\n";
								bowler--;
						}
				}
				system("pause");
		} while (team.getBalls() != 0 && team.getWickets() != 0);
		system("CLS");
		cout << "--------------Score board----------------" << endl;
		cout << "Opponent team Total Score: " << team.getScore() << endl;
		score = (rand() % team.getScore()) + 2;
		cout << "Your Score: " << score << endl;
		int win = team.winStatus(score);
		if (win == 0) {
				cout << "Congratulations!!! You won the match\n";
		}
		else if (win == 1) {
				cout << "You lost the match\n";
		}
		else {
				cout << "Match drawn!!!\n";
		}
}

// Function decision of toss
int toss() {
		system("CLS");
		int choose, randomToss;
		cout << "Heads or Tails?\n";
		cout << "1.Heads\n2.Tails\n";
		cin >> choose;
		randomToss = (rand() % 2) + 1;
		if (choose == randomToss) {
				cout << "Congratulations! You have won the toss. Would you like to bat aur ball?\n";
				cout << "1. Bat\n2. Ball\n";
				cin >> choose;
				choose -= 1;
		}
		else {
				cout << "You have lost the toss\n";
				choose = rand() % 2;
				if (choose == 0) {
						cout << "The opponent has chosen to bowl first.\n";
				}
				else {
						cout << "The opponent has chosen to bat first.\n";
				}
		}
		system("Pause");
		return choose;
}

// Function Play
void play() {
		system("CLS");
		// Team Selection
		int selectTeam;
		cout << "Select your team from the following\n"
				<< "1.Pakistan\n2.Australia\n3.New Zealand\n4.Zimbabwe\n5.Srilanka\n";
		cin >> selectTeam;
		cout << "Your team: " << selectTeam << endl;
		system("Pause");
		system("CLS");
		// Opening File
		ifstream fin("teamPlayers.txt", ios::in);
		// Setting pointer in the file according to team 
		if (selectTeam == 2) {
				fin.seekg(226);
		}
		else if (selectTeam == 3) {
				fin.seekg(460);
		}
		else if (selectTeam == 4) {
				fin.seekg(687);
		}
		else if (selectTeam == 5) {
				fin.seekg(944);
		}
		string playerName;
		string playerNames[16];
		//Showing the players according to relative team
		if (fin) {
				cout << "Select 11 players from the following Squad: \n";
				for (int i = 0; i < 16; i++) {
						getline(fin, playerName);
						cout << i + 1 << "." << playerName << endl;
						playerNames[i] = playerName;;
				}
		}
		else {
				cout << "File does not exist\n";
				exit(0);
		}
		fin.close();
		// Selection of Players
		Team team;
		team.setTeamId(selectTeam);
		int playerNo;
		cout << "Enter the number to select the relevant player\n";
		int flag;
		for (int i = 0; i < 11; i++) {
				flag = 1;
				// Player number range check
				do {
						cout << "Player " << i + 1 << ": ";
						cin >> playerNo;
						if (playerNo < 1 || playerNo > 16) {
								flag = 0;
								cout << "Enter value in range (1-16), try again: ";
						}
						else {
								flag = 1;
						}
				} while (!flag);
				playerName = playerNames[playerNo - 1];
				// To check for repetitive players
				for (int j = 0; j < i; j++) {
						if (playerName != team.getPlayerName(j)) {
								flag = 1;
						}
						else {
								flag = 0;
								break;
						}
				}
				if (flag) {
						team.addPlayerName(i, playerName);
				}
				else {
						cout << "The player is already selected, Try another: ";
						i--;
				}
		}
		system("CLS");
		cout << "------------Your Selected Team------------" << endl;
		team.displayTeam();
		// To modify batting order
		char wannaModify;
		do {
				cout << "Do you want to modify the batting order(Y / N) ?: ";
				cin >> wannaModify;
				if (wannaModify == 'Y' || wannaModify == 'y') {
						int i, j;
						cout << "Please enter the id number of the player which needs to be modified: ";
						cin >> i;
						cout << "Please specify the position number in the team to insert the player : ";
						cin >> j;
						team.modifyOrder(i - 1, j - 1);
						team.displayTeam();
				}
		} while (wannaModify == 'Y' || wannaModify == 'y');
		system("CLS");
		cout << "This is a "<< team.getBalls() % 6 << " over match.Are you ready.\n";
		system("Pause");
		if (toss()) {
				bowling(team);
		}
		else {
				batting(team);
		}
}

// Function Rules
void rules() {
		system("CLS");
		char wannaPlay;
		cout << "1.Select team\n"
				<< "2.Select your squad of 11 players from given 16 players\n"
				<< "3.If you want to modify a batsman you can press Y else press N\n"
				<< "4.Toss.You can choose heads or tails\n"
				<< "5.Batsman can strike a ball or skip the ball(Defensive)\n"
				<< "Four categories of balls is considered\ni.No Ball\nii.Bouncer\niii.Wide\niv.Spin\n";
		cout << "Now if you want to play press Y else press N\n";
		cin >> wannaPlay;
		if (wannaPlay == 'Y' || wannaPlay == 'y') {
				play();
		}
}

// Main
int main() {
		srand(time(0));
		int wannaPlay;
		cout << "\t\t**Welcome**\n";
		cout << "Select an option(1-3)\n1.Play\n2.Rules\n3.Exit\n";
		cin >> wannaPlay;
		switch (wannaPlay) {
		case 1:
				play();
				break;
		case 2:
				rules();
				break;
		case 3:
				cout << "You Have exited\n";
				break;
		default:
				cout << "Enter a correct number\n";
		}
		system("Pause");
}