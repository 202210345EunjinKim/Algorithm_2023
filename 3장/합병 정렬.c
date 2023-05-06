/*
* 실습자: 김은진
* 프로그램 내용: 합벙 정렬
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void mergeSort(int data[], int p, int r);
void merge(int data[], int p, int q, int r);
int main() {

    FILE* fp_in = fopen("data.txt", "r"); // 입력 파일 열기
    FILE* fp_out = fopen("result.txt", "w"); // 출력 파일 열기

    int i=0;
    int data[10] = { 0 }; // 초기화
    printf("정렬 전\n");
    while (1) {
        if (feof(fp_in))
            break;
        fscanf(fp_in, "%d ", &data[i]); // data 배열에 파일에 있는 원소들을 차례대로 대입
        printf("%d ", data[i]); // 화면에 출력
        i++;
    }
    fclose(fp_in); // 파일 닫기
    i = 0; // i 초기화
    mergeSort(data, 0, 9); // MergeSort 호출
    printf("\n정렬 후\n");
    for (i = 0; i < 10;i++) {
        fprintf(fp_out, "%d ", data[i]); // result.txt에 정렬된 원소들 쓰기
        printf("%d ", data[i]); // 화면에 출력
    }
    fclose(fp_out); // 파일 닫기
    return 0;
}
void mergeSort(int *data, int p, int r) {
    int q;
    if (p < r) { // p가 r보다 작으면
        q = (p + r) / 2; // 반으로 나누고
        mergeSort(data, p, q); // Left
        mergeSort(data, q + 1, r); // Right
        merge(data, p, q, r);
    }
}
void merge(int *data, int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    int tmp[10]; // 새 배열
    while (i <= q && j <= r) {
        if (data[i] <= data[j]) // 만약 i가 j보다 작고, j가 r보다 작다면
            tmp[k++] = data[i++]; // 새 배열 시작에 i++ 넣기
        else tmp[k++] = data[j++]; // i가 j보다 크다면 새 배열에 j++ 넣기 , 과정 반복!
    }
    while (i <= q) tmp[k++] = data[i++]; // i가 q보다 작거나 같다면 i++
    while (j <= r) tmp[k++] = data[j++]; // j가 r보다 작거나 같다면 j++
    for (int a = p; a <= r; a++) data[a] = tmp[a]; // 그리고 다시 data 배열에 정렬된 새 배열 넣기
}
