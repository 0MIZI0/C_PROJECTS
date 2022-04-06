#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ?‹¨?ˆœ ?—°ê²? ë¦¬ìŠ¤?Š¸?˜ ?…¸?“œ êµ¬ì¡°ë¥? êµ¬ì¡°ì²´ë¡œ ? •?˜
typedef struct ListNode {
    char data[4];
    struct ListNode* link;
} listNode;

// ë¦¬ìŠ¤?Š¸?˜ ?‹œ?ž‘?„ ?‚˜????‚´?Š” head ?…¸?“œë¥? êµ¬ì¡°ì²´ë¡œ ? •?˜
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

    printf("(1) ê³µë°± ë¦¬ìŠ¤?Š¸ ?ƒ?„±?•˜ê¸? \n");
    L = createLinkedList_h();
    printList(L);

    printf("(2) ë¦¬ìŠ¤?Š¸?— ì²? ë²ˆì§¸ ?…¸?“œë¡? ?‚½?ž…?•˜ê¸? \n");
    insertFirstNode(L, "?ˆ˜");
    insertFirstNode(L, "?™”");
    insertFirstNode(L, "?›”");
    printList(L);

    printf("(3) ë¦¬ìŠ¤?Š¸?— ë§ˆì??ë§‰ì— ?…¸?“œ ?‚½?ž…?•˜ê¸? \n");
    insertLastNode(L, "?† ");
    insertLastNode(L, "?¼");
    printList(L);

    printf("(4) ë¦¬ìŠ¤?Š¸?— ì¤‘ê°„?— ?…¸?“œ ?‚½?ž…?•˜ê¸? \n");
    insertMiddleNode(L, searchNode(L, "?ˆ˜"), "ëª?");
    insertMiddleNode(L, searchNode(L, "ëª?"), "ê¸?");
    printList(L);

    printf("(5) ë¦¬ìŠ¤?Š¸ ê³µê°„?„ ?•´? œ?•˜?—¬ ê³µë°± ë¦¬ìŠ¤?Š¸ë¡? ë§Œë“¤ê¸? \n");
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
// ê³µë°± ?—°ê²? ë¦¬ìŠ¤?Š¸ë¥? ?ƒ?„±?•˜?Š” ?—°?‚°
linkedList_h* createLinkedList_h() {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;        // ê³µë°± ë¦¬ìŠ¤?Š¸?´ë¯?ë¡? NULLë¡? ?„¤? •
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

// ?—°ê²? ë¦¬ìŠ¤?Š¸ë¥? ?ˆœ?„œ???ë¡? ì¶œë ¥?•˜?Š” ?—°?‚°
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