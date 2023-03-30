#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	int arr[10];
	int max;
	int num;

	printf("입력하실 숫자의 갯수를 입력해주세요 (최대 10): ");
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		printf("숫자: ");
		scanf("%d", &arr[i]);
	}
	max = arr[0];

	for (int i = 0; i < 7; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	printf("최대 숫자는 %d입니다.", max);
}