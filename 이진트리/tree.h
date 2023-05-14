#pragma once
#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* left;
	struct node* right;
}Node; // 노드 타입. 정수값, 왼쪽 노드, 오른쪽 노드 포인터로 구성

Node* createNode(int val); // 노드 생성 함수
Node* makeTree(); // 트리 생성 함수
void printTree(Node* root); // 트리 출력 함수
void printPreOrder(Node* root); // 전위 순회 함수 (전체 노드 값 출력 함수)
void printInOrder(Node* root); // 중위 순회 함수 (전체 노드 값 출력 함수)
void printPostOrder(Node* root); // 후위 순회 함수 (전체 노드 값 출력 함수)
static void connectChild(Node * parent, Node * left, Node * right); // 부모 노드와 두 개의 노드를 연결하는 함수
Node* findNode(Node* root, int value);