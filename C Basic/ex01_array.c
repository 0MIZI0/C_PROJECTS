#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int arr[10], max, min;
    int n = sizeof(arr) / sizeof(arr[0]);

    // 1. 배열에 1~1000 사이의 랜덤값 저장
    for(int i = 0;i < n;i++){
        arr[i] = rand() % 1000 + 1;
    }

    // 2. 배열의 모든 요소 출력하기
    for(int i = 0;i < n; i++)
        printf("%d ", arr[i]);

    // 3. 배열에서 가장 큰 값과 작은 값 찾기
    max = min = arr[0];
    for(int i =0; i < n; i++){
        if(arr[i] > max)max = arr[i];
        if(min > arr[i]) min = arr[i];
    }

    // 4. 배열에서 가장 큰 값과 작은 값 출력
    printf("\n\n배열에서 가장 큰 값 = %d\n", max);
    printf("배열에서 가장 작은 값 = %d\n", min);

    return 0;
}