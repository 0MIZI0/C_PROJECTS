#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ?¨? ?°κ²? λ¦¬μ€?Έ? ?Έ? κ΅¬μ‘°λ₯? κ΅¬μ‘°μ²΄λ‘ ? ?
typedef struct ListNode {
    char data[4];
    struct ListNode* link;
} listNode;

// λ¦¬μ€?Έ? ??? ?????΄? head ?Έ?λ₯? κ΅¬μ‘°μ²΄λ‘ ? ?
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

    printf("(1) κ³΅λ°± λ¦¬μ€?Έ ??±?κΈ? \n");
    L = createLinkedList_h();
    printList(L);

    printf("(2) λ¦¬μ€?Έ? μ²? λ²μ§Έ ?Έ?λ‘? ?½??κΈ? \n");
    insertFirstNode(L, "?");
    insertFirstNode(L, "?");
    insertFirstNode(L, "?");
    printList(L);

    printf("(3) λ¦¬μ€?Έ? λ§μ??λ§μ ?Έ? ?½??κΈ? \n");
    insertLastNode(L, "? ");
    insertLastNode(L, "?Ό");
    printList(L);

    printf("(4) λ¦¬μ€?Έ? μ€κ°? ?Έ? ?½??κΈ? \n");
    insertMiddleNode(L, searchNode(L, "?"), "λͺ?");
    insertMiddleNode(L, searchNode(L, "λͺ?"), "κΈ?");
    printList(L);

    printf("(5) λ¦¬μ€?Έ κ³΅κ°? ?΄? ??¬ κ³΅λ°± λ¦¬μ€?Έλ‘? λ§λ€κΈ? \n");
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
// κ³΅λ°± ?°κ²? λ¦¬μ€?Έλ₯? ??±?? ?°?°
linkedList_h* createLinkedList_h() {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;        // κ³΅λ°± λ¦¬μ€?Έ?΄λ―?λ‘? NULLλ‘? ?€? 
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

// ?°κ²? λ¦¬μ€?Έλ₯? ?????λ‘? μΆλ ₯?? ?°?°
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