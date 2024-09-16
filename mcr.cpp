#include<iostream>
using namespace std;

bool isWin(char game[3][3]) {
	bool win = false;
	if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
	if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true;
	if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true;
	// column
	if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
	if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true;
	if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
	// diagonal 
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
	if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
	return win;
}


int main(){
		int i, j;
		char game[3][3] = { ' ' }; // Tic-tac-toe
		int is_Occupied[3][3] = {0};//Determine if the position is already occupied
		char playerl = 'X';
		char player2 = 'O';
		bool turn = true;// false for player 1's turn, true for player 2's turn. Player l first.
		cout << "X = Player 1" << endl <<"O = Player 2"<< endl;
		int n;
		for (n = 0; n < 9; n++) {
			turn = !turn;// use the not-operator to change true to false or false to true.
			if (turn == false) cout << "Player 1: ";
			else cout << "Player 2: ";
			cout << "Which cell to mark? i : [0 . . 2], j : [0 . . 2] : ";
			cin >> i >> j;
			if ((i != 0 && i != 1 && i != 2) || (j != 0 && j != 1 && j != 2)) break;//Illegal input, stop the game!
			if (is_Occupied[i][j] == 1) break;//this position has been occupied, cannot be used again
			else {
				is_Occupied[i][j] = 1;//this position is going to be occupied
				if (turn == false) game[i][j] = 'X';
				else game[i][j] = 'O';
				if (isWin(game)) {
					cout << "Win!" << endl;
					break;// need to terminate the problem
				}
				if (n == 9) // all celles with i=0 to 2 have been inputted above but no winner yet 
					cout << "Tie!" << endl;
			}
			// show the game to console
			cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
			cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
			cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
			return 0;
		}
