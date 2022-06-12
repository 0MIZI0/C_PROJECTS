#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {	
	char data;
	struct treeNode* left;  
	struct treeNode* right; 
} treeNode;

typedef treeNode* element;

#define SIZE 100
treeNode* stack[SIZE];
int top = -1;

typedef struct {
	element queue[SIZE];	// 1차원 배열 큐 선언
	int front, rear;
} QueueType;

QueueType* createCQueue();
int isCQueueEmpty(QueueType* cQ);
int isCQueueFull(QueueType* cQ);
void enCQueue(QueueType* cQ, element item);
element deCQueue(QueueType* cQ);

treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode);
void levelOrder_iterative(treeNode* root);
void push(treeNode* p);
treeNode* pop();

int main(void) {
	// (A*B-C/D) 수식 이진 트리 만들기
	treeNode* n7 = makeRootNode('D', NULL, NULL);
	treeNode* n6 = makeRootNode('C', NULL, NULL);
	treeNode* n5 = makeRootNode('B', NULL, NULL);
	treeNode* n4 = makeRootNode('A', NULL, NULL);
	treeNode* n3 = makeRootNode('/', n6, n7);
	treeNode* n2 = makeRootNode('*', n4, n5);
	treeNode* n1 = makeRootNode('-', n2, n3);

	levelOrder_iterative(n1);

	return 0;
}

// data를 루트 노드로 하여 왼쪽 서브 트리와 오른쪽 서브 트리를 연결하는 연산
treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

void push(treeNode* p) {
	if (top < SIZE - 1)
		stack[++top] = p;
}

treeNode* pop() {
	treeNode* p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

QueueType* createCQueue() {
	QueueType* cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ->front = 0;       // front 초깃값 설정
	cQ->rear = 0;        // rear 초깃값 설정
	return cQ;
}

// 원형 큐가 공백 상태인지 검사하는 연산
int isCQueueEmpty(QueueType* cQ) {
	if (cQ->front == cQ->rear) {
		printf(" Circular Queue is empty! ");
		return 1;
	}
	else return 0;
}

// 원형 큐가 포화 상태인지 검사하는 연산
int isCQueueFull(QueueType* cQ) {
	if (((cQ->rear + 1) % SIZE) == cQ->front) {
		printf("  Circular Queue is full! ");
		return 1;
	}
	else return 0;
}

// 원형 큐의 rear에 원소를 삽입하는 연산
void enCQueue(QueueType* cQ, element item) {
	if (isCQueueFull(cQ))	return;
	else {
		cQ->rear = (cQ->rear + 1) % SIZE;
		cQ->queue[cQ->rear] = item;
	}
}

// 원형 큐의 front에서 원소를 삭제하고 반환하는 연산
element deCQueue(QueueType* cQ) {
	if (isCQueueEmpty(cQ)) return NULL;
	else {
		cQ->front = (cQ->front + 1) % SIZE;
		return cQ->queue[cQ->front];
	}
}

// 원형 큐의 원소를 출력하는 연산
void printCQ(QueueType* cQ) {
	int i, first, last;
	first = (cQ->front + 1) % SIZE;
	last = (cQ->rear + 1) % SIZE;
	printf(" Circular Queue : [");
	i = first;
	while (i != last) {
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % SIZE;
	}
	printf(" ] ");
}

void levelOrder_iterative(treeNode* root){
    QueueType* queue = createCQueue();
    treeNode* currNode;

    enCQueue(queue, root);
    while( 1 ){
        currNode = deCQueue(queue);
        printf("%c ", currNode->data);
        if( currNode->left ) enCQueue(queue, currNode->left);
        if( currNode->right ) enCQueue(queue, currNode->right);

        if( isCQueueEmpty(queue) ) break;
    }
}