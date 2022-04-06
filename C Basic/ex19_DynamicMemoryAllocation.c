#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    int* ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // 1. 메모리 할당  
    ptr = (int*)malloc(sizeof(int)*n);


    // if memory cannot be allocated
    if (ptr == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    // 2. n개의 요소를 입력받기, 합계 구하기
    for(int i = 0;i<n;i++){
        scanf("%d",&ptr[i]);
        sum+=ptr[i];
    } 

    // 3. n개의 요소를 " + " 로 연결한 형태로 출력하기
    for (int i = 0; i < n - 1; i++)
        printf("%d + ", ptr[i]);
    printf("%d = %d", ptr[n - 1], sum);

    // 4. 메모리 해제
    free(ptr);
   
    return 0;
}