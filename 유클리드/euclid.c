#include <stdio.h>

int Euclid(int a, int b) { 
	int num;

	while (b != 0) {
		num = a;
		a = b;
		b = num % b;
	} return a;
} // �ݺ���
int Euclid2(int a, int b) {
	if (b == 0)
		return a;

	return Euclid2(b, a % b);
} // �����