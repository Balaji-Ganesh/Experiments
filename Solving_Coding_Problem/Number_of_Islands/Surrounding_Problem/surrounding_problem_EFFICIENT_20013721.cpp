// Approach-2: Uses only 1 DFS, without using the is_visited grid..
// Ref: TechDose (Youtube)
#include <iostream>
#include <vector>
#define DEBUG_MODE 0		// Change to switch between debug_mode and normal_mode....
using namespace std;

// Global declaration of the helper functions..
void is_border_island(vector<vector<char>> &grid, int x, int y, int rows, int cols);			// DFS.. 
void find_border_islands(vector<vector<char>> &board);

int main()
{
	cout << "Enter the dimensions of the grid. \nnum_rows: ";
	int num_rows=0, num_cols=0;
	cin >> num_rows;
	cout << "num_cols: ";
	cin >> num_cols;

	// A grid to hold the values..
	vector<vector<char>> board;
	char ch;
	// Take the grid..
	cout << "Please enter the grid of " << num_rows << " x " << num_cols << ": " << endl;
	for (int i=0; i<num_rows; i++)
	{
		vector<char> temp_row;
		for (int j=0; j<num_cols; j++)
		{
			cin>>ch;
			temp_row.push_back(ch);
		}
		board.push_back(temp_row);
	}	

	// Find the islands which are at border...
	find_border_islands(board);
	// Upon returning the control back to here, can convert the board into appropriate form, but as here not using for further purposes rather than printing
	//   it is just changed while printing.
	// But, its recommended to modify the matrix as done in the print-section, if used for further purposes.

	// Finally print the grid...
	for (int i=0; i<num_rows; i++)
	{
		for (int j=0; j<num_cols; j++)
			if (board[i][j] == '*')
				cout << "O  ";
			else
				cout << "X  ";
		cout << endl;
	}
}

//Implementation of the globally declared helper functions..
void find_border_islands(vector<vector<char>> &board)			// NOTICE that, its the reference paramter.....
{
	// Handling empty grid cases...
	int rows = board.size();
	if (rows <= 1)
	{
		cout << "[WARNING] Passed empty grid, please pass a valid grid to find the islands which are at border." << endl;
		return;
	}
	int cols = board[0].size();
	if (cols <=1)
	{
		cout << "[WARNING] Please pass the grid, which has columns >=2." << endl;
		return;
	}
	
	// Start iterating over the LeftMost and RightMost columns....
	for (int i=0; i<rows; i++)
	{
		is_border_island(board, i, 0 ,rows, cols);
		is_border_island(board, i, cols-1,rows, cols);
	}
	
	// Start iterating over the TopMost and the BottomMost rows... (leaving the extremes behind, as they would get covered in above traversal..)
	for (int j=1; j<cols-1; j++)
	{
		is_border_island(board, 0, j, rows, cols);
		is_border_island(board, rows-1, j, rows, cols);
	}
}

void is_border_island(vector<vector<char>> &board, int x, int y, int rows, int cols)	// NOTICE that there are reference parameters..
{
	/* Base cases for recursions....*/
	// If the cell isn't the island or its already been visited....
	if(x<0 || x>=rows || y<0 || y>=cols || board[x][y] != 'O' || board[x][y] == '*')
	{
		if( DEBUG_MODE)
			cout << "[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'." << endl;
		return;
	}
	//cout << "board[" << x << "]" << "[" << y << "] = " << board[x][y] << endl;	
	//if (board[x][y] == 'O')
	//{
		//cout << "Encountered an island at border. " << endl;
		board[x][y] = '*';
	//}

	// Span to the four adjacent directions of the cell..
	is_border_island(board, x-1, y, rows, cols);	// Bottom..
	is_border_island(board, x+1, y, rows, cols);	// Top..
	is_border_island(board, x, y+1, rows, cols);	// Right...
	is_border_island(board, x, y-1, rows, cols);	// Lefr
}
/* OUTPUT:
 *
 *
 * krishna@helloworld:.../Surrounding_Problem$ vim surrounding_problem_EFFICIENT_20013721.cpp +57
krishna@helloworld:.../Surrounding_Problem$ g++ surrounding_problem_EFFICIENT_20013721.cpp -o surrounding_problem_EFFICIENT_20013721
krishna@helloworld:.../Surrounding_Problem$ ./surrounding_problem_EFFICIENT_20013721
Enter the dimensions of the grid.
num_rows: 4
num_cols: 4
Please enter the grid of 4 x 4:
X	X	O	X
X	X	O	X
O	X	O	X
X	X	X	X
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
board[2][0] = O
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
board[0][2] = O
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
board[1][2] = O
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
board[2][2] = O
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
X  X  O  X
X  X  O  X
O  X  O  X
X  X  X  X
krishna@helloworld:.../Surrounding_Problem$ ./surrounding_problem_EFFICIENT_20013721
Enter the dimensions of the grid.
num_rows: 4
num_cols: 4
Please enter the grid of 4 x 4:
X	X	X	X
X	O	O	X
X	O	O	X
X	X	X	X
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
X  X  X  X
X  X  X  X
X  X  X  X
X  X  X  X
krishna@helloworld:.../Surrounding_Problem$ ./surrounding_problem_EFFICIENT_20013721
Enter the dimensions of the grid.
num_rows: 4
num_cols: 4
Please enter the grid of 4 x 4:
X	X	O	X
X	O	X	O
X	O	O	X
X	X	X	X
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
board[1][3] = O
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
board[0][2] = O
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
X  X  O  X
X  X  X  O
X  X  X  X
X  X  X  X
krishna@helloworld:.../Surrounding_Problem$ ./surrounding_problem_EFFICIENT_20013721
Enter the dimensions of the grid.
num_rows: 4
num_cols: 4
Please enter the grid of 4 x 4:
X	X	O	X
X	O	X	X
X	O	O	X
X	X	X	X
board[0][2] = O
X  X  O  X
X  X  X  X
X  X  X  X
X  X  X  X
krishna@helloworld:.../Surrounding_Problem$ ./surrounding_problem_EFFICIENT_20013721
Enter the dimensions of the grid.
num_rows: 3
num_cols: 3
Please enter the grid of 3 x 3:
X	X	X
X	O	X
X	X	X
X  X  X
X  X  X
X  X  X

 *
 * Time-complsity: Same as the previous one
 * 	i.e., Here even though it uses 1 DFS to work on m*n array... upon using the "O", constants get removed...so still its taken as O(m*n)
 *
 * Space-complexity:
 * 	Compared to previous approach, this approach solves using only one single m*n grid..
 * 	O(m*n).
 *
 * */
