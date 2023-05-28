#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 100 // �ִ� ���� ����
#define ALPHA_SIZE 58 // ���ĺ� ����

typedef struct Node {
	int weight; // �󵵼�
	int alpha; // ���ĺ�
	char code[100]; // ���� �ڵ�
	int depth; // Ʈ���� ����
	struct Node* left; // ���� �ڽ� ���
	struct Node* right; // ������ �ڽ� ���
}Node; // ������ Ʈ�� ��� ����ü

typedef struct {
	Node* ptree; // Ʈ�� ������
	int key; // �󵵼�
}Element; // �켱���� ť�� ����

typedef struct {
	Element heap[MAX_ELEMENT]; // �迭
	int heap_size; // ���� ũ��
}HeapType; // �켱���� ť�� ����ϱ� ���� �� ����ü

void init(HeapType* h) {
	h->heap_size = 0;
} // �� �ʱ�ȭ �Լ�
void insert_heap(HeapType* h, Element item) {
	int i;
	i = ++(h->heap_size); // ������ ����� ��ġ
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	} // i�� �����Ϸ��� ��Ұ� �θ� ��庸�� ���� ���, �θ� ��带 ���� ��ġ�� �̵��ϰ�
	  // i�� �θ� ����� ��ġ�� ����
	h->heap[i] = item; // �ش� ��ġ�� item�� ����
}
Element delete_heap(HeapType* h) {
	int parent, child;
	Element item, temp;

	item = h->heap[1]; // ���� ��Ʈ ��� ����
	temp = h->heap[(h->heap_size)--]; // ���� ������ ��� ������ �� ���� ũ�� ����
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key) {
			child++; // ������ �ڽĺ��� ���� �ڽ��� �� Ŭ ��� child ����
		}
		if (temp.key <= h->heap[child].key) break; // temp.key���� ���õ� �ڽ��� Ű ������ �۰ų� ���� ��� ����
		h->heap[parent] = h->heap[child]; // ������ ��� ����
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
} // �ּ� ������ �ּ� Ű ���� ���� ��Ҹ� �����ϰ� ������ ��Ҹ� ��ȯ
Node* make_tree(Node* left, Node* right) {
	Node* node = (Node*)malloc(sizeof(Node)); // ���� �޸� �Ҵ�
	if (node == NULL) {
		fprintf(stderr, "����\n");
		exit(1);
	} // ������ ��� ���� �޽��� ���, ���α׷� ����
	node->left = left; // ���� �ڽ� ��� ����
	node->right = right; // ������ �ڽ� ��� ����
	return node; // ���� ������ ��带 ��ȯ
}
void delete_tree(Node* root) {
	if (root == NULL) return; // Ʈ���� ����ִ� ��� ����
	delete_tree(root->left); // ���� ����Ʈ���� ����
	delete_tree(root->right); // ������ ����Ʈ���� ����
	free(root); // ���� ��� ����
}
void Huffman(Node* r, int n, char* code) {
	if (r) {
		n++; // n�� 1 ������Ŵ
		code[n] = '1'; // n��° ��ġ�� 1�� ����
		Huffman(r->right, n, code); // ������ �ڽ��� ��Ʈ�� �ϴ� ���� Ʈ���� ���� ȣ��
		code[n] = '0'; // n��° ��ġ�� 0�� ����
		Huffman(r->left, n, code); // ���� �ڽ��� ��Ʈ�� �ϴ� ���� Ʈ���� ���� ȣ��
		code[n] = '\0'; // n��° ��ġ�� �� ���� ����
		if (r->left == NULL && r->right == NULL) {
			strcpy(r->code, code); // ���� ����� �ڵ带 r�� �ڵ�� ����
			r->depth = n; // r�� ���̸� ���� ���̷� ����
		}
	}
}
void sub_order(Node* r, int i) {
	if (r) {
		sub_order(r->right, i); // ������ �ڽ��� ��Ʈ�� �ϴ� ����Ʈ���� ���� �Լ� ȣ��
		sub_order(r->left, i); // ���� �ڽ��� ��Ʈ�� �ϴ� ����Ʈ���� ���� �Լ� ȣ��
		if ((r->left == NULL || r->right == NULL) && r->depth == i) {
			printf("�󵵼�=%2d ����=%c �ڵ�=%s\n", r->weight, r->alpha, r->code);
		} // ���� �ڽ� ��� �Ǵ� ������ �ڽ� ��尡 ����ְ�, r�� ���̰� i�� ���� ���
		  // �󵵼�, ����, �ڵ带 ���
	}
}
void level_order(Node* r) {
	int i;
	for (i = 0; i < 10; i++) {
		sub_order(r, i); // r�� ��Ʈ�� �ϴ� Ʈ������ ���� i�� �ش��ϴ� ���鿡 ���� ȣ��
	}
} // Ư�� ���̿� �ش��ϴ� ������ ����ϴ� �Լ�
int huffman_tree(int freq[], int n) {
	int i, j = 0;
	Node* node, * x;
	HeapType heap;
	Element e, e1, e2;
	char* code = (char*)malloc(sizeof(char));

	init(&heap); // �� �ʱ�ȭ
	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL); // ���� �ڽİ� ������ �ڽ��� ����ִ� ��带 ����
		e.key = node->weight = freq[i]; // ������ ����� ����ġ�� �󵵼��� ����
		node->alpha = (i + 65); // ���ĺ� �� ����
		e.ptree = node; 
		insert_heap(&heap, e); // ������ e�� ���� ����
		j++;
	}
	for (i = 1; i < j; i++) {
		e1 = delete_heap(&heap); // ���� ���� ���Ҹ� �����ϰ� ��ȯ
		e2 = delete_heap(&heap); // �������� ���� ���Ҹ� �����ϰ� ��ȯ
		x = make_tree(e1.ptree, e2.ptree); // �� ���� ��带 �ڽ����� �ϴ� ���ο� ��� ����
		e.key = x->weight = e1.key + e2.key; // ������ ����� ����ġ�� �� ����� ����ġ�� ������ ����
		e.ptree = x;
		insert_heap(&heap, e);
	}
	e = delete_heap(&heap); // ���������� ���� ���Ҹ� �����ϰ� ��ȯ
	Huffman(e.ptree, -1, code); // huffman �Լ��� ȣ���Ͽ� �� ��忡 �ڵ�� ���̸� �Ҵ�
	level_order(e.ptree); // ���� ������ ��ȸ�ϸ� Ư�� ���̿� �ش��ϴ� ��� ���
	delete_tree(e.ptree); // Ʈ�� ����
}
Node* find_node(Node* root, int alpha) {
	if (root == NULL)
		return NULL;

	if (root->alpha == alpha)
		return root; // ���ĺ� ���� ã�� ���� ��ġ�ϸ� �ش� ��� ��ȯ

	Node* left = find_node(root->left, alpha);
	if (left != NULL)
		return left; // ���� ����Ʈ������ �߰��ϸ� �ش� ��� ��ȯ

	Node* right = find_node(root->right, alpha);
	if (right != NULL)
		return right; // ������ ����Ʈ������ �߰��ϸ� �ش� ��� ��ȯ

	return NULL; // ã�� ���ϸ� NULL ��ȯ
}
void main() {
	int i = 0;
	int freq[ALPHA_SIZE] = { 0 };
	Node* root;
	FILE* fp = fopen("input.txt", "r"); // input.txt �о���̱�
	if (fp == NULL) { puts("����x"); } // �����ϸ� ���� �޽��� ���
	while (i != EOF) {
		i = fgetc(fp); // �� ���ھ� �б�
		if ((0 <= (i - 65) <= 25) || (32 <= (i - 65) <= 57)) {
			freq[i - 65] += 1; // �о�� ���ڰ� ���ĺ� �빮�� �Ǵ� ���ڿ� �ش��Ѵٸ�
							   //�ش� �󵵼� 1 ����
		}
	}
	fclose(fp);
	
	root = huffman_tree(freq, ALPHA_SIZE);
	char code[100];
	Huffman(root, -1, code);
	FILE* compressed = fopen("output.huf", "wb");
	if (compressed == NULL) {
		puts("���� ����");
		return;
	}
	fp = fopen("input.txt", "r"); // input.txt�� �б� ���� ����
	if (fp == NULL) {
		puts("����x");
		fclose(compressed);
		return;
	}
	while ((i = fgetc(fp)) != EOF) { // �� ���� �� �б�
		if ((0 <= (i - 65) <= 25) || (32 <= (i - 65) <= 57)) {
			Node* node = find_node(root, i - 65); // �о�� ���ڰ� �ش��Ѵٸ� �ش� ��带 Ʈ������ ã��
			fputs(node->code, compressed); // ã�� ��Ʈ�带 ���� ���Ͽ� ���
		}
	}
	fclose(fp);
	fclose(compressed);
	delete_tree(root);
}