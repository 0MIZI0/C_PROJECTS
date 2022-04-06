#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define STACK_SIZE 100

typedef int element;        // 스택 원소(element)의 자료형을 int로 정의 
element stack[STACK_SIZE];  // 1차원 배열 스택 선언

int isStackEmpty();
int isStackFull();
void push(element item);
element pop();
element peek();
void printStack();

int top = -1;

int main(void) {
	element item;

	printf("\n** 순차 스택 연산 **\n");
	printStack();
	push(1);	printStack();		// 1 삽입
	push(2);	printStack();		// 2 삽입
	push(3);	printStack();		// 3 삽입

	item = peek();  printStack();	// 현재 top의 원소 출력
	printf("peek => %d", item);

	item = pop();  printStack();	// 삭제
	printf("\t pop  => %d", item);

	item = pop();  printStack();	// 삭제
	printf("\t pop  => %d", item);

	item = pop();  printStack();	// 삭제
	printf("\t pop  => %d\n", item);

	return 0;
}

// 스택의 원소를 출력하는 연산
void printStack() {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("] ");
}

// 스택이 포화 상태인지 확인하는 연산
int isStackFull() {
	return (top == STACK_SIZE - 1) ? 1 : 0;
}

// 스택이 공백 상태인지 확인하는 연산
int isStackEmpty() {
	return (top == -1) ? 1 : 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
	if (isStackFull()) {				// 스택이 포화 상태인 경우
		printf("\n\n Stack is FULL! \n");
		return;
	}
	else stack[++top] = item;	// top을 증가시킨 후 현재 top에 원소 삽입
}

// 스택의 top에서 원소를 삭제하는 연산
element pop() {
	if (isStackEmpty()) {			// 스택이 공백 상태인 경우
		printf("\n\n Stack is Empty!!\n");
		return 0;
	}
	else return stack[top--];	// 현재 top의 원소를 삭제한 후 top 감소
}

// 스택의 top 원소를 검색하는 연산
element peek() {
	if (isStackEmpty()) {			// 스택이 공백 상태인 경우
		printf("\n\n Stack is Empty !\n");
		return -1;
	}
	else return stack[top];		// 현재 top의 원소 확인
}