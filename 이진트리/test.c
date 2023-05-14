#pragma once
#include "tree.h"

int main() {
	Node* root = makeTree();
	int value = 0;

	printf("°ª? ");
	scanf("%d", &value);

	printf("³ëµå: %d", findNode(root, value));
}