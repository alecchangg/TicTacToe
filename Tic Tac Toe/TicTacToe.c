#include <stdio.h>
#include <stdlib.h>


int player = 0; //counter for who's turn it is
char board[3][3] = { {' ', ' ', ' '},{' ',' ',' '},{' ',' ',' '} }; //2D array to represent the 3x3 tic tac toe board
int keepPlaying; //keeps track of if the game is still going
int input; //initializes the input variable


void drawBoard() { //displays the board into the terminal
	printf("---------------\n");
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			printf("| %c |", board[row][column]);
		}
		printf("\n");
		printf("---------------\n");
	}
}

int checkWin() { //checks to see if any of the win conditions are met. returns 0 if there is a win on the board
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != ' ') {
		return 0;
	}
	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != ' ') {
		return 0;
	}
	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != ' ') {
		return 0;
	}
	else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != ' ') {
		return 0;
	}
	else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != ' ') {
		return 0;
	}
	else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != ' ') {
		return 0;
	}
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
		return 0;
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
		return 0;
	}
	else {
		return 1;
	}
}

int occupied(int square) { //checks to see if the given square already has a symbol on it or not
	if (square == 1 && board[0][0] != ' ') {
		return 0;
	}
	else if (square == 2 && board[0][1] != ' ') {
		return 0;
	}
	else if (square == 3 && board[0][2] != ' ') {
		return 0;
	}
	else if (square == 4 && board[1][0] != ' ') {
		return 0;
	}
	else if (square == 5 && board[1][1] != ' ') {
		return 0;
	}
	else if (square == 6 && board[1][2] != ' ') {
		return 0;
	}
	else if (square == 7 && board[2][0] != ' ') {
		return 0;
	}
	else if (square == 8 && board[2][1] != ' ') {
		return 0;
	}
	else if (square == 9 && board[2][2] != ' ') {
		return 0;
	}
	else {
		return 1;
	}
}

void placeSquare(int square, int currentPlayer) { //places a symbol onto the given square.
	char symbol;
	if (currentPlayer == 1) {
		symbol = 'X';
	}
	else {
		symbol = 'O';
	}

	if (square == 1) {
		board[0][0] = symbol;
	}
	else if (square == 2) {
		board[0][1] = symbol;
	}
	else if (square == 3) {
		board[0][2] = symbol;
	}
	else if (square == 4) {
		board[1][0] = symbol;
	}
	else if (square == 5) {
		board[1][1] = symbol;
	}
	else if (square == 6) {
		board[1][2] = symbol;
	}
	else if (square == 7) {
		board[2][0] = symbol;
	}
	else if (square == 8) {
		board[2][1] = symbol;
	}
	else if (square == 9) {
		board[2][2] = symbol;
	}

}

int boardFull() { //checks to see if the board is full
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			if (board[row][column] == ' ') {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	drawBoard();
	printf("Press 1 to start. ");
	scanf_s("%d", &keepPlaying);
	while (keepPlaying == 1) {
		int currentPlayer = player % 2 + 1;
		printf("Player %d - Choose a square (1 - 9) ", currentPlayer);
		scanf_s("%d", &input);
		while (input > 9 || input < 1) {
			printf("Invalid input, try again. ");
			scanf_s("%d", &input);
		}
		while (occupied(input) == 0) {
			printf("Space already occupied, try again. ");
			scanf_s("%d", &input);
		}
		placeSquare(input, currentPlayer);
		drawBoard();
		keepPlaying = checkWin();
		if (keepPlaying == 0) {
			printf("Player %d Wins!!!!\n", currentPlayer);
		}
		if (boardFull() == 0) {
			keepPlaying = 0;
			printf("Tie! No one wins.");
		}
		player++;
	}
	return 0;
}

