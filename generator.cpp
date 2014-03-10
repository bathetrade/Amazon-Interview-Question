#include <iostream>
#include <cstdlib>
#include <time.h>
#include "board2d.h"
#include "constraints.h"
using namespace std;

void RandomizeBoard(unsigned short rows, unsigned short cols, Board2D& board) {
	bool val;
	for (int i=0; i<rows; ++i) {
		for (int j=0; j<cols; ++j) {
			val = rand()%2; //0 or 1
			board.Set(i,j,val);
		}
	}
}

int main()
{
	const char* filename = "input.txt";
	srand(time(NULL));
	unsigned short rows = (rand() % BOARD_LIMIT) + 1;
	unsigned short cols = (rand() % BOARD_LIMIT) + 1;
	
	Board2D grid(rows, cols);
	RandomizeBoard(rows, cols, grid);
	grid.PrintToFile(filename);
	
	return 0;
}
