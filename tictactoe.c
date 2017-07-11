#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void drawBoard(char inputBoard[3][3]);
void clearScreen();
int computerPosition();
bool winCondition(char winBoard[3][3]);
bool validMoveCheck(int checkMove, char playBoardFunc[3][3]);

int main(void)
{

	int userPosition = 0;
	int compPosition = 0;
	int count = 0;
	bool endGame = false;
	bool validUserMove = true;
	bool validComputerMove = true;
	char playBoard[3][3] = {
							{'-', '-', '-'},
							{'-', '-', '-'},
							{'-', '-', '-'}
	};

	printf("\e[1;1H\e[2J");
	printf("Welcome to Alex Montague's Tic Tac Toe game!\n");
	printf("You will be playing against the computer.\n");
	printf("Have Fun!\n");
	printf("\n");
	printf("When asked to choose a postion, use this format:\n");
	printf("1 2 3\n");
	printf("4 5 6\n");
	printf("7 8 9\n");
	printf("\n");

	printf(" -  |  -  |  - \n");
	printf("****|*****|****\n");
	printf(" -  |  -  |  - \n");
	printf("****|*****|****\n");
	printf(" -  |  -  |  - \n");
	printf("\n");

	while(endGame == false) {
		
		printf("Choose your position: ");
		do {
			scanf("%d", &userPosition);
			validUserMove = validMoveCheck(userPosition, playBoard);
			printf("Invalid move, try again: ");
		}
		while(validUserMove == false);

		if(userPosition == 1) {
			playBoard[0][0] = 'X';
		}
		else if(userPosition == 2) {
			playBoard[0][1] = 'X';
		}
		else if(userPosition == 3) {
			playBoard[0][2] = 'X';
		}
		else if(userPosition == 4) {
			playBoard[1][0] = 'X';
		}
		else if(userPosition == 5) {
			playBoard[1][1] = 'X';
		}
		else if(userPosition == 6) {
			playBoard[1][2] = 'X';
		}
		else if(userPosition == 7) {
			playBoard[2][0] = 'X';
		}
		else if(userPosition == 8) {
			playBoard[2][1] = 'X';
		}
		else if(userPosition == 9) {
			playBoard[2][2] = 'X';
		}
		else {
			printf("Invalid position, try again.\n");
		}

		drawBoard(playBoard);
		endGame = winCondition(playBoard);
		if(endGame == true) {
			break;
		}
		for(int i = 0; i <= 2; i++) {
			for(int j = 0; j <= 2; j++) {
				if(playBoard[i][j] != '-') {
					count++;
				}
			}
		}
		if(count == 9) {
			printf("Cats Game!\n");
			break;
		}
		count = 0;

		do {
			compPosition = computerPosition();
			validComputerMove = validMoveCheck(compPosition, playBoard);
		}
		while(validComputerMove == false);

		if(compPosition == 1) {
		playBoard[0][0] = 'O';
		}
		else if(compPosition == 2) {
			playBoard[0][1] = 'O';
		}
		else if(compPosition == 3) {
			playBoard[0][2] = 'O';
		}
		else if(compPosition == 4) {
			playBoard[1][0] = 'O';
		}
		else if(compPosition == 5) {
			playBoard[1][1] = 'O';
		}
		else if(compPosition == 6) {
			playBoard[1][2] = 'O';
		}
		else if(compPosition == 7) {
			playBoard[2][0] = 'O';
		}
		else if(compPosition == 8) {
			playBoard[2][1] = 'O';
		}
		else if(compPosition == 9) {
			playBoard[2][2] = 'O';
		}
		else {
			printf("Computer move invalid.\n");
		}

		drawBoard(playBoard);

		endGame = winCondition(playBoard);
	
	}

	return 0;
}

void drawBoard(char inputBoard[3][3]) {

	clearScreen();

	printf("\n");
	printf("1 2 3\n");
	printf("4 5 6\n");
	printf("7 8 9\n");
	printf("\n");

	printf(" %c  |  %c  |  %c \n", inputBoard[0][0], inputBoard[0][1], inputBoard[0][2]);
	printf("****|*****|****\n");
	printf(" %c  |  %c  |  %c \n", inputBoard[1][0], inputBoard[1][1], inputBoard[1][2]);
	printf("****|*****|****\n");
	printf(" %c  |  %c  |  %c \n", inputBoard[2][0], inputBoard[2][1], inputBoard[2][2]);	

}

void clearScreen() {

	printf("\e[1;1H\e[2J");

}

bool validMoveCheck(int checkMove, char playBoardFunc[3][3]) {

	bool validMove = true;

	if(checkMove == 1) {
		if(playBoardFunc[0][0] == 'X' || playBoardFunc[0][0] == 'O') {
			validMove = false;
		}
	}
	else if(checkMove == 2) {
		if(playBoardFunc[0][1] == 'X' || playBoardFunc[0][1] == 'O') {
			validMove = false;
		}
	}
	else if(checkMove == 3) {
		if(playBoardFunc[0][2] == 'X' || playBoardFunc[0][2] == 'O') {
			validMove = false;
		}
	}
	else if(checkMove == 4) {
		if(playBoardFunc[1][0] == 'X' || playBoardFunc[1][0] =='O') {
			validMove = false;
		}
	}
	else if(checkMove == 5) {
		if(playBoardFunc[1][1] == 'X' || playBoardFunc[1][1] == 'O') {
			validMove = false;
		}
	}
	else if(checkMove == 6) {
		if(playBoardFunc[1][2] == 'X' || playBoardFunc[1][2] == 'O') {
			validMove = false;
		}
	}
	else if(checkMove == 7) {
		if(playBoardFunc[2][0] == 'X' || playBoardFunc[2][0] == 'O') {
			validMove = false;
		}
	}
	else if(checkMove == 8) {
		if(playBoardFunc[2][1] == 'X' || playBoardFunc[2][1] == 'O') {
			validMove = false;
		}
	}
	else if(checkMove == 9) {
		if(playBoardFunc[2][2] == 'X' || playBoardFunc[2][2] == 'O') {
			validMove = false;
		}
	}
	else {
		printf("Invalid position, try again.\n");
	}

	return validMove;

}

int computerPosition() {
	
	int randNum = 0;

	srand(time(NULL));
	do {
		randNum = (rand() % 10) + 1;
	}
	while(randNum == 10);

	return randNum;

}

bool winCondition(char winBoard[3][3]) {

	bool gameOver = false;
	
	if(winBoard[0][0] == 'X' && winBoard[0][1] == 'X' && winBoard[0][2] == 'X') {
		gameOver = true;
		printf("You Win!\n");
	}
	else if(winBoard[1][0] == 'X' && winBoard[1][1] == 'X' && winBoard[1][2] == 'X') {
		gameOver = true;
		printf("You Win!\n");
	}
	else if(winBoard[2][0] == 'X' && winBoard[2][1] == 'X' && winBoard[2][2] == 'X') {
		gameOver = true;
		printf("You Win!\n");
	}
	else if(winBoard[0][0] == 'X' && winBoard[1][0] == 'X' && winBoard[2][0] == 'X') {
		gameOver = true;
		printf("You Win!\n");
	}
	else if(winBoard[0][1] == 'X' && winBoard[1][1] == 'X' && winBoard[2][1] == 'X') {
		gameOver = true;
		printf("You Win!\n");
	}
	else if(winBoard[0][2] == 'X' && winBoard[1][2] == 'X' && winBoard[2][2] == 'X') {
		gameOver = true;
		printf("You Win!\n");
	}
	else if(winBoard[0][0] == 'X' && winBoard[1][1] == 'X' && winBoard[2][2] == 'X') {
		gameOver = true;
		printf("You Win!\n");
	}
	else if(winBoard[0][2] == 'X' && winBoard[1][1] == 'X' && winBoard[2][0] == 'X') {
		gameOver = true;
		printf("You Win!\n");
	}
	else if(winBoard[0][0] == 'O' && winBoard[0][1] == 'O' && winBoard[0][2] == 'O') {
		gameOver = true;
		printf("You Lose!\n");
	}
	else if(winBoard[1][0] == 'O' && winBoard[1][1] == 'O' && winBoard[1][2] == 'O') {
		gameOver = true;
		printf("You Lose!\n");
	}
	else if(winBoard[2][0] == 'O' && winBoard[2][1] == 'O' && winBoard[2][2] == 'O') {
		gameOver = true;
		printf("You Lose!\n");
	}
	else if(winBoard[0][0] == 'O' && winBoard[1][0] == 'O' && winBoard[2][0] == 'O') {
		gameOver = true;
		printf("You Lose!\n");
	}
	else if(winBoard[0][1] == 'O' && winBoard[1][1] == 'O' && winBoard[2][1] == 'O') {
		gameOver = true;
		printf("You Lose!\n");
	}
	else if(winBoard[0][2] == 'O' && winBoard[1][2] == 'O' && winBoard[2][2] == 'O') {
		gameOver = true;
		printf("You Lose!\n");
	}
	else if(winBoard[0][0] == 'O' && winBoard[1][1] == 'O' && winBoard[2][2] == 'O') {
		gameOver = true;
		printf("You Lose!\n");
	}
	else if(winBoard[0][2] == 'O' && winBoard[1][1] == 'O' && winBoard[2][0] == 'O') {
		gameOver = true;
		printf("You Lose!\n");
	}

	return gameOver;

}