#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void QuickSort(int* a, int left, int right);
void swap(int A[], int i, int j) {
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int main() {
    int a[10] = { 0 };
    int i = 0;
    FILE* fp_in = fopen("data.txt", "r"); // �Է� ���� ����
    FILE* fp_out = fopen("result.txt", "w"); // ��� ���� ����
    if (fp_in == NULL || fp_out == NULL) { // ���� ���� ���н� ���� �޽��� ����ϰ� ����
        printf("File open error!\n");
        exit(1);
    }
    while(1) {
        if (feof(fp_in))
            break;
        fscanf(fp_in, "%d ", &a[i]);
        i++;
    }
    fclose(fp_in);
    printf("���� ��: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    QuickSort(a, 0, 10 - 1);
    i = 0;
    printf("���� ��: ");
    for (i = 0; i < 10;i++) {
        fprintf(fp_out, "%d ", a[i]);
        printf("%d ", a[i]);
    }
    fclose(fp_out);
}

void QuickSort(int* a, int left, int right) {

    FILE* fp_out = fopen("result.txt", "w"); // ��� ���� ����

    if (left >= right) return; // ���� ����

    int pivot = left; // �ǹ��� ���ʿ� ��ġ.
    int i = left + 1; // ���ʺ��� �����ϴ� �ε���
    int j = right; // �����ʺ��� �����ϴ� �ε���

    while (i <= j) { // i�� j�� ������ ������ �ݺ�
        while (i <= right && a[i] <= a[pivot]) i++; // �ǹ����� ū ���Ҹ� ã�� ������ ���������� �̵�
        while (j > left && a[j] >= a[pivot]) j--; // �ǹ����� ���� ���Ҹ� ã�� ������ �������� �̵�

        if (i > j) swap(a, pivot, j); // i�� j�� �����ϸ� �ǹ��� j�� ��ȯ
        else swap(a, i, j); // i�� j�� �������� ������ i�� j�� ��ȯ
    }


    QuickSort(a, left, j - 1); // ���� �κ� �迭�� ���� ��� ȣ��
    QuickSort(a, j + 1, right); // ������ �κ� �迭�� ���� ��� ȣ��
}