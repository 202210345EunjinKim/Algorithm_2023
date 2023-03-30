#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	int arr[10];
	int max;
	int num;

	printf("입력하실 숫자의 갯수를 입력해주세요 (최대 10): ");
	scanf("%d", &num); // 숫자의 갯수를 num 변수에 저장

	for (int i = 0; i < num; i++) {
		printf("숫자: ");
		scanf("%d", &arr[i]); // num까지 숫자를 입력받아 arr[i]에 저장
	}
	max = arr[0]; // max를 첫번째 인덱스에 저장

	for (int i = 0; i < num; i++) {
		if (max < arr[i]) {
			max = arr[i]; // num까지 반복하며, 만약 arr[i]가 클 경우 max에 저장
		}
	}

	printf("최대 숫자는 %d입니다.", max); // 출력
}
