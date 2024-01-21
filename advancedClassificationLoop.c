#include "NumClass.h"


int power(int base, int hezka) { //helper method for isArmstrong
    
    int ans = 1;

    for(int i = 0 ; i < hezka ; i++){
        ans *= base;
    }

    return ans;

}

int isArmstrong(int n) {

    int original = n;
    int noOfDigits = 0;
    int sum = 0;

    while(original != 0){ // calculating how many digits n has

    original /= 10;
    noOfDigits++;

    }

    original = n;

    while(original != 0){ //calculatig the sum

        int digit = original%10;
        sum += power(digit, noOfDigits);
        original /= 10;
    }

    original = n;

    if(sum == original){
        return TRUE;
    }

    return FALSE;

}

int isPalindrome(int n) { //standart algorithm to check if a number is a Palindrome

    int original = n;
    int reverse = 0;


    while(n > 0){

    int digit = n%10;
    reverse = (reverse * 10) + digit;
    n /= 10;

    }

    if(reverse == original){
        return TRUE;
    }

    return FALSE;

}




