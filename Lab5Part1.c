// The function ecrypts the user input number using a cipher making it unreadable to others

// The following imports the libraries for the program 
#include <stdio.h>
#include <math.h>

// The function input is used to read a positive integer having at least six digits and store it in the variable num.
void input(int *num)
{
    printf("Please enter an integer greater than 99999: ");
    scanf("%d", num); // The input is a pointer meaning scanf does not require ampersand to store input
    
    // The function will continue requesting for a number until a valid input is provided by the user.
    while(*num <= 99999)
    {
        printf("Incorrect input.\n");
        printf("Please enter an integer greater than 99999: ");
        scanf("%d", num);
    }
    printf("The number entered is %d\n", *num);
}

// The function add4 modifies the value of each digit of num by adding 4 to each digit, and returns the modified number.
int add4(int num)
{
    int digit = 0;
    digit = num;
    int i = 0;
    while (digit > 0) 
    {
        if ((digit % 10) > 5)
        {        
            num = num - (6 * pow(10,i));
        }
        else if ((digit % 10) <= 5)
        {
            num = num + (4 * pow(10,i));
        }
        digit = digit / 10;
        i++;
    }
    return num;
}

// The function shift takes the output of the function add4 and shifts the position of each digit to the left by one place.
int shift(int num)
{
    double value;
    value = (double)(num);
    int j = 0;
    while (value > 10)
    {
        value = value/10;
        j++;
    }
    num = num - (((int)value) * pow(10,j));
    num = num * 10;
    num = num + (int)value;
    //printf("After the shift function, the number is %d\n", num);
    return num;
}

// The function printOutput prints the original number (originalNum) and the encrypted number (encryptNum).
void printOutput(int encryptNum, int originalNum)
{
    printf("Original number: %d\n", originalNum);
    printf("Encrypted number: %d\n", encryptNum);
}

int main(void)
{
    int num;
    int encryptNum;
    int originalNum;
    input(&num);
    originalNum = num;
    num = add4(num);
    encryptNum = shift(num);
    printOutput(encryptNum, originalNum);
    return 0;
}