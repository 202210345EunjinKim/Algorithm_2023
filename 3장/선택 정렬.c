/*
* 실습자: 김은진
* 프로그램 내용: 선택 정렬
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Selection(int *a, int left, int right, int k);
int main() {
    int i = 0, k;
    int a[10] = { 0 };
    int value;

    FILE* fp_in = fopen("data.txt", "r"); // 입력 파일 열기
    FILE* fp_out = fopen("result.txt", "w"); // 출력 파일 열기

    if (fp_in == NULL || fp_out == NULL) { // 파일 열기 실패시 에러 메시지 출력하고 종료
        printf("File open error!\n");
        exit(1);
    }
    while (1) {
        if (feof(fp_in))
            break;
        fscanf(fp_in, "%d ", &a[i]); // data.txt에 있는 원소들을 a[i]에 저장
        i++;
    }
    fclose(fp_in);
    printf("몇 번째로 작은 숫자가 궁금하십니까? (숫자만 입력) ");
    scanf("%d", &k);

    value = Selection(a, 0, 10 - 1, k-1); // 0부터 시작이므로 k-1


    printf("\n%d번째로 작은 숫자는 %d입니다.", k, value);

    for (i = 0; i < 10; i++) {
        fprintf(fp_out, "%d ", a[i]); // 정렬된 원소들을 result.txt에 쓰기
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

    int pivot = left; // 피벗을 왼쪽에 위치.
    int i = left + 1; // 왼쪽부터 시작하는 인덱스
    int j = right; // 오른쪽부터 시작하는 인덱스

    while (i <= j) { // i와 j가 교차할 때까지 반복
        while (i <= right && a[i] <= a[pivot]) i++; // 피벗보다 큰 원소를 찾을 때까지 오른쪽으로 이동
        while (j > left && a[j] >= a[pivot]) j--; // 피벗보다 작은 원소를 찾을 때까지 왼쪽으로 이동

        if (i > j) swap(a, pivot, j); // i와 j가 교차하면 피벗과 j를 교환
        else swap(a, i, j); // i와 j가 교차하지 않으면 i와 j를 교환
    }

    if (j == i && j == k) {
        return a[j]; 
    }

    if (j == k) {
        return a[j]; // 피봇과 같은 위치라면 a[j] 리턴
    }
    else if (j > k) {
        value = Selection(a, left, j - 1, k); // 피봇보다 Small Group에 있다면 j-1로 다시 호출
    }
    else {
        value = Selection(a, j + 1, right, k); // 피봇보다 Large Group에 있다면 j+1로 다시 호출
    }
    return value; // 결과값 리턴
}