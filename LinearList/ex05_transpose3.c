#include <stdio.h>

#define MAX_TERMS 100

typedef struct {
	int row;
	int col;
	int value;
} term;

typedef struct {
	term data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
} SparseMatrix;

SparseMatrix smTranspose(SparseMatrix a);

int main(void) {
	SparseMatrix a = {
						{{0,2,2}, {0,6,12}, {1,4,7}, {2,0,23}, {3,3,31}, {4,1,14}, {4,5,25}, {5,6,6}, {6,0,52}, {7,4,11}},
						8, 7, 10
	};
	SparseMatrix b;

	printf("<<희소 행렬 a>>\n");
	printf("%d x %d행열(%d개)\n", a.rows, a.cols, a.terms);
	// 행렬 a의 모든 요소 출력
    for(int i = 0;i < a.terms ;i++){
        printf("[ %03d, %03d, %03d]\n", a.data[i].row, a.data[i].col, a.data[i].value);
    }

	b = smTranspose(a);

	printf("\n\n<<전치 행렬 b>>\n");
	printf("%d x %d행열(%d개)\n", b.rows, b.cols, b.terms);
	// 행렬 b의 모든 요소 출력
    for(int i = 0;i < b.terms ;i++){
        printf("[ %03d, %03d, %03d]\n", b.data[i].row, b.data[i].col, b.data[i].value);
    }


	return 0;
}

SparseMatrix smTranspose(SparseMatrix a) {
	SparseMatrix b;

	// 코드 작성
    b.cols = a.rows;
    b.rows = a.cols;
    b.terms = a.terms;

    if(a.terms > 0){
        int p = 0;
        for(int i = 0;i < a.cols; i++){
            for(int j = 0; j < a.terms; j++){
                if(a.data[j].col == i){
                    b.data[p].row = a.data[j].col;
                    b.data[p].col = a.data[j].row;
                    b.data[p].value = a.data[j].value;
                    p++;
                }
            }
        }
    }

    return b;
}