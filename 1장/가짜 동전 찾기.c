/*
* 학번: 202210345
* 실습자: 김은진
* 실습일: 2023.03.31
* 프로그램 내용: 가짜 동전 찾기
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

	srand((unsigned int)time(NULL)); // 난수 생성

	printf("동전의 갯수를 입력해주세요! ");
	scanf("%d", &Coinnum); // 동전의 갯수를 입력받아, Coinnum에 저장

	fake = rand() % Coinnum + 1; // 가짜동전이 있는 곳은 랜덤으로 지정

	for (i = 0; i < Coinnum; i++) {
		if (i == fake) {
			coin[i] = 20; // 가짜 동전이 있는 인덱스에는 무게를 20으로 설정
		}
		else {
			coin[i] = 30; // 나머지 인덱스에는 더 무거운 30으로 설정
		}
	}

	x = 0;
	y = Coinnum-1;

	while (x < y) { // 0부터 Coinnum-1까지 실행
		sum1 = 0;
		sum2 = 0; // 초기화 해줌

		mid = (x + y) / 2; // 동전 더미를 반으로 나눔

		for (i = x; i <= y; i++) {
			if (i <= mid) {
				sum1 += coin[i];
			}
			else
				sum2 += coin[i]; // 무게를 더함
		}

		if (sum1 < sum2) {
			y = mid; // 만약, sum2가 무게가 더 크다면 0~Coinnum까지 -> 0~mid까지로 다시 설정
		}
		else
			x = mid + 1; // 아닐 경우 mid+1 ~ Coinnum까지로 다시 설정
	}
	printf("가짜 동전은 %d번째에 있습니다! \n", x + 1);
	
}