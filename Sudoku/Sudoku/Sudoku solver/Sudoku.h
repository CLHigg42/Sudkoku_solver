#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;
class Sudoku{

public:

	static const int num = 9; //number of rows and columns 
	int grid[num][num]; // Sudoku grid
	

	//Constructor class
	Sudoku() {};
		



	

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
		
	}



};


//driver code
int main() {
	
	Sudoku game;
	game.generateGrid();
	
	


	

	return 0;
}

/* TO-DO:
make git repository before any more work is done
evenly populate the sudoku board 
solve rows
solve columns
solve boxes*/