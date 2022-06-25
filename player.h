#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "X.h"
#include "O.h"

class Player {
	public:
		Player(WINDOW * window, int y, int x);
		
		void moveUp();
		void moveDown();
		void moveRight();
		void moveLeft();		
		int getMove();
		void markPosition();
		void display();
		int getBoardY();
		int getBoardX();
		char getPiece();		

	private:
		int y, x, yMax, xMax, boardY, boardX, turn;
		char currentPiece;
		WINDOW * currentWindow;
};

Player::Player(WINDOW * window, int y, int x) {
	currentWindow = window;
	Player::y = y;
	Player::x = x;
	Player::boardY = 0;
	Player::boardX = 0;
	Player::turn = 1;
	getmaxyx(currentWindow, yMax, xMax);
	keypad(currentWindow, true);
}

/*int Player::getWindowX() {
	return x;
}
int Player::getWindowY() {
	return y;
}*/
int Player::getBoardX() {
	return boardX;
}
int Player::getBoardY() {
	return boardY;
}
char Player::getPiece() {
	return currentPiece;
}
void Player::markPosition() {
	if (turn == 1) {
		X *xpiece = new X(currentWindow);
		xpiece->mark(y, x);
		currentPiece = 'x';
		turn++;
	} else if (turn == 2) {
		O *opiece = new O(currentWindow);
		opiece->mark(y, x);
		currentPiece = 'o';
		turn--;
	}
	refresh();
	wrefresh(currentWindow);
}
void Player::moveRight() {
	boardX++;
	x = x + 8;
	if (x > (xMax / 2) + 4) {
		boardX = 2;
		x = xMax - 5;
	}
}
void Player::moveLeft() {
	boardX--;
	x = x - 8;
	if (x < (xMax / 2)) {
		boardX = 0;
		x = 4;
	}
}
void Player::moveUp() {
	boardY--;
	y = y - 4;
	if (y < (yMax / 2)) {
		boardY = 0;
		y = 2;
	}
}
void Player::moveDown() {
	boardY++;
	y = y + 4;
	if (y > (yMax / 2)) {
		boardY = 2;
		y = yMax - 3;
	}
}
int Player::getMove() {
	int choice = wgetch(currentWindow);
	switch(choice) {
		case KEY_RIGHT:
			moveRight();
			currentPiece = '@';
			break;
		case KEY_LEFT:
			moveLeft();
			currentPiece = '@';
			break;
		case KEY_UP:
			moveUp();
			currentPiece = '@';
			break;
		case KEY_DOWN:
			moveDown();
			currentPiece = '@';
			break;
		case '\n':
			markPosition();
			break;
		default:
			break;
	}

	return choice;
}
void Player::display() {
	wmove(currentWindow, y, x);
}

#endif
