#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main() 
{
    char grid[3][3] = 
	{
       {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} 
	};
	
    int position, row, col, player = 1;
    char mark;

    while (1) 
	{
        // Display the grid
        
        printf(" %c | %c | %c \n", grid[0][0], grid[0][1], grid[0][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", grid[1][0], grid[1][1], grid[1][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", grid[2][0], grid[2][1], grid[2][2]);

        // Determining the current player's mark
        
        mark = (player == 1) ? 'X' : 'O';

        // Input position
        
        printf("Player %d (%c), enter your position (1-9): ", player, mark);
        scanf("%d", &position);

        // Validating input and update the grid
        
        if (position < 1 || position > 9) 
		{
            printf("Invalid position! Please try again.\n");
            continue;
        }

        row = (position - 1) / 3;
        col = (position - 1) % 3;

        if (grid[row][col] != ' ') 
		{
            printf("Position already taken! Please try again.\n");
            continue;
        }
        
        // Remark For Player
        
        grid[row][col] = mark;
        
        // Switch player
        
        player = (player == 1) ? 2 : 1;

        // Function to check for a win or draw.
        
    }
    return 0;
}