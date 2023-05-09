#include <stdio.h>
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    unsigned long long numKeys = factorial(25) / factorial(25 - 5);
    unsigned long long numUniqueKeys = numKeys / 2;  
    numUniqueKeys /= 2;
    numUniqueKeys *= factorial(5); 
    int powerOf2 = 0;
    while (numUniqueKeys > 1) {
        numUniqueKeys /= 2;
        powerOf2++;
    }

    printf("The Playfair cipher has approximately 2^%d effectively unique keys.\n", powerOf2);

    return 0;
}
