// 이진 탐색 트리를 사용한 영어 사전
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_SIZE	 100
#define MAX_MEANING_SIZE 200

// 데이터 형식
typedef struct {
	char word[MAX_WORD_SIZE];		
	char meaning[MAX_MEANING_SIZE];
} element;

// 노드의 구조
typedef struct TreeNode {
	element key;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

// 만약 e1 < e2 이면 -1 반환
// 만약 e1 == e2 이면 0 반환
// 만약 e1 > e2 이면 1 반환
int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);	
}

// 이진 탐색 트리 출력 함수
void display(TreeNode* p)
{
	if (p != NULL) {
		printf("(");
		display(p->left);
		printf("%s:%s", p->key.word, p->key.meaning);
		display(p->right);
		printf(")");
	}
}

// 이진 탐색 트리 탐색 함수 => 탐색에 실패했을 경우 NULL 반환
TreeNode* search(TreeNode* root, element key)
{
	// 코드 작성
    TreeNode* tmp = root;
    if(tmp == NULL) return NULL;
    
    if(compare(tmp->key, key) < 0) tmp=tmp->right;
    else if(compare(tmp->key, key) > 0) tmp=tmp->left;

    if(compare(tmp->key, key) == 0 ) return tmp;
    
    return tmp;
}

TreeNode* new_node(element item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, element key)
{
	// 코드 작성
    if(node == NULL) return new_node(key);

    if(compare(key, node->key) < 0) {
        node->left = insert_node(node->left, key);
    }
    
    else if(compare(key, node->key) > 0){
        node-> right = insert_node(node->right, key);
    }

    return node;
}

// 오른쪽 트리에서 가장 왼쪽 단말 노드 리턴
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 
// 새로운 루트 노드를 반환한다. 
TreeNode* delete_node(TreeNode* root, element key)
{
	if (root == NULL) return root;

	if (compare(key, root->key) < 0)								// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
		root->left = delete_node(root->left, key);
	else if (compare(key, root->key) > 0)						// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
		root->right = delete_node(root->right, key);
	else {																					// 키가 루트와 같으면 이 노드를 삭제하면 됨
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		else {
			// 코드 작성
		}
	}
	return root;
}

// 이진 탐색 트리를 사용하는 영어 사전 프로그램 
int main(void)
{
	char command;
	element e;
	TreeNode* root = NULL;
	TreeNode* tmp;

	// 기본 단어 입력
	element words[5] = { {"Mon", "월"}, {"Tue", "화"}, {"Wed", "수"},{"Thu", "목"},{"Fri", "금"} };
	for (int i = 0; i < 5; i++)
		root = insert_node(root, words[i]);

	do {
		printf("\n**** i: 입력, d: 삭제, s: 탐색, p: 출력, q: 종료 ****: ");
		command = getchar(); 
		getchar();		// 엔터키 제거

		switch (command) {
		case 'i':
			printf("단어:"); 
			gets(e.word);
			printf("의미:"); 
			gets(e.meaning);
			root = insert_node(root, e);
			break;
		case 'd':
			printf("단어:");
			gets(e.word);
			root = delete_node(root, e);
			break;
		case 'p':
			display(root);
			printf("\n");
			break;
		case 's':
			printf("단어:");
			gets(e.word);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("의미:%s\n", tmp->key.meaning);
			break;
		}
	} while (command != 'q');

	return 0;
}