#include <iostream>
#include <fstream>
#include <chrono>
#include "board2d.h"
using namespace std;

//Visit entire shape recursively
void VisitShapeCell(Board2D& grid, unsigned short row, unsigned short col) {
	grid.SetVisit(row, col, true);
	
	unsigned short down  = row+1;
	if (grid.Get(down, col) == 1 && grid.IsVisited(down, col) == false)
		VisitShapeCell(grid, down, col);
	
	unsigned short left = col-1;
	if (grid.Get(row, left) == 1 && grid.IsVisited(row, left) == false)
		VisitShapeCell(grid, row, left);
	
	unsigned short up = row-1;
	if (grid.Get(up, col) == 1 && grid.IsVisited(up, col) == false)
		VisitShapeCell(grid, up, col);
	
	unsigned short right = col+1;
	if (grid.Get(row, right) == 1 && grid.IsVisited(row, right) == false)
		VisitShapeCell(grid, row, right);

	return;
}

unsigned short GetNumShapes(Board2D& grid) {
	const unsigned short rows = grid.GetRows();
	const unsigned short cols = grid.GetCols();
	unsigned short numShapes  = 0;

	for (unsigned short i=0; i<rows; ++i) {
		for (unsigned short j=0; j<cols; ++j) {
			if (grid.Get(i, j) == 1 && grid.IsVisited(i, j) == false) {
				VisitShapeCell(grid, i, j);
				numShapes++;
			}
		}
	}
	return numShapes;
}

using namespace std::chrono;
int main() {
	const char* inputFile = "input.txt";
	Board2D grid;
	
	//Sophisticated error handling
	if (!grid.GetGridFromFile(inputFile)) {
		cout << "Something went horribly wrong.\n";
		return 0;
	}
	grid.Print();
	
	//Time how long recursive GetNumShapes() algorithm takes
	auto t0 = high_resolution_clock::now();
	cout << "Number of shapes: " << GetNumShapes(grid) << endl;
	auto t1 = high_resolution_clock::now();
	cout << "Number of nanoseconds: " << duration_cast<nanoseconds>(t1-t0).count() << endl;
	return 0;
}
