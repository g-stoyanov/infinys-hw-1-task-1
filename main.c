#include <stdio.h>

#define OVERFLOW_LIMIT 93
#define OVERFLOW_CODE 0

unsigned long long trivialFibonacci(unsigned short n);
short getUserInput();

int main() {
    short numberOfFibonacciMember = getUserInput();
    unsigned long long fibonacciNumber = trivialFibonacci(numberOfFibonacciMember);

    if(fibonacciNumber == OVERFLOW_CODE) {
        printf("%hi Fibonacci member is too big to be calculated!", numberOfFibonacciMember);
    }
    else {
        printf("%hi Fibonacci member is %llu", numberOfFibonacciMember, fibonacciNumber);
    }

    return 0;
}

unsigned long long trivialFibonacci(unsigned short n) {

    if(n > OVERFLOW_LIMIT) {
        return OVERFLOW_CODE;
    }

    unsigned long long previous = 1;
    unsigned long long current = 1;

    for (int i = 0; i < n - 2; ++i) {
        unsigned long long new = previous + current;
        previous = current;
        current = new;
    }

    return current;
}

short getUserInput() {
    short userInput;
    do {
        printf("\nPlease input number of Fibonacci member: ");
        scanf("%hi", &userInput);

        if(userInput < 0) {
            printf("\n%hi - Error: Input positive number!\n", userInput);
        }
        else if(userInput == 0) {
            printf("\n%hi - Error: Input larger number than 0!\n", userInput);
        }
    } while(userInput <= 0);

    return userInput;
}
