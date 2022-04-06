#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;

typedef struct {
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* CL);
void insertFirstNode(linkedList_h* CL, char* x);
listNode* searchNode(linkedList_h* CL, char* x);
void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x);
void deleteNode(linkedList_h* CL, listNode* p);

int main(void) {
	linkedList_h* CL;

	printf("(1) 원형 연결 리스트 생성하기!\n");
	CL = createLinkedList_h();
	printList(CL);

	printf("(2) 원형 연결 리스트에 첫 부분에 [수], [월] 노드 삽입하기 \n");
	insertFirstNode(CL, "수");
	insertFirstNode(CL, "월");
	printList(CL);

	printf("(3) 원형 연결 리스트의 [월] 노드 뒤에 [화]노드 삽입하기 \n");
	insertMiddleNode(CL, searchNode(CL, "월"), "화");
	printList(CL);

	printf("(4) 원형 연결 리스트의 [수] 노드 뒤에 [목]노드 삽입하기 \n");
	insertMiddleNode(CL, searchNode(CL, "수"), "목");
	printList(CL);

	printf("(5) 원형 연결 리스트에서 [수], [월] 노드 삭제하기 \n");
	deleteNode(CL, searchNode(CL, "수"));
	deleteNode(CL, searchNode(CL, "월"));
	printList(CL);

	return 0;
}

listNode* searchNode(linkedList_h* CL, char* x){

    listNode* tmp = CL->head;
    do{
        if(strcmp(tmp->data, x) == 0)return tmp;
        else tmp = tmp->link;
    }while(tmp != CL->head);
    return NULL;
}

linkedList_h* createLinkedList_h(void) {
	linkedList_h* CL = (linkedList_h*)malloc(sizeof(linkedList_h));
	if (CL == NULL) return NULL;
	CL->head = NULL;
	return CL;
}

void printList(linkedList_h* CL) {
	listNode* p;
	printf("CL = (");
	p = CL->head;
	if (p == NULL) {
		printf(") \n\n");
		return;
	}
	do {
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) printf(" → ");
	} while (p != CL->head);
	printf(") \n\n");
}

void insertFirstNode(linkedList_h* CL, char* x){
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->link = NULL;
    strcpy(newNode->data, x);
    
    if(CL -> head == NULL){
        CL->head = newNode;
        newNode->link = newNode;
        return;
    }

    listNode* pre = CL->head;
    listNode* tmp = CL->head;
    while( pre->link != CL->head ) pre = pre->link;

    pre->link = newNode;
    CL->head = newNode;
    newNode->link = tmp;
}

void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x){
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = NULL;

    if(CL->head == NULL){
        CL->head = newNode;
        newNode->link = newNode;
        return;
    }

    if(pre == NULL){
        printf("pre 노드 검색 실패!\n");
        return;
    }

    newNode->link = pre->link;
    pre->link = newNode;
    
}

void deleteNode(linkedList_h* CL, listNode* p){
    if( CL->head == NULL || p == NULL) return ;
    if((CL->head)->link == CL->head){
        free(CL->head);
        CL->head = NULL;
    }
    else{
        listNode* pre = CL->head;
        while(pre->link != p) pre = pre->link;
        if(p == CL->head) CL->head = p->link;
        pre->link = p->link;
        free(p);
    }   
}