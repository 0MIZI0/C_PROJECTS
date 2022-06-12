#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 30					// 헤드 포인터 배열의 최대 크기

// 인접 리스트의 노드 구조를 구조체로 정의
typedef struct graphNode {
	int vertex;							// 정점을 나타내는 데이터 필드
	struct graphNode* link;			// 다음 인접 정점을 연결하는 링크 필드
} graphNode;

// 그래프를 인접 리스트로 표현하기 위한 구조체 정의
typedef struct graphType {
	int n;															// 그래프의 정점 개수
	graphNode* adjList_H[MAX_VERTEX];		// 그래프 정점에 대한 헤드 포인터 배열
} graphType;

void initGraph(graphType* g);
void insertVertex(graphType* g, int v);
void insertEdge(graphType* g, int u, int v);
void print_adjList(graphType* g);

int main(void) {
	graphType* G1 = (graphType*)malloc(sizeof(graphType));
	graphType* G2 = (graphType*)malloc(sizeof(graphType));
	graphType* G3 = (graphType*)malloc(sizeof(graphType));
	graphType* G4 = (graphType*)malloc(sizeof(graphType));

	//G1 구성 : 정점 u에 대한 간선 (u,v)의 삽입순서는 v가 큰 것부터.
	initGraph(G1);
	for (int i = 0; i < 4; i++)
		insertVertex(G1, i);	//G1의 정점 0~3 삽입
	insertEdge(G1, 0, 3);
	insertEdge(G1, 0, 1);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 1, 2);
	insertEdge(G1, 1, 0);
	insertEdge(G1, 2, 3);
	insertEdge(G1, 2, 1);
	insertEdge(G1, 3, 2);
	insertEdge(G1, 3, 1);
	insertEdge(G1, 3, 0);

	//G2 구성 : 정점 u에 대한 간선 (u,v)의 삽입순서는 v가 큰 것부터.
	initGraph(G2);
	for (int i = 0; i < 3; i++)
		insertVertex(G2, i);	// G2의 정점 0~2 삽입
	insertEdge(G2, 0, 2);
	insertEdge(G2, 0, 1);
	insertEdge(G2, 1, 2);
	insertEdge(G2, 1, 0);
	insertEdge(G2, 2, 1);
	insertEdge(G2, 2, 0);

	//G3 구성 : 정점 u에 대한 간선 <u,v>의 삽입순서는 v가 큰 것부터.
	initGraph(G3);
	for (int i = 0; i < 4; i++)
		insertVertex(G3, i);	// G3의 정점 0~3 삽입
	insertEdge(G3, 0, 3);
	insertEdge(G3, 0, 1);
	insertEdge(G3, 1, 3);
	insertEdge(G3, 1, 2);
	insertEdge(G3, 2, 3);

	//G4 구성 : 정점 u에 대한 간선 <u,v>의 삽입순서는 v가 큰 것부터.
	initGraph(G4);
	for (int i = 0; i < 3; i++)
		insertVertex(G4, i);	// G4의 정점 0~2 삽입
	insertEdge(G4, 0, 2);
	insertEdge(G4, 0, 1);
	insertEdge(G4, 1, 2);
	insertEdge(G4, 1, 0);

	//--- 완성된 인접 리스트 출력
	printf("\n G1의 인접 리스트");
	print_adjList(G1);

	printf("\n\n G2의 인접 리스트");
	print_adjList(G2);

	printf("\n\n G3의 인접 리스트");
	print_adjList(G3);

	printf("\n\n G4의 인접 리스트");
	print_adjList(G4);

	return 0;
}

// 그래프 초기화
void initGraph(graphType* g) {
	g->n = 0;							// 그래프의 정점 개수를 0으로 초기화
	for (int v = 0; v < MAX_VERTEX; v++)
		g->adjList_H[v] = NULL;			// 그래프의 정점에 대한 헤드 포인터 배열을 NULL로 초기화
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
	graphNode* p;
	for (int i = 0; i < g->n; i++) {
		printf("\n\t\t정점 %c의 인접 리스트", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf(" -> %c", p->vertex + 65); // 정점 0~3을 A~D로 출력
			p = p->link;
		}
	}
}