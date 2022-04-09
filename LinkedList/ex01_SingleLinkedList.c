#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
   char data[4];
   struct ListNode* link;
} listNode;

// 리스트의 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
   listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h();
void printList(linkedList_h* L);
void insertFirstNode(linkedList_h* L, char* x);
listNode* searchNode(linkedList_h* L, char* x);
void insertMiddleNode(linkedList_h* L,listNode* pre, char* x);
void insertLastNode(linkedList_h* L,char* x);
void freeLinkedList(linkedList_h* L);

int main(void) {
   linkedList_h* L;

   printf("(1) 공백 리스트 생성하기 \n");
   L = createLinkedList_h();
   printList(L);

   printf("(2) 리스트에 첫 번째 노드로 삽입하기 \n");
   insertFirstNode(L, "수");
   insertFirstNode(L, "화");
   insertFirstNode(L, "월");
   printList(L);

   printf("(3) 리스트에 마지막에 노드 삽입하기 \n");
   insertLastNode(L, "토");
   insertLastNode(L, "일");
   printList(L);

   printf("(4) 리스트에 중간에 노드 삽입하기 \n");
   insertMiddleNode(L, searchNode(L, "수"), "목");
   insertMiddleNode(L, searchNode(L, "묙"), "금");
   printList(L);

   printf("(5) 리스트 공간을 해제하여 공백 리스트로 만들기 \n");
   freeLinkedList(L);
   printList(L);

   return 0;
}


linkedList_h* createLinkedList_h() {
   linkedList_h* L;
   L = (linkedList_h*)malloc(sizeof(linkedList_h));
   L->head = NULL;
   return L;
}

listNode* searchNode(linkedList_h* L, char* a) {
   listNode* node = L->head;

   while (node->link != NULL && strcmp(node->data, a)) {
      node = node->link;
   }

   if (!strcmp(node->data, a))
      return node;
   else
      return NULL;
}

void insertMiddleNode(linkedList_h* L, listNode* index, char* a) {
   if (index == NULL) {
      printf("이전 노드 검색 실패\n");
      return;
   }

   listNode* new = (listNode*)malloc(sizeof(listNode));

   if (new == NULL) return;
   strcpy(new->data, a);

   if (L == NULL) {
      L->head = new;
      new->link = NULL;
   }
   else {
      new->link = index->link;
      index->link = new;
   }
}

void printList(linkedList_h* L) {
   listNode* p;
   printf("L = (");
   p = L->head;
   while (p != NULL) {
      printf("%s", p->data);
      p = p->link;
      if (p != NULL) printf(", ");
   }
   printf(") \n");
}



void insertFirstNode(linkedList_h* L, char* x){
    listNode* new = (listNode*)malloc(sizeof(listNode));
    if (new == NULL) return;
    strcpy(new->data, x);
    new->link = L->head;
    L->head = new;
}



void insertLastNode(linkedList_h* L,char* x){
    listNode* newNode;
    listNode* temp;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, x);
    newNode -> link = NULL;
    if (L -> head == NULL){ 
        L -> head = newNode;
        return;
    }
    
    temp = L -> head;
    while (temp -> link != NULL)temp = temp -> link;
    temp -> link = newNode;
}

void freeLinkedList(linkedList_h* L){
    listNode* p;
    while(L->head != NULL){
        p = L->head;
        L -> head = L -> head -> link;
        free(p);
        p = NULL;
    }
}