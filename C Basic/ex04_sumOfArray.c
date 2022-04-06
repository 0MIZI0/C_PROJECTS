#include<stdio.h>

int sumOfArray(int*, int);

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(arr) / sizeof(int);

	// 2. 결과 출력
    printf("배열의 모든 요소의 합 : %d", sumOfArray(arr, n));
	return 0;
}

// 1. sumOfArray 함수 정의
int sumOfArray(int* arr, int n){
    int sum = 0;
    for(int i = 0;i < n; i++) sum += arr[i];

    return sum;
}