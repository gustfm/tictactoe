#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "player.h"

using namespace std;

WINDOW * createBoard() {
	int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  WINDOW * window = newwin(10, 20, (yMax/2-10), 10);
  box(window, 0, 0);
  refresh();
  wrefresh(window);

	return window;
}

int main() {
	initscr();

	WINDOW * window = createBoard();
	
	Player * p = new Player(window, 1, 1, 'x');
	while (p->getMove() != 'k') {
		p->display();
		wrefresh(window);
	}
	
	getch();
	endwin();
	return 0;
}
