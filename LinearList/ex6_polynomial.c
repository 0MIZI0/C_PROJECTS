#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b)) //매크로 함수
#define MAX_DEGREE 50

typedef struct {             
	int degree;              // 다항식의 차수
	float coef[MAX_DEGREE];  // 다항식의 각 항의 계수
} polynomial;

polynomial addPoly(polynomial A, polynomial B);
void printPoly(polynomial P);

int main(void) {
	polynomial A = { 3, { 4,3,5,0 } };    // 다항식 A의 초기화
	polynomial B = { 4, { 3,1,0,2,1 } };  // 다항식 B의 초기화
	polynomial C;

	C = addPoly(A, B);					  // 다항식 A, B에 대한 덧셈

	printf("\n A(x) =");  printPoly(A);   // 다항식 A 출력
	printf("\n B(x) =");  printPoly(B);   // 다항식 B 출력
	printf("\n C(x) =");  printPoly(C);   // 다항식 C 출력

	return 0;
}

void printPoly(polynomial P) {
	int i, degree;
	degree = P.degree;

	for (i = 0; i <= P.degree; i++) {
		printf("%3.0fx^%d", P.coef[i], degree--);
		if (i < P.degree) printf(" +");
	}
	printf("\n");
}

polynomial addPoly(polynomial A, polynomial B) {
	polynomial C;   
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (A_index <= A.degree && B_index <= B.degree) {
		if (A_degree > B_degree) {
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--;
		}
		else if (A_degree == B_degree) {
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else {
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	return C;    // 다항식 덧셈의 결과 다항식 C를 반환
}