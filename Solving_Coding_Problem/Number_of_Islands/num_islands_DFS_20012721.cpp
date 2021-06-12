/*
 *
 *         From LeetCode: https://leetcode.com/problems/number-of-islands/
 *         The solution was explained by TechDose: https://youtu.be/__98uL6wst8
 *
 *         Problem-Statement
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    grid[i][j] is '0' or '1'.


 * */

#include <iostream>
#include <vector>
#define DEBUG_MODE 0
using namespace std;

// Global declaration of utility functions..
int calculate_islands(vector<vector<char>> &grid);	// as Reference parameter..
void mark_island(vector<vector<char>> &grid, int rows, int cols, int x, int y);

int main()
{
	vector<vector<char>> grid;
	int m=0, n=0;
	char temp;
	cout << "Enter the dimensions of the grid. \nm = ";
	cin >> m;
	cout << "n = ";
	cin >> n;
	
	// Get the grid from the user...
	for (int i=0; i<m; i++)
	{
		vector<char> temp_vec;		// A vector for each row...
		for (int j=0; j<n; j++)
		{
			cin >> temp;
			temp_vec.push_back(temp);
		}
		grid.push_back(temp_vec);	// Place in the grid..
	}

	// Calculate the number of islands in the passed grid..
	cout << "Total islands are: " << calculate_islands(grid) << endl;

	return 0;
}

/* Implementation of the globally declared functions.. */
// Helper function...
int calculate_islands(vector<vector<char>> &grid)
{
	int rows = grid.size();
	// Empty grid handling...
	if (rows == 0)
	{
		cout << "[WARNING] Passed empty grid, cannot find the islands in the empty grid. Please pass a valid grid." << endl;
		return 0;
	}
	// control here means, grid isn't empty...
	int cols = grid[0].size();
	int num_islands=0;

	// start iterating over the grid..cell be cell...
	for (int i=0; i<rows; i++)
		for (int j=0; j<cols; j++)
			if (grid[i][j] == '1')	// If it is the unvisited island...
			{
				mark_island(grid, rows, cols, i, j);
				num_islands++;
			}
	
	// Return the calculated number_of_islands..
	return num_islands;
}

// DFS..
void mark_island(vector<vector<char>> &grid, int m, int n, int x, int y)
{
	/* Base case for the recursion... */
	// Handling the values that execeed the grid_boundary, and the not island one...
	if (x < 0 || x >=m || y<0 || y>=n || grid[x][y] != '1')
	{
		if (DEBUG_MODE)
			cout << "[INFO] Reached the base case of the recursion...." << endl;
		return;
	}

	// Control here means, then it would be definately a non-visited island. As got visited now, mark as visited..
	grid[x][y] = '*';		// A symbol, to know that this island has already visited...

	// Now mark the adjacent ones... via Recursion...
	mark_island(grid, m, n, x, y-1);	// check Left..
	mark_island(grid, m, n, x, y+1);	// check Right..
	mark_island(grid, m, n, x+1, y);	// Check Top..
	mark_island(grid, m, n, x-1, y);	// check Bottom..
}

/* Output:
 *
 * krishna@helloworld:.../Number_of_Islands$ g++ num_islands_DFS_20012721.cpp -o num_islands_DFS_20012721
krishna@helloworld:.../Number_of_Islands$ ./num_islands_DFS_20012721
Enter the dimensions of the grid. 
m = 4
n = 3
0	0	0
0	1	1
1	0	1
0	1	0
Total islands are: [INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
[INFO] Reached the base case of the recursion....
3
krishna@helloworld:.../Number_of_Islands$ vim num_islands_DFS_20012721.cpp
krishna@helloworld:.../Number_of_Islands$ g++ num_islands_DFS_20012721.cpp -o num_islands_DFS_20012721
krishna@helloworld:.../Number_of_Islands$ ./num_islands_DFS_20012721
Enter the dimensions of the grid. 
m = 4
n = 0
Total islands are: 0
krishna@helloworld:.../Number_of_Islands$ ./num_islands_DFS_20012721
Enter the dimensions of the grid. 
m = 0
n = 0
Total islands are: [WARNING] Passed empty grid, cannot find the islands in the empty grid. Please pass a valid grid.
0
krishna@helloworld:.../Number_of_Islands$ ./num_islands_DFS_20012721
Enter the dimensions of the grid. 
m = 4
n = 2
0	1
1	0
0	1
1	0
Total islands are: 4

 *
 *
 *
 * Time complexity: 
 * 	In worst case
 * 		- All the cells containing the '1's, then recursion call (DFS) call happens for each cell
 * 		- Each cell gets called 5 times (1 via processing the cell, other 4 via adjacent cell calls.
 * 	Hence, its O(m*n).
 *
 * Space Complexity:
 * 	O(1) -- if ignored the space taken by stack in recursion.
 * 	If to be specific..
 * 		O(m*n *memory for each recursive_call)
 * 			-- also includes the parameters in the time of function call.
 *
 * */	















