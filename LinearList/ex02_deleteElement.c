#include<stdio.h>

void printList(int*, int);
int deleteElement(int*, int, int);

int main()
{
    int arr[100] = { 10, 20, 40, 50, 60, 70 };
    int n, x;
    n = 6;
    printList(arr, n);                 // 배열의 초기 상태 출력

    // 요소 3개 삭제
    for (int i = 0; i < 3; i++) {
        printf("Target to delete: ");
        scanf("%d", &x);
        if (deleteElement(arr, n, x)) {
            n--;
            printList(arr, n);
        }
        else {
            printf("No Such Element.\n\n");
        }
    }

    return 0;
}

int deleteElement(int* arr, int n, int x) {
    int k = n;
    // 1. 삭제할 원소 x의 위치 찾기
    for(int i =0;i<n;i++)if(arr[i]==x){k=i;break;}
    if (k == n) return 0;

    // 2. (k+1) ~ 마지막 원소까지 앞으로 한 칸씩 이동
    for(int i = k+1;i < n;i++)arr[i-1] = arr[i];

    return 1;
}

void printList(int* arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}