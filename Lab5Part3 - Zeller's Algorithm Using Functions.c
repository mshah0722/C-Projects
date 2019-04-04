// This program uses Zeller's Algorithm to calculate the day of the week on which a given date will fall or fell.

// The following imports the libraries for the program 
#include <stdio.h>
#include <math.h>

// The function inputDate stores the user input in the variables day, month and year.
void inputDate(int *day, int *month, int *year)
{
    printf("Please enter a date: ");
    scanf("%d/%d/%d", day, month, year); // The input is a pointer meaning scanf does not require ampersand to store input
    return;
}

// The function calculateDay will calculate the day of the week and print it.
void calculateDay(int day, int month, int year)
{
    // Initializes all integers
    int A = 0;
    int B = 0; 
    int C = 0; 
    int D = 0;
    int W = 0;
    int X = 0;
    int Y = 0; 
    int Z = 0; 
    int R = 0;
    
    // Initializes the string using char function
    char *dayOfWeek;
    
    // Stores and calculates the day of the week using Zeller's Algorithm
    B = day;
    C = year % 100;
    D = (year - (year % 100))/100;
    
    // If statements control the storing of integers
    if (month >= 3)
    {
        A = (month - 2);
    }
    
    else if (month == 1 || month == 2)
    {
        A = (month + 10);
        C = C - 1;
    }
    
    if (C < 0)
    {
        C = C + 100;
        D = D - 1;
    }
    
    W = ((13 * A) - 1) / 5;
    X = (C / 4);
    Y = (D / 4);
    Z = (W + X + Y + B + C - (2 * D));
    R = (Z % 7);
    
    if (R < 0)
    {
        R = R + 7;
    } 

    // The value of R determines the day of the week
    if (R == 0)
    {
        dayOfWeek = "Sunday";
    }
    
    if (R == 1)
    {
        dayOfWeek = "Monday";
    }
    
    if (R == 2)
    {
        dayOfWeek = "Tuesday";
    }
    
    if (R == 3)
    {
        dayOfWeek = "Wednesday";
    }
    
    if (R == 4)
    {
        dayOfWeek = "Thursday";
    }
    
    if (R == 5)
    {
        dayOfWeek = "Friday";
    }
    
    if (R == 6)
    {
        dayOfWeek = "Saturday";
    }

    // Prints the day of the week
    printf("The day %d/%d/%d is a %s.\n", day, month, year, dayOfWeek);
    return;
}


int main(void)
{
    int day = 0; 
    int month = 0;
    int year = 0;
    inputDate(&day, &month, &year);
    calculateDay(day, month, year);
}
