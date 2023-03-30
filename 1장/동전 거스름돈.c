/*
* 학번: 202210345
* 실습자: 김은진
* 실습일: 2023.03.25
* 프로그램 내용: 거스름돈을 입력받아 최소 동전 개수 출력하는 프로그램
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ChangeCoin(int change);

int main() {
	int change;

	printf("거스름돈 입력: ");
	scanf("%d", &change); // 거스름돈을 change 변수에 저장한다.

	ChangeCoin(change); // 함수 호출
}
int ChangeCoin(int change) {
	int coin500, coin100, coin50, coin10;
	int num;

	num = change; // num 변수에 처음 입력받은 거스름돈을 저장한다.

	coin500 = change / 500; // 500으로 나눈 몫을 저장하고,
	change = change % 500; // change 변수에는 나머지를 저장

	coin100 = change / 100;
	change = change % 100;

	coin50 = change / 50;
	change = change % 50;

	coin10 = change / 10;
	change = change % 10; // 반복

	printf("%d원의 거스름돈 동전 갯수는 500원 %d개, 100원 %d개, 50원 %d개, 10원 %d개 입니다", num, coin500, coin100, coin50, coin10);
}