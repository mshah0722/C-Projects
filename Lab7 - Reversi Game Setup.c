/*
This Lab 7 develops the code for a Reversi Game
In this lab I will be implementing board configuration and checking move legality
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The following function statically initializes the 2-D game board for the up to 26 columns and rows
void initializeBoard(char board[][26], int n)
{
    int i, j;
    
    for (i = 0; i <= n-1; i++)
    {
        for (j = 0; j <= n-1; j++)
        {
            board[i][j] = 'U';
            board[n/2 - 1][n/2 - 1] = 'W';
            board[n/2][n/2 - 1] = 'B';
            board[n/2 - 1][n/2] = 'B';
            board[n/2][n/2] = 'W';
        }
    }
}

// The following function prints the game board along with the axis labeled a-z depending on the size of the of the dimensions
void printBoard(char board[][26], int n)
{
    int i, j, k;
    
    printf("  ");
    
    for (k = 0; k <= n-1; k++)
    {
        printf("%c", 'a' + k);
    }
    
    printf("\n");
    
    for (i = 0; i <= n-1; i++)
    {
        printf("%c ", 'a' + i);
        for (j = 0; j < n; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }        
}

// This boolean functions checks whether the specified row and col lie within the board dimensions
bool positionInBounds(int n, int row, int col)
{
    return (((row >= 0) && (row <= n-1)) && ((col >= 0) && (col <= n-1)));
}

// This boolean function checks whether the row and col are in a legal position for a tile of colour by searching in the direction specified by deltaRow and deltaCol
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol)
{
    int i = 1;
    char opponentColor;
    
    if(colour == 'W') 
    {
        opponentColor = 'B';
    }
    
    else 
    {
        opponentColor = 'W';
    }
            
    // immediate surroundings
    while ((positionInBounds(n, row + (deltaRow * i), col + (deltaCol * i))) 
        && ((board[row + (deltaRow * i)][col + (deltaCol * i)]) != (colour)) && ((board[row + (deltaRow * i)][col + (deltaCol * i)]) != ('U')))
    {
        i++;
        if ((positionInBounds(n, row + (deltaRow * i), col + (deltaCol * i))) && (board[row + (deltaRow * i)][col + (deltaCol * i)] == colour))
        {
            return true;
        }
        
        else
        {
            if ((positionInBounds(n, row + (deltaRow * i), col + (deltaCol * i))) && (board[row + (deltaRow * i)][col + (deltaCol * i)] == opponentColor)) 
            {
                continue;
            } 
            
            else 
            {
                if((positionInBounds(n, row + (deltaRow * i), col + (deltaCol * i)) == false)) 
                {
                    return false;
                } 
                
                else 
                {
                    if(board[row + (deltaRow * i)][col + (deltaCol * i)] == colour) 
                    {
                        return true;
                    }
                    
                    else
                    {
                        return false;
                    }
                }
            }
        } 
    }
    return false;
}

// This function checks for possible moves on the board
void possibleMoves(char board[][26], int n, char colour)
{
    int row, col, deltaRow, deltaCol;
    
    bool signal = false;
    
    printf("Available moves for %c:\n", colour);
    
    for (row = 0; row <= n-1; row++)
    {
        for (col = 0; col <= n-1; col++)
        {
            if (board[row][col] == 'U')
            {
                for (deltaRow = -1; deltaRow <= 1; deltaRow++)
                {
                    if (signal == true) 
                    { 
                        signal = false; 
                        break;
                    }

                    for (deltaCol = -1; deltaCol <= 1; deltaCol++)
                    {
                        if (deltaRow == 0 && deltaCol == 0)
                        {
                        }
                        
                        else
                        {
                            if (checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol))
                            {
                                printf("%c%c\n", row + 'a', col + 'a');
                                signal = true;
                            }
                        }  
                    }
                }
            }
        }
    }
}

// This function is responsible for flipping the tiles for the game
void flipTiles(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol)
{
    int i = 1;
    while (board[row + (deltaRow * i)][col + (deltaCol * i)] != colour)
    {
        board[row + (deltaRow * i)][col + (deltaCol * i)] = colour;
        i++;
    }
}

// This functions checks for valid input
void checkForValidInput(char board[][26], int n, char colour, int row, int col)
{
    int deltaRow, deltaCol;
    
    if ((positionInBounds(n, row, col)) && (board[row][col] == 'U'))
    {
        for (deltaRow = -1; deltaRow <= 1; deltaRow++)
        {
            for (deltaCol = -1; deltaCol <= 1; deltaCol++)
            {
                if((deltaRow != 0 || deltaCol != 0) && checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol))
                {
                    board[row][col] = colour;
                        
                    flipTiles(board, n, row, col, colour, deltaRow, deltaCol);
                
                    printf("Valid move.\n");
                    printBoard(board, n);
                    return;
                }                 
            }
        }
        
        printf("Invalid move.\n");
        printBoard(board, n);
        return;
    }
        
    else
    {
        printf("Invalid move.\n");
        printBoard(board, n);
        return;
    }

}

// In the main function we use the individual functions to run the game
int main(void)
{
    int n;
    char board[26][26];
    
    printf("Enter the board dimension: ");
    scanf("%d", &n);
    initializeBoard(board, n);
    printBoard(board, n);
    
    char colour, row, col;
    printf("Enter board configuration:\n");
    
    while (colour != '!' || row != '!' || col != '!')
    {
        scanf(" %c%c%c", &colour, &row, &col);
        board[row - 'a'][col - 'a'] = colour;
    }
    
    printBoard(board, n);
    
    possibleMoves(board, n, 'W');
    
    possibleMoves(board, n, 'B');
    
    printf("Enter a move:\n");
    scanf(" %c%c%c", &colour, &row, &col);
    
    checkForValidInput(board, n, colour, row - 'a', col - 'a');
    
    return 0;
}
