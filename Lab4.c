/*
This project will utilize Reimann Sum to calculate area under a function (integral).
*/

// Includes standard, math, and boolean libraries
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Boolean Function used to validate the input from the user
bool validateInput(double left, double right, int n)
{
    if (left < -10.0 || right > 10.0 || right <= left || n <= 0)
    {
        return false;
    }
    
    else
    {
        return true;
    }
}

// Function calculate for the f(x) = 2(x^2)-7x-2 with an input double
double evalFunc(double x)
{
    return ((2 * (pow(x,2))) - (7*x) - 2);
}

// Main Function where all functions are called and utilized
int main(void)
{
    double leftPoint, rightPoint;
    int n;
    double stepSize, midPointEvaluation = 0, leftPointEvaluation = 0, rightPointEvaluation = 0;
    
    // Prints the intial statements
    printf("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use.\n");
    printf("To exit enter 0 0 0\n");
    scanf("%lf %lf %d", &leftPoint, &rightPoint, &n);

    // Checks condition by calling validateInput Function
    if (! validateInput(leftPoint, rightPoint, n))
    {
        if (leftPoint == 0 && rightPoint == 0 && n == 0)
        {
            printf("Invalid inputs...\n\n");
            printf("Terminating main!\n");
            return 0;
        }
        
        // Functions loops until a valid input is placed or 0 0 0 is entered
        while (! validateInput(leftPoint, rightPoint, n))
        { 
            if (! validateInput(leftPoint, rightPoint, n))
            printf("Invalid inputs...\n\n");
         
            printf("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use.\n");
            printf("To exit enter 0 0 0\n");
            scanf("%lf %lf %d", &leftPoint, &rightPoint, &n); 
            
            if (leftPoint == 0 && rightPoint == 0 && n == 0)
            {
                printf("Invalid inputs...\n\n");
                printf("Terminating main!\n");
                return 0;
            }
        }
    }
    
    // Does the calculations after the valid inputs are placed
    stepSize = ((rightPoint - leftPoint)/ n);
    
    // Uses for loop to calculate the midpoint, leftpoint, and rightpoint evaluations
    int i;
    for (i = 0; i<n; i++)
    {
        midPointEvaluation += (evalFunc((leftPoint + (stepSize/2)) + stepSize*i) * stepSize);
    }
     
    int j;
    for (j = 0; j<n; j++)
    {
        leftPointEvaluation += (evalFunc(leftPoint + (stepSize)*j) * stepSize);   
    }
    
    int k;
    for (k = 1; k<=n; k++)
    {
        rightPointEvaluation += (evalFunc(leftPoint + (stepSize)*k) * stepSize);
    }
    
    // Presents the calculations to the user
    printf("With Step Size: %0.4lf\n", stepSize);
    printf("The approximate integral of the f(x) = 2(x^2)-7x-2\n");
    printf("Bound between %0.2lf and %0.2lf, using %d rectangles is as follows\n\n", leftPoint, rightPoint, n);
    printf("Mid point evaluation approximate: %0.4lf\n", midPointEvaluation);
    printf("Left point evaluation approximate: %0.4lf\n", leftPointEvaluation);
    printf("Right point evaluation approximate: %0.4lf\n", rightPointEvaluation);
    
    return 0;
}
