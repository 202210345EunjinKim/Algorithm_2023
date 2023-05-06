/*
* �ǽ���: ������
* ���α׷� ����: ���� ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Selection(int *a, int left, int right, int k);
int main() {
    int i = 0, k;
    int a[10] = { 0 };
    int value;

    FILE* fp_in = fopen("data.txt", "r"); // �Է� ���� ����
    FILE* fp_out = fopen("result.txt", "w"); // ��� ���� ����

    if (fp_in == NULL || fp_out == NULL) { // ���� ���� ���н� ���� �޽��� ����ϰ� ����
        printf("File open error!\n");
        exit(1);
    }
    while (1) {
        if (feof(fp_in))
            break;
        fscanf(fp_in, "%d ", &a[i]); // data.txt�� �ִ� ���ҵ��� a[i]�� ����
        i++;
    }
    fclose(fp_in);
    printf("�� ��°�� ���� ���ڰ� �ñ��Ͻʴϱ�? (���ڸ� �Է�) ");
    scanf("%d", &k);

    value = Selection(a, 0, 10 - 1, k-1); // 0���� �����̹Ƿ� k-1


    printf("\n%d��°�� ���� ���ڴ� %d�Դϴ�.", k, value);

    for (i = 0; i < 10; i++) {
        fprintf(fp_out, "%d ", a[i]); // ���ĵ� ���ҵ��� result.txt�� ����
    }
    fclose(fp_out);
}
void swap(int A[], int i, int j) {
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
int Selection(int *a, int left, int right, int k) {
    int value;

    if (left >= right) {
        return a[k];
    }

    int pivot = left; // �ǹ��� ���ʿ� ��ġ.
    int i = left + 1; // ���ʺ��� �����ϴ� �ε���
    int j = right; // �����ʺ��� �����ϴ� �ε���

    while (i <= j) { // i�� j�� ������ ������ �ݺ�
        while (i <= right && a[i] <= a[pivot]) i++; // �ǹ����� ū ���Ҹ� ã�� ������ ���������� �̵�
        while (j > left && a[j] >= a[pivot]) j--; // �ǹ����� ���� ���Ҹ� ã�� ������ �������� �̵�

        if (i > j) swap(a, pivot, j); // i�� j�� �����ϸ� �ǹ��� j�� ��ȯ
        else swap(a, i, j); // i�� j�� �������� ������ i�� j�� ��ȯ
    }

    if (j == i && j == k) {
        return a[j]; 
    }

    if (j == k) {
        return a[j]; // �Ǻ��� ���� ��ġ��� a[j] ����
    }
    else if (j > k) {
        value = Selection(a, left, j - 1, k); // �Ǻ����� Small Group�� �ִٸ� j-1�� �ٽ� ȣ��
    }
    else {
        value = Selection(a, j + 1, right, k); // �Ǻ����� Large Group�� �ִٸ� j+1�� �ٽ� ȣ��
    }
    return value; // ����� ����
}