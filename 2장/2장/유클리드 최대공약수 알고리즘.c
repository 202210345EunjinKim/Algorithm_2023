/*
* �й�: 202210345
* �̸�: ������
* �ǽ���: 2023.03.20
* ���α׷� ����: ��Ŭ���� �ִ����� �˰��� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Euclid(int a, int b) {
	int num;

	while (b != 0) {
		num = a;	// �ʱ� a�� num�� ����
		a = b;		// a �ڸ��� b�� �ְ�
		b = num % b; // b �ڸ��� num(=a)�� b�� ���� ������ ���� �ִ´�.
	} return a;		 // b�� 0�� �Ǳ� ������ �ݺ��ϰ�, 0�� �Ǹ� �ִ����� a�� �����Ѵ�.
}

int main() {
	int num1, num2;

	printf("�� ���� �ִ������� ���غ��ڽ��ϴ�. �� ���� �Է� �� �ּ���. ");
	scanf("%d %d", &num1, &num2);

	printf("�� ���� �ִ������� %d�Դϴ�.", Euclid(num1, num2)); // Euclid �Լ� �̿�
}