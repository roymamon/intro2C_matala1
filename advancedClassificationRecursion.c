#include "NumClass.h"

int power2(int base, int hezka) { //helper method for isArmstrong
    
    int ans = 1;

    for(int i = 0 ; i < hezka ; i++){
        ans *= base;
    }

    return ans;

}

int countDigits(int n) { //another helper method for isArmstrong

     if(n == 0){
        return 0;
     }

     return countDigits(n/10)+1;

}

int isArmstrong(int n) { //standart recursive algorithm

    int original = n;
    int noOfDigits = countDigits(original);
    int sum = isArmstrongRecHelper(original, noOfDigits);
    if(sum == original){
        return TRUE;
    }

    return FALSE;
    
    }

int isArmstrongRecHelper(int n, int noOfDigits) { //standart recursive algorithm
    if (n == 0) {
        return 0;
    } else {
        int digit = n % 10;
        return power2(digit, noOfDigits) + isArmstrongRecHelper(n / 10, noOfDigits);
    }
}

int isPalindrome(int n) { 
 
    int original = n;
    int reverse = isPalindromeRecHelper(n, 0);
    if(reverse == original){
        return TRUE;
    }

    return FALSE;

}

int isPalindromeRecHelper(int n, int reverse) { //standart recursive algorithm
    if (n == 0) {
        return reverse;
    } else {
        int digit = n % 10;
        return isPalindromeRecHelper(n / 10, reverse * 10 + digit);
    }
}



