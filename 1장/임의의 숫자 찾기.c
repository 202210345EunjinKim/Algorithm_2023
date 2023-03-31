#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int searchnumber(int num);

int main() {
    int num;
    
    printf("찾으려는 값을 입력해주세요, ");
    scanf("%d", &num);

    searchnumber(num);

}

int searchnumber(int num)
{
    int array[] = { 13, 24, 55, 2, 95, 10, 67, 20 };

    for (int i = 0; i < 10; i++) { // 배열 순회, 검색
        if (array[i] == num) {
            printf("%d는 %d번째에 있습니다.",num, i + 1); // 3번째 위치 출력
        }
    }
}
