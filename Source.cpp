#include <iostream>
using namespace std;

//Name: Hagar Fisher
// This program is a tic tac toe game.
// valid inputs are as follows in sruct board.
typedef struct board {
	char A1;
	char A2;
	char A3;
	char B1;
	char B2;
	char B3;
	char C1;
	char C2;
	char C3;
} BOARD;

typedef struct play {
	char row;
	char col;
} PLAY;

BOARD init_board()
// Initialize board with empty values
{
	BOARD b = { ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

	return b;
}

bool chk_input(char row, char col) {
	//Checks if user input is valid
	
	if ((row == 'A' || row == 'B' || row == 'C') && (col == '1' || col == '2' || col == '3')) {
		return true;
	}	
	else
		return false;
}

char flip_XO(int player)
// change player sign to X/O
{
	if (player == 1)
		return 'X';
	else
		return 'O';
}

int flip_player(int player)
// this function switches players
{
	if (player == 1)
		return 2;
	else
		return 1;
}

PLAY get_move(int player) {
	// Ask player for input, check if valid. if not ask again.
	PLAY play;
	do {
		cout << "Select a cell: ";
		cin >> play.row >> play.col;
	} while (!chk_input(play.row, play.col));

	return play;
}

BOARD mk_move(PLAY move, struct board x, int player) {
	// inputs an X or an O into the selected cell.
	if (move.row == 'A') {
		switch (move.col) {
		case '1':
			x.A1 = flip_XO(player);
			break;
		case '2':
			x.A2 = flip_XO(player);
			break;
		case '3':
			x.A3 = flip_XO(player);
			break;
		}
	}
	if (move.row == 'B') {
		switch (move.col) {
		case '1':
			x.B1 = flip_XO(player);
			break;
		case '2':
			x.B2 = flip_XO(player);
			break;
		case '3':
			x.B3 = flip_XO(player);
			break;
		}
	}
	if (move.row == 'C') {
		switch (move.col) {
		case '1':
			x.C1 = flip_XO(player);
			break;
		case '2':
			x.C2 = flip_XO(player);
			break;
		case '3':
			x.C3 = flip_XO(player);
			break;
		}
	}
	return x;
}

bool is_board_full(BOARD board)
// This function checks if the board is full
{
	return
			board.A1 != ' ' &&
			board.A2 != ' ' &&
			board.A3 != ' ' &&
			board.B1 != ' ' &&
			board.B2 != ' ' &&
			board.B3 != ' ' &&
			board.C1 != ' ' &&
			board.C2 != ' ' &&
			board.C3 != ' ';
}

bool player_won(BOARD board)
// The function checks if a player succeeded in placing 
//three of their marks in a horizontal, vertical, or diagonal rows.
{	// check cols
	if (board.A1 != ' ' && board.A1 == board.B1 && board.B1 == board.C1)
		return true;
	if (board.A2 != ' ' && board.A2 == board.B2 && board.B2 == board.C2)
		return true;
	if (board.A3 != ' ' && board.A3 == board.B3 && board.B3  == board.C3)
		return true;
	// check rows
	if (board.A1 != ' ' && board.A1 == board.A2 && board.A2 == board.A3)
		return true;
	if (board.B1 != ' ' && board.B1 == board.B2 && board.B2 == board.B3)
		return true;
	if (board.C1 != ' ' && board.C1 == board.C2 && board.C2 == board.C3)
		return true;
	// check diags
	if (board.A3 != ' ' && board.A3 == board.B2 && board.B2 == board.C1)
		return true;
	if (board.A1 != ' ' && board.A1 == board.B2 && board.B2 == board.C3)
		return true;

	return false;
}

bool is_end_game(BOARD board, int player)
// checks if one of the game ending conditions have been met.
{
	if (player_won(board)) {
		cout << "The winning player is " << player;
		return true;
	}
		
	else if (is_board_full(board)) {
		cout << "It's a tie!";
		return true;
	}
		
	return false;
}

void printBoard(BOARD b) {
	// print the board
	cout << "   1  " << "  2  " << "  3  " << endl;
	cout << "A  " << b.A1 << "    " << b.A2 << "    " << b.A3 << endl;
	cout << "B  " << b.B1 << "    " << b.B2 << "    " << b.B3 << endl;
	cout << "C  " << b.C1 << "    " << b.C2 << "    " << b.C3 << endl;
}

int main() {
	BOARD board;
	bool end_game = false;
	int player = 1;
	PLAY play;
	
	board = init_board();
	printBoard(board);
		do {
		play = get_move(player);
		board = mk_move(play, board, player);
		printBoard(board);
		end_game = is_end_game(board, player);
		player = flip_player(player);
	} while (!end_game);
	
	
	return 0;
}
