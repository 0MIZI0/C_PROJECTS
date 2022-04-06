#include <stdio.h>

// 행렬 원소를 저장하기 위한 구조체 term 정의
typedef struct {
	int row;
	int col;
	int value;
} term;

void smTranspose(term a[], term b[]);

int main(void) {
	term a[] = { {8,7,10}, {0,2,2}, {0,6,12}, {1,4,7}, {2,0,23}, {3,3,31},
				 {4,1,14}, {4,5,25}, {5,6,6}, {6,0,52}, {7,4,11} };
	term b[sizeof(a) / sizeof(a[0])]; //배열 원소 개수 계산
	int i;

	printf("<<희소 행렬 a>>\n");
	for (i = 0; i <= a[0].value; i++)
		printf("[%3d, %3d, %3d ]\n", a[i].row, a[i].col, a[i].value);

	smTranspose(a, b);

	printf("\n\n<<희소 행렬 b>>\n");
	for (i = 0; i <= b[0].value; i++)
		printf("[%3d, %3d, %3d ]\n", b[i].row, b[i].col, b[i].value);

	return 0;
}

void smTranspose(term a[], term b[]) {
	b[0].col = a[0].row;	
	b[0].row = a[0].col;	
	b[0].value = a[0].value; 

	if (a[0].value > 0) {	// 0이 아닌 원소가 있는 경우에만 전치 연산 수행
		int p = 1;
		for (int i = 0; i < a[0].col; i++)			// 희소 행렬 a의 열별로 전치 반복 수행
			for (int j = 1; j <= a[0].value; j++)	// 0이 아닌 원소 수에 대해서만 반복 수행
				if (a[j].col == i) {				// 현재의 열에 속하는 원소가 있으면 b[]에 삽입
					b[p].row = a[j].col;
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					p++;
				}
	}
}