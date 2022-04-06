#include <stdio.h>
#include <stdlib.h>

typedef char element;	// 데크 원소(element)의 자료형을 char로 정의

typedef struct DQNode {	// 이중 연결 리스트 데크의 노드 구조를 구조체로 정의
	element data;
	struct DQNode* llink;
	struct DQNode* rlink;
} DQNode;

typedef struct {       // 데크에서 사용하는 포인터 front와 rear를 구조체로 정의
	DQNode* front, * rear;
} DQueType;

DQueType* createDQue();
int isDeQEmpty(DQueType* DQ);
void insertFront(DQueType* DQ, element item);
void insertRear(DQueType* DQ, element item);
element deleteFront(DQueType* DQ);
element deleteRear(DQueType* DQ);
element peekFront(DQueType* DQ);
element peekRear(DQueType* DQ);
void printDQ(DQueType* DQ);

int main(void)
{
	DQueType* DQ1 = createDQue();  // 데크 생성
	element data;
	printf("\n ***** 데크 연산 ***** \n");
	printf("\n front 삽입 A>> ");  insertFront(DQ1, 'A');  printDQ(DQ1);
	printf("\n front 삽입 B>> ");  insertFront(DQ1, 'B');  printDQ(DQ1);
	printf("\n rear  삽입 C>> ");  insertRear(DQ1, 'C');  printDQ(DQ1);
	printf("\n front 삭제  >> ");  data = deleteFront(DQ1);    printDQ(DQ1);
	printf("\t삭제 데이터: %c", data);
	printf("\n rear  삭제  >> ");  data = deleteRear(DQ1);     printDQ(DQ1);
	printf("\t\t삭제 데이터: %c", data);
	printf("\n rear  삽입 D>> ");  insertRear(DQ1, 'D');  printDQ(DQ1);
	printf("\n front 삽입 E>> ");  insertFront(DQ1, 'E');  printDQ(DQ1);
	printf("\n front 삽입 F>> ");  insertFront(DQ1, 'F');  printDQ(DQ1);

	data = peekFront(DQ1);  printf("\n peek Front item : %c \n", data);
	data = peekRear(DQ1);  printf(" peek Rear item : %c \n", data);

	return 0;
}

// 공백 데크를 생성하는 연산
DQueType* createDQue() {
	// 코드 작성
}

// 데크가 공백 상태인지 검사하는 연산
int isDeQEmpty(DQueType* DQ) {
	// 코드 작성
    return(DQ->front == NULL) ? 1 : 0;
}

// 데크의 front 앞으로 원소를 삽입하는 연산
void insertFront(DQueType* DQ, element item) {
	// 코드 작성
    DQNode* new = (DQNode*)malloc(sizeof(DQNode));
    new->data = item;

    if(isDeQEmpty()){
        new->llink = new->rlink = NULL;
        DQ->front = DQ->rear = new;
    }
    else{
        new->llink = NULL;
        new->rlink = DQ->front;
        DQ->front->rlink = 
    }

}

// 데크의 rear 뒤로 원소를 삽입하는 연산
void insertRear(DQueType* DQ, element item) {
	// 코드 작성
}

// 데크의 front 노드를 삭제하고 반환하는 연산
element deleteFront(DQueType* DQ) {
	// 코드 작성
}

// 데크의 rear 노드를 삭제하고 반환하는 연산
element deleteRear(DQueType* DQ) {
	// 코드 작성
}

// 데크의 front 노드의 데이터 필드를 반환하는 연산
element peekFront(DQueType* DQ) {
	// 코드 작성
}

// 데크의 rear 노드의 데이터 필드를 반환하는 연산
element peekRear(DQueType* DQ) {
	// 코드 작성
}

// 데크의 front 노드부터 rear 노드까지 출력하는 연산
void printDQ(DQueType* DQ) {
	// 코드 작성
    DQNode* tmp = DQ->front;
    printf("DeQue : [ ");
    while(tmp){
        printf("%c", tmp->data);
        tmp = tmp->rlink;
    }
    printf(" ]");
}