#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef char element;		// 스택 원소(element)의 자료형을 int로 정의 

typedef struct  stackNode {	// 스택의 노드를 구조체로 정의
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;				// 스택의 top 노드를 지정하기 위해 포인터 top 선언

int isStackEmpty();
void push(element item);
element pop();
element peek();
void printStack();

int main(void) {
	char* express[] = {"{(A+B)-3}+[{cos(x+y)+7}-1]*4", 
						"{(A+B)-3}+[{cos(x+y)+7}-1]*4)" };
	int length = sizeof(express) / sizeof(char*);

	for (int i = 0; i < length; i++) {
		printf("%s\n", express[i]);
		if (testPair(express[i]))
			printf("right\n");
		else
			printf("wrong\n");
	}

	return 0;
}   

int testPair(char* express){
    top = NULL;
    char tmp;

    for(int i = 0; express[i] != '\0'; i++){
        switch(express[i]){
            case '(' : case '{' :  case '[' :
                push(express[i]); break;
            case ')' : case '}' :  case ']' : 
                if(isStackEmpty()) return 0;
                else{
                    tmp = pop();
                    if( tmp == '(' && express[i] != ')' || tmp == '{' && express[i] != '}' || tmp == '[' && express[i] != ']') return 0;
                    break;
                }
        }
    }

    return (top == NULL) ? 1 : 0;
}

// 스택이 공백 상태인지 확인하는 연산
int isStackEmpty() {
	return (top == NULL) ? 1 : 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	if (temp == NULL) return;

	temp->data = item;
	temp->link = top;     // 삽입 노드를 top의 위에 연결
	top = temp;           // top 위치를 삽입 노드로 이동
}

// 스택의 top에서 원소를 삭제하는 연산
element pop() {
	element item;
	stackNode* temp = top;

	if (isStackEmpty()) {		// 스택이 공백 리스트인 경우
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// 스택이 공백 리스트가 아닌 경우
		item = temp->data;
		top = top->link;	// top 위치를 삭제 노드 아래로 이동
		free(temp);			// 삭제된 노드의 메모리 반환
		return item;		// 삭제된 원소 반환
	}
}

// 스택의 top 원소를 검색하는 연산
element peek() {
	if (isStackEmpty()) {		// 스택이 공백 리스트인 경우
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// 스택이 공백 리스트가 아닌 경우
		return(top->data);  // 현재 top의 원소 반환
	}
}

// 스택의 원소를 top에서 bottom 순서로 출력하는 연산
void printStack() {
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}