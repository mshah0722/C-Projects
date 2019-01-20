/*
  This program will convert two positive input numbers and compute their products, 
  their difference, and sum of the square roots of the two numbers.
*/

#include <stdio.h>   //Includes contents of the standard library header file stdio.h
#include <math.h>   //Imports the math library in C to compute results

int main(void)   //Program execution starts in the main function
{
	double firstInputNumber, secondInputNumber;   //Defines the two input numbers
    double outputProduct, outputDifference, outputSumOfSquareRoots;   //Defines the output numbers
    
    printf("Enter two positive numbers: ");   //Present the message to the user
    scanf("%lf ", &firstInputNumber);   //%lf will require input of the first decimal point number
    scanf("%lf", &secondInputNumber);   //%lf will require input of the second decimal point number
    
    outputProduct = firstInputNumber * secondInputNumber;   //Calculates the product of the two input numbers
    outputDifference = firstInputNumber - secondInputNumber;   //Calculates the difference of the two input numbers: (first number) - (second number)
    outputSumOfSquareRoots = sqrt(firstInputNumber) + sqrt(secondInputNumber);   //Calculates the sum of the square roots of the input numbers
    
    printf("The product is: %.2f, the difference is: %.2f and the sum of the roots is: %.2f\n", outputProduct, outputDifference, outputSumOfSquareRoots);
    //The above statements prints of the the three tabulated calculations
	
    return 0;   //Returning the integer 0 will indicate the execution process is terminated
}
