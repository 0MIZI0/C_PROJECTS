#include <stdio.h>
#include <stdlib.h>

// unsigned long long fibo(int n){
//     if( n == 0 ) return 0;
//     if( n == 1 ) return 1;
//     return fibo(n-1)+fibo(n-2);
// }

// int main(void){

//     for(int i = 0;i <= 50;i++){
//         printf("fibonacci(%2d) = %lld\n", i, fibo(i));
//     }
//     return 0;
// }

int main(void){
    unsigned long long a = 0, b = 1, next;

    for(int i = 0;i <= 80; i++){
        printf("fibonacci(%2d) = %llu\n", i, a);
        next = a+b;
        a = b;
        b = next;
    }
}