#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int searchnumber(int num);

int main() {
    int num;
    
    printf("ã������ ���� �Է����ּ���, ");
    scanf("%d", &num);

    searchnumber(num);

}

int searchnumber(int num)
{
    int array[] = { 13, 24, 55, 2, 95, 10, 67, 20 };

    for (int i = 0; i < 10; i++) { // �迭 ��ȸ, �˻�
        if (array[i] == num) {
            printf("%d�� %d��°�� �ֽ��ϴ�.",num, i + 1); // 3��° ��ġ ���
        }
    }
}
