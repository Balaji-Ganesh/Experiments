// Approach_1: Uses 2 DFS and a is_visited array to keep track of te visit status of each element...
// Ref: TechDose (Youtube)
#include <iostream>
#include <vector>
#define DEBUG_MODE 0		// Change to switch between debug_mode and normal_mode....
using namespace std;

// Global declaration of the helper functions..
void make_island_as_water(vector<vector<char>> &grid, int x, int y, int rows, int cols);						// DFS...
void is_border_island(vector<vector<char>> &grid, vector<vector<bool>> &is_visited, int x, int y, int rows, int cols);			// DFS.. 
void find_border_islands(vector<vector<char>> &board);

// Global variable to find the islands which are connected to the border..
bool is_connected=false;		// Intially let's assume that, the passed island isn't connected to border. If not, changed at appropriate place....

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

	// Finally print the grid...
	for (int i=0; i<num_rows; i++)
	{
		for (int j=0; j<num_cols; j++)
			cout << board[i][j] << "  ";
		cout << endl;
	}
}

//Implementation of the globally declared helper functions..
void find_border_islands(vector<vector<char>> &grid)			// NOTICE that, its the reference paramter.....
{
	// Handling empty grid cases...
	int rows = grid.size();
	if (rows <= 1)
	{
		cout << "[WARNING] Passed empty grid, please pass a valid grid to find the islands which are at border." << endl;
		return;
	}
	int cols = grid[0].size();
	if (cols <=1)
	{
		cout << "[WARNING] Please pass the grid, which has columns >=2." << endl;
		return;
	}
	
	// Visited array, to be safe from checking each cell multiple times...
	vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));
	// Start iterating each cell..
	for (int i=1; i<rows-1; i++)
		for (int j=1; j<cols-1; j++)
			if (grid[i][j] == 'O' && is_visited[i][j]==false)
			{
				is_connected = false;
				is_border_island(grid, is_visited, i, j, rows, cols);
				if (is_connected == false)		// When known that, it wasn't a island connected to border..
					make_island_as_water(grid, i, j, rows, cols);
				//is_connected=true;	/// Why this.....................................................................CHECKPOINT-1
			}

}

void is_border_island(vector<vector<char>> &board, vector<vector<bool>> &is_visited, int x, int y, int rows, int cols)	// NOTICE that there are reference parameters..
{
	/* Base cases for recursions....*/
	// If the cell isn't the island or its already been visited....
	if(board[x][y] != 'O' || is_visited[x][y] == true)
	{
		if( DEBUG_MODE)
			cout << "[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'." << endl;
		return;
	}
	
	// If reached border.. means that island is connected to border.. hence make change to the "is_connected" global variable..
	if (x<=0 || x==rows ||  y<=0 || y==cols)
	{
		if (DEBUG_MODE)
	       		cout << "[INFO] Reached base case of the recursion...Island connected to border." << endl;
		is_visited[x][y] = true;
		is_connected = true;
		return;
	}
	
	// As the part of island is now visited, mark as visited...
	is_visited[x][y]=true;

	// Span to the four adjacent directions of the cell..
	is_border_island(board, is_visited, x-1, y, rows, cols);	// Bottom..
	is_border_island(board, is_visited, x+1, y, rows, cols);	// Top..
	is_border_island(board, is_visited, x, y-1, rows, cols);	// Left..
	is_border_island(board, is_visited, x, y+1, rows, cols);	// Right..
}

void make_island_as_water(vector<vector<char>> &grid, int x, int y, int rows, int cols)
{

	/** Baase case for the recursion....*/
	// If exceeding the borders.. simply take the back step...
	if (x<=0 || y<=0 || x>=rows || y>=cols || grid[x][y] == 'X')
	{
		if (DEBUG_MODE)
			cout << "[INFO] Reached base case of the recursion. Exceeding the boundaries of the area grid..." << endl;
		return;				// As it was an incorrect decision, back track...
	}

	grid[x][y] = 'X';		// Mark as water..

	// Span over adjacent cells of the island...
	make_island_as_water(grid, x, y+1, rows, cols);		// Right..
	make_island_as_water(grid, x, y-1, rows, cols);		// Left..
	make_island_as_water(grid, x-1, y, rows, cols);		// Bottom..
	make_island_as_water(grid, x+1, y, rows, cols);		// Top..
}


/* Output:
 *
 *
 * krishna@helloworld:.../Surrounding_Problem$ g++ surrounding_problem_DFS_20013721.cpp -o surrounding_problem_DFS_20013721
krishna@helloworld:.../Surrounding_Problem$ ./surrounding_problem_DFS_20013721
Enter the dimensions of the grid.
um_rows: 3
num_cols: 3
Please enter the grid of 3 x 3:
X	X	X
X	O	X
X	X	X
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of the recursion. Exceeding the boundaries of the area grid...
[INFO] Reached base case of the recursion. Exceeding the boundaries of the area grid...
[INFO] Reached base case of the recursion. Exceeding the boundaries of the area grid...
[INFO] Reached base case of the recursion. Exceeding the boundaries of the area grid...
X  X  X
X  X  X
X  X  X
krishna@helloworld:.../Surrounding_Problem$ ./surrounding_problem_DFS_20013721
Enter the dimensions of the grid.
um_rows: 4
num_cols: 4
Please enter the grid of 4 x 4:
X	X	O	X
O	X	O	X
X	O	X	O
X	X	O	X
[INFO] Reached base case of the recursion...Island connected to border.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of recursion... It might be 'already visted one' or 'it is not an island'.
[INFO] Reached base case of the recursion. Exceeding the boundaries of the area grid...
[INFO] Reached base case of the recursion. Exceeding the boundaries of the area grid...
[INFO] Reached base case of the recursion. Exceeding the boundaries of the area grid...
[INFO] Reached base case of the recursion. Exceeding the boundaries of the area grid...
X  X  O  X
O  X  O  X
X  X  X  O
X  X  O  X
krishna@helloworld:.../Surrounding_Problem$ vim surrounding_problem_DFS_20013721.cpp +71
krishna@helloworld:.../Surrounding_Problem$ g++ surrounding_problem_DFS_20013721.cpp -o surrounding_problem_DFS_20013721
krishna@helloworld:.../Surrounding_Problem$ ./surrounding_problem_DFS_20013721
Enter the dimensions of the grid.
um_rows: 4
num_cols: 3
Please enter the grid of 4 x 3:
X	X	O
O	O	X
X	X	O
X	O	X
X  X  O
O  O  X
X  X  O
X  O  X
krishna@helloworld:.../Surrounding_Problem$ ./surrounding_problem_DFS_20013721
Enter the dimensions of the grid.
um_rows: 3
num_cols: 5
Please enter the grid of 3 x 5:
X	X	X	X	O
X	O	O	O	X
O	X	X	X	O
X  X  X  X  O
X  X  X  X  X
O  X  X  X  O

 

*
*  Time Complexity:
*  	Two DFS's work on the entire board grid of size m*n. 
*  	 - Hence m*n + m*n = 2(m*n)
  	 - So, the complexity will be O(m*n)
  Space Complexity:
  	Two grids of size (board and is_visited) m*n.
	Hence it will be 2(m*n) => O(m*n).
 * */







