all: tictactoe
	
tictactoe: tictactoe.cpp
	g++ -o tictactoe tictactoe.cpp -lncurses
	./tictactoe
