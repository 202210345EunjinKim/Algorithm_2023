#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	int arr[10];
	int max;
	int num;

	printf("�Է��Ͻ� ������ ������ �Է����ּ��� (�ִ� 10): ");
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		printf("����: ");
		scanf("%d", &arr[i]);
	}
	max = arr[0];

	for (int i = 0; i < 7; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	printf("�ִ� ���ڴ� %d�Դϴ�.", max);
}