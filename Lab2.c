#include <stdio.h>   // Imports the content of the standard library
#include <math.h>   // Imports the content of the math library 

int main(void)   // Main function for the program
{
    double purchasePrice, interestRate;   // Defines the two input floating point numbers
    int monthsForRepayment;   // Defines the third input integer number
    double monthlyPayment, totalCostForPurchase;   // Defined the two output floating point numbers
    
    printf("Enter the purchase price of the item: ");   // Presents the message to the user by printing it on the screen
    scanf("%lf", &purchasePrice);   // The user will be prompted to enter a purchase price of the product
    
    printf("Enter the interest rate per year as a percentage: ");   // Presents the message to the user by printing it on the screen
    scanf("%lf", &interestRate);   // The user will be prompted to enter the yearly interest rate percent for the product
    
    printf("Enter the number of months for repayment: ");   // Presents the message to the user by printing it on the screen
    scanf("%d", &monthsForRepayment);   // The user will be prompted to enter the number of months for repayment for the product
    
    interestRate = (interestRate/100)/12;   // Changes the yearly interest rate percent to interest rate per month in decimal form
    monthlyPayment = ((interestRate)/(1 - pow((1 + interestRate),- monthsForRepayment))) * purchasePrice;   // Calculates the monthly Payment using a formula
    totalCostForPurchase = monthlyPayment * monthsForRepayment;   // Calculates the total cost for purchase after repayment
    
    printf("The monthly payment is: %0.2lf\n", monthlyPayment);   // Presents the monthly payment to the user by printing it on the screen
    printf("The total cost of the purchase is: %0.2lf\n", totalCostForPurchase);   // Presents the total cost for purchase after repayment to the user by printing it on the screen
    
    return 0;   // Returning the integer 0 will indicate the execution process for the main function is terminated
}