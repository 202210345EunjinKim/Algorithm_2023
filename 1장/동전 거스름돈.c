/*
* �й�: 202210345
* �ǽ���: ������
* �ǽ���: 2023.03.25
* ���α׷� ����: �Ž������� �Է¹޾� �ּ� ���� ���� ����ϴ� ���α׷�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ChangeCoin(int change);

int main() {
	int change;

	printf("�Ž����� �Է�: ");
	scanf("%d", &change); // �Ž������� change ������ �����Ѵ�.

	ChangeCoin(change); // �Լ� ȣ��
}
int ChangeCoin(int change) {
	int coin500, coin100, coin50, coin10;
	int num;

	num = change; // num ������ ó�� �Է¹��� �Ž������� �����Ѵ�.

	coin500 = change / 500; // 500���� ���� ���� �����ϰ�,
	change = change % 500; // change �������� �������� ����

	coin100 = change / 100;
	change = change % 100;

	coin50 = change / 50;
	change = change % 50;

	coin10 = change / 10;
	change = change % 10; // �ݺ�

	printf("%d���� �Ž����� ���� ������ 500�� %d��, 100�� %d��, 50�� %d��, 10�� %d�� �Դϴ�", num, coin500, coin100, coin50, coin10);
}