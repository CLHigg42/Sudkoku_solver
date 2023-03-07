

#include <iostream>
#include <cstdlib>

using namespace std;
class Sudoku {

public:

	static const int num = 9; //number of rows and columns 
	int grid[num][num] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},		// Sudoku grid
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
	};


	//Constructor class
	Sudoku() {};


	//checkers for grid validation and solving 
	bool checkCol(int col, int num) {
		for (int row = 0; row < num; row++)
			if (grid[row][col] == num)
				return true;
		return false;
	};
	bool checkRow(int row, int num) {
		for (int col = 0; col < num; col++)
			if (grid[row][col] == num)
				return true;
		return false;
	};
	bool checkBox(int startRow, int startCol, int num) {
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 3; col++)
				if (grid[row + startRow][col + startCol] == num)
					return true;
		return false;
	};

	void generateGrid() {

		srand(time(0)); // allows rand() function to generate new seed every time 

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (j % 3 == 0)
					cout << " | ";
				grid[i][j] = rand() % 10; // generate a number 0-9

				cout << grid[i][j] << " ";


			}

			cout << "|";
			if (i == 2 || i == 5) {
				cout << endl;
				cout << "----------------------------";
			}

			cout << endl;

		}

	};

	void printGrid() {
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (j % 3 == 0)
					cout << " | ";
				cout << grid[i][j] << " ";


			}

			cout << "|";
			if (i == 2 || i == 5) {
				cout << endl;
				cout << "----------------------------";
			}
			cout << endl;
		}

	}


	bool findEmpty(int& row, int& col) {
		for (row = 0; row < num; row++)
			for (col = 0; col < num; col++)
				if (grid[row][col] == 0) // places with 0 are seen as empty
					return true;
		return false;
	}

	bool isValid(int row, int col, int num) {
		return !checkRow(row, num) && !checkCol(col, num) && !checkBox(row - row % 3, col - col % 3, num);
	}

	bool solve() {
		int row;
		int col;

		if (!findEmpty(row, col))
			return true;
		for (int num = 1; num <= 9; num++) {
			if (isValid(row, col, num)) {
				grid[row][col] = num;
				if (solve())
					return true;
				grid[row][col] = 0;
			}
		}
		return false;
	}
};










//driver code
int main() {

	Sudoku game;
	//game.generateGrid();
	game.printGrid();
	cout << endl << endl; 
	if (game.solve() == true)
		game.printGrid();
	else
		cout << "No Solution";






	return 0;
};



/* TO-DO:
* manually insert board
solve rows
solve columns
solve boxes
figure out randomly populated board 
finished for now*/

