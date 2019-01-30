#include <stdio.h>
#include <math.h>
// Imports the content of the standard library and the math library

int main(void)
{
    // The input variables for the Project
    double costOfCoffee, amountOfCoffeeMoney;
    double couponsRequiredForFreeCoffee;
   
    // The output variables for the Project
    int coffeesThatCanBePurchased, freeCoffee;
    double amountOfMoneyLeft;
    int couponsRemaining;
    double averageMoneySpentOnEachCoffee;
   
    printf("How much does a coffee cost?\n");
    scanf("%lf", &costOfCoffee);
   
    if (costOfCoffee < 0.01)   // The if statement is a control flow statement which controls the output of the code
    {
        printf("Invalid Input.");
        return 0;
    }

    printf("How many coupons does it take to get a free coffee?\n");
    scanf("%lf", &couponsRequiredForFreeCoffee);
    
    if (couponsRequiredForFreeCoffee < 1)
    {
        printf("Invalid Input.");
        return 0;
    }
    
    // The next else if statement checks if the input is an integer or not   
    else if ((int) couponsRequiredForFreeCoffee != couponsRequiredForFreeCoffee)
    {
        printf("Invalid Input.");
        return 0;
    }
    
    printf("How much money do you have to spend on coffee this month?\n");
    scanf("%lf", &amountOfCoffeeMoney);
           
    if (amountOfCoffeeMoney < 0)   // Only if the inputs are valid then does the prompt continue, otherwise it displays a 'Invalid Input' message
    {
        printf("Invalid input.");
        return 0;
    }
        
    coffeesThatCanBePurchased = amountOfCoffeeMoney / costOfCoffee;
    freeCoffee = coffeesThatCanBePurchased / couponsRequiredForFreeCoffee;
    amountOfMoneyLeft = amountOfCoffeeMoney - (costOfCoffee * coffeesThatCanBePurchased);
    couponsRemaining = (coffeesThatCanBePurchased % (int) couponsRequiredForFreeCoffee) + freeCoffee;
    
    // The free coffees increase the number of coupons, which also increases the number of free coffees and so on
    // The following code accounts for this and adds a free coffee based on the new number of coupons remaining
    while (couponsRemaining>=couponsRequiredForFreeCoffee)
    {
        freeCoffee++;
        couponsRemaining--;
    }
    
    averageMoneySpentOnEachCoffee = (amountOfCoffeeMoney - amountOfMoneyLeft) / (coffeesThatCanBePurchased + freeCoffee);
    
    printf("This month, you can purchase %d coffees at $%0.2lf each.\n", coffeesThatCanBePurchased, costOfCoffee);
    
    if (freeCoffee == 0)   // If the user does not have enough coupons for free coffee then the following message will be displayed
    {
        printf("You will not be able to redeem any additional coffees from coupons this month.\n");
    }           
    
    else   // If the user does have enough coupons for free coffee then the following message will be displayed
    {
        printf("You will be able to redeem an additional %d coffee(s) from coupons.\n", freeCoffee);
    }
    
    // The following messages conclude the presentation of the calculations
    printf("At the end of the month, you will have $%0.2lf and %d coupon(s) remaining.\n", amountOfMoneyLeft, couponsRemaining);
    printf("On average, you spent $%0.2lf on each cup of coffee this month.\n", averageMoneySpentOnEachCoffee);
    
    return 0;
}
