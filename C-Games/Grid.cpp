#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 3

// Function to print the grid

void printGrid(char grid[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            printf(" %c ", grid[i][j]);
            if (j < SIZE - 1) 
                printf("|");
                
				// Vertical separator
        }
        printf("\n");
        if (i < SIZE - 1) 
            printf("---|---|---\n");
            
			// Horizontal separator
    }
}

// Function to check if a player has won

int checkWinner(char grid[SIZE][SIZE], char mark) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        // Check rows and columns
        
        if ((grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] == mark) || 
            (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] == mark)) 
        {
            return 1;
            
			// Winner found
        }
    }

    // Check diagonals
    
    if ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] == mark) || 
        (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] == mark)) 
    {
        return 1;
        
		// Winner found
    }

    return 0; 
    
	// No winner
}

// Function to check for a draw

int isDraw(int moves) 
{
    return moves == SIZE * SIZE;
    
	// Draw if all positions are filled
}

// Function to get and validate input from the user\

int getInput(int *row, int *col, char grid[SIZE][SIZE]) 
{
    printf("Enter row and column (0-2): ");
    if (scanf("%d %d", row, col) != 2) 
    {
        while 
		   (getchar() != '\n');
		   
		// Clear the input buffer
		
        return 0;
        
		// Invalid input
    }

    if (*row < 0 || *row >= SIZE || *col < 0 || *col >= SIZE || grid[*row][*col] != ' ') 
    {
        printf("Invalid position! Try again.\n");
        return 0;
        
		// Invalid position
    }

    return 1;
    
	// Valid input
}

// Function to play the game

void playGame() 
{
    char grid[SIZE][SIZE] = 
	{
	    {' ', ' ', ' '}, 
	    {' ', ' ', ' '}, 
	    {' ', ' ', ' '}
	};
	
    int row, col, player = 1, moves = 0;
    char mark;

    while (1) 
    {
        printGrid(grid);
        
		// Display the grid

        mark = (player == 1) ? 'X' : 'O';
        
		// Determine the current player's mark

        // Get a valid input for row and column
        
        while (!getInput(&row, &col, grid)); 

        grid[row][col] = mark;
        
		// Place the mark on the grid
		
        moves++;

        // Check for a winner
        
        if (checkWinner(grid, mark)) 
        {
            printGrid(grid);
            printf("\nPlayer %d (%c) wins!\n", player, mark);
            break;
        }

        // Check for a draw
        
        if (isDraw(moves)) 
        {
            printGrid(grid);
            printf("\nIt's a draw!\n");
            break;
        }

        // Switch player
        
        player = (player == 1) ? 2 : 1;
    }
}

// Main function to start the game

int main() 
{
    printf("Welcome to Tic-Tac-Toe!\n");
    playGame();
    
	// Start the game

    return 0;
}
