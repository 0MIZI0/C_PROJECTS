#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// 생성 함수
HeapType* create()
{
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	h->heap_size = 0;
	return h;
}

// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
void insert_max_heap(HeapType* h, element item)
{
	//코드 작성
    h->heap_size++;
    if(h->heap_size == MAX_ELEMENT) {
        printf("heap is full");
        return;
    }

    
}

element delete_max_heap(HeapType* h)
{
	//코드 작성
}

void printHeap(HeapType* h) {
	printf("\n히프 트리: ");
	for (int i = 1; i <= h->heap_size; i++) {
		printf("%d ", h->heap[i]);
	}
}

int main(void)
{
	element eArr[] = { 10, 45, 19, 11, 96 };
	int n = sizeof(eArr) / sizeof(element);
	HeapType* heap;
	heap = create();

	// 삽입
	printf("삽입 순서: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", eArr[i].key);
		insert_max_heap(heap, eArr[i]);
	}

	printHeap(heap);

	// 삭제
	printf("\n삭제 순서: ");
	for (int i = 0; i < n; i++)
		printf("%d ", delete_max_heap(heap));
	free(heap);

	return 0;
}