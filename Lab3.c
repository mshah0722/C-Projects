#include <stdio.h>   // Imports the content of the standard library
#include <math.h>   // Imports the content of the math library

int main(void)   // Main function for the program
{
    // The following defines the input variables for the Project 
    double costOfCoffee, amountOfCoffeeMoney;
    int couponsRequiredForFreeCoffee; 
    
    // The following defines the output variables for the Project
    int coffeesThatCanBePurchased, freeCoffee;
    double amountOfMoneyLeft;
    int couponsRemaining;
    double averageMoneySpentOnEachCoffee;
    
    // The following command presents the message to the user by printing it on the screen
    printf("How much does a coffee cost?\n");
    scanf("%lf", &costOfCoffee);
    
    if (costOfCoffee < 0.01)   // The if statement is a control flow statement which controls the output of the code
        printf("Invalid Output.");
    
    else   // If the code doesn't meet the requirement of the if statment then the computer follows the else command
        printf("How many coupons does it take to get a free coffee?\n");
        scanf("%d", &couponsRequiredForFreeCoffee);
        
        if (couponsRequiredForFreeCoffee < 1)   // I have used nested if and else statements to control the flow of code depending on user input
            printf("Invalid Output.");
        
        else   // I used nested if and else statement here to check if the user input is valid or not
            printf("How much money do you have to spend on coffee this month?\n");
            scanf("%lf", &amountOfCoffeeMoney);
            
            if (amountOfCoffeeMoney < 0)   // Only if the inputs are valid then does the prompt continue, otherwise it displays a 'Invalid Output' message
                printf("Invalid Output.");
            
            else   // The following calculations take place if the previous three inputs are valid
                
                coffeesThatCanBePurchased = amountOfCoffeeMoney / costOfCoffee;
                freeCoffee = coffeesThatCanBePurchased / couponsRequiredForFreeCoffee;
                amountOfMoneyLeft = amountOfCoffeeMoney - (costOfCoffee * coffeesThatCanBePurchased);
                couponsRemaining = (coffeesThatCanBePurchased % couponsRequiredForFreeCoffee) + freeCoffee;
                averageMoneySpentOnEachCoffee = (amountOfCoffeeMoney - amountOfMoneyLeft) / (coffeesThatCanBePurchased + freeCoffee);
                
                // The calculations are presented to the user if all three inputs are valid
                printf("This month, you can purchase %d coffees at $%0.2lf each.\n", coffeesThatCanBePurchased, costOfCoffee);
                
                if (freeCoffee == 0)   // If the user does not have enough coupons for free coffee then the following message will be displayed
                    printf("You will not be able to redeem any additional coffees from coupons this month.\n", freeCoffee);
                
                else   // If the user does have enough coupons for free coffee then the following message will be displayed
                    printf("You will be able to redeem an additional %d coffee(s) from coupons.\n", freeCoffee);
                
                // The following messages conclude the presentation of the calculations
                printf("At the end of the month, you will have $%0.2lf and %d coupon(s) remaining.\n", amountOfMoneyLeft, couponsRemaining);
                printf("On average, you spent $%0.2lf on each cup of coffee this month.\n", averageMoneySpentOnEachCoffee);
    
    return 0;   // Returning the integer 0 will indicate the execution process for the main function is terminated
}
