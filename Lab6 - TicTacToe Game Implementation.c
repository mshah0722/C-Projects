// This program is used to play the popular game of Tic Tac Toe

// The following imports the libraries for the program 
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

// The following function prints the Tic Tac Toe Board
// I used a ternary operator to execute code based on the result of a binary condition
// This allowed me to convert 65 to A and 66 to B while keeping the 1-9 numbers as numbers on the board
void printBoard(int board[], int playerA, int playerB)
{
    printf("\n");
    printf(" %c %c %c\n", board[0]<64 ? board[0]+48 : board[0], board[1]<64 ? board[1]+48 : board[1], board[2]<64 ? board[2]+48 : board[2]);
    printf(" %c %c %c\n", board[3]<64 ? board[3]+48 : board[3], board[4]<64 ? board[4]+48 : board[4], board[5]<64 ? board[5]+48 : board[5]);
    printf(" %c %c %c\n", board[6]<64 ? board[6]+48 : board[6], board[7]<64 ? board[7]+48 : board[7], board[8]<64 ? board[8]+48 : board[8]);
    printf("\n");
}

// I used this function to request a valid input
// I used a do while loop to loop the function until a valid input was entered by the user
int requestValidInput(int board[], int playerA, int playerB)
{
    int inputOne;
    int indexOne;
    int value;
    
    printf("Please enter a valid position to play.\n");
    scanf("%d", &inputOne);
    
    do
    {
        if (inputOne < 1 || inputOne > 9) // checks whether the input is between 1 to 9
        {
            printf("Invalid input, please try again.\n");
            scanf("%d", &inputOne);
            value = 0;
        }
    
        else if (inputOne != board[inputOne - 1]) // checks whether the position has been filled already
        {
            printf("That position has already been played, please try again.\n");
            scanf("%d", &inputOne);   
            value = 0;
        }
    
        else //if neither conditions meet then the input is accepted
        {
            value = inputOne;
        }  
        
    } while (value != inputOne);
    
    indexOne = inputOne-1;
    return indexOne; // inputOne -1 returns the index of the array where it will be entered
}

// This function checks for a winner using the 8 possible ways to win Tic Tac Toe
// The function uses if and else statements to check if winning conditions have been met
int checkForWinner(int board[], int playerA, int playerB)
{
    int winner;
    
    if (board[0] == board[1] && board[1] == board[2])
    {
        winner = 1;
    }
    
    else if (board[3] == board[4] && board[4] == board[5])
    {
        winner = 1;
    }
    
    else if (board[6] == board[7] && board[7] == board[8])
    {
        winner = 1;
    }
    
    else if (board[0] == board[3] && board[3] == board[6])
    {
        winner = 1;
    }
    
    else if (board[1] == board[4] && board[4] == board[7])
    {
        winner = 1;
    }
    
    else if (board[2] == board[5] && board[5] == board[8])
    {
        winner = 1;
    }
    
    else if (board[0] == board[4] && board[4] == board[8])
    {
        winner = 1;
    }
    
    else if (board[2] == board[4] && board[4] == board[6])
    {
        winner = 1;
    }
    
    else 
    {
        winner = 0;
    }
    
    return winner;
}

// In the main function all the other functions are called to run the code
int main(void)
{ 
    int board[9] = {};
    int i = 0;
    int j = 0;
    
    // The following initializes the board
    for (i = 0; i < 9; i++)
    {
        board[i] = i+1;
    }
    
    const int playerA = 65;
    const int playerB = 66;
    int inputOne = 0;
    int winner = 0;
    
    // The following bool statements control the flow of the game and loop the game when certain conditions have not been met
    bool player = true;
    bool gameOver = false;
    
    while (gameOver == false)
    {
        printf("The current state of the Tic-tac-toe Board:\n");
        printBoard(board, playerA, playerB);
        if (player == true)
        {
           printf("It is Player A's turn.\n"); 
        }
        
        else
        {
            printf("It is Player B's turn.\n"); 
        }
        
        inputOne = requestValidInput(board, playerA, playerB);
        
        if (player == true)
        {
            board[inputOne] = playerA; 
        }
        
        else if (player == false)
        {
            board[inputOne] = playerB;
        }
        
        // The following code calls the function "checkForWinner" to check if any players have won
        winner = checkForWinner(board, playerA, playerB);
        if (winner == 1)
        {
            if (player == true)
            {
                printf("Player A wins!\n");
                printBoard(board, playerA, playerB);
                gameOver = true;
            }
            
            else if(player != true)
            {
                printf("Player B wins!\n");
                printBoard(board, playerA, playerB);
                gameOver = true;
            }
        }
        j++;
        
        // When 9 turns have occured, and there is not a winner, this means that the game has ended in a stalemate
        if (j==9)
        {
            printf("It's a draw!\n");
            printBoard(board, playerA, playerB);
            gameOver = true;
        }
        
        // The following statement switches the player each turn
        player = !player;
    }
	return 0;
}
