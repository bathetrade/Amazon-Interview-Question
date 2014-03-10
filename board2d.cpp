#include <iostream>
#include <fstream>
#include "board2d.h"
using namespace std;

//Cell code
Cell::Cell() {
	value = false; 
	visited = false;
}

Cell::~Cell() { 
	++count;
	//cout << "Deleting cell: " << count << endl;
}

unsigned short Cell::count = 0;

//Board2D code
Board2D::Board2D() {
	mRows = mCols = 0;
	mCellArray = 0;
}

Board2D::Board2D(unsigned short numRows, unsigned short numCols) {
	mRows      = numRows;
	mCols      = numCols;
	mCellArray = 0;
	InitArray();
}

Board2D::~Board2D() {
	Delete();
}

void Board2D::InitArray() {
	mCellArray = new Cell*[mRows];
	for (int i=0; i<mRows; ++i)
		mCellArray[i] = new Cell[mCols];
}

void Board2D::Clear() {
	for (int i=0; i<mRows; ++i) {
		for (int j=0; j<mCols; ++j) {
			mCellArray[i][j].value   = false;
			mCellArray[i][j].visited = false;
		}
	}
}

void Board2D::Delete() {
	if (mCellArray != 0) {
		for (int i=0; i<mRows; ++i)
			delete[] mCellArray[i];
		delete[] mCellArray;
	}
	mCellArray = 0;
	mRows	   = 0;
	mCols	   = 0;
}

int Board2D::Get(unsigned short i, unsigned short j) const {
	if (!InBounds(i, j))
		return -1;
	else return (int)mCellArray[i][j].value;
}

bool Board2D::GetGridFromFile(const char* filename) {
	//Open the input file
	ifstream file(filename);
	if (!file.is_open())
		return false;
	
	//Get grid dimensions from the file
	unsigned short rows = 0;
	unsigned short cols = 0;
	file >> rows;
	file >> cols;
	Resize(rows, cols);
	
	//Iterate over the cells in the file and set the corresponding cell in grid
	bool buffer = false;
	for (int i=0; i<rows; ++i) {
		for (int j=0; j<cols; ++j) {
			file >> buffer;
			Set(i, j, buffer);
		}
		file.ignore();		//Ignore newline character
	}
	file.close();
	return true;
}

unsigned short Board2D::GetCols() const {
	return mCols;
}

unsigned short Board2D::GetRows() const {
	return mRows;
}

bool Board2D::InBounds(unsigned short i, unsigned short j) const {
	if (i >= mRows || j >= mCols)
		return false;
	else return true;
}

bool Board2D::IsEmpty() const {
	return (mCellArray == 0);
}

bool Board2D::IsVisited(unsigned short i, unsigned short j) const {
	if (!InBounds(i, j))
		return false;
	return mCellArray[i][j].visited;
}

void Board2D::Print() const {
	if (IsEmpty())
		cout << "Empty array\n";
	else {
		for (int i=0; i<mRows; ++i) {
			for (int j=0; j<mCols; ++j)
				cout << mCellArray[i][j].value << "  ";
			cout << endl;
		}
	}
}

bool Board2D::PrintToFile(const char* filename) {
	ofstream file;
	file.open(filename, ios::trunc);
	if (!file.is_open())
		return false;
	
	file << mRows << endl;
	file << mCols << endl;
	for (int i=0; i<mRows; ++i) {
		for (int j=0; j<mCols; ++j)
			file << mCellArray[i][j].value << "  ";
		file << endl;
	}
	
	file.close();
	return true;
}

void Board2D::Resize(unsigned short numRows, unsigned short numCols) {
	Delete();
	mRows = numRows;
	mCols = numCols;
	InitArray();
}

	
void Board2D::Set(unsigned short i, unsigned short j, bool val) {
	if (!InBounds(i, j))
		return;
	mCellArray[i][j].value= val;
}

bool Board2D::SetVisit(unsigned short i, unsigned short j, bool visit) {
	int returnVal = Get(i, j);
	if (returnVal != 1)		//We can only visit shapes, not empty cells
		return false;
	mCellArray[i][j].visited = visit;
	return true;
}
