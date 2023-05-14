#pragma once
#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* left;
	struct node* right;
}Node; // ��� Ÿ��. ������, ���� ���, ������ ��� �����ͷ� ����

Node* createNode(int val); // ��� ���� �Լ�
Node* makeTree(); // Ʈ�� ���� �Լ�
void printTree(Node* root); // Ʈ�� ��� �Լ�
void printPreOrder(Node* root); // ���� ��ȸ �Լ� (��ü ��� �� ��� �Լ�)
void printInOrder(Node* root); // ���� ��ȸ �Լ� (��ü ��� �� ��� �Լ�)
void printPostOrder(Node* root); // ���� ��ȸ �Լ� (��ü ��� �� ��� �Լ�)
static void connectChild(Node * parent, Node * left, Node * right); // �θ� ���� �� ���� ��带 �����ϴ� �Լ�
Node* findNode(Node* root, int value);