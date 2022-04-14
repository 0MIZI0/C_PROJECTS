#include <stdio.h>
#include <stdlib.h>

#define cQ_SIZE  4

typedef char element;		// 큐 원소(element)의 자료형을 char로 정의

typedef struct {
	element queue[cQ_SIZE];	// 1차원 배열 큐 선언
	int front, rear;
} QueueType;

QueueType* createCQueue();
int isCQueueEmpty(QueueType* cQ);
int isCQueueFull(QueueType* cQ);
void enCQueue(QueueType* cQ, element item);
element deCQueue(QueueType* cQ);
element peekCQ(QueueType* cQ);
void printCQ(QueueType* cQ);

int main(void) {
	QueueType* cQ = createCQueue();  // 큐 생성
	element data;
	printf("\n ***** 원형 큐 연산 ***** \n");
	printf("\n 삽입 A>>");  enCQueue(cQ, 'A'); printCQ(cQ);
	printf("\n 삽입 B>>");  enCQueue(cQ, 'B'); printCQ(cQ);
	printf("\n 삽입 C>>");  enCQueue(cQ, 'C'); printCQ(cQ);
	data = peekCQ(cQ);    printf(" peek item : %c \n", data);
	printf("\n 삭제  >>");  data = deCQueue(cQ); printCQ(cQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n 삭제  >>");  data = deCQueue(cQ); printCQ(cQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n 삭제  >>");  data = deCQueue(cQ); printCQ(cQ);
	printf("\t\t삭제 데이터: %c", data);
	printf("\n 삽입 D>>");  enCQueue(cQ, 'D'); printCQ(cQ);
	printf("\n 삽입 E>>");  enCQueue(cQ, 'E'); printCQ(cQ);
	printf("\n");
	return 0;
}

QueueType* createCQueue() {
	// 코드 작성
    QueueType* cQ = (QueueType*)malloc(sizeof(QueueType));
    cQ->front = -1;
    cQ->rear = -1;
	return cQ;
}

// 원형 큐가 공백 상태인지 검사하는 연산
int isCQueueEmpty(QueueType* cQ) {
	// 코드 작성
    if(cQ->front == cQ->rear) {
        printf("cQ is empty!");
        return 1;
    }
    else return 0;
}

// 원형 큐가 포화 상태인지 검사하는 연산
int isCQueueFull(QueueType* cQ) {
	// 코드 작성
    if(((cQ->rear+1)%cQ_SIZE) == cQ->front) return 1;
    else return 0;
}

// 원형 큐의 rear에 원소를 삽입하는 연산
void enCQueue(QueueType* cQ, element item) {
	// 코드 작성
    if(isCQueueFull(cQ)) return;
    else{
        cQ->rear = (cQ->rear+1)%cQ_SIZE;
        cQ->queue[cQ->rear] = item;
    }
}

// 원형 큐의 front에서 원소를 삭제하고 반환하는 연산
element deCQueue(QueueType* cQ) {
	// 코드 작성
    if(isCQueueEmpty(cQ)) return -1;
    else{
        cQ->front = (cQ->front + 1) % cQ_SIZE;
        return cQ->queue[cQ->front];
    }
}

// 원형 큐의 가장 앞에 있는 원소를 검색하는 연산
element peekCQ(QueueType* cQ) {
	// 코드 작성
    if(isCQueueEmpty(cQ)) return -1;
    else return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}

// 원형 큐의 원소를 출력하는 연산
void printCQ(QueueType* cQ) {
	// 코드 작성
    int first = (cQ->front + 1) % cQ_SIZE;
    int last = (cQ->rear + 1) % cQ_SIZE;
    int i = first;

    printf("CQ : [");
    while( i != last){
        printf("%3c", cQ->queue[i]);
        i = (i + 1) % cQ_SIZE;
    }
    printf(" ]");
}