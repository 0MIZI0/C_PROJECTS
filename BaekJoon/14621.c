//이민재 - 프림 알고리즘 - 나만 안돼는 연애

//14621
#include <stdio.h>
#include <stdlib.h>

#define N 1000

#pragma region heap
#define MAX_ELEMENT 10001

typedef struct {
	int key, start, end;
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
void insert_min_heap(HeapType* h, element item)
{
	h->heap_size += 1;
	int i = h->heap_size;
	while (i != 1 && item.key < h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType* h)
{
	element item = h->heap[1];
	element temp = h->heap[h->heap_size];
	h->heap_size -= 1;
	int parent = 1, child = 2;

	while (child <= h->heap_size) {
		if (child < h->heap_size && h->heap[child].key > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		else {
			h->heap[parent] = h->heap[child];
			parent = child;
			child *= 2;
		}
	}
	h->heap[parent] = temp;
	return item;
}
#pragma endregion

#pragma region linkedList
// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	int data;
	int end;
	struct ListNode* link;
} listNode;

// 리스트의 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h() {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

void insertFirstNode(linkedList_h* L, int end, int a) {
	listNode* n = (listNode*)malloc(sizeof(listNode));
	if (n == NULL) return;
	n->data = a;
	n->end = end;
	n->link = L->head;
	L->head = n;
}
#pragma endregion

int gender[N], visited[N], n, m;
linkedList_h* graph[N];

void insertGraph(int x, int y, int value) {
	insertFirstNode(graph[x], y, value);
	insertFirstNode(graph[y], x, value);
}

element input(int key, int start, int end) {
	element k;
	k.key = key;
	k.start = start;
	k.end = end;

	return k;
}

void init() {
	for (int i = 0; i < N; i++) {
		graph[i] = createLinkedList_h();
	}
}

int main() {
	init();

	scanf("%d %d", &n, &m);
	getchar();

	for (int i = 0; i < n; i++) {
		char x;
		x = getchar(); getchar();

		switch (x) {
		case 'M':
			gender[i] = 0;
			break;
		case 'W':
			gender[i] = 1;
			break;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (gender[a - 1] != gender[b - 1])
			insertGraph(a - 1, b - 1, c);
	}

	for (int i = 0; i < n; i++) {
		if (graph[i]->head == NULL) {
			printf("-1");
			return 0;
		}
	}

	HeapType* heap;
	heap = create();
	int cost = 0;

	insert_min_heap(heap, input(0, 0, 0));
	//printf("경로 출력 : ");
	while (heap->heap_size != 0) {
		//printHeap(heap);
		element temp = delete_min_heap(heap);

		if (visited[temp.end]) continue;
		visited[temp.end] = 1;

		listNode* p = graph[temp.end]->head;
		while (p != NULL) {
			if (!visited[p->end]) {
				insert_min_heap(heap, input(p->data, temp.end, p->end));
			}
			p = p->link;
		}

		cost += temp.key;
	}

	printf("%d\n", cost);
}