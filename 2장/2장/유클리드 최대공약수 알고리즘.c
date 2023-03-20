/*
* 학번: 202210345
* 이름: 김은진
* 실습일: 2023.03.20
* 프로그램 내용: 유클리드 최대공약수 알고리즘 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Euclid(int a, int b) {
	int num;

	while (b != 0) {
		num = a;	// 초기 a를 num에 저장
		a = b;		// a 자리에 b를 넣고
		b = num % b; // b 자리에 num(=a)와 b를 나눈 나머지 값을 넣는다.
	} return a;		 // b가 0이 되기 전까지 반복하고, 0이 되면 최대공약수 a를 리턴한다.
}

int main() {
	int num1, num2;

	printf("두 수의 최대공약수를 구해보겠습니다. 두 수를 입력 해 주세요. ");
	scanf("%d %d", &num1, &num2);

	printf("두 수의 최대공약수는 %d입니다.", Euclid(num1, num2)); // Euclid 함수 이용
}