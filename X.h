#ifndef _X_H_
#define _X_H_

class X {
	public:
		X(WINDOW *window);	
		
		void mark(int y, int x);

	private:
		WINDOW *currentWindow;
};

X::X(WINDOW *window) {
	currentWindow = window;
}

void X::mark(int y, int x) {
	mvwaddch(currentWindow, y-1, x-1, '\\');
	mvwaddch(currentWindow, y-1, x-2, '\\');
	mvwaddch(currentWindow, y-1, x+1, '/');
	mvwaddch(currentWindow, y-1, x+2, '/');
	mvwaddch(currentWindow, y, x, '|');
	mvwaddch(currentWindow, y, x-1, '|');
	mvwaddch(currentWindow, y, x+1, '|');
	mvwaddch(currentWindow, y+1, x-1, '/');
	mvwaddch(currentWindow, y+1, x-2, '/');
	mvwaddch(currentWindow, y+1, x+1, '\\');
	mvwaddch(currentWindow, y+1, x+2, '\\');
}

#endif
