#include <stdio.h>

// 1. swap 함수 정의
void swap(int* num1, int* num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int main() {
	int a = 10, b = 20;

	printf("a=%d, b=%d\n", a, b);
	
	// 2. swap 함수 호출
    swap(&a,  &b);

	printf("a=%d, b=%d\n", a, b);

	return 0;
}