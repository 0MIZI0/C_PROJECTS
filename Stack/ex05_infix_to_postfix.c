#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc()
#include <string.h>  // strlen()

#define EXPRESSION_SIZE 100

typedef char element;

typedef struct  stackNode {
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;

int isStackEmpty();
void push(element item);
element pop();
element peek();
void printStack();
int precedence(char op);
void infix_to_postfix(element* exp, element* postfix_exp);
element evalPostfix(element* postfix_exp);

int main(void) {
	printf("** 중위 표기 → 후위 표기 변환 **\n\n");

	char* expArr[] = { "1+2", "1+2*3", "1*2+3", "(1+2)*3", "4*3-2/1", "5*(4-3)+6/2", "2*((8-2)/2)*5" };
	element postfix_exp[EXPRESSION_SIZE];
	int n = sizeof(expArr) / sizeof(char*);

	for (int i = 0; i < n; i++) {
		printf("중위 표기식: %s\n", expArr[i]);
		infix_to_postfix(expArr[i], postfix_exp);
		printf("후위 표기식: %s\n", postfix_exp);
		printf("계산 결과: %d\n", evalPostfix(postfix_exp));
		printf("-----------------------------\n");
	}

	return 0;
}

// 스택이 공백 상태인지 확인하는 연산
int isStackEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	if (temp == NULL)return;
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
		top = temp->link;	// top 위치를 삭제 노드 아래로 이동
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

// 연산자의 우선순위 반환하는 함수
int precedence(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// 중위 표기를 후위 표기로 변환하는 함수
void infix_to_postfix(element* exp, element* postfix_exp) {
	// 1. 변수 선언 및 스택 초기화
    top = NULL;
    char c, top_op;
    int n = strlen(exp, p = 0);

	// 2. 표현식의 토근(문자)수만큼 반복처리
	for(int i = 0;i < n; i++){
        c = exp[i];
        switch(c){
            case '+': case '-': case '*': case '/':
                if(isStackEmpty() && precedence(c) <= precedence(peek())) postfix_exp[p++] = pop();
                push(c);
                break;
            case '(':
                push(c);break;
            case ')':
                while((top_op = pop()) != '('){
                    postfix_exp[p++] = top_op;
                }
                break;
            default:
                postfix_exp[p++] = c;
                break;
        }
    }
    while( !isStackEmpty()){
        postfix_exp[p++] = pop();
    }
    postfix_exp[0] = '\0';
	// 3. 스택에 남아있는 연산자를 출력한다.
	
}