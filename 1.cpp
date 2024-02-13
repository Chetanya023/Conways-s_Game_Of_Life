#include <iostream>                    // header file 
#include <vector>                      // vector file for dynamic arrays 
using namespace std;                   
int countLiveNeighbors(const vector<vector<int>>& grid, int x, int y)        // counting the number of live neighours from the coordinate (x,y) - x,y centre of the grid
{
    int liveNeighbors = 0;                    // it initializes the live neighbours to 0 to count live neighbours
    for (int dx = -1; dx <= 1; dx++)          // two nested for loops for iterating over each cell over the grid
    {
        for (int dy = -1; dy <= 1; dy++) 
        {
            if (dx == 0 && dy == 0) continue;         // examining that the cell is exactly the centre cell or not 
            int newX = x + dx;                        // for calculating the new x and y coordinates by increasing the current coordinates with the change in the coordinates
            int newY = y + dy;
            
            // this below condition checks that the neighboring cell is in the boundaries i.e left , right , top ,bottom and also checks whether there are any alive cells or not
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 1) 
            {
                liveNeighbors++;                    // if there are alive cells then increase the liveneighbours counter
            }
        }
    }
    return liveNeighbors;                             // to return the number of live neighbours
}
int main() 
{
    int gridSize;                                        // declaring the gridSize variable of type int 
    
    cout << "Enter the grid size: ";           
    cin >> gridSize;                                                   // inputing the grid size from user

    vector<vector<int>> grid(gridSize, vector<int>(gridSize, 1));          // Initialize all cells in the grid as alive (1)

    cout << "Initial Generation:\n";	

    // Display the initial grid
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++) 
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    int generation = 0;
    vector<vector<int>> newGrid(gridSize, vector<int>(gridSize, 0));         // Create a new grid with all cells initialised to 0 (dead)
    
    // the below nested loops are used for iterating through each cell of the grid
    for (int i = 0; i < gridSize; i++) 
    {
        for (int j = 0; j < gridSize; j++) 
        {
            int liveNeighbors = countLiveNeighbors(grid, i, j);       // function call with 3 arguments

            if (liveNeighbors == 3)                        // condition check for alive cells 
            {
                newGrid[i][j] = 1; // Cell becomes alive       // changing the cell value to 1
            }
        }
    }

    grid = newGrid;                                 // Update the main grid with the new generation
    generation++;
    cout << "Final Generation:\n";

    // Display the final grid
    for (int i = 0; i < gridSize; i++) 
    {
        for (int j = 0; j < gridSize; j++) 
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << "All cells are dead. Game over!" << endl;
    return 0;
}
