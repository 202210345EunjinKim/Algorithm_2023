/*
* �й�: 202210345
* �ǽ���: ������
* �ǽ���: 2023.03.31
* ���α׷� ����: ��¥ ���� ã��
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>


int main() {
	int fake, Coinnum = 0;
	int coin[100];
	int i, sum1, sum2, mid;
	int x = 0;
	int y;

	srand((unsigned int)time(NULL)); // ���� ����

	printf("������ ������ �Է����ּ���! ");
	scanf("%d", &Coinnum); // ������ ������ �Է¹޾�, Coinnum�� ����

	fake = rand() % Coinnum + 1; // ��¥������ �ִ� ���� �������� ����

	for (i = 0; i < Coinnum; i++) {
		if (i == fake) {
			coin[i] = 20; // ��¥ ������ �ִ� �ε������� ���Ը� 20���� ����
		}
		else {
			coin[i] = 30; // ������ �ε������� �� ���ſ� 30���� ����
		}
	}

	x = 0;
	y = Coinnum-1;

	while (x < y) { // 0���� Coinnum-1���� ����
		sum1 = 0;
		sum2 = 0; // �ʱ�ȭ ����

		mid = (x + y) / 2; // ���� ���̸� ������ ����

		for (i = x; i <= y; i++) {
			if (i <= mid) {
				sum1 += coin[i];
			}
			else
				sum2 += coin[i]; // ���Ը� ����
		}

		if (sum1 < sum2) {
			y = mid; // ����, sum2�� ���԰� �� ũ�ٸ� 0~Coinnum���� -> 0~mid������ �ٽ� ����
		}
		else
			x = mid + 1; // �ƴ� ��� mid+1 ~ Coinnum������ �ٽ� ����
	}
	printf("��¥ ������ %d��°�� �ֽ��ϴ�! \n", x + 1);
	
}