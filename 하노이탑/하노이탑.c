/*
* 학번: 202210345
* 실습자: 김은진
* 실습일: 2023.04.18
* 프로그램 내용: 하노이탑
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to);

int main() {
	hanoi_tower(4, 'A', 'B', 'C');
}
void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1)
		printf("원판 1을 %c에서 %c으로 옮긴다.\n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}