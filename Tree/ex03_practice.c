#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct treeNode {	
	element data;
	struct treeNode* left;  
	struct treeNode* right; 
} treeNode;

#define SIZE 100
treeNode* stack[SIZE];
treeNode* stack2[SIZE];
int top = -1;
int top2 = -1;

treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode);
void inorder_iterative(treeNode* root);
void push(treeNode* p);
treeNode* pop();

int main(void) {
	// (A*B-C/D) 수식 이진 트리 만들기
	treeNode* n7 = makeRootNode('D', NULL, NULL);
	treeNode* n6 = makeRootNode('C', NULL, NULL);
	treeNode* n5 = makeRootNode('B', NULL, NULL);
	treeNode* n4 = makeRootNode('A', NULL, NULL);
	treeNode* n3 = makeRootNode('/', n6, n7);
	treeNode* n2 = makeRootNode('*', n4, n5);
	treeNode* n1 = makeRootNode('-', n2, n3);

	inorder_iterative(n1);

	return 0;
}

// data를 루트 노드로 하여 왼쪽 서브 트리와 오른쪽 서브 트리를 연결하는 연산
treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

void push(treeNode* p) {
	if (top < SIZE - 1)
		stack[++top] = p;
}

treeNode* pop() {
	treeNode* p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

void inorder_iterative(treeNode* root) {
	treeNode* currNode = root;
	while (1) {
		while (currNode) {
			push(currNode);
            printf("%c ",currNode->data);
			currNode = currNode->left;
		}
		currNode = pop();
		if (!currNode) break;
		currNode = currNode->right;
	}
	printf("\n");
}   