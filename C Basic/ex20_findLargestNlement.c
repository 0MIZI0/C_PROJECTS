#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNum(float* arr, int n);
void printArr(float* arr, int n);
float findMaxNum(float* arr, int n);

int main()
{
    int n;
    float* arr;
    printf(" Input total number of elements(1 to 100): ");
    scanf("%d", &n);

    // 1. Memory is allocated for 'n' elements 
    arr = (float*)calloc(n, sizeof(float));


    // 배열에 랜덤 숫자 저장
    generateRandomNum(arr, n);
    printArr(arr, n);

    printf(" The Largest element is :  %2.1f \n\n", findMaxNum(arr, n));
    return 0;
}

void generateRandomNum(float* arr, int n) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; ++i)
        arr[i] = (float)rand() / RAND_MAX * 100;
}

void printArr(float* arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%2.1f ", arr[i]);
    printf("\n");
}

float findMaxNum(float* arr, int n) {
    // 2. 배열 중 가장 큰 숫자 리턴
    float tmp = arr[0];
    for(int i = 1;i<n;i++) if(tmp < arr[i]) tmp = arr[i];
    return tmp;
}