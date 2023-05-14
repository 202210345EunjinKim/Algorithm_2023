#pragma once
#include "tree.h"

int main() {
	printf("Hello World\n");

	Node* root = makeTree(); // 트리를 생성
	printTree(root); // 트리를 출력
	printf("\nPreOrder:");
	printPreOrder(root); // 전위 순회 함수를 호출하여 출력
	printf("\n");
	printf("InOrder:");
	printInOrder(root); // 중위 순회 함수를 호출하여 출력
	printf("\n");
	printf("PostOrder:");
	printPostOrder(root); // 후위 순회 함수를 호출하여 출력
	printf("\n");
}