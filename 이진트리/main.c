#pragma once
#include "tree.h"

int main() {
	printf("Hello World\n");

	Node* root = makeTree(); // Ʈ���� ����
	printTree(root); // Ʈ���� ���
	printf("\nPreOrder:");
	printPreOrder(root); // ���� ��ȸ �Լ��� ȣ���Ͽ� ���
	printf("\n");
	printf("InOrder:");
	printInOrder(root); // ���� ��ȸ �Լ��� ȣ���Ͽ� ���
	printf("\n");
	printf("PostOrder:");
	printPostOrder(root); // ���� ��ȸ �Լ��� ȣ���Ͽ� ���
	printf("\n");
}