#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player {
	public:
		Player(WINDOW * window, int y, int x, char p);
		
		void moveUp();
		void moveDown();
		void moveRight();		
		int getMove();
		void display();		

	private:
		int y, x, yMax, xMax;
		char p;
		WINDOW * currentWindow;
};

Player::Player(WINDOW * window, int y, int x, char p) {
	currentWindow = window;
	y = y;
	x = x;
	getmaxyx(currentWindow, yMax, xMax);
	keypad(currentWindow, true);
	p = p;
}

void Player::moveUp() {}
void Player::moveRight() {
	x++;
	if (x > xMax - 2) {
		x = xMax - 2;
	}
}
void Player::moveDown() {
	y++;
	if (y > yMax - 2) {
		y = yMax - 2;
	}
}
int Player::getMove() {
	int choice = wgetch(currentWindow);
	switch(choice) {
		case KEY_RIGHT:
			moveRight();
			break;
		case KEY_DOWN:
			moveDown();
			break;
		default:
			break;
	}
	return choice;
}
void Player::display() {
	mvwaddch(currentWindow, y, x, p);
}

#endif
