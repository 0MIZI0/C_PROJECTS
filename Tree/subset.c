#include <stdio.h>
#include <stdlib.h>

// int subset(int n){
//     if(n == 0){
//         printf("0 0 0\n");
//         return 0;;
//     }

//     int arr[3] = {0,0,0};
//     int tmp = n;
//     if((tmp/2)%2==1)arr[2]=1;
//     if((tmp/4)%2==1)arr[1]=1;
//     if((tmp/8)%2==1)arr[0]=1;

//     printf("%d %d %d\n",arr[0], arr[1], arr[2]);
//     subset(n-1);
// }

int main(void){
    int a,b,c,d;

    for(a = 0;a <= 1; a++)for(b = 0;b <= 1; b++)for(c = 0;c <= 1; c++)for(d = 0;d <= 1; d++)printf("%d %d %d %d\n",a,b,c,d);
    // subset(8);
    return 0;
}