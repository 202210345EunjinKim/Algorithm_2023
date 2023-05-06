#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void mergeSort(int data[], int p, int r);
void merge(int data[], int p, int q, int r);
int main() {

    FILE* fp_in = fopen("data.txt", "r"); // 입력 파일 열기
    FILE* fp_out = fopen("result.txt", "w"); // 출력 파일 열기

    int i=0;
    int data[10] = { 0 };
    printf("정렬 전\n");
    while (1) {
        if (feof(fp_in))
            break;
        fscanf(fp_in, "%d ", &data[i]);
        printf("%d ", data[i]);
        i++;
    }
    fclose(fp_in);
    i = 0;
    mergeSort(data, 0, 9);
    printf("\n정렬 후\n");
    for (i = 0; i < 10;i++) {
        fprintf(fp_out, "%d ", data[i]);
        printf("%d ", data[i]);
    }
    fclose(fp_out);
    return 0;
}
void mergeSort(int *data, int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(data, p, q);
        mergeSort(data, q + 1, r);
        merge(data, p, q, r);
    }
}
void merge(int *data, int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    int tmp[10]; // 새 배열
    while (i <= q && j <= r) {
        if (data[i] <= data[j])
            tmp[k++] = data[i++];
        else tmp[k++] = data[j++];
    }
    while (i <= q) tmp[k++] = data[i++];
    while (j <= r) tmp[k++] = data[j++];
    for (int a = p; a <= r; a++) data[a] = tmp[a];
}
