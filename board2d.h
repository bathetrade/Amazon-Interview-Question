#ifndef BOARD2D_H
#define BOARD2D_H

//The cell (i,j) is in 0-based indices. First row is the 0th row, second column has an index of 1, etc.

struct Cell {
	bool value;
	bool visited;
	static unsigned short count;
	Cell();
	~Cell();
};

class Board2D {
private:
	Cell** mCellArray;
	unsigned short mRows;
	unsigned short mCols;
	void InitArray();
public:
	Board2D();
	Board2D(unsigned short numRows, unsigned short numCols);
	~Board2D();

	void Clear();
	void Delete();
	int Get(unsigned short i, unsigned short j) const;
	bool GetGridFromFile(const char* filename);
	unsigned short GetCols() const;
	unsigned short GetRows() const;
	bool InBounds(unsigned short i, unsigned short j) const;
	bool IsEmpty() const;
	bool IsVisited(unsigned short i, unsigned short j) const;
	void Print() const;
	bool PrintToFile(const char* filename);
	void Resize(unsigned short numRows, unsigned short numCols);
	void Set(unsigned short i, unsigned short j, bool val);
	bool SetVisit(unsigned short i, unsigned short j, bool visit);	
};

#endif
