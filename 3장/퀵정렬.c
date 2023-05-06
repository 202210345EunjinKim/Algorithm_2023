/*
* 실습자: 김은진
* 프로그램 내용: 퀵정렬
*/
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
    FILE* fp_in = fopen("data.txt", "r"); // 입력 파일 열기
    FILE* fp_out = fopen("result.txt", "w"); // 출력 파일 열기
    if (fp_in == NULL || fp_out == NULL) { // 파일 열기 실패시 에러 메시지 출력하고 종료
        printf("File open error!\n");
        exit(1);
    }
    while(1) {
        if (feof(fp_in))
            break;
        fscanf(fp_in, "%d ", &a[i]); // data.txt에 있는 원소들을 a[i]에 저장
        i++;
    }
    fclose(fp_in);
    printf("정렬 전: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]); // 정렬 전 화면 출력
    }
    printf("\n");

    QuickSort(a, 0, 10 - 1); // 퀵정렬 함수 호출
    i = 0;
    printf("정렬 후: ");
    for (i = 0; i < 10;i++) {
        fprintf(fp_out, "%d ", a[i]); // 정렬된 원소들을 result.txt에 쓰기
        printf("%d ", a[i]); // 화면 출력
    }
    fclose(fp_out); // 파일 닫기!
}

void QuickSort(int* a, int left, int right) {

    FILE* fp_out = fopen("result.txt", "w"); // 출력 파일 열기

    if (left >= right) return; // 종료 조건

    int pivot = left; // 피벗을 왼쪽에 위치.
    int i = left + 1; // 왼쪽부터 시작하는 인덱스
    int j = right; // 오른쪽부터 시작하는 인덱스

    while (i <= j) { // i와 j가 교차할 때까지 반복
        while (i <= right && a[i] <= a[pivot]) i++; // 피벗보다 큰 원소를 찾을 때까지 오른쪽으로 이동
        while (j > left && a[j] >= a[pivot]) j--; // 피벗보다 작은 원소를 찾을 때까지 왼쪽으로 이동

        if (i > j) swap(a, pivot, j); // i와 j가 교차하면 피벗과 j를 교환
        else swap(a, i, j); // i와 j가 교차하지 않으면 i와 j를 교환
    }


    QuickSort(a, left, j - 1); // 왼쪽 부분 배열에 대해 재귀 호출
    QuickSort(a, j + 1, right); // 오른쪽 부분 배열에 대해 재귀 호출
}