#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct treeNode {	// 연결 자료구조로 구성하기 위해 트리의 노드 정의
	element data;
	struct treeNode* left;  // 왼쪽 서브 트리에 대한 링크 필드
	struct treeNode* right; // 오른쪽 서브 트리에 대한 링크 필드
} treeNode;

treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode);
void preorder(treeNode* root);
void inorder(treeNode* root);
void postorder(treeNode* root);

int main(void) {
	// (A*B-C/D) 수식 이진 트리 만들기
	treeNode* n7 = makeRootNode('D', NULL, NULL);
	treeNode* n6 = makeRootNode('C', NULL, NULL);
	treeNode* n5 = makeRootNode('B', NULL, NULL);
	treeNode* n4 = makeRootNode('A', NULL, NULL);
	treeNode* n3 = makeRootNode('/', n6, n7);
	treeNode* n2 = makeRootNode('*', n4, n5);
	treeNode* n1 = makeRootNode('-', n2, n3);

	printf("\n preorder : ");
	preorder(n1);

	printf("\n inorder : ");
	inorder(n1);

	printf("\n postorder : ");
	postorder(n1);

	getchar();  return 0;
}

// data를 루트 노드로 하여 왼쪽 서브 트리와 오른쪽 서브 트리를 연결하는 연산
treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

// 이진 트리에 대한 전위 순회 연산
void preorder(treeNode* root) {
	if (root) {
		printf("%c", root->data);  //작업D
		preorder(root->left);       //작업L
		preorder(root->right);	 //작업R
	}
}

// 이진 트리에 대한 중위 순회 연산
void inorder(treeNode* root) {
	if (root) {
		inorder(root->left);        //작업L
		printf("%c", root->data); //작업D
		inorder(root->right);      //작업R
	}
}

// 이진 트리에 대한 후위 순회 연산
void postorder(treeNode* root) {
	if (root) {
		postorder(root->left);    //작업L
		postorder(root->right);  //작업R
		printf("%c", root->data); //작업D
	}
}