#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "player.h"

using namespace std;

#define ROWS 13
#define COLS 25

WINDOW * createBoard() {
	int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  WINDOW * window = newwin(ROWS, COLS, (yMax/2-10), 10);
  box(window, 0, 0);
  refresh();
  wrefresh(window);

	for(int v=1;v<ROWS-1;v++) {
		mvwaddch(window, v, 8, ACS_VLINE);
		mvwaddch(window, v, 16, ACS_VLINE);
		mvwaddch(window, v, 24, ACS_VLINE);
	}
	
	for(int h=1;h<3;h++) {
		for(int hItem=1;hItem<COLS-1;hItem++) {
			mvwaddch(window, h*4, hItem, ACS_HLINE);
		}
	}
	
	refresh();
	wrefresh(window);

	return window;
}

void setBoardCoordinates(int y, int x, char piece, char board[3][3]) {
	if (piece == 'x' || piece == 'o') {
		board[y][x] = piece;
	}
}

void checkWinner(char b[3][3], char piece) {
	if ((b[0][0] != '@' && b[0][0] == b[0][1] && b[0][1] == b[0][2]) ||
			(b[1][0] != '@' && b[1][0] == b[1][1] && b[1][1] == b[1][2]) ||
			(b[2][0] != '@' && b[2][0] == b[2][1] && b[2][1] == b[2][2]) ||
			(b[0][0] != '@' && b[0][0] == b[1][1] && b[1][1] == b[2][2]) ||
			(b[0][2] != '@' && b[0][2] == b[1][1] && b[1][1] == b[2][0])) {
		printw("The player %c won!", piece);
	}	
}

int main() {
	initscr();

	int turn = 1;
	WINDOW * window = createBoard();
	char board[3][3] = {{'@', '@', '@'}, {'@', '@', '@'}, {'@', '@', '@'}};

	wmove(window, 2, 4);
	refresh();
	wrefresh(window);	

	Player * p = new Player(window, 2, 4);
	while (p->getMove() != 'k') {	
		setBoardCoordinates(p->getBoardY(), p->getBoardX(), p->getPiece(), board);
		checkWinner(board, p->getPiece());
		
		//if (p->getMove() == '\n') {
			//printw("%c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
		//	printw("%c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
		//	printw("%c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
		//	refresh();
		//}
		p->display();
		refresh();
		wrefresh(window);
	}
	
	getch();
	endwin();
	return 0;
}
