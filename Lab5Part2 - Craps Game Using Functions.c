// This program is used to play the popular dice game of Craps

// The following imports the libraries for the program 
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

// The function rollDice generates two random numbers, each between 1 and 6, and returns their sum.
int rollDice(void)
{
    int rollOne = 0;
    int rollTwo = 0;
    int sum = 0;
    
    // Using rand function for rolling each dice to obtain a number between 1 and 6.
    rollOne = rand() % 6 + 1;
    rollTwo = rand() % 6 + 1;
    sum = rollOne + rollTwo;
    
    return sum;
}

// The function playGame plays one craps game. It returns true if the player wins and false if the player loses.
bool playGame(void)
{
    int sum = rollDice();
    int newSum = 0;
    
    printf("You rolled: %d\n", sum);
    if (sum == 7 || sum == 11)
    {
        printf("You win!\n");     
        return true;
    }
    
    else if (sum == 2 || sum == 3 || sum == 12)
    {
        printf("You lose!\n");
        return false;
    }
    
    else
    {
        printf("Your point is: %d\n", sum);
        newSum = rollDice();
        printf("You rolled: %d\n", newSum);
            
        if (newSum == 7)
        {
            printf("You lose!\n");
            return false;
        }

        else if (newSum == sum)
        {
            printf("You win!\n");     
            return true;
        }
    }
        
    while (newSum != sum)
    {
        newSum = rollDice();
        printf("You rolled: %d\n", newSum);
    
        if (newSum == 7)
        {
            printf("You lose!\n");
            return false;
        }

        else if (newSum == sum)
        {
            printf("You win!\n");     
            return true;
        }
    }
}

// The function winLoss keeps track of the number of wins and losses in one session.
// It repeatedly calls the function playGame until the user requests to end the program. 
// winLoss also reports the number of wins and losses before it ends.
void winLoss(void)
{
    char playAgain;
    
    int winCount = 0;
    int lossCount = 0;
    bool result = playGame();
    while (result == true)
    {
        winCount ++;
        printf("Play again? ");
        scanf(" %c", &playAgain);
        
        while (playAgain == 'y' || playAgain == 'Y')
        {
            if (playGame() == true)
            {
                winCount ++;
                printf("Play again? ");
                scanf(" %c", &playAgain);
            }
            
            else
            {
                lossCount ++;
                printf("Play again? ");
                scanf(" %c", &playAgain);
            }
        }
        printf("\n");
        break;
    }
    
    while (result == false)
    {
        lossCount ++;
        printf("Play again? ");
        scanf(" %c", &playAgain);
    
        while (playAgain == 'y' || playAgain == 'Y')
        {
            if (playGame() == true)
            {
                winCount ++;
                printf("Play again? ");
                scanf(" %c", &playAgain);
            }
            
            else
            {
                lossCount ++;
                printf("Play again? ");
                scanf(" %c", &playAgain);
            }
        }
        printf("\n");
        break;
    }
    // Prints the total wins and losses
    printf("Wins: %d\n", winCount);
    printf("Losses: %d\n", lossCount);
}

int main(void)
{
    winLoss();
}
