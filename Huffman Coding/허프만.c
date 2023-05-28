#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 100 // 최대 원소 개수
#define ALPHA_SIZE 58 // 알파벳 개수

typedef struct Node {
	int weight; // 빈도수
	int alpha; // 알파벳
	char code[100]; // 압축 코드
	int depth; // 트리의 깊이
	struct Node* left; // 왼쪽 자식 노드
	struct Node* right; // 오른쪽 자식 노드
}Node; // 허프만 트리 노드 구조체

typedef struct {
	Node* ptree; // 트리 포인터
	int key; // 빈도수
}Element; // 우선순위 큐의 원소

typedef struct {
	Element heap[MAX_ELEMENT]; // 배열
	int heap_size; // 힙의 크기
}HeapType; // 우선순위 큐를 사용하기 위한 힙 구조체

void init(HeapType* h) {
	h->heap_size = 0;
} // 힙 초기화 함수
void insert_heap(HeapType* h, Element item) {
	int i;
	i = ++(h->heap_size); // 삽입할 요소의 위치
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	} // i에 삽입하려는 요소가 부모 노드보다 작을 경우, 부모 노드를 현재 위치로 이동하고
	  // i를 부모 노드의 위치로 갱신
	h->heap[i] = item; // 해당 위치에 item를 삽입
}
Element delete_heap(HeapType* h) {
	int parent, child;
	Element item, temp;

	item = h->heap[1]; // 힙의 루트 요소 삽입
	temp = h->heap[(h->heap_size)--]; // 힙의 마지막 요소 삽입한 뒤 힙의 크기 감소
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key) {
			child++; // 오른쪽 자식보다 왼쪽 자식이 더 클 경우 child 증가
		}
		if (temp.key <= h->heap[child].key) break; // temp.key값이 선택된 자식의 키 값보다 작거나 같을 경우 종료
		h->heap[parent] = h->heap[child]; // 삭제된 요소 제거
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
} // 최소 힙에서 최소 키 값을 가진 요소를 삭제하고 삭제한 요소를 반환
Node* make_tree(Node* left, Node* right) {
	Node* node = (Node*)malloc(sizeof(Node)); // 동적 메모리 할당
	if (node == NULL) {
		fprintf(stderr, "에러\n");
		exit(1);
	} // 실패할 경우 에러 메시지 출력, 프로그램 종료
	node->left = left; // 왼쪽 자식 노드 연결
	node->right = right; // 오른쪽 자식 노드 연결
	return node; // 새로 생성된 노드를 반환
}
void delete_tree(Node* root) {
	if (root == NULL) return; // 트리가 비어있는 경우 종료
	delete_tree(root->left); // 왼쪽 서브트리를 삭제
	delete_tree(root->right); // 오른쪽 서브트리를 삭제
	free(root); // 현재 노드 삭제
}
void Huffman(Node* r, int n, char* code) {
	if (r) {
		n++; // n을 1 증가시킴
		code[n] = '1'; // n번째 위치에 1을 저장
		Huffman(r->right, n, code); // 오른쪽 자식을 루트로 하는 서브 트리에 대해 호출
		code[n] = '0'; // n번째 위치에 0을 저장
		Huffman(r->left, n, code); // 왼쪽 자식을 루트로 하는 서브 트리에 대해 호출
		code[n] = '\0'; // n번째 위치에 널 문자 저장
		if (r->left == NULL && r->right == NULL) {
			strcpy(r->code, code); // 현재 경로의 코드를 r의 코드로 복사
			r->depth = n; // r의 깊이를 현재 깊이로 설정
		}
	}
}
void sub_order(Node* r, int i) {
	if (r) {
		sub_order(r->right, i); // 오른쪽 자식을 루트로 하는 서브트리에 대해 함수 호출
		sub_order(r->left, i); // 왼쪽 자식을 루트로 하는 서브트리에 대해 함수 호출
		if ((r->left == NULL || r->right == NULL) && r->depth == i) {
			printf("빈도수=%2d 문지=%c 코드=%s\n", r->weight, r->alpha, r->code);
		} // 왼쪽 자식 노드 또는 오른쪽 자식 노드가 비어있고, r의 깊이가 i와 같은 경우
		  // 빈도수, 문자, 코드를 출력
	}
}
void level_order(Node* r) {
	int i;
	for (i = 0; i < 10; i++) {
		sub_order(r, i); // r을 루트로 하는 트리에서 깊이 i에 해당하는 노드들에 대해 호출
	}
} // 특정 깊이에 해당하는 노드들을 출력하는 함수
int huffman_tree(int freq[], int n) {
	int i, j = 0;
	Node* node, * x;
	HeapType heap;
	Element e, e1, e2;
	char* code = (char*)malloc(sizeof(char));

	init(&heap); // 힙 초기화
	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL); // 왼쪽 자식과 오른쪽 자식이 비어있는 노드를 생성
		e.key = node->weight = freq[i]; // 생성한 노드의 가중치를 빈도수로 설정
		node->alpha = (i + 65); // 알파벳 값 설정
		e.ptree = node; 
		insert_heap(&heap, e); // 생성한 e를 힙에 삽입
		j++;
	}
	for (i = 1; i < j; i++) {
		e1 = delete_heap(&heap); // 가장 작은 원소를 삭제하고 반환
		e2 = delete_heap(&heap); // 다음으로 작은 원소를 삭제하고 반환
		x = make_tree(e1.ptree, e2.ptree); // 두 개의 노드를 자식으로 하는 새로운 노드 생성
		e.key = x->weight = e1.key + e2.key; // 생성한 노드의 가중치를 두 노드의 가중치의 합으로 설정
		e.ptree = x;
		insert_heap(&heap, e);
	}
	e = delete_heap(&heap); // 마지막으로 남은 원소를 삭제하고 반환
	Huffman(e.ptree, -1, code); // huffman 함수를 호출하여 각 노드에 코드와 깊이를 할당
	level_order(e.ptree); // 레벨 순서로 순회하며 특정 깊이에 해당하는 노드 출력
	delete_tree(e.ptree); // 트리 삭제
}
Node* find_node(Node* root, int alpha) {
	if (root == NULL)
		return NULL;

	if (root->alpha == alpha)
		return root; // 알파벳 값과 찾는 값이 일치하면 해당 노드 반환

	Node* left = find_node(root->left, alpha);
	if (left != NULL)
		return left; // 왼쪽 서브트리에서 발견하면 해당 노드 반환

	Node* right = find_node(root->right, alpha);
	if (right != NULL)
		return right; // 오른쪽 서브트리에서 발견하면 해당 노드 반환

	return NULL; // 찾지 못하면 NULL 반환
}
void main() {
	int i = 0;
	int freq[ALPHA_SIZE] = { 0 };
	Node* root;
	FILE* fp = fopen("input.txt", "r"); // input.txt 읽어들이기
	if (fp == NULL) { puts("파일x"); } // 실패하면 에러 메시지 출력
	while (i != EOF) {
		i = fgetc(fp); // 한 글자씩 읽기
		if ((0 <= (i - 65) <= 25) || (32 <= (i - 65) <= 57)) {
			freq[i - 65] += 1; // 읽어온 글자가 알파벳 대문자 또는 숫자에 해당한다면
							   //해당 빈도수 1 증가
		}
	}
	fclose(fp);
	
	root = huffman_tree(freq, ALPHA_SIZE);
	char code[100];
	Huffman(root, -1, code);
	FILE* compressed = fopen("output.huf", "wb");
	if (compressed == NULL) {
		puts("생성 실패");
		return;
	}
	fp = fopen("input.txt", "r"); // input.txt를 읽기 모드로 열고
	if (fp == NULL) {
		puts("파일x");
		fclose(compressed);
		return;
	}
	while ((i = fgetc(fp)) != EOF) { // 한 글자 씩 읽기
		if ((0 <= (i - 65) <= 25) || (32 <= (i - 65) <= 57)) {
			Node* node = find_node(root, i - 65); // 읽어온 글자가 해당한다면 해당 노드를 트리에서 찾기
			fputs(node->code, compressed); // 찾은 노트드를 압축 파일에 출력
		}
	}
	fclose(fp);
	fclose(compressed);
	delete_tree(root);
}