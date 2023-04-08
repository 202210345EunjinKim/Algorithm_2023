#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Euclid(int a, int b);
int Euclid2(int a, int b);

int main() {
	time_t start, end;
	double result; // 시간 측정 변수 선언
	int num1, num2;
	int test1, test2;

	printf("두 수를 입력해주세요. ");
	scanf("%d %d", &num1, &num2);

	printf("최대공약수는 %d입니다. (반복적)\n", Euclid(num1, num2));
	printf("최대공약수는 %d입니다. (재귀적)\n\n", Euclid2(num1, num2)); // 입력받은 두 수를 각각 재귀적, 반복적 함수로 결과 출력

	start = time(NULL); // 수행 시간 측정 시작

	srand((unsigned)time(NULL));

	test1 = rand() % (5000-1000+1)+1000;			
	test2 = rand() % (5000 - 1000 + 1) + 1000;			// 난수 생성 범위를 1000~5000으로 설정

	printf("test 1= %d\n", test1);
	printf("test 2= %d\n", test2); // 두 난수를 출력 
	printf("최대공약수는 %d입니다. (반복적)\n", Euclid(test1, test2));
	printf("최대공약수는 %d입니다. (재귀적)\n\n", Euclid2(test1, test2));

	end = time(NULL); // 수행 시간 측정 종료
	result = (double)(end - start); // 시간 결과 저장

	printf("이 코드의 수행 결과는 %f초입니다.", result); // 수행 시간 출력
	
}