#pragma once
#include "tree.h"

// ��� ���� �Լ�
Node* createNode(int val) {
	Node* pNode = (Node*)malloc(sizeof(Node));

	pNode->value = val; // ����� value �� ����
	pNode->left = NULL;
	pNode->right = NULL; // ���� ���� ������ ��� �ʱ�ȭ

	return pNode; // ������ ��� ������ return
}
// �θ� ���� �� ���� ��带 �����ϴ� �Լ�
void connectChild(Node* parent, Node* left, Node* right) {
	if (parent == NULL) return NULL; // �θ� ��尡 NULL�� ��� NULL�� return
	parent->left = left; // �θ� ����� ���� ��带 left ���� ����
	parent->right = right; // �θ� ����� ������ ��带 right ���� ����
}
Node* makeTree() {
	Node* pRoot = NULL; // root ��� �ʱ�ȭ
	Node* tLeft = NULL; // ���� ��� �ʱ�ȭ
	Node* tRight = NULL; // ������ ��� �ʱ�ȭ

	pRoot = createNode(100); // root ��� 100���� ����
	tLeft = createNode(200); // ���� ��带 200���� ����
	tRight = createNode(300); // ������ ��带 300���� ����

	connectChild(pRoot, tLeft, tRight); // ������ �� ��带 ����
	connectChild(tRight, createNode(400), createNode(500)); // ������ ��忡 400�� 500 ��带 �����Ͽ� ����

	return pRoot; // root ��带 return
}
void printTree(Node* root) {
	if (root == NULL) return; // root�� NULL�̶�� return

	printf("Node: %d ", root->value); // ���
	printTree(root->left);
	printTree(root->right);
}
// ���� ��ȸ �Լ�
void printPreOrder(Node* root) {
	if (root != NULL) {
		printf("%d ", root->value);  // ��� �� ���
		printPreOrder(root->left);  // ���� ����Ʈ�� ��ȸ
		printPreOrder(root->right); // ������ ����Ʈ�� ��ȸ
	}
}

// ���� ��ȸ �Լ�
void printInOrder(Node* root) {
	if (root != NULL) {
		printInOrder(root->left);   // ���� ����Ʈ�� ��ȸ
		printf("%d ", root->value);  // ��� �� ���
		printInOrder(root->right);  // ������ ����Ʈ�� ��ȸ
	}
}

// ���� ��ȸ �Լ�
void printPostOrder(Node* root) {
	if (root != NULL) {
		printPostOrder(root->left);  // ���� ����Ʈ�� ��ȸ
		printPostOrder(root->right); // ������ ����Ʈ�� ��ȸ
		printf("%d ", root->value);   // ��� �� ���
	}
}

// Ư�� ���� ��带 ã�� ����� �����͸� ��ȯ�ϴ� �Լ�
Node* findNode(Node* root, int value) {
	if (root == NULL || root->value == value)
		return root; // ��尡 NULL�̰ų�, Ư�� ���� ����� ���� ��ġ�ϴٸ� root�� ��ȯ

	Node* found = findNode(root->left, value);  // ��� �Լ��� �̿��Ͽ� ���� ����Ʈ������ ã��
	if (found == NULL) { // ���� ����Ʈ������ �߰����� ���ߴٸ�,
		found = findNode(root->right, value);  // ��� �Լ��� �̿��Ͽ� ������ ����Ʈ������ ã��
	}
	return found; // ã�� ��带 ��ȯ. ã�� ���Ͽ��ٸ� NULL�� ��ȯ
}