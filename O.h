#ifndef _O_H_
#define _O_H_

class O {
	public:
		O(WINDOW *window);	
		
		void mark(int y, int x);

	private:
		WINDOW *currentWindow;
};

O::O(WINDOW *window) {
	currentWindow = window;
}

void O::mark(int y, int x) {
	mvwaddch(currentWindow, y-1, x, '#');
	mvwaddch(currentWindow, y-1, x-1, '#');
	mvwaddch(currentWindow, y-1, x-2, '#');
	mvwaddch(currentWindow, y-1, x+1, '#');
	mvwaddch(currentWindow, y-1, x+2, '#');
	mvwaddch(currentWindow, y, x-2, '#');
	mvwaddch(currentWindow, y, x+2, '#');
	mvwaddch(currentWindow, y+1, x, '#');
	mvwaddch(currentWindow, y+1, x-1, '#');
	mvwaddch(currentWindow, y+1, x-2, '#');
	mvwaddch(currentWindow, y+1, x+1, '#');
	mvwaddch(currentWindow, y+1, x+2, '#');
}

#endif
