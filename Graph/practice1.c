#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 30					// 헤드 포인터 배열의 최대 크기
#define FALSE 0								
#define TRUE 1								

#pragma region 그래프 기존 조작
// 인접 리스트의 노드 구조를 구조체로 정의
typedef struct graphNode {
	int vertex;										// 정점을 나타내는 데이터 필드
	struct graphNode* link;				// 다음 인접 정점을 연결하는 링크 필드
} graphNode;

// 그래프를 인접 리스트로 표현하기 위한 구조체 정의
typedef struct graphType {
	int n;															// 그래프의 정점 개수
	graphNode* adjList_H[MAX_VERTEX];		// 그래프 정점에 대한 헤드 포인터 배열
	int visited[MAX_VERTEX];						// 정점에 대한 방문 표시를 위한 배열 추가!
} graphType;

void createGraph(graphType* g);
void insertVertex(graphType* g, int v);
void insertEdge(graphType* g, int u, int v);
void print_adjList(graphType* g);
#pragma endregion

void DFS_adjList(graphType* g, int v);

int main(void) {
	int i;
	graphType* G9;
	G9 = (graphType*)malloc(sizeof(graphType));
	createGraph(G9);

	// 그래프 G9 구성 : 정점 u에 대한 간선 (u,v)의 삽입순서는 v가 큰 것부터.
	for (i = 0; i < 7; i++)
		insertVertex(G9, i);
	insertEdge(G9, 0, 2);
	insertEdge(G9, 0, 1);
	insertEdge(G9, 1, 4);
	insertEdge(G9, 1, 3);
	insertEdge(G9, 1, 0);
	insertEdge(G9, 2, 4);
	insertEdge(G9, 2, 0);
	insertEdge(G9, 3, 6);
	insertEdge(G9, 3, 1);
	insertEdge(G9, 4, 6);
	insertEdge(G9, 4, 2);
	insertEdge(G9, 4, 1);
	insertEdge(G9, 5, 6);
	insertEdge(G9, 6, 5);
	insertEdge(G9, 6, 4);
	insertEdge(G9, 6, 3);
	printf("G9의 인접 리스트 ");
	print_adjList(G9);  //G9의 인접 리스트를 확인용으로 출력

	printf("\n\n깊이 우선 탐색 >> ");
	DFS_adjList(G9, 0);     // 0번 정점인 정점 A에서 깊이 우선 탐색 시작
	
	return 0;
}

// 공백 그래프를 생성하는 연산
void createGraph(graphType* g) {
	int v;
	g->n = 0;														// 그래프의 정점 개수를 0으로 초기화
	for (v = 0; v < MAX_VERTEX; v++) {
		g->adjList_H[v] = NULL;						// 그래프의 정점에 대한 헤드 포인터 배열을 NULL로 초기화
		g->visited[v] = FALSE;						// 그래프의 정점에 대한 배열 visited를 FALSE로 초기화 추가!
	}
}

// 그래프 g에 정점 v를 삽입하는 연산
void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;								// 그래프의 정점 개수 n을 하나 증가
}

// 그래프 g에 간선 (u, v)를 삽입하는 연산
void insertEdge(graphType* g, int u, int v) {
	graphNode* node;

	// 간선 (u, v)를 삽입하기 위해 정점 u와 정점 v가 현재 그래프에 있는지 확인
	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];	// 삽입 간선에 대한 노드를 리스트의 첫 번째 노드로 연결
	g->adjList_H[u] = node;
}

// 그래프 g의 각 정점에 대한 인접 리스트를 출력하는 연산
void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n정점 %c의 인접 리스트", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf(" -> %c", p->vertex + 65); // 정점 0~3을 A~D로 출력
			p = p->link;
		}
	}
}

// 그래프 g에서 정점 v에 대한 깊이 우선 탐색 연산 : [알고리즘 8-1] 구현
void DFS_adjList(graphType* g, int v) {

	// 방문하지 않았다면 정점 v 출력
	if (!g->visited[v]) {
		printf(" %c", v + 65);
		g->visited[v] = TRUE;
	}				
		
	// 연결된 모든 정점에 대해 재귀적 방문 처리
	graphNode* w = g->adjList_H[v];
	while (w) {
		if (!g->visited[w->vertex])
			DFS_adjList(g, w->vertex);
		w = w->link;
	}
}