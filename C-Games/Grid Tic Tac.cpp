#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() 
{
    // Initialize a 3x3 grid
    
    char grid[3][3] = 
    {
        {' ', ' ', ' '}, 
        {' ', ' ', ' '}, 
        {' ', ' ', ' '}
    };
	
    int row, col, player = 1;
    char mark;

    while (1) 
    {
        // Display The Grid
        
        printf("\n");
        printf(" %c | %c | %c \n", grid[0][0], grid[0][1], grid[0][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", grid[1][0], grid[1][1], grid[1][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", grid[2][0], grid[2][1], grid[2][2]);

        // Determine the current player's mark
        
        mark = (player == 1) ? 'X' : 'O';

        // Input row and column
        
        printf("Player %d (%c), enter your position as row and column (e.g., 0 1): ", player, mark);
        if (scanf("%d %d", &row, &col) != 2) 
        {
            printf("Invalid input! Please enter two integers separated by a space.\n");
            while (getchar() != '\n');
            
			// Clear the input buffer
			
            continue;
        }

        // Validate input
        
        if (row < 0 || row > 2 || col < 0 || col > 2) 
        {
            printf("Invalid position! Rows and columns must be between 0 and 2. Please try again.\n");
            continue;
        }

        if (grid[row][col] != ' ') 
        {
            printf("Position already taken! Please try again.\n");
            continue;
        }

        // Place the mark
        
        grid[row][col] = mark;

        // Function to check for a winner or draw here

        // Switch player
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}
