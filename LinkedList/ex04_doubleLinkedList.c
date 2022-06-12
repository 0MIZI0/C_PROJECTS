#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode {
	struct ListNode* llink;
	char data[4];
	struct ListNode* rlink;
}listNode;

typedef struct {
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* L);
void insertNode(linkedList_h* L, listNode* pre, char* x);
listNode* searchNode(linkedList_h* L, char* x);
void deleteNode(linkedList_h* L, listNode* old);

int main() {
	linkedList_h* L;

	printf("(1) 이중 연결 리스트 생성하기!\n");
	L = createLinkedList_h();
	printList(L);

	printf("(2) 이중 연결 리스트의 첫 부분에 [금], [수], [월] 노드 삽입하기\n");
	insertNode(L, NULL, "금");
	insertNode(L, NULL, "수");
	insertNode(L, NULL, "월");
	printList(L);

	printf("(3) 이중 연결 리스트의 처음에 [수]노드 뒤에 [목]노드 삽입하기\n");
	insertNode(L, searchNode(L, "수"), "목");
	printList(L);

	printf("(4) 이중 연결 리스트의 [월]노드 뒤에 [화]노드 삽입하기\n");
	insertNode(L, searchNode(L, "월"), "화");
	printList(L);

	printf("(5) 이중 연결 리스트의 [토], [월], [금], [수], [수]노드 삭제하기\n");
	deleteNode(L, searchNode(L, "토")); printList(L);
	deleteNode(L, searchNode(L, "월")); printList(L);
	deleteNode(L, searchNode(L, "금")); printList(L);
	deleteNode(L, searchNode(L, "수")); printList(L);
	deleteNode(L, searchNode(L, "수")); printList(L);

	return 0;
}

linkedList_h* createLinkedList_h(void) {
	linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

void printList(linkedList_h* L) {
	listNode* p = L->head;
	printf("DL = (");
	if (p == NULL) {
		printf(" )\n\n");
	}
	else {
		while (p != NULL) {
			printf("%s", p->data);
			p = p->rlink;
			if (p != NULL)printf(" ↔ ");
		}
		printf(")\n\n");
	}
}

listNode* searchNode(linkedList_h* L, char* x){
    listNode* tmp = L->head;
    while(tmp != NULL){
        if(strcmp(tmp->data,x) == 0) return tmp;
        else tmp = tmp->rlink;
    }
    return NULL;
}

void insertNode(linkedList_h* L, listNode* pre, char* x)
{
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);

    if(L->head == NULL){
        newNode->rlink = NULL;
        newNode->llink = NULL;
        L->head = newNode;
    }
    else if(pre == NULL){
        newNode->llink = NULL;
        L->head->llink = newNode;
        newNode->rlink = L->head;
        L->head = newNode;
    }
    else{
        newNode->rlink = pre->rlink;
        pre->rlink = newNode;
        newNode->llink = pre;
        if(newNode->rlink != NULL) newNode->rlink->llink = newNode;
    }
}

void deleteNode(linkedList_h* L, listNode* old){
    if(L->head == NULL) {
        printf("빈 리스트 입니다.\n");
        return;
    }
    else if(old == NULL) {
        printf("삭제할 노드가 없습니다.\n");
        return;
    }
    else if(old->llink == NULL){
        old->rlink->llink = NULL;
        L->head = old->rlink;
        free(old);
    }
    else if(old->rlink == NULL){
        old->llink->rlink = NULL;
        free(old);
    }
    else{
        old->llink->rlink = old->rlink;
        old->rlink->llink = old->llink;
        free(old);
    }
}
