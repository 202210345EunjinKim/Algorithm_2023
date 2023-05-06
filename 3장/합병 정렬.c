/*
* �ǽ���: ������
* ���α׷� ����: �պ� ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void mergeSort(int data[], int p, int r);
void merge(int data[], int p, int q, int r);
int main() {

    FILE* fp_in = fopen("data.txt", "r"); // �Է� ���� ����
    FILE* fp_out = fopen("result.txt", "w"); // ��� ���� ����

    int i=0;
    int data[10] = { 0 }; // �ʱ�ȭ
    printf("���� ��\n");
    while (1) {
        if (feof(fp_in))
            break;
        fscanf(fp_in, "%d ", &data[i]); // data �迭�� ���Ͽ� �ִ� ���ҵ��� ���ʴ�� ����
        printf("%d ", data[i]); // ȭ�鿡 ���
        i++;
    }
    fclose(fp_in); // ���� �ݱ�
    i = 0; // i �ʱ�ȭ
    mergeSort(data, 0, 9); // MergeSort ȣ��
    printf("\n���� ��\n");
    for (i = 0; i < 10;i++) {
        fprintf(fp_out, "%d ", data[i]); // result.txt�� ���ĵ� ���ҵ� ����
        printf("%d ", data[i]); // ȭ�鿡 ���
    }
    fclose(fp_out); // ���� �ݱ�
    return 0;
}
void mergeSort(int *data, int p, int r) {
    int q;
    if (p < r) { // p�� r���� ������
        q = (p + r) / 2; // ������ ������
        mergeSort(data, p, q); // Left
        mergeSort(data, q + 1, r); // Right
        merge(data, p, q, r);
    }
}
void merge(int *data, int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    int tmp[10]; // �� �迭
    while (i <= q && j <= r) {
        if (data[i] <= data[j]) // ���� i�� j���� �۰�, j�� r���� �۴ٸ�
            tmp[k++] = data[i++]; // �� �迭 ���ۿ� i++ �ֱ�
        else tmp[k++] = data[j++]; // i�� j���� ũ�ٸ� �� �迭�� j++ �ֱ� , ���� �ݺ�!
    }
    while (i <= q) tmp[k++] = data[i++]; // i�� q���� �۰ų� ���ٸ� i++
    while (j <= r) tmp[k++] = data[j++]; // j�� r���� �۰ų� ���ٸ� j++
    for (int a = p; a <= r; a++) data[a] = tmp[a]; // �׸��� �ٽ� data �迭�� ���ĵ� �� �迭 �ֱ�
}
