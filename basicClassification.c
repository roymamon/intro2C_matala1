#include "NumClass.h"

int factorial(int n) { //recursive helper method to calculat factorial
    if (n == 0 || n == 1) {
        return 1;
    } 
    else 
    {
        return n*factorial(n-1);
    }
}

int isPrime(int n) { //standart algorithm to check if a number is prime
    if (n < 1) {
        return FALSE;  
    }

    for (int i = 2 ; i < n; i++) {
        if (n % i == 0) {
            return FALSE;  
        }
    }

    return TRUE;  

}

int isStrong(int n) { //calculate the factorial of each digit, sum it and compare to given number

    int original = n;
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += factorial(digit);
        n /= 10;
    }

    if (sum == original) {
        return TRUE;
    }

    return FALSE;

}


