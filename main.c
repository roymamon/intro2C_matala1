#include "NumClass.h"
#include <stdio.h>

int main(){

   int number1;
   int number2;
   int result;

   do { //checking if the input is valid
        printf("Please enter two integers: ");
        result = scanf("%d%d", &number1, &number2);

        if (result == 2 && number1 > -1 && number2 > -1) {
            break;  
        } else {
            while (getchar() != '\n');
            printf("wrong input. please enter two positive integers\n");
        }
    } while (1);  


   printf("The Armstrong numbers are:");

   if (number1 > number2) {
        int temp = number1;
        number1 = number2;
        number2 = temp;
    }

   for(int i = number1 ; i <= number2 ; i++){
   if(isArmstrong(i)){
      printf(" %d", i);
}

   }

   printf("\nThe Palindromes are:");

for(int i = number1 ; i <= number2 ; i++){
   if(isPalindrome(i)){
      printf(" %d", i);
}

   }

   printf("\nThe Prime numbers are:");

   for(int i = number1 ; i <= number2 ; i++){
   if(isPrime(i)){
      printf(" %d", i);
}

   }

   
   printf("\nThe Strong numbers are:");

   for(int i = number1 ; i <= number2 ; i++){
   if(isStrong(i)){
      printf(" %d", i);
}

   }

return 0;
   
}
