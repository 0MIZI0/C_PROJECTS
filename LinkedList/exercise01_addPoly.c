#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    int coef;
    int exp;
    struct ListNode* link;
} listNode;

typedef struct {
    int size;
    listNode* head;
    listNode* tail;
} linkedList_h;

linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* L);
void insertTeam(linkedList_h* L, int coef, int exp);
linkedList_h* addPoly(linkedList_h* A, linkedList_h* B);

int main(void) {
    linkedList_h* A, *B, *C;

    // 다항식 A, B의 헤더 노드 생성
    A = createLinkedList_h();
    B = createLinkedList_h();

    // 다항식별 계수와 지수
    int termsA[][2] = { {3, 12}, {2, 8}, {3, 7} , {4, 6} , {1, 0} };
    int termsB[][2] = { {8, 12}, {-3, 10} , {-3, 7}, {10, 6} };
    int termCountA = sizeof(termsA) / sizeof(termsA[0]);
    int termCountB = sizeof(termsB) / sizeof(termsB[0]);

    // 다항식 항 추가
    for (int i = 0; i < termCountA; i++)
        insertTeam(A, termsA[i][0], termsA[i][1]);
    printList(A);

    for (int i = 0; i < termCountB; i++)
        insertTeam(B, termsB[i][0], termsB[i][1]);
    printList(B);

    // 다항식의 덧셈 수행
    C = addPoly(A, B);
    printList(C);

    return 0;
}

linkedList_h* createLinkedList_h(void) {
    linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
    if (L == NULL) return NULL;
    L->size = 0;
    L->head = L->tail = NULL;
    return L;
}

void printList(linkedList_h* L) {
    listNode* p;
    p = L->head;
    if (p == NULL)
        return;
    while (p != NULL) {
        printf("%dx^%d", p->coef, p->exp);
        p = p->link;
        if (p != NULL) printf(" + ");
    }
    printf("\n");
}

void insertTeam(linkedList_h* L, int coef, int exp) {
    listNode* new = (listNode*)malloc(sizeof(listNode));
    if (new == NULL)return;
    new->coef = coef;
    new->exp = exp;
    new->link = NULL;
    if (L->head == NULL) {
        L->head = L->tail = new;
    }
    else {
        L->tail->link = new;
        L->tail = new;
    }
    L->size++;
}

linkedList_h* addPoly(linkedList_h* A, linkedList_h* B) {
    linkedList_h* ans = (linkedList_h*)malloc(sizeof(linkedList_h));
    listNode* A_node = (listNode*)malloc(sizeof(listNode));
    listNode* B_node = (listNode*)malloc(sizeof(listNode));
    A_node = A->head;
    B_node = B->head;
    while(A_node!=NULL&&B_node!=NULL){
        if(A_node->exp<B_node->exp){
            insertTeam(ans, B_node->coef, B_node->exp);
            B_node = B_node->link;
        }else if(A_node->exp>B_node->exp){
            insertTeam(ans, A_node->coef, A_node->exp);
            A_node=A_node->link;
        }else if(A_node->exp == B_node->exp){
            if(A_node->coef+B_node->coef!=0)insertTeam(ans, A_node->coef+B_node->coef, A_node->exp);
            A_node = A_node->link;
            B_node = B_node->link;
        }
        //printf("%d %d\n",A_node->exp,B_node->exp)
    }
    while(A_node!=NULL){
        insertTeam(ans, A_node->coef, A_node->exp);
        A_node = A_node->link;
    }
    while(B_node!=NULL){
        insertTeam(ans, B_node->coef, B_node->exp);
        B_node = B_node->link;
    }
    return ans;
}