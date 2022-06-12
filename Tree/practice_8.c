#include<stdio.h> 
#include<stdlib.h> 
#define MAX(a, b) (((a)>(b))?(a):(b))

// AVL 트리 노드 정의
typedef struct AVLNode
{
	int key;
	struct AVLNode* left;
	struct AVLNode* right;
} AVLNode;

// 트리의 높이를 반환
int get_height(AVLNode* node)
{
	int height = 0;

	if (node != NULL)
		height = 1 + MAX(get_height(node->left), get_height(node->right));

	return height;
}

// 노드의 균형인수를 반환
int get_balance(AVLNode* node)
{
	if (node == NULL) return 0;
	return get_height(node->left) - get_height(node->right);
}

// 노드를 동적으로 생성하는 함수
AVLNode* create_node(int key)
{
	AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// 오른쪽으로 회전시키는 함수
AVLNode* rotate_right(AVLNode* parent)
{
	//코드 작성
    AVLNode* child = parent->left;
    parent->left = child->right;
    child->right = parent;
    return child;
}

// 왼쪽으로 회전시키는 함수
AVLNode* rotate_left(AVLNode* parent)
{
	//코드 작성
    AVLNode* child = parent->right;
    parent->right = child->left;
    child->left = parent;
    return child;   
}

// AVL 트리에 새로운 노드 추가 함수: 새로운 루트를 반환 
AVLNode* insert(AVLNode* node, int key)
{
	if (node == NULL)
		return create_node(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else	// 동일한 키는 허용되지 않음
		return node;

	// 노드들의 균형인수 재계산
	int balance = get_balance(node);

	// LL 타입 처리
	if (balance > 1 && key < node->left->key)
		return rotate_right(node);

	// RR 타입 처리
	if (balance < -1 && key > node->right->key)
		return rotate_left(node);

	// LR 타입 처리
	if (balance > 1 && key > node->left->key)
	{
		// 코드 작성
        AVLNode* child = node->left;
        node->left = rotate_left(child);
        return rotate_right(node);
	}

	// RL 타입 처리
	if (balance < -1 && key < node->right->key)
	{
		// 코드 작성
        AVLNode* child = node->right;
        node->right = rotate_right(child);
        return rotate_left(node);
	}

	return node;
}

// 중위 순회 함수
void Inorder(AVLNode* root) {
	if (root) {
		printf("(");
		Inorder(root->left);
		printf("%d", root->key);
		Inorder(root->right);
		printf(")");
	}
}

int main(void)
{
	AVLNode* root = NULL;

	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 29);

	printf("중위 순회 결과 \n");
	Inorder(root);

	return 0;
}