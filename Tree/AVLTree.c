#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a>b)?a:b)

typedef int element;	// 이진 탐색 트리 element의 자료형 수정

typedef struct treeNode {
	element key;				// 데이터 필드
	struct treeNode* left;  	// 왼쪽 서브 트리 링크 필드
	struct treeNode* right;	// 오른쪽 서브 트리 링크 필드
} treeNode;

void displayInorder(treeNode* root);

treeNode* LL_rotate(treeNode* parent);
treeNode* RR_rotate(treeNode* parent);
treeNode* LR_rotate(treeNode* parent);
treeNode* RL_rotate(treeNode* parent);
int getHeight(treeNode* p);
int getBF(treeNode* p);
treeNode* rebalance(treeNode** p);
treeNode* insertAVLNode(treeNode** root, element x);

treeNode* searchBST(treeNode* root, element x);
treeNode* insertBSTNode(treeNode* p, element x);
void deleteBSTNode(treeNode* root, element key);

int main(void) {
	treeNode* root_AVL = NULL;
	treeNode* root_BST = NULL;
	//////////////////////////////////////////////////////////////////
	root_AVL = insertAVLNode(&root_AVL, 50); // AVL 트리 만들기
	insertAVLNode(&root_AVL, 60);
	insertAVLNode(&root_AVL, 70);
	insertAVLNode(&root_AVL, 90);
	insertAVLNode(&root_AVL, 80);
	insertAVLNode(&root_AVL, 75);
	insertAVLNode(&root_AVL, 73);
	insertAVLNode(&root_AVL, 72);
	insertAVLNode(&root_AVL, 78);
	printf("\n ******* AVL 트리 출력 ****************** \n\n");
	displayInorder(root_AVL); //중위순회 경로 출력
	printf("\n\n AVL 트리에서 70 탐색 : ");
	searchBST(root_AVL, 70);
	printf("\n\n AVL 트리에서 72 탐색 : ");
	searchBST(root_AVL, 72);
	printf("\n\n AVL 트리에서 76 탐색 : ");
	searchBST(root_AVL, 76);

	/////////////////////////////////////////////////////////////////////////////
	root_BST = insertBSTNode(root_BST, 50); //BST 만들기
	insertBSTNode(root_BST, 60);
	insertBSTNode(root_BST, 70);
	insertBSTNode(root_BST, 90);
	insertBSTNode(root_BST, 80);
	insertBSTNode(root_BST, 75);
	insertBSTNode(root_BST, 73);
	insertBSTNode(root_BST, 72);
	insertBSTNode(root_BST, 78);
	printf("\n\n\n ******* BST 출력 ************************ \n\n");
	displayInorder(root_BST);  //중위순회 경로 출력
	printf("\n\n BST에서 70 탐색 : ");
	searchBST(root_BST, 70);
	printf("\n\n BST에서 72 탐색 : ");
	searchBST(root_BST, 72);
	printf("\n\n BST에서 76 탐색 : ");
	searchBST(root_BST, 76);
	getchar(); return 0;
}

treeNode* LL_rotate(treeNode* parent) {
	treeNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}

treeNode* RR_rotate(treeNode* parent) {
	treeNode* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

treeNode* LR_rotate(treeNode* parent) {
	treeNode* child = parent->left;
	parent->left = RR_rotate(child);
	return LL_rotate(parent);
}

treeNode* RL_rotate(treeNode* parent) {
	treeNode* child = parent->right;
	parent->right = LL_rotate(child);
	return RR_rotate(parent);
}

// 서브 트리의 높이를 구하는 연산
int getHeight(treeNode* p) {
	int height = 0;
	if (p != NULL) height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
	return height;
}

// 서브 트리의 높이를 이용해 균형 인수 BF를 구하는 연산
int getBF(treeNode* p) {
	if (p == NULL) return 0;
	return getHeight(p->left) - getHeight(p->right);
}

// BF를 검사하여 불균형이 발생한 경우, 회전 연산 호출
treeNode* rebalance(treeNode** p) {
	int BF = getBF(*p);
	if (BF > 1) {
		if (getBF((*p)->left) > 0)
			*p = LL_rotate(*p);
		else *p = LR_rotate(*p);
	}
	else if (BF < -1) {
		if (getBF((*p)->right) < 0)
			*p = RR_rotate(*p);
		else *p = RL_rotate(*p);
	}
	return *p;
}

// AVL 트리에 노드를 삽입하는 연산: 이진 탐색 연산처럼 삽입한 후에, rebalance() 호출 
treeNode* insertAVLNode(treeNode** root, element x) {
	if (*root == NULL) {
		*root = (treeNode*)malloc(sizeof(treeNode));
		(*root)->key = x;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if (x < (*root)->key) {
		(*root)->left = insertAVLNode(&((*root)->left), x);
		*root = rebalance(root);
	}
	else if (x > (*root)->key) {
		(*root)->right = insertAVLNode(&((*root)->right), x);
		*root = rebalance(root);
	}
	else {
		printf("\n 이미 같은 키가 있습니다! \n");
		exit(1);
	}
	return *root;
}

// 이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
// 예제 7-5 실행을 위해 "탐색성공, count" 출력 추가
treeNode* searchBST(treeNode* root, element x) {
	treeNode* p;
	int count = 0;
	p = root;
	while (p != NULL) {
		count++;
		if (x < p->key) p = p->left;
		else if (x == p->key) {
			printf("%3d번째에 탐색 성공", count);
			return p;
		}
		else p = p->right;
	}
	count++;
	printf("%3d번째에 탐색 실패! 찾는 키가 없습니다!", count);
	return p;
}

// 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
treeNode* insertBSTNode(treeNode* p, element x) {
	treeNode* newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key)  p->left = insertBSTNode(p->left, x);
	else if (x > p->key)  p->right = insertBSTNode(p->right, x);
	else  printf("\n 이미 같은 키가 있습니다! \n");

	return p;
}

// 루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
void deleteBSTNode(treeNode* root, element key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) {  // 삭제할 노드의 위치 탐색
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	// 삭제할 노드가 없는 경우
	if (p == NULL) {
		printf("\n 찾는 키가 이진 트리에 없습니다!!");
		return;
	}

	// 삭제할 노드가 단말 노드인 경우
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	// 삭제할 노드가 자식 노드를 한 개 가진 경우
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	// 삭제할 노드가 자식 노드를 두 개 가진 경우
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) { // 왼쪽 서브 트리에서 후계자 찾기
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ)  succ_parent->left = succ->left;
		else succ_parent->right = succ->left;
		p->key = succ->key;
		p = succ;
	}
	free(p);
}

// 이진 탐색 트리를 중위 순회하면서 출력하는 연산
void displayInorder(treeNode* root) {
	if (root) {
		displayInorder(root->left);
		printf("%d_", root->key); //element형에 맞게 출력형식 지정
		displayInorder(root->right);
	}
}