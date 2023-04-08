#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Euclid(int a, int b);
int Euclid2(int a, int b);

int main() {
	time_t start, end;
	double result; // �ð� ���� ���� ����
	int num1, num2;
	int test1, test2;

	printf("�� ���� �Է����ּ���. ");
	scanf("%d %d", &num1, &num2);

	printf("�ִ������� %d�Դϴ�. (�ݺ���)\n", Euclid(num1, num2));
	printf("�ִ������� %d�Դϴ�. (�����)\n\n", Euclid2(num1, num2)); // �Է¹��� �� ���� ���� �����, �ݺ��� �Լ��� ��� ���

	start = time(NULL); // ���� �ð� ���� ����

	srand((unsigned)time(NULL));

	test1 = rand() % (5000-1000+1)+1000;			
	test2 = rand() % (5000 - 1000 + 1) + 1000;			// ���� ���� ������ 1000~5000���� ����

	printf("test 1= %d\n", test1);
	printf("test 2= %d\n", test2); // �� ������ ��� 
	printf("�ִ������� %d�Դϴ�. (�ݺ���)\n", Euclid(test1, test2));
	printf("�ִ������� %d�Դϴ�. (�����)\n\n", Euclid2(test1, test2));

	end = time(NULL); // ���� �ð� ���� ����
	result = (double)(end - start); // �ð� ��� ����

	printf("�� �ڵ��� ���� ����� %f���Դϴ�.", result); // ���� �ð� ���
	
}