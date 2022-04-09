#include <stdio.h>
#include <stdlib.h>

#define N 15

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

    treeNode tree[N+1];
    //1. 1~15 데이터 저장
    for(int i = 1;i <= N;i++){
        tree[i].data = i;
        tree[i].left = NULL;
        tree[i].right = NULL;
    }

    //2. 각 노드 연결
    for(int i = 2;i <= N; i++){
        if( i % 2 == 0) tree[i / 2].left = &tree[i];
        else tree[i / 2].right = &tree[i];        
    }

    //3. 트리 순회
    printf("\n preorder : ");
    preorder(&tree[1]); // &tree[1] == tree+1

    
    printf("\n inorder : ");
    inorder(&tree[1]);

    
    printf("\n postorder : ");
    postorder(&tree[1]);

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

// 이진 트리에 대한 전위 순회 연산
void preorder(treeNode* root) {
	if (root) {
		printf("%3d", root->data);  //작업D
		preorder(root->left);       //작업L
		preorder(root->right);	 //작업R
	}
}

// 이진 트리에 대한 중위 순회 연산
void inorder(treeNode* root) {
	if (root) {
		inorder(root->left);        //작업L
		printf("%3d", root->data); //작업D
		inorder(root->right);      //작업R
	}
}

// 이진 트리에 대한 후위 순회 연산
void postorder(treeNode* root) {
	if (root) {
		postorder(root->left);    //작업L
		postorder(root->right);  //작업R
		printf("%3d", root->data); //작업D
	}
}