#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    if(n == 1) return 1;
    else{
        return n*factorial(n-1); 
    }
}

int main(void){
    int n = 5, result = 1;

    for(int i = 1; i <= n; i++) result *= i;
    printf("%d",result);

    // printf("factorial(%d) = %d\n",n, factorial(n));
    return 0;
}