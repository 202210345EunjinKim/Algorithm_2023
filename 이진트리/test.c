#pragma once
#include "tree.h"

int main() {
	Node* root = makeTree();
	int value = 0;

	printf("��? ");
	scanf("%d", &value);

	printf("���: %d", findNode(root, value));
}