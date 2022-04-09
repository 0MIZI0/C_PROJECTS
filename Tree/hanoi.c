#include <stdio.h>
#include <stdlib.h>

void hanoi(int n , char from, char other, char to){
    if(n == 1)  {
        printf("%c -> %c\n",from, to); 
        return;//원반이 1개일 때 문제 최소 단순화
    }

    hanoi(n-1, from, to, other);
    printf("%c -> %c\n", from, to);
    hanoi(n-1, other, from, to);
}

int main(void){

    hanoi(3, 'A', 'B', 'C');
    return 0;
}
