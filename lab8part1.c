/*
Lab 8 further develops the code from Lab 7 for the Reversi Game
In part 1 I will be implementing a program that plays the Reversi game against a human opponent using a specified algorithm for computer moves.
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

// This function checks if all positions have been filled
bool gameOver(char board[][26], int n, bool *humanMadeInvalid)
{
    int row, col;
    
    if (*humanMadeInvalid == true)
    {
        return true;
    }
    
    for (row = 0; row <= n-1; row++)
    {
        for (col = 0; col <= n-1; col++)
        {
            if (board[row][col] == 'U')
            {
                return false;
            }
        }
    }
    return true;
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
    
    if (colour == 'W') 
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

// This function is responsible for flipping the tiles for the game
void flipTiles(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol)
{
    board[row][col]=colour;
    int i = 1;
    while (board[row + (deltaRow * i)][col + (deltaCol * i)] != colour)
    {
        board[row + (deltaRow * i)][col + (deltaCol * i)] = colour;
        i++;
    }
}  

bool movesPossibleForPlayer(char board[][26], int n, char currentPlayer)
{
    int row, col, deltaRow, deltaCol;
    
    for (row = 0; row <= n-1; row++)
    {
        for (col = 0; col <= n-1; col++)
        {
            if (board[row][col] == 'U')
            {
                for (deltaRow = -1; deltaRow <= 1; deltaRow++)
                {
                    for (deltaCol = -1; deltaCol <= 1; deltaCol++)
                    {
                        if (deltaRow == 0 && deltaCol == 0)
                        {
                        }
                        
                        else
                        {
                            if (checkLegalInDirection(board, n, row, col, currentPlayer, deltaRow, deltaCol))
                            {
                                return true;
                            }
                        }  
                    }
                }
            }
        }
    }
    return false;
}

// This functions checks for valid input
void checkForValidInput(char board[][26], int n, char colour, char computerColour, int row, int col, bool *humanMadeInvalid)
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
                    flipTiles(board, n, row, col, colour, deltaRow, deltaCol);
                    printBoard(board, n);
                    return;
                }                 
            }
        }
    }
    
    printf("Invalid move.\n");
    printf("%c player wins.", computerColour);
    *humanMadeInvalid = true;
    gameOver(board, n, humanMadeInvalid);
    return;
}

int numberOfFlippedTiles(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol)
{
    int i = 1;
    int max = 0;
    while ((positionInBounds(n, row + (deltaRow * i), col + (deltaCol * i))) && board[row + (deltaRow * i)][col + (deltaCol * i)] != colour)
    {
        i++; 
        max++;        
    }
    return max;
}

void copyBoard(char board[][26], int n, char computerColour)
{
    int deltaRow, deltaCol;
    int count = 0;
    int imax = 0;
    int jmax = 0;
    int scoremax = 0;
    
    int boardCopy[26][26];
    
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if ((positionInBounds(n, row, col)) && (board[row][col] == 'U'))
            {
                for (deltaRow = -1; deltaRow <= 1; deltaRow++)
                {
                    for (deltaCol = -1; deltaCol <= 1; deltaCol++)
                    {
                        if((deltaRow != 0 || deltaCol != 0) && checkLegalInDirection(board, n, row, col, computerColour, deltaRow, deltaCol))
                        {
                            count += numberOfFlippedTiles(board, n, row, col, computerColour, deltaRow, deltaCol);
                        }
                    }
                }
                
            }
            boardCopy[row][col] = count;
            count = 0;
        }
    }
    
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (boardCopy[row][col] > scoremax)
            {
                scoremax = boardCopy[row][col];
                imax=row;
                jmax=col;
            }
        }
    }
    
    for (deltaRow = -1; deltaRow <= 1; deltaRow++)
    {
        for (deltaCol = -1; deltaCol <= 1; deltaCol++)
        { 
            if (checkLegalInDirection(board, n, imax, jmax, computerColour, deltaRow, deltaCol))
            {
                flipTiles(board, n, imax, jmax, computerColour, deltaRow, deltaCol);
            }
        }
    }
    
    printf("Computer places %c at %c%c.\n", computerColour, imax + 97, jmax + 97);
    
    printBoard(board, n);
    
}  

void playHumanPlayer(char board[][26], int n, char currentPlayer, char computerColour, char humanColour, bool *humanMadeInvalid)
{
    char row, col;
    
    if (movesPossibleForPlayer(board, n, humanColour))
    {
        printf("Enter move for colour %c (RowCol): ", humanColour);
        scanf(" %c%c", &row, &col);
        checkForValidInput(board, n, currentPlayer, computerColour, row - 'a', col - 'a', humanMadeInvalid);
        return;
    }
    
    else
    {
        printf("%c player has no valid move.\n", humanColour);
        return;
    }
}

void playComputerPlayer(char board[][26], int n, char currentPlayer, char computerColour, char humanColour)
{
        
    if (movesPossibleForPlayer(board, n, computerColour))
    {
        copyBoard(board, n, computerColour);
    } 
   
    else
    {
        printf("%c player has no valid move.\n", computerColour);
    }
}

// This function determines who's turn it is and plays the game accordingly
char whichColourTurn(char board[][26], int n, char currentPlayer, char computerColour, char humanColour, bool *humanMadeInvalid)
{
    if (currentPlayer == humanColour)
    {
        playHumanPlayer(board, n, currentPlayer, computerColour, humanColour, humanMadeInvalid);
        currentPlayer = computerColour;
        
    }
    
    else if (currentPlayer == computerColour)
    {
        playComputerPlayer(board, n, currentPlayer, computerColour, humanColour);
        currentPlayer = humanColour;
    }
    return currentPlayer;
}

int main(void)
{
    int n;
    char board[26][26];
    char currentPlayer = 'B';
    char computerColour, humanColour;
    bool humanMadeInvalid = false;
    
    printf("Enter the board dimension: ");
    scanf(" %d", &n);
    
    printf("Computer plays (B/W): ");
    scanf(" %c", &computerColour);
    
    initializeBoard(board, n);
    printBoard(board, n);

    if (computerColour == 'W')
    {
        humanColour = 'B';
    }
    
    else
    {
        humanColour = 'W';
    }

    while (gameOver(board, n, &humanMadeInvalid) == false)
    {
        currentPlayer = whichColourTurn(board, n, currentPlayer, computerColour, humanColour, &humanMadeInvalid);
    }
    
    if (humanMadeInvalid == false)
    {
        int row, col;
        int compCount = 0;
        int humanCount = 0;
        for (row = 0; row <= n-1; row++)
        {
        
            for (col = 0; col <= n-1; col++)
            {
                if (board[row][col] == computerColour)
                {   
                    compCount++;
                }
    
                else if(board[row][col] == humanColour)
                {
                    humanCount++;
                }
            }
        }
    
        if (compCount>humanCount)
        {
            printf("%c player wins.", computerColour);
            return 0;
        }

        else if (humanCount>compCount)
        {
            printf("%c player wins.", humanColour);
            return 0;
        }
    
        else
        {
            printf("Draw!");
            return 0;
        }
    } 
    return 0;
}
   