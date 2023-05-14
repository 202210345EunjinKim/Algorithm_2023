#pragma once
#include "tree.h"

// 노드 생성 함수
Node* createNode(int val) {
	Node* pNode = (Node*)malloc(sizeof(Node));

	pNode->value = val; // 노드의 value 값 설정
	pNode->left = NULL;
	pNode->right = NULL; // 왼쪽 노드와 오른쪽 노드 초기화

	return pNode; // 생성된 노드 포인터 return
}
// 부모 노드와 두 개의 노드를 연결하는 함수
void connectChild(Node* parent, Node* left, Node* right) {
	if (parent == NULL) return NULL; // 부모 노드가 NULL인 경우 NULL을 return
	parent->left = left; // 부모 노드의 왼쪽 노드를 left 노드로 연결
	parent->right = right; // 부모 노드의 오른쪽 노드를 right 노드로 연결
}
Node* makeTree() {
	Node* pRoot = NULL; // root 노드 초기화
	Node* tLeft = NULL; // 왼쪽 노드 초기화
	Node* tRight = NULL; // 오른쪽 노드 초기화

	pRoot = createNode(100); // root 노드 100으로 생성
	tLeft = createNode(200); // 왼쪽 노드를 200으로 생성
	tRight = createNode(300); // 오른쪽 노드를 300으로 생성

	connectChild(pRoot, tLeft, tRight); // 생성한 세 노드를 연결
	connectChild(tRight, createNode(400), createNode(500)); // 오른쪽 노드에 400과 500 노드를 생성하여 연결

	return pRoot; // root 노드를 return
}
void printTree(Node* root) {
	if (root == NULL) return; // root가 NULL이라면 return

	printf("Node: %d ", root->value); // 출력
	printTree(root->left);
	printTree(root->right);
}
// 전위 순회 함수
void printPreOrder(Node* root) {
	if (root != NULL) {
		printf("%d ", root->value);  // 노드 값 출력
		printPreOrder(root->left);  // 왼쪽 서브트리 순회
		printPreOrder(root->right); // 오른쪽 서브트리 순회
	}
}

// 중위 순회 함수
void printInOrder(Node* root) {
	if (root != NULL) {
		printInOrder(root->left);   // 왼쪽 서브트리 순회
		printf("%d ", root->value);  // 노드 값 출력
		printInOrder(root->right);  // 오른쪽 서브트리 순회
	}
}

// 후위 순회 함수
void printPostOrder(Node* root) {
	if (root != NULL) {
		printPostOrder(root->left);  // 왼쪽 서브트리 순회
		printPostOrder(root->right); // 오른쪽 서브트리 순회
		printf("%d ", root->value);   // 노드 값 출력
	}
}

// 특정 값의 노드를 찾는 노드의 포인터를 반환하는 함수
Node* findNode(Node* root, int value) {
	if (root == NULL || root->value == value)
		return root; // 노드가 NULL이거나, 특정 값과 노드의 값이 일치하다면 root를 반환

	Node* found = findNode(root->left, value);  // 재귀 함수를 이용하여 왼쪽 서브트리에서 찾기
	if (found == NULL) { // 왼쪽 서브트리에서 발견하지 못했다면,
		found = findNode(root->right, value);  // 재귀 함수를 이용하여 오른쪽 서브트리에서 찾기
	}
	return found; // 찾은 노드를 반환. 찾지 못하였다면 NULL을 반환
}