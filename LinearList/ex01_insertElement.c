#include<stdio.h>

void printList(int*, int);
void insertElement(int*, int, int);

int main()
{
    int arr[100] = { 10, 20, 40, 50, 60, 70 };
    int n, x;
    n = 6;
    printList(arr, n);                 // 배열의 초기 상태 출력

    // 요소 3개 삽입
    for (int i = 0; i < 3; i++) {
        printf("Insert : ");
        scanf("%d", &x);
        insertElement(arr, n++, x);   // 배열에 새로운 요소 삽입
        printList(arr, n);             
    }

    return 0;
}

void insertElement(int* arr, int n, int x)
{
    // 1. 새로운 요소를 삽입할 위치 k 찾기
    int k = n;
    for(int i = 0;i < n; i++) {
        if(arr[i] > x) {
            k = i;
            break;
        }
    }

    // 2. 기존 요소들 옮기기
    if(k < n){
        for(int i = n-1;i >= k;i--){
            arr[i+1] = arr[i];
            arr[i] = 0;
        }
    }
    // 3. 준비된 자리에 새로운 값 x 저장하기
    arr[k] = x;
}

void printList(int* arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}