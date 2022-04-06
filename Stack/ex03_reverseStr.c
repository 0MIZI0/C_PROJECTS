#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100
#define _CRT_SECURE_NO_WARNINGS

typedef char element;        
element stack[STACK_SIZE]; 

int isStackEmpty();
int isStackFull();
void push(element item);
element pop();
element peek();
void printStack();

int top = -1;

int main(void) {
    
    char str[100], rev_str[100] = "";

    printf("** 스택을 이용한 역순 문자열 **\n");
    printf("문자열 입력 : ");
    gets(str);

    for(int i = 0; str[i]!='\0'; i++) push(str[i]);

    printf("입력된 문자열 : %s", str);
    printStack(stack);

    for(int i = 0; !isStackEmpty(); i++) rev_str[i] = pop();

    printStack();
    printf("\n뒤집힌 문자열 : %s", rev_str);
    return 0;
}

// 스택의 원소를 출력하는 연산
void printStack() {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%c ", stack[i]);
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
		exit(1);
	}
	else return stack[top];		// 현재 top의 원소 확인
}