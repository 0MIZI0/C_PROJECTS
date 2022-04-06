#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ?��?�� ?���? 리스?��?�� ?��?�� 구조�? 구조체로 ?��?��
typedef struct ListNode {
    char data[4];
    struct ListNode* link;
} listNode;

// 리스?��?�� ?��?��?�� ?��????��?�� head ?��?���? 구조체로 ?��?��
typedef struct {
    listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h();
void printList(linkedList_h* L);
void insertFirstNode(linkedList_h* L, char* x);
void insertLastNode(linkedList_h* L, char* x);
void insertMiddleNode(linkedList_h* L, listNode* temp, char* x);
void freeLinkedList(linkedList_h* L);
listNode* searchNode(linkedList_h* L, char* x);

int main(void) {
    linkedList_h* L;

    printf("(1) 공백 리스?�� ?��?��?���? \n");
    L = createLinkedList_h();
    printList(L);

    printf("(2) 리스?��?�� �? 번째 ?��?���? ?��?��?���? \n");
    insertFirstNode(L, "?��");
    insertFirstNode(L, "?��");
    insertFirstNode(L, "?��");
    printList(L);

    printf("(3) 리스?��?�� 마�??막에 ?��?�� ?��?��?���? \n");
    insertLastNode(L, "?��");
    insertLastNode(L, "?��");
    printList(L);

    printf("(4) 리스?��?�� 중간?�� ?��?�� ?��?��?���? \n");
    insertMiddleNode(L, searchNode(L, "?��"), "�?");
    insertMiddleNode(L, searchNode(L, "�?"), "�?");
    printList(L);

    printf("(5) 리스?�� 공간?�� ?��?��?��?�� 공백 리스?���? 만들�? \n");
    freeLinkedList(L);
    printList(L);

    return 0;
}
void freeLinkedList(linkedList_h* L){
    listNode* p;
    while(L->head != NULL){
        p = L->head;
        L->head = L->head->link;
        free(p);
        p = NULL;
    }
}
// 공백 ?���? 리스?���? ?��?��?��?�� ?��?��
linkedList_h* createLinkedList_h() {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;        // 공백 리스?��?���?�? NULL�? ?��?��
    return L;
}

listNode* searchNode(linkedList_h* L, char x[]){
    listNode* temp = (listNode*)malloc(sizeof(listNode));
    temp = L->head;
    while(temp!=NULL){
        //printf("%s %s\n",temp->data,x);
        if(!strcmp(temp->data,x)){
            return temp;
        }else{
            temp = temp->link;
        }
    }
    return temp;
}

// ?���? 리스?���? ?��?��???�? 출력?��?�� ?��?��
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

void insertFirstNode(linkedList_h* L, char* x) {
    listNode* new = (listNode*)malloc(sizeof(listNode));
    if(new == NULL) return;
    strcpy(new->data,x);
    new->link = L->head;
    L->head = new;
}
void insertLastNode(linkedList_h* L, char* x) {
    listNode* new = (listNode*)malloc(sizeof(listNode));
    if(new == NULL) return;
    strcpy(new->data,x);
    new->link = NULL;
    if(L == NULL){
        L->head = new;
        return;
    }
    listNode* temp = (listNode*)malloc(sizeof(listNode));
    temp = L->head;
    while(temp->link!=NULL){
        temp = temp->link;
    }
    temp->link = new;
}

void insertMiddleNode(linkedList_h* L, listNode* temp, char* x){
    listNode* new = (listNode*)malloc(sizeof(listNode));
    printf("11:%s\n",temp->data);
    if(new == NULL) return;
    strcpy(new->data, x);
    if(L == NULL){
        L->head = new;
        new->link = NULL;
    }else{
        new->link = temp->link;
        temp->link = new;
    }
}