#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
typedef struct {
	char name[30];
	char ID[15];
	char PW[20];
	char birth[20];
	char phone[50];
} USER; // 회원 정보

typedef struct {
	char title[100];
	char writer[20];
	char company[30];
	char genre[20];
	char price[15];
	char sales[10];
} BOOK; // 도서 정보

typedef struct {
	char buy_date[30];
	char ID[15];
	char title[100];
	char price[15];
	char sales[10];
} BUY; // 구매 정보

typedef struct {
	char title[100];
	char company[30];
	char stock[10];
}INVENTORY; // 재고 정보


HANDLE COUT = 0;    // 콘솔 출력 장치
HANDLE CIN = 0;        // 콘솔 입력 장치
void gotoxy(int x, int y); // 좌표
int be_input();
int get_input(WORD* vkey, COORD* pos); // 마우스 클릭 함수
int total = 0;

void map(void);
void map2(void);
void map3(void);
void map4(void);
void mainscreen(void); // 메인화면
void login(void); // 로그인
void find_ID_PW(); // ID, PW 찾기
void new_login(); // 회원가입
void usermenu(char id[]); // 회원 메뉴
void search_book(char id[]); // 회원 - 도서 검색
void user_buy_book(char title[], char id[]); // 회원 - 도서 검색 - 구매
void buy_list(char id[]); // 회원 - 구매 목록
void change_user(char id[]); // 회원 - 정보 수정
void change_PW(char id[]); // 회원 - 정보 수정 - 비밀번호
void change_phone(char id[]); // 회원 - 정보 수정 - 전화번호
void adminmenu(char id[]); // 관리자 메뉴
void setting_book(char id[]); // 관리자 - 도서 관리
void new_book(char id[]); // 관리자 - 도서 등록
void search_book2(char id[]); // 관리자 - 도서 수정/삭제 전 제목 입력 받기
void search_book3(char id[]); // 관리자 - 재고 관리 전 도서 입력 받기
void changeordeletebook(char id[], char title[]); // 관리자 - 도서 수정? 삭제? 여부
void change_book(char id[], char title[]); // 관리자 - 도서 수정 메뉴
void change_book_title(char id[], char title[]); // 도서 수정 - 제목
void change_book_writer(char id[], char title[]);  // 도서 수정 - 저자
void change_book_company(char id[], char title[]);  // 도서 수정 - 출판사
void change_book_genre(char id[], char title[]);  // 도서 수정 - 장르
void change_book_price(char id[], char title[]);  // 도서 수정 - 가격
void delete_book(char id[], char title[]); // 관리자 - 도서 삭제
void look_book(char id[]); // 관리자 - 도서 조회
void setting_stock(char id[],char title[]); // 관리자 - 재고 관리
void look_stock(char id[], char title[]); // 관리자 - 재고 조회
void change_stock(char id[], char title[]); // 관리자 - 재고 수정
void setting_total(char id[]); // 관리자 - 매출 관리
void totalsales(char id[]); // 관리자 - 총 매출 확인
void popularbook(char id[]); // 관리자 - 인기 도서 확인
void setting_user(char id[]); // 관리자 - 회원 관리
void new_user(char id[]); // 관리자 - 회원 등록
void search_user(char id[]); // 괸리자 - 회원 조회 전 회원 검색
void look_user(char id[], char info[]); // 관리자 - 회원 조회
void setting_user2(char id[],char info[]); // 관리자 - 회원 수정
void delete_user(char id[], char info[]); // 관리자 - 회원 삭제
void processAllUsers(char id[]);
void updateSales(BOOK books[], int* totalBooks, const char* title,char id[]);
void selectionSort(BOOK books[], int totalBooks,char id[]);
void printRankedBooks(BOOK books[], int totalBooks,char id[]);

void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
int be_input()
{
	INPUT_RECORD input_record;
	DWORD input_count;

	PeekConsoleInput(CIN, &input_record, 1, &input_count);
	return input_count;
}
int get_input(WORD* vkey, COORD* pos)
{
	INPUT_RECORD input_record;
	DWORD input_count;

	ReadConsoleInput(CIN, &input_record, 1, &input_count);
	switch (input_record.EventType) {
	case MOUSE_EVENT:
		if (pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
			CONSOLE_SCREEN_BUFFER_INFO csbi;

			GetConsoleScreenBufferInfo(COUT, &csbi);

			*pos = input_record.Event.MouseEvent.dwMousePosition;
			pos->X -= csbi.srWindow.Left;
			pos->Y -= csbi.srWindow.Top;

			return MOUSE_EVENT;
		}
		break;

	}

	//    FlushConsoleInputBuffer(CIN);
	return 0;
} 
void map() {
	system("cls");
	printf("┌───────────────────────────────────────────────────────────────────────┐\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("│									│\n");
	printf("└───────────────────────────────────────────────────────────────────────┘\n");
}
void map2() {
	system("cls");
	printf("┌─────────────────────────────────────────────────┐\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("│						  │\n");
	printf("└─────────────────────────────────────────────────┘\n");
}
void map3() {
	system("cls");
	printf("┌───────────────────────────────────────────────────────────────────────────────┐\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("│										│\n");
	printf("└───────────────────────────────────────────────────────────────────────────────┘\n");
}
void map4() {
	system("cls");
	printf("┌─────────────────────────────────────────────────────────────────────────────────┐\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("│										  │\n");
	printf("└─────────────────────────────────────────────────────────────────────────────────┘\n");
}
/*void user_read() {
	FILE* fp = fopen("user.txt", "r");
	if (fp == NULL)
		return 0;
	while (1) {
		fscanf(fp, "%s  ", test[count].name);
		fscanf(fp, "%s  ", test[count].ID);
		fscanf(fp, "%s  ", test[count].PW);
		fscanf(fp, "%s  ", test[count].birth);
		fscanf(fp, "%s  ", test[count].phone);
		if (feof(fp) != 0) //파일의 끝을 만나면
			break;
		count++;
	}
	fclose(fp);
}*/
/*void user_read() {
	USER test[SIZE];
	FILE* fp = fopen("user.txt", "r");
	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[count].name, test[count].ID, test[count].PW, test[count].birth, test[count].phone);
		//removeRow(test[i].ID);
		if (strchr(test[count].name, '\n')) {
			for (int k = 1; k < strlen(test[count].name) + 1; k++) {
				test[count].name[k - 1] = test[count].name[k];
			}
		}
		count++;
	}
	fclose(fp);
}*/
// 메인 화면
void mainscreen() {
	FILE* fp;
	BOOK test[100];
	DWORD mode;
	WORD key;
	COORD pos;
	int i = 0, y = 7, event, x = 0, yy = 0, index = 0;
	char search[50];

	fp = fopen("book.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].title, test[i].writer, test[i].company, test[i].genre, test[i].price, test[i].sales);
		//removeRow(test[i].code);

		if (strchr(test[i].title, '\n')) {
			for (int k = 1; k < strlen(test[i].title) + 1; k++) {
				test[i].title[k - 1] = test[i].title[k];
			}
		}
		i++;
	}
	fclose(fp);
	map();
	gotoxy(3, 1);
	printf("종료");
	gotoxy(65, 1);
	printf("로그인");
	gotoxy(33, 2);
	printf("서원 서점");
	gotoxy(13, 3);
	printf("────────────────────────────────────────────────");
	gotoxy(10, 4);
	printf("검색:");
	gotoxy(68, 17);
	printf("구매");
	gotoxy(8, 6);
	printf("%-18s %-13s %-13s %-10s %-5s", "제목", "저자", "출판사", "장르", "가격");

	for (int j = 0; j < i; j++) {
		gotoxy(3, y++);
		printf("%-18s %-16s %-14s %-10s %-5s", test[j].title, test[j].writer, test[j].company, test[j].genre, test[j].price);
	}

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// 마우스 활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(33, 18);
			exit(0);
		}
		else if (x >= 65 && yy == 1) {
			gotoxy(65, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("로그인");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			Sleep(200);
			login();
			break;
		}
		else if (x >= 10 && x <= 20 && yy == 4) {
			gotoxy(10, 4);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("검색:");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(16, 4);
			scanf("%s", search);
			for (int j = 0; j < i; j++) {
				if (strcmp(test[j].title, search) == 0) {
					index = j;
					break;
				}
			}
		}
	}
}
// 로그인
void login() {
	FILE* fp;
	USER user[100];
	char test_id[20];
	char test_pw[20];
	int i = 0, j;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;

	fp = fopen("user.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]s", user[i].name, user[i].ID, user[i].PW, user[i].birth, user[i].phone);
		//removeRow(test[i].ID);
		if (strchr(user[i].ID, '\n')) {
			for (int k = 1; k < strlen(user[i].ID) + 1; k++) {
				user[i].ID[k - 1] = user[i].ID[k];
			}
		}
		i++;
	}
	fclose(fp);
	map2();
	gotoxy(23, 3);
	printf("로그인");
	gotoxy(12, 4);
	printf("─────────────────────────────");
	gotoxy(9, 7);
	printf("ID:");
	gotoxy(9, 10);
	printf("PW:");
	gotoxy(20, 12);
	printf("┌─────────┐");
	gotoxy(20, 13);
	printf("│ 로 그 인│");
	gotoxy(20, 14);
	printf("└─────────┘");
	gotoxy(7, 16);
	printf("┌─────────────┐");
	gotoxy(7, 17);
	printf("│ ID / PW 찾기│");
	gotoxy(7, 18);
	printf("└─────────────┘");
	gotoxy(29, 16);
	printf("┌────────────┐");
	gotoxy(29, 17);
	printf("│ 회 원 가 입│");
	gotoxy(29, 18);
	printf("└────────────┘");
	gotoxy(4, 20);
	printf("뒤로가기");
	gotoxy(45, 20);
	printf("종료");
	
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// 마우스 활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 13 && x <= 17 && yy == 7) {
			gotoxy(13, 7);
			scanf("%s", test_id);
			gotoxy(13, 10);
			scanf("%s%*c", test_pw);
			gotoxy(22, 22);
			while (1) {
				if (be_input()) {
					if (get_input(&key, &pos) != 0)
					{
						MOUSE_EVENT;
						x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
						yy = pos.Y;
					}
				}
				if (x >= 20 && x <= 35 && yy >= 12 && yy <= 14) {
					gotoxy(20, 12);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("┌─────────┐");
					gotoxy(20, 13);
					printf("│ 로 그 인│");
					gotoxy(20, 14);
					printf("└─────────┘");
					Sleep(300);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					for (j = 0; j < i; j++) {
						if ((strcmp(user[j].ID, test_id) == 0)) {
							if ((strcmp(user[j].PW, test_pw) == 0)) {
								map2();
								gotoxy(20, 10);
								printf("로그인 완료!");
								Sleep(1000);
								usermenu(test_id);
								break;
							}
						}
						else if ((strcmp(user[2].ID, test_id) == 0)) {
							if ((strcmp(user[2].PW, test_pw) == 0)) {
								map2();
								gotoxy(17, 10);
								printf("관리자 로그인 완료!");
								Sleep(1000);
								adminmenu(test_id);
								break;
							}
						}
						else {
							map2();
							gotoxy(13, 10);
							printf("ID나 PW가 일치하지 않습니다.");
							Sleep(1000);
							login();
							break;
						}
					}
				}
				else if ((x >= 4 && x <= 15 && yy == 20)) {
					gotoxy(4, 20);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("뒤로가기");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					Sleep(200);
					mainscreen();
					break;
				}
				else if (x >= 45 && yy == 20) {
					gotoxy(45, 20);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("종료");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					Sleep(200);
					gotoxy(33, 22);
					exit(0);
				}
				else if (x >= 7 && x <= 27 && yy >= 16 && yy <= 18) {
					gotoxy(7, 16);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("┌─────────────┐");
					gotoxy(7, 17);
					printf("│ ID / PW 찾기│");
					gotoxy(7, 18);
					printf("└─────────────┘");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					Sleep(200);
					find_ID_PW();
					break;
				}
				else if (x >= 29 && x <= 40 && yy >= 16 && yy <= 18) {
					gotoxy(29, 16);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("┌────────────┐");
					gotoxy(29, 17);
					printf("│ 회 원 가 입│");
					gotoxy(29, 18);
					printf("└────────────┘");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					Sleep(200);
					new_login();
					break;
				}
			}
		}
	}
}
// ID_PW 찾기
void find_ID_PW() {
	FILE* fp;
	USER user[100];
	USER test;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0, index = 0, i = 0;

	fp = fopen("user.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]s", user[i].name,user[i].ID, user[i].PW, user[i].birth, user[i].phone);
		//removeRow(test[i].ID);
		if (strchr(user[i].name, '\n')) {
			for (int k = 1; k < strlen(user[i].name) + 1; k++) {
				user[i].name[k - 1] = user[i].name[k];
			}
		}
		i++;
	}
	fclose(fp);
	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(20, 2);
	printf("ID / PW 찾기");
	gotoxy(12, 3);
	printf("────────────────────────────");
	gotoxy(10, 8);
	printf("1. ID 찾기");
	gotoxy(10, 13);
	printf("2. PW 찾기");
	gotoxy(22, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 10 && x <= 25 && yy == 8) {
			gotoxy(10, 8);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("1. ID 찾기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			map2();
			gotoxy(3, 1);
			printf("뒤로가기");
			gotoxy(45, 1);
			printf("종료");
			gotoxy(20, 2);
			printf("ID / PW 찾기");
			gotoxy(12, 3);
			printf("────────────────────────────");
			gotoxy(11, 8);
			printf("이름과 생년월일을 입력해주세요.");
			gotoxy(11, 11);
			printf("이름:");
			gotoxy(11, 14);
			printf("생년월일:");
			gotoxy(17, 11);
			scanf("%s", test.name);
			gotoxy(21, 14);
			scanf("%s", test.birth);
			gotoxy(22, 22);
			for (int j = 0; j < i; j++) {
				if (strcmp(user[j].name, test.name) == 0) {
					if (strcmp(user[j].birth, test.birth) == 0) {
						index = j;
						break;
					}
				}
			}
			map2();
			gotoxy(12, 10);
			printf("%s님의 ID는 %s 입니다.", test.name, user[index].ID);
			gotoxy(22, 22);
			Sleep(3000);
			login();
			break;
		}
		else if (x >= 10 && x <= 25 && yy == 13) {
			gotoxy(10, 13);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("2. PW 찾기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			map2();
			gotoxy(3, 1);
			printf("뒤로가기");
			gotoxy(45, 1);
			printf("종료");
			gotoxy(20, 2);
			printf("ID / PW 찾기");
			gotoxy(12, 3);
			printf("────────────────────────────");
			gotoxy(11, 9);
			printf("ID를 입력해주세요.");
			gotoxy(11, 12);
			printf("ID:");
			gotoxy(15, 12);
			scanf("%s", test.ID);
			gotoxy(22, 22);
			for (int j = 0; j < i; j++) {
				if (strcmp(user[j].ID, test.ID) == 0) {
					index = j;
					break;
				}
			}
			map2();
			gotoxy(12, 10);
			printf("%s님의 PW는 %s 입니다.", user[index].name, user[index].PW);
			gotoxy(22, 22);
			Sleep(3000);
			login();
			break;
		}
	}
}
// 회원가입
void new_login() {
	FILE* fp;
	USER user;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;
	map2();
	gotoxy(3,1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(23, 2);
	printf("회원가입");
	gotoxy(12, 3);
	printf("────────────────────────────");
	gotoxy(8, 5);
	printf("ID:");
	gotoxy(8, 8);
	printf("PW:");
	gotoxy(8, 11);
	printf("이름:");
	gotoxy(8, 14);
	printf("생년월일(6자리):");
	gotoxy(8, 17);
	printf("전화번호(숫자만):");
	gotoxy(20, 18);
	printf("┌────────────┐");
	gotoxy(20, 19);
	printf("│ 회 원 가 입│");
	gotoxy(20, 20);
	printf("└────────────┘");
	gotoxy(22, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// 마우스 활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 8 && yy == 5) {
			gotoxy(12, 5);
			scanf("%s", user.ID);
			gotoxy(12, 8);
			scanf("%s", user.PW);
			gotoxy(14, 11);
			scanf("%s", user.name);
			gotoxy(25, 14);
			scanf("%s", user.birth);
			gotoxy(26, 17);
			scanf("%s", user.phone);
			gotoxy(22, 22);
			while (1) {
				if (be_input())
				{
					if (get_input(&key, &pos) != 0)
					{
						MOUSE_EVENT;
						x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
						yy = pos.Y;
					}
				}
				if (x >= 20 && x <= 35 && yy >= 18 && yy <= 20) {
					gotoxy(20, 18);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("┌────────────┐");
					gotoxy(20, 19);
					printf("│ 회 원 가 입│");
					gotoxy(20, 20);
					printf("└────────────┘");
					Sleep(200);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					Sleep(200);
					fp = fopen("user.txt", "a");
					fprintf(fp, "\n%s,%s,%s,%s,%s", user.name, user.ID, user.PW, user.birth, user.phone);
					fclose(fp);
					map2();
					gotoxy(18, 10);
					printf("회원가입 완료!");
					gotoxy(22, 22);
					Sleep(2000);
					login();
					break;
				}
				else if (x >= 3 && x <= 10 && yy == 1) {
					gotoxy(3, 1);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("뒤로가기");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					Sleep(200);
					login();
					break;
				}
				else if (x >= 45 && yy == 1) {
					gotoxy(45, 1);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("종료");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					Sleep(200);
					gotoxy(33, 22);
					exit(0);
					break;
				}
			}
		}
	}
}
// 회원 메뉴
void usermenu(char id[]) {
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;
	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(24, 3);
	printf("메뉴");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(12, 8);
	printf("ㆍ 도서 검색");
	gotoxy(12, 12);
	printf("ㆍ 구매 목록");
	gotoxy(12, 16);
	printf("ㆍ 정보 수정");
	gotoxy(3, 20);
	printf("로그아웃");
	gotoxy(22, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			mainscreen();
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(23, 22);
			exit(0);
			break;
		}
		else if (x >= 3 && x <= 15 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("로그아웃");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			mainscreen();
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 8) {
			gotoxy(12, 8);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 도서 검색");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			search_book(id);
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 12) {
			gotoxy(12, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 구매 목록");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			buy_list(id);
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 16) {
			gotoxy(12, 16);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 정보 수정");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_user(id);
			break;
		}
	}
}
// 회원 도서 검색
void search_book(char id[]) {
	FILE* fp;
	BOOK test[100];
	DWORD mode;
	WORD key;
	COORD pos;
	int i = 0, y = 7, j = 0;
	int event, x = 0, yy = 0;

	fp = fopen("book.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].title, test[i].writer, test[i].company, test[i].genre, test[i].price,test[i].sales);
		//removeRow(test[i].code);

		if (strchr(test[i].title, '\n')) {
			for (int k = 1; k < strlen(test[i].title) + 1; k++) {
				test[i].title[k - 1] = test[i].title[k];
			}
		}
		i++;
	}
	fclose(fp);
	map();
	gotoxy(3, 1);
	printf("종료");
	gotoxy(63, 1);
	printf("로그아웃");
	gotoxy(33, 2);
	printf("서원 서점");
	gotoxy(13, 3);
	printf("────────────────────────────────────────────────");
	/*gotoxy(10, 4);
	printf("검색:");*/
	gotoxy(68, 17);
	printf("구매");
	gotoxy(8, 6);
	printf("%-18s %-13s %-13s %-10s %-5s", "제목", "저자", "출판사", "장르", "가격");

	for (j = 0; j < i; j++) {
		gotoxy(3, y++);
		printf("%-18s %-16s %-14s %-10s %-5s", test[j].title, test[j].writer, test[j].company, test[j].genre, test[j].price);
	}
	gotoxy(22, 22);
	j = 0;
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			Sleep(300);
			gotoxy(33, 18);
			exit(0);
		}
		else if (x >= 63 && yy == 1) {
			gotoxy(63, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("로그아웃");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			Sleep(300);
			mainscreen();
			break;
		}
		else if (x >= 3 && x <= 68 && yy == 7) {
			gotoxy(3, 7);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("%-18s %-16s %-14s %-10s %-5s", test[j].title, test[j].writer, test[j].company, test[j].genre, test[j].price);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			
			if (be_input())
			{
				if (get_input(&key, &pos) != 0)
				{
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
					yy = pos.Y;
				}
			}
			if (x >= 68 && yy == 17) {
				gotoxy(68, 17);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				printf("구매");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				Sleep(300);
				user_buy_book(test[j].title, id);
				break;
			}
		}
		else if (x >= 3 && x <= 68 && yy == 8) {
			gotoxy(3, 8);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("%-18s %-16s %-14s %-10s %-5s", test[1].title, test[1].writer, test[1].company, test[1].genre, test[1].price);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			if (be_input())
			{
				if (get_input(&key, &pos) != 0)
				{
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
					yy = pos.Y;
				}
			}
			if (x >= 68 && yy == 17) {
				gotoxy(68, 17);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				printf("구매");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				Sleep(300);
				user_buy_book(test[1].title, id);
				break;
			}
		}
		else if (x >= 3 && x <= 68 && yy == 9) {
			gotoxy(3, 9);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("%-18s %-16s %-14s %-10s %-5s", test[2].title, test[2].writer, test[2].company, test[2].genre, test[2].price);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			if (be_input())
			{
				if (get_input(&key, &pos) != 0)
				{
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
					yy = pos.Y;
				}
			}
			if (x >= 68 && yy == 17) {
				gotoxy(68, 17);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				printf("구매");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				Sleep(300);
				user_buy_book(test[2].title, id);
				break;
			}
		}
		else if (x >= 3 && x <= 68 && yy == 10) {
			gotoxy(3, 10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("%-18s %-16s %-14s %-10s %-5s", test[3].title, test[3].writer, test[3].company, test[3].genre, test[3].price);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			if (be_input())
			{
				if (get_input(&key, &pos) != 0)
				{
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
					yy = pos.Y;
				}
			}
			if (x >= 68 && yy == 17) {
				gotoxy(68, 17);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				printf("구매");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				Sleep(300);
				user_buy_book(test[3].title, id);
				break;
			}
		}
	}
}
// 회원 도서 구매
void user_buy_book(char title[],char id[]) {
	FILE* fp;
	BOOK book[100];
	BUY buy;
	int i = 0, j = 0, index = 0;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;
	struct tm* t;
	time_t timer = time(NULL);

	t = localtime(&timer);


	fp = fopen("book.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", book[i].title, book[i].writer, book[i].company, book[i].genre,book[i].price,book[i].sales);
		//removeRow(test[i].code

		if (strchr(book[i].title, '\n')) {
			for (int k = 1; k < strlen(book[i].title) + 1; k++) {
				book[i].title[k - 1] = book[i].title[k];
			}
		}
		i++;
	}
	fclose(fp);

	for (int j = 0; j < i; j++) {
		if (strcmp(book[j].title, title) == 0) {
			index = j;
			break;
		}
	}

	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(21, 3);
	printf("도서 구매");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(6, 8);
	printf("'%s'를(을) 구매하시겠습니까?", title);
	gotoxy(19, 11);
	printf("결제 금액:%s", book[index].price);
	gotoxy(13, 13);
	printf("┌─────┐");
	gotoxy(13, 14);
	printf("│  예 │");
	gotoxy(13, 15);
	printf("└─────┘");
	gotoxy(28, 13);
	printf("┌─────────┐");
	gotoxy(28, 14);
	printf("│  아니오 │");
	gotoxy(28, 15);
	printf("└─────────┘");
	gotoxy(22, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 13 && x <= 24 && yy >= 13 && yy <= 15) {
			gotoxy(13, 13);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("┌─────┐");
			gotoxy(13, 14);
			printf("│  예 │");
			gotoxy(13, 15);
			printf("└─────┘");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			map2();
			gotoxy(15, 10);
			printf("구매가 완료되었습니다.");
			Sleep(2000);
			fp = fopen("buy.txt", "a");
			fprintf(fp, "\n%d.%d.%d,%s,%s,%s", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, id, title, book[index].price);
			fclose(fp);
			map2();
			gotoxy(2, 2);
			printf("%d", &total);
			Sleep(3000);
			usermenu(id);
			break;
		}
		else if (x >= 28 && x <= 43 && yy >= 13 && yy <= 15) {
			gotoxy(28, 13);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("┌─────────┐");
			gotoxy(28, 14);
			printf("│  아니오 │");
			gotoxy(28, 15);
			printf("└─────────┘");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			map2();
			gotoxy(15, 10);
			printf("구매가 취소되었습니다.");
			Sleep(2000);
			usermenu(id);
			break;
		}
	}
}
// 회원 구매 목록
void buy_list(char id[]) {
	FILE* fp;
	USER test[100];
	BUY test2[100];
	BOOK test3[100];
	DWORD mode;
	WORD key;
	COORD pos;
	int i = 0, q=0,p=0,y = 7,index=0,index2=0,count=0;
	int event, x = 0, yy = 0;

	
	fp = fopen("buy.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]s", test2[q].buy_date, test2[q].ID, test2[q].title,test2[q].price);
		//removeRow(test[i].code);

		if (strchr(test2[q].buy_date, '\n')) {
			for (int k = 1; k < strlen(test2[q].buy_date) + 1; k++) {
				test2[q].buy_date[k - 1] = test2[q].buy_date[k];
			}
		}
		q++;
	}

	fp = fopen("book.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test3[p].title, test3[p].writer, test3[p].company, test3[p].genre, test3[p].price,test3[p].sales);
		//removeRow(test[i].code);

		if (strchr(test3[p].title, '\n')) {
			for (int k = 1; k < strlen(test3[p].title) + 1; k++) {
				test3[p].title[k - 1] = test3[p].title[k];
			}
		}
		p++;
	}
	fclose(fp);
	
	map3();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(75, 1);
	printf("종료");
	gotoxy(37, 2);
	printf("구매 목록");
	gotoxy(13, 3);
	//printf("────────────────────────────────────────────────────────");
	gotoxy(71, 17);
	printf("로그아웃");
	gotoxy(4, 5);
	printf("%-13s %-18s %-13s %-12s %-10s %-3s", "날짜", "제목", "저자", "출판사", "장르","가격");

	for (int j = 0; j < q; j++) {
		if (strcmp(test2[j].ID, id) == 0) {
			if (strcmp(test3[j].title, test2[j].title) == 0) {
				index2 = j;
				gotoxy(3, y++);
				printf("%-13s %-18s %-13s %-12s %-10s %-3s", test2[index].buy_date, test3[index2].title, test3[index2].writer, test3[index2].company, test3[index2].genre, test3[index2].price);
			}
		}
	}

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			usermenu(id);
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(23, 22);
			exit(0);
			break;
		}
		else if (x >= 71 && yy == 17) {
			gotoxy(71, 17);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("로그아웃");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			mainscreen();
			break;
		}
	}
}
// 회원 정보 수정
void change_user(char id[]) {
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;

	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("정보 수정");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(3, 20);
	printf("로그아웃");
	gotoxy(10, 9);
	printf("ㆍ 비밀번호 변경");
	gotoxy(10, 13);
	printf("ㆍ 전화번호 변경");

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 10 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			usermenu(id);
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			exit(0);
			break;
		}
		else if (x>=3 && x<=15 && yy==20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("로그아웃");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			mainscreen();
			break;
		}
		else if (x>=10 && x<=30 && yy==9) {
			gotoxy(10, 9);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 비밀번호 변경");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_PW(id);
			break;
		}
		else if (x>=10 && x<=30 && yy==13) {
			gotoxy(10, 13);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 전화번호 변경");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_phone(id);
			break;
		}
	}
}
// 회원 정보 수정 - 비밀번호
void change_PW(char id[]) {
	FILE* fp;
	USER test[100];
	char new_pw[100];
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0,i=0,j=0,index=0;

	fp = fopen("user.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].name, test[i].ID, test[i].PW, test[i].birth, test[i].phone);
		//removeRow(test[i].ID);
		if (strchr(test[i].name, '\n')) {
			for (int k = 1; k < strlen(test[i].name) + 1; k++) {
				test[i].name[k - 1] = test[i].name[k];
			}
		}
		i++;
	}
	fclose(fp);

	for (int j = 0; j < i; j++) {
		if (strcmp(test[j].ID, id) == 0) {
			index = j;
			break;
		}
	}

	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("정보 수정");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(6, 10);
	printf("변경하실 새로운 비밀번호를 입력해 주세요.");
	gotoxy(6, 12);
	printf("☞");
	gotoxy(3, 20);
	printf("로그아웃");
	gotoxy(21, 15);
	printf("┌──────┐");
	gotoxy(21, 16);
	printf("│ 변 경│");
	gotoxy(21, 17);
	printf("└──────┘");
	gotoxy(9, 12);
	scanf("%s", new_pw);
	gotoxy(12, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 21 && x <= 27 && yy >= 15 && yy <= 17) {
			gotoxy(21, 15);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("┌──────┐");
			gotoxy(21, 16);
			printf("│ 변 경│");
			gotoxy(21, 17);
			printf("└──────┘");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			strcpy(test[index].PW, new_pw);
			fp = fopen("user.txt", "w");
			for (int j = 0; j < i; j++) {
				fprintf(fp, "%s,%s,%s,%s,%s\n", test[j].name, test[j].ID, test[j].PW, test[j].birth, test[j].phone);
			}
			fclose(fp);
			map2();
			gotoxy(11, 10);
			printf("비밀번호 변경이 완료되었습니다.");
			Sleep(3000);
			change_user(id);
		}
	}
}
// 회원 정보 수정 - 전화번호
void change_phone(char id[]) {
	FILE* fp;
	USER test[100];
	char new_phone[100];
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0, i = 0, j = 0, index = 0;

	fp = fopen("user.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].name, test[i].ID, test[i].PW, test[i].birth, test[i].phone);
		//removeRow(test[i].ID);
		if (strchr(test[i].name, '\n')) {
			for (int k = 1; k < strlen(test[i].name) + 1; k++) {
				test[i].name[k - 1] = test[i].name[k];
			}
		}
		i++;
	}
	fclose(fp);

	for (int j = 0; j < i; j++) {
		if (strcmp(test[j].ID, id) == 0) {
			index = j;
			break;
		}
	}

	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("정보 수정");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(6, 10);
	printf("변경하실 새로운 전화번호를 입력해 주세요.");
	gotoxy(6, 12);
	printf("☞");
	gotoxy(3, 20);
	printf("로그아웃");
	gotoxy(21, 15);
	printf("┌──────┐");
	gotoxy(21, 16);
	printf("│ 변 경│");
	gotoxy(21, 17);
	printf("└──────┘");
	gotoxy(9, 12);
	scanf("%s", new_phone);
	gotoxy(12, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 21 && x <= 27 && yy >= 15 && yy <= 17) {
			gotoxy(21, 15);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("┌──────┐");
			gotoxy(21, 16);
			printf("│ 변 경│");
			gotoxy(21, 17);
			printf("└──────┘");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			strcpy(test[index].phone, new_phone);
			fp = fopen("user.txt", "w");
			for (int j = 0; j < i; j++) {
				fprintf(fp, "%s,%s,%s,%s,%s\n", test[j].name, test[j].ID, test[j].PW, test[j].birth, test[j].phone);
			}
			fclose(fp);
			map2();
			gotoxy(11, 10);
			printf("전화번호 변경이 완료되었습니다.");
			Sleep(3000);
			change_user(id);
		}
	}
}
// 관리자 메뉴
void adminmenu(char id[]) {
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;
	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(24, 3);
	printf("메뉴");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(12, 7);
	printf("ㆍ 도서 관리");
	gotoxy(12, 10);
	printf("ㆍ 재고 관리");
	gotoxy(12, 13);
	printf("ㆍ 매출 관리");
	gotoxy(12, 16);
	printf("ㆍ 회원 관리");
	gotoxy(3, 20);
	printf("로그아웃");

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			mainscreen();
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(23, 22);
			exit(0);
			break;
		}
		else if (x >= 3 && x <= 15 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("로그아웃");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			mainscreen();
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 7) {
			gotoxy(12, 7);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 도서 관리");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			setting_book(id);
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 10) {
			gotoxy(12, 10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 재고 관리");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			search_book3(id);
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 13) {
			gotoxy(12, 13);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 매출 관리");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			setting_total(id);
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 16) {
			gotoxy(12, 16);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 회원 관리");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			setting_user(id);
			break;
		}
	}
}
// 도서 관리
void setting_book(char id[]) {
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;
	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("도서 관리");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(12, 8);
	printf("ㆍ 등록");
	gotoxy(12, 12);
	printf("ㆍ 수정 & 삭제");
	gotoxy(12, 16);
	printf("ㆍ 조회");
	gotoxy(3, 20);
	printf("로그아웃");

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			adminmenu(id);
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(23, 22);
			exit(0);
			break;
		}
		else if (x >= 3 && x <= 15 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("로그아웃");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			mainscreen();
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 8) {
			gotoxy(12, 8);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 등록");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			new_book(id);
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 12) {
			gotoxy(12, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 수정 & 삭제");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			search_book2(id);
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 16) {
			gotoxy(12, 16);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 조회");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			look_book(id);
			break;
		}
	}
}
// 도서 등록
void new_book(char id[]) {
	FILE* fp;
	BOOK book;
	INVENTORY ivt;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;

	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("도서 등록");
	gotoxy(9, 4);
	printf("──────────────────────────────────");
	gotoxy(8, 6);
	printf("ㆍ 제목:");
	gotoxy(8, 8);
	printf("ㆍ 저자:");
	gotoxy(8, 10);
	printf("ㆍ 출판사:");
	gotoxy(8, 12);
	printf("ㆍ 장르:");
	gotoxy(8, 14);
	printf("ㆍ 가격:");
	gotoxy(8, 16);
	printf("ㆍ 재고:");
	gotoxy(22, 18);
	printf("┌──────┐");
	gotoxy(22, 19);
	printf("│ 등 록│");
	gotoxy(22, 20);
	printf("└──────┘");
	gotoxy(17, 6);
	gets(book.title);
	gotoxy(17, 8);
	gets(book.writer);
	gotoxy(19, 10);
	gets(book.company);
	gotoxy(17, 12);
	scanf("%s", book.genre);
	gotoxy(17, 14);
	scanf("%s", book.price);
	gotoxy(17, 16);
	scanf("%s", ivt.stock);
	gotoxy(22, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	
	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x>=22 && x<=35&&yy>=18&&yy<=19) {
			gotoxy(22, 18);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("┌──────┐");
			gotoxy(22, 19);
			printf("│ 등 록│");
			gotoxy(22, 20);
			printf("└──────┘");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			fp = fopen("book.txt", "a");
			fprintf(fp, "\n%s,%s,%s,%s,%s,%s", book.title, book.writer, book.company, book.genre, book.price,"0");
			fclose(fp);
			fp = fopen("inventory.txt", "a");
			fprintf(fp, "\n%s,%s,%s", book.title, book.company,ivt.stock);
			fclose(fp);
			map2();
			gotoxy(12, 10);
			printf("도서 등록이 완료되었습니다.");
			Sleep(3000);
			setting_book(id);
			break;
		}
	}
}
// 도서 수정 & 삭제 전 도서 제목 입력받기
void search_book2(char id[]) {
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;
	char title[30];

	map2();
	gotoxy(3, 20);
	printf("뒤로가기");
	gotoxy(45, 20);
	printf("확인");
	gotoxy(22, 3);
	printf("도서 검색");
	gotoxy(9, 4);
	printf("──────────────────────────────────");
	gotoxy(8, 10);
	printf("도서의 제목을 입력해주세요.");
	gotoxy(8, 12);
	printf("☞");
	gotoxy(11, 12);
	gets(title);
	gotoxy(13, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 10 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			setting_book(id);
			break;
		}
		else if (x >= 45 && yy == 20) {
			gotoxy(45, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("확인");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			changeordeletebook(id,title);
			break;
		}
	}
}
// 도서 수정? 삭제? 여부
void changeordeletebook(char id[],char title[]) {
	FILE* fp;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;
	BOOK test[100];
	int i = 0, j = 0, index = 0;

	fp = fopen("book.txt", "r");
	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].title, test[i].writer, test[i].company, test[i].genre, test[i].price,test[i].sales);

		if (strchr(test[i].title, '\n')) {
			for (int k = 1; k < strlen(test[i].title) + 1; k++) {
				test[i].title[k - 1] = test[i].title[k];
			}
		}
		i++;
	}
	fclose(fp);

	for (int j = 0; j < i; j++) {
		if (strcmp(test[j].title, title) == 0) {
			index = j;
			break;
		}
	}

	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("도서 정보");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(3, 20);
	printf("수정");
	gotoxy(45, 20);
	printf("삭제");
	gotoxy(10, 6);
	printf("ㆍ 제목: %s", test[index].title);
	gotoxy(10, 9);
	printf("ㆍ 저자: %s", test[index].writer);
	gotoxy(10, 12);
	printf("ㆍ 출판사: %s", test[index].company);
	gotoxy(10, 15);
	printf("ㆍ 장르: %s", test[index].genre);
	gotoxy(10, 18);
	printf("ㆍ 가격: %s원", test[index].price);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			search_book2(id);
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(23, 22);
			exit(0);
			break;
		}
		else if (x >= 3 && x <= 10 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("수정");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_book(id, title);
			break;
		}
		else if (x >= 45 && yy == 20) {
			gotoxy(45, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("삭제");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			delete_book(id, title);
			break;
		}
	}
}
// 도서 수정 메뉴
void change_book(char id[], char title[]) {
	FILE* fp;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;

	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("도서 수정");
	gotoxy(9, 4);
	printf("──────────────────────────────────");
	gotoxy(8, 6);
	printf("ㆍ 제목");
	gotoxy(8, 9);
	printf("ㆍ 저자");
	gotoxy(8, 12);
	printf("ㆍ 출판사");
	gotoxy(8, 15);
	printf("ㆍ 장르");
	gotoxy(8, 18);
	printf("ㆍ 가격");

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			changeordeletebook(id, title);
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(23, 22);
			exit(0);
			break;
		}
		else if (x >= 8 && x <= 20 && yy == 6) {
			gotoxy(8, 6);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 제목");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_book_title(id, title);
			break;
		}
		else if (x >= 8 && x <= 20 && yy == 9) {
			gotoxy(8, 9);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 저자");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_book_writer(id, title);
			break;
		}
		else if (x >= 8 && x <= 20 && yy == 12) {
			gotoxy(8, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 출판사");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_book_company(id, title);
			break;
		}
		else if (x >= 8 && x <= 20 && yy == 15) {
			gotoxy(8, 15);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 장르");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_book_genre(id, title);
			break;
		}
		else if (x >= 8 && x <= 20 && yy == 18) {
			gotoxy(8, 18);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 가격");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_book_price(id, title);
			break;
		}
	}
}
// 도서 수정 - 제목
void change_book_title(char id[], char title[]) {
	FILE* fp;
	BOOK test[100];
	char new_title[100];
	int i = 0, j = 0, index = 0;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;
	char tmp[50] = "\n";

	fp = fopen("book.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].title, test[i].writer, test[i].company, test[i].genre, test[i].price,test[i].sales);

		if (strchr(test[i].title, '\n')) {
			for (int k = 1; k < strlen(test[i].title) + 1; k++) {
				test[i].title[k - 1] = test[i].title[k];
			}
		}
		i++;
	}
	fclose(fp);

	for (int j = 0; j < i; j++) {
		if (strcmp(test[j].title, title) == 0) {
			index = j;
			break;
		}
	}

	map2();
	gotoxy(3, 20);
	printf("뒤로가기");
	gotoxy(45, 20);
	printf("확인");
	gotoxy(22, 3);
	printf("제목 수정");
	gotoxy(9, 4);
	printf("──────────────────────────────────");
	gotoxy(8, 10);
	printf("새로운 도서 제목을 입력해주세요.");
	gotoxy(8, 12);
	printf("☞");
	gotoxy(11, 12);
	gets(new_title);
	gotoxy(13, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 10 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_book(id,title);
			break;
		}
		else if (x >= 45 && yy == 20) {
			gotoxy(45, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("확인");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			strcat(tmp, new_title);
			strcpy(test[index].title, tmp);
			fp = fopen("book.txt", "w");
			for (int j = 0; j < i; j++) {
				fprintf(fp, "%s,%s,%s,%s,%s,%s\n", test[j].title, test[j].writer, test[j].company, test[j].genre, test[j].price,"0");
			}
			fclose(fp);
			map2();
			gotoxy(12, 10);
			printf("제목 변경이 완료되었습니다.");
			Sleep(3000);
			change_book(id, title);
			break;
		}
	}
}
// 도서 수정 - 저자
void change_book_writer(char id[], char title[]) {
	FILE* fp;
	BOOK test[100];
	char new_writer[100];
	int i = 0, j = 0, index = 0;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;

	fp = fopen("book.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].title, test[i].writer, test[i].company, test[i].genre, test[i].price,test[i].sales);

		if (strchr(test[i].title, '\n')) {
			for (int k = 1; k < strlen(test[i].title) + 1; k++) {
				test[i].title[k - 1] = test[i].title[k];
			}
		}
		i++;
	}
	fclose(fp);

	for (int j = 0; j < i; j++) {
		if (strcmp(test[j].title, title) == 0) {
			index = j;
			break;
		}
	}

	map2();
	gotoxy(3, 20);
	printf("뒤로가기");
	gotoxy(45, 20);
	printf("확인");
	gotoxy(22, 3);
	printf("저자 수정");
	gotoxy(9, 4);
	printf("──────────────────────────────────");
	gotoxy(8, 10);
	printf("새로운 도서 저자를 입력해주세요.");
	gotoxy(8, 12);
	printf("☞");
	gotoxy(11, 12);
	gets(new_writer);
	gotoxy(13, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 10 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_book(id, title);
			break;
		}
		else if (x >= 45 && yy == 20) {
			gotoxy(45, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("확인");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			strcpy(test[index].writer, new_writer);
			fp = fopen("book.txt", "w");
			for (int j = 0; j < i; j++) {
				fprintf(fp, "%s,%s,%s,%s,%s,%s\n", test[j].title, test[j].writer, test[j].company, test[j].genre, test[j].price,"0");
			}
			fclose(fp);
			map2();
			gotoxy(12, 10);
			printf("저자 변경이 완료되었습니다.");
			Sleep(3000);
			change_book(id, title);
			break;
		}
	}
}
// 도서 수정 - 출판사
void change_book_company(char id[], char title[]) {
	FILE* fp;
	BOOK test[100];
	char new_company[100];
	int i = 0, j = 0, index = 0;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;

	fp = fopen("book.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].title, test[i].writer, test[i].company, test[i].genre, test[i].price,test[i].sales);

		if (strchr(test[i].title, '\n')) {
			for (int k = 1; k < strlen(test[i].title) + 1; k++) {
				test[i].title[k - 1] = test[i].title[k];
			}
		}
		i++;
	}
	fclose(fp);

	for (int j = 0; j < i; j++) {
		if (strcmp(test[j].title, title) == 0) {
			index = j;
			break;
		}
	}

	map2();
	gotoxy(3, 20);
	printf("뒤로가기");
	gotoxy(45, 20);
	printf("확인");
	gotoxy(21, 3);
	printf("출판사 수정");
	gotoxy(9, 4);
	printf("──────────────────────────────────");
	gotoxy(8, 10);
	printf("새로운 도서 출판사를 입력해주세요.");
	gotoxy(8, 12);
	printf("☞");
	gotoxy(11, 12);
	gets(new_company);
	gotoxy(13, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 10 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_book(id, title);
			break;
		}
		else if (x >= 45 && yy == 20) {
			gotoxy(45, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("확인");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			strcpy(test[index].company, new_company);
			fp = fopen("book.txt", "w");
			for (int j = 0; j < i; j++) {
				fprintf(fp, "%s,%s,%s,%s,%s,%s\n", test[j].title, test[j].writer, test[j].company, test[j].genre, test[j].price,test[j].sales);
			}
			fclose(fp);
			map2();
			gotoxy(11, 10);
			printf("출판사 변경이 완료되었습니다.");
			Sleep(3000);
			change_book(id, title);
			break;
		}
	}
}
// 도서 수정 - 장르
void change_book_genre(char id[], char title[]) {
	FILE* fp;
	BOOK test[100];
	char new_genre[100];
	int i = 0, j = 0, index = 0;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;

	fp = fopen("book.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].title, test[i].writer, test[i].company, test[i].genre, test[i].price,test[i].sales);

		if (strchr(test[i].title, '\n')) {
			for (int k = 1; k < strlen(test[i].title) + 1; k++) {
				test[i].title[k - 1] = test[i].title[k];
			}
		}
		i++;
	}
	fclose(fp);

	for (int j = 0; j < i; j++) {
		if (strcmp(test[j].title, title) == 0) {
			index = j;
			break;
		}
	}

	map2();
	gotoxy(3, 20);
	printf("뒤로가기");
	gotoxy(45, 20);
	printf("확인");
	gotoxy(22, 3);
	printf("장르 수정");
	gotoxy(9, 4);
	printf("──────────────────────────────────");
	gotoxy(8, 10);
	printf("새로운 도서 장르를 입력해주세요.");
	gotoxy(8, 12);
	printf("☞");
	gotoxy(11, 12);
	scanf("%s", new_genre);
	gotoxy(13, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 10 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_book(id, title);
			break;
		}
		else if (x >= 45 && yy == 20) {
			gotoxy(45, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("확인");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			strcpy(test[index].genre, new_genre);
			fp = fopen("book.txt", "w");
			for (int j = 0; j < i; j++) {
				fprintf(fp, "%s,%s,%s,%s,%s,%s\n", test[j].title, test[j].writer, test[j].company, test[j].genre, test[j].price,test[j].sales);
			}
			fclose(fp);
			map2();
			gotoxy(12, 10);
			printf("장르 변경이 완료되었습니다.");
			Sleep(3000);
			change_book(id, title);
			break;
		}
	}
}
// 도서 수정 - 가격
void change_book_price(char id[], char title[]) {
	FILE* fp;
	BOOK test[100];
	char new_price[100];
	int i = 0, j = 0, index = 0;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;

	fp = fopen("book.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].title, test[i].writer, test[i].company, test[i].genre, test[i].price,test[i].sales);

		if (strchr(test[i].title, '\n')) {
			for (int k = 1; k < strlen(test[i].title) + 1; k++) {
				test[i].title[k - 1] = test[i].title[k];
			}
		}
		i++;
	}
	fclose(fp);

	for (int j = 0; j < i; j++) {
		if (strcmp(test[j].title, title) == 0) {
			index = j;
			break;
		}
	}

	map2();
	gotoxy(3, 20);
	printf("뒤로가기");
	gotoxy(45, 20);
	printf("확인");
	gotoxy(22, 3);
	printf("가격 수정");
	gotoxy(9, 4);
	printf("──────────────────────────────────");
	gotoxy(8, 10);
	printf("새로운 도서 가격을 입력해주세요.");
	gotoxy(8, 12);
	printf("☞");
	gotoxy(11, 12);
	gets(new_price);
	gotoxy(13, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 10 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_book(id, title);
			break;
		}
		else if (x >= 45 && yy == 20) {
			gotoxy(45, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("확인");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			strcpy(test[index].price, new_price);
			fp = fopen("book.txt", "w");
			for (int j = 0; j < i; j++) {
				fprintf(fp, "%s,%s,%s,%s,%s,%s\n", test[j].title, test[j].writer, test[j].company, test[j].genre, test[j].price,test[j].sales);
			}
			fclose(fp);
			map2();
			gotoxy(12, 10);
			printf("가격 변경이 완료되었습니다.");
			Sleep(3000);
			change_book(id, title);
			break;
		}
	}
}
// 도서 삭제
void delete_book(char id[], char title[]) {
	FILE* fp;
	BOOK book[100];
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0, i = 0, j = 0, index = 0;

	fp = fopen("book.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", book[i].title, book[i].writer, book[i].company, book[i].genre, book[i].price,book[i].sales);
		//removeRow(test[i].code

		if (strchr(book[i].title, '\n')) {
			for (int k = 1; k < strlen(book[i].title) + 1; k++) {
				book[i].title[k - 1] = book[i].title[k];
			}
		}
		i++;
	}
	fclose(fp);

	for (int j = 0; j < i; j++) {
		if (strcmp(book[j].title, title) == 0) {
			index = j;
			break;
		}
	}
	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(21, 3);
	printf("도서 삭제");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(15, 10);
	printf("정말 삭제하시겠습니까?");
	gotoxy(13, 13);
	printf("┌─────┐");
	gotoxy(13, 14);
	printf("│  예 │");
	gotoxy(13, 15);
	printf("└─────┘");
	gotoxy(28, 13);
	printf("┌─────────┐");
	gotoxy(28, 14);
	printf("│  아니오 │");
	gotoxy(28, 15);
	printf("└─────────┘");
	gotoxy(22, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 13 && x <= 24 && yy >= 13 && yy <= 15) {
			gotoxy(13, 13);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("┌─────┐");
			gotoxy(13, 14);
			printf("│  예 │");
			gotoxy(13, 15);
			printf("└─────┘");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			fp = fopen("book.txt", "w");

			for (j = 0; j < index; j++) {
				fprintf(fp, "%s,%s,%s,%s,%s,%s",book[j].title, book[j].writer, book[j].company, book[j].genre, book[j].price,book[j].sales);
			}
			fclose(fp);

			fp = fopen("book.txt", "a");

			for (j = index + 1; j < i; j++) {
				fprintf(fp, "%s,%s,%s,%s,%s,%s",book[j].title, book[j].writer, book[j].company, book[j].genre, book[j].price,book[j].sales);
			}
			fclose(fp);
			map2();
			gotoxy(15, 10);
			printf("삭제가 완료되었습니다.");
			Sleep(2000);
			setting_book(id);
			break;
		}
		else if (x >= 28 && x <= 43 && yy >= 13 && yy <= 15) {
			gotoxy(28, 13);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("┌─────────┐");
			gotoxy(28, 14);
			printf("│  아니오 │");
			gotoxy(28, 15);
			printf("└─────────┘");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			map2();
			gotoxy(15, 10);
			printf("삭제가 취소되었습니다.");
			Sleep(2000);
			setting_book(id);
			break;
		}
	}
}
// 도서 조회
void look_book(char id[]) {
	FILE* fp;
	BOOK test[100];
	INVENTORY test2[100];
	DWORD mode;
	WORD key;
	COORD pos;
	int i = 0,q=0, y = 7, event, x = 0, yy = 0, index = 0;
	char search[50];

	fp = fopen("book.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].title, test[i].writer, test[i].company, test[i].genre, test[i].price, test[i].sales);
		//removeRow(test[i].code);

		if (strchr(test[i].title, '\n')) {
			for (int k = 1; k < strlen(test[i].title) + 1; k++) {
				test[i].title[k - 1] = test[i].title[k];
			}
		}
		i++;
	}
	fclose(fp);
	
	fp = fopen("inventory.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^\n]s", test2[q].title, test2[q].company, test2[q].stock);

		if (strchr(test2[q].title, '\n')) {
			for (int k = 1; k < strlen(test2[q].title) + 1; k++) {
				test2[q].title[k - 1] = test2[q].title[k];
			}
		}
		q++;
	}
	fclose(fp);
	map4();
	gotoxy(2, 1);
	printf("뒤로가기");
	gotoxy(78, 1);
	printf("종료");
	gotoxy(40, 2);
	printf("서원 서점");
	gotoxy(20, 3);
	printf("────────────────────────────────────────────────");
	gotoxy(10, 4);
	printf("검색:");
	gotoxy(8, 6);
	printf("%-18s %-13s %-13s %-10s %-7s %-8s", "제목", "저자", "출판사", "장르", "가격", "재고");

	for (int j = 0; j < i; j++) {
		gotoxy(3, y++);
		printf("%-18s %-16s %-14s %-10s %-9s %-7s", test[j].title, test[j].writer, test[j].company, test[j].genre, test[j].price, test2[j].stock);
	}
	gotoxy(44, 22);
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// 마우스 활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 78 && yy == 1) {
			gotoxy(78, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(33, 18);
			exit(0);
		}
		else if (x >= 2 && x<=10 && yy == 1) {
			gotoxy(2, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			Sleep(200);
			setting_book(id);
			break;
		}
		else if (x >= 10 && x <= 20 && yy == 4) {
			gotoxy(10, 4);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("검색:");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(16, 4);
			scanf("%s", search);
			for (int j = 0; j < i; j++) {
				if (strcmp(test[j].title, search) == 0) {
					index = j;
					break;
				}
			}
		}
	}
}
// 재고 관리 전 도서 입력 받기
void search_book3(char id[]) {
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;
	char title[30];

	map2();
	gotoxy(3, 20);
	printf("뒤로가기");
	gotoxy(45, 20);
	printf("확인");
	gotoxy(22, 3);
	printf("도서 검색");
	gotoxy(9, 4);
	printf("──────────────────────────────────");
	gotoxy(8, 10);
	printf("도서의 제목을 입력해주세요.");
	gotoxy(8, 12);
	printf("☞");
	gotoxy(11, 12);
	gets(title);
	gotoxy(13, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 10 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			setting_book(id);
			break;
		}
		else if (x >= 45 && yy == 20) {
			gotoxy(45, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("확인");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			setting_stock(id, title);
			break;
		}
	}
}
// 재고 관리
void setting_stock(char id[],char title[]) {
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;
	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("재고 관리");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(12, 10);
	printf("ㆍ 재고 조회");
	gotoxy(12, 14);
	printf("ㆍ 재고 수정");
	gotoxy(3, 20);
	printf("로그아웃");

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			mainscreen();
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(23, 22);
			exit(0);
			break;
		}
		else if (x >= 3 && x <= 15 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("로그아웃");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			mainscreen();
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 10) {
			gotoxy(12, 10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 재고 조회");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			look_stock(id,title);
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 14) {
			gotoxy(12, 14);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 재고 수정");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_stock(id,title);
			break;
		}
	}
}
// 재고 조회
void look_stock(char id[], char title[]) {
	FILE* fp;
	INVENTORY test[100];
	int i = 0, j = 0, index = 0;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;
	fp = fopen("inventory.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^\n]s", test[i].title, test[i].company, test[i].stock);

		if (strchr(test[i].title, '\n')) {
			for (int k = 1; k < strlen(test[i].title) + 1; k++) {
				test[i].title[k - 1] = test[i].title[k];
			}
		}
		i++;
	}
	fclose(fp);

	for (int j = 0; j < i; j++) {
		if (strcmp(test[j].title, title) == 0) {
			index = j;
			break;
		}
	}
	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("재고 조회");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(12, 10);
	printf("ㆍ 제목: %s", test[index].title);
	gotoxy(12, 14);
	printf("ㆍ 현재 재고 수: %s", test[index].stock);
	gotoxy(22, 18);
	printf("┌──────┐");
	gotoxy(22, 19);
	printf("│ 확 인│");
	gotoxy(22, 20);
	printf("└──────┘");

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			setting_stock(id,title);
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(23, 22);
			exit(0);
			break;
		}
		else if (x >= 22 && x <= 40 && yy >= 18 && yy <= 20) {
			gotoxy(22, 18);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("┌──────┐");
			gotoxy(22, 19);
			printf("│ 확 인│");
			gotoxy(22, 20);
			printf("└──────┘");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			setting_stock(id, title);
		}
	}
}
// 재고 수정
void change_stock(char id[], char title[]) {
	FILE* fp;
	INVENTORY test[100];
	char new_stock[20];
	int i = 0, j = 0, index = 0;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;
	fp = fopen("inventory.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^\n]s", test[i].title, test[i].company, test[i].stock);

		if (strchr(test[i].title, '\n')) {
			for (int k = 1; k < strlen(test[i].title) + 1; k++) {
				test[i].title[k - 1] = test[i].title[k];
			}
		}
		i++;
	}
	fclose(fp);

	for (int j = 0; j < i; j++) {
		if (strcmp(test[j].title, title) == 0) {
			index = j;
			break;
		}
	}
	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("재고 수정");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(12, 9);
	printf("ㆍ 제목: %s", test[index].title);
	gotoxy(12, 13);
	printf("ㆍ 현재 재고 수: %s", test[index].stock);
	gotoxy(12, 17);
	printf("ㆍ 실사 재고 수: ");
	gotoxy(45, 20);
	printf("확인");
	gotoxy(29, 17);
	scanf("%s", new_stock);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			setting_stock(id, title);
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(23, 22);
			exit(0);
			break;
		}
		else if (x >= 45 && yy <= 20) {
			gotoxy(45, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("확인");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			strcpy(test[index].stock, new_stock);
			fp = fopen("inventory.txt", "w");
			for (int j = 0; j < i; j++) {
				fprintf(fp, "%s,%s,%s\n", test[j].title, test[j].company,test[j].stock);
			}
			fclose(fp);
			map2();
			gotoxy(12, 10);
			printf("재고 수정이 완료되었습니다.");
			Sleep(3000);
			setting_stock(id, title);
		}
	}
}
// 매출 관리
void setting_total(char id[]) {
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;

	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("매출 관리");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(12, 10);
	printf("ㆍ 총 매출 확인");
	gotoxy(12, 14);
	printf("ㆍ 인기 도서 확인");
	gotoxy(3, 20);
	printf("로그아웃");

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			adminmenu(id);
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(23, 22);
			exit(0);
			break;
		}
		else if (x >= 3 && x <= 15 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("로그아웃");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			mainscreen();
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 10) {
			gotoxy(12, 10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 총 매출 확인");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			totalsales(id);
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 14) {
			gotoxy(12, 14);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 인기 도서 확인");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			popularbook(id);
			break;
		}
	}
}
// 총 매출 확인
void totalsales(char id[]) {
	FILE* fp;
	BUY test[SIZE];
	int total = 0;
	int i = 0;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;

	fp = fopen("buy.txt", "r");
	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]s", test[i].buy_date, test[i].ID, test[i].title, test[i].price);

		if (strchr(test[i].buy_date, '\n')) {
			for (int k = 1; k < strlen(test[i].buy_date) + 1; k++) {
				test[i].buy_date[k - 1] = test[i].buy_date[k];
			}
		}
		total += atoi(test[i].price);
		i++;
	}
	fclose(fp);

	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("매출 확인");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(14, 10);
	printf("서원 서점의 총 매출액은");
	gotoxy(18, 12);
	printf("%d 원입니다.", total);
	gotoxy(3, 20);
	printf("로그아웃");

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			setting_total(id);
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(23, 22);
			exit(0);
			break;
		}
		else if (x >= 3 && x <= 15 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("로그아웃");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			mainscreen();
			break;
		}
	}
}
void updateSales(BOOK books[], int* totalBooks, const char* title,char id[]) {
	FILE* fp;
	int i;
	int books_sales = 0;
	for (i = 0; i < *totalBooks; i++) {
		if (strcmp(books[i].title, title) == 0) {
			// 도서를 찾았으면 판매 횟수를 증가시킴
			books_sales += atoi(books[i].sales);              
			return;
		}
	}
}
void selectionSort(BOOK books[], int totalBooks,char id[]) {
	int i, j, maxIndex;
	BOOK temp;

	for (i = 0; i < totalBooks - 1; i++) {
		maxIndex = i;
		for (j = i + 1; j < totalBooks; j++) {
			if (books[j].sales > books[maxIndex].sales) {
				maxIndex = j;
			}
		}

		// 판매 횟수를 기준으로 내림차순 정렬
		temp = books[i];
		books[i] = books[maxIndex];
		books[maxIndex] = temp;
	}
}
void printRankedBooks(BOOK books[], int totalBooks,char id[]) {
	FILE* fp;
	BOOK test[100];
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0, y = 7, i = 0;

	fp = fopen("book.txt", "r");
	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].title, test[i].writer, test[i].company, test[i].genre, test[i].price, test[i].sales);

		if (strchr(test[i].title, '\n')) {
			for (int k = 1; k < strlen(test[i].title) + 1; k++) {
				test[i].title[k - 1] = test[i].title[k];
			}
		}
		i++;
	}
	fclose(fp);

	map4();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(78, 1);
	printf("종료");
	gotoxy(34, 2);
	printf("서원 서점 인기 도서");
	gotoxy(19, 3);
	printf("────────────────────────────────────────────────");
	gotoxy(4, 5);
	printf("%-11s %-18s %-10s %-13s %-10s %-7s", "순위", "제목", "저자", "출판사", "장르", "가격");

	for (int j = 0; j < i; j++) {
		gotoxy(4, y++);
		printf("%-11d %-18s %-10s %-13s %-10s %-7s", j + 1, books[j].title, books[j].writer, books[j].company, books[j].genre, books[j].price);
	}
	
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// 마우스 활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			setting_total(id);
		}
		else if (x >= 78 && yy == 1) {
			gotoxy(78, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			exit(0);
		}
	}
}
void processAllUsers(char id[]) {
	FILE* fp;
	BUY test[100];
	BOOK books[100];
	int i = 0;
	int totalBooks = 0;

	fp = fopen("buy.txt", "r");
	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%d", test[i].buy_date, test[i].ID, test[i].title, test[i].price, &test[i].sales);

		if (strchr(test[i].buy_date, '\n')) {
			for (int k = 1; k < strlen(test[i].buy_date) + 1; k++) {
				test[i].buy_date[k - 1] = test[i].buy_date[k];
			}
		}
		updateSales(books, &totalBooks, test[i].title,id);
		i++;
	}
	fclose(fp);

	// 도서를 판매 횟수의 내림차순으로 정렬
	selectionSort(books, totalBooks,id);


	map2();
	// 인기 도서 출력
	printRankedBooks(books, totalBooks,id);
	Sleep(5000);
}

void popularbook(char id[]) {
	processAllUsers(id);
}
// 회원 관리
void setting_user(char id[]) {
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;

	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("회원 관리");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(12, 10);
	printf("ㆍ 등록");
	gotoxy(12, 14);
	printf("ㆍ 조회 & 수정 & 삭제");
	gotoxy(3, 20);
	printf("로그아웃");
	

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			adminmenu(id);
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(23, 22);
			exit(0);
			break;
		}
		else if (x >= 3 && x <= 15 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("로그아웃");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			mainscreen();
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 10) {
			gotoxy(12, 10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 등록");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			new_user(id);
			break;
		}
		else if (x >= 12 && x <= 25 && yy == 14) {
			gotoxy(12, 14);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 조회 & 수정 & 삭제");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			search_user(id);
			break;
		}
	}
}
// 회원 등록
void new_user(char id[]) {
	FILE* fp;
	USER user;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;
	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(23, 2);
	printf("회원 등록");
	gotoxy(12, 3);
	printf("────────────────────────────");
	gotoxy(8, 5);
	printf("ID:");
	gotoxy(8, 8);
	printf("PW:");
	gotoxy(8, 11);
	printf("이름:");
	gotoxy(8, 14);
	printf("생년월일(6자리):");
	gotoxy(8, 17);
	printf("전화번호(숫자만):");
	gotoxy(20, 18);
	printf("┌────────────┐");
	gotoxy(20, 19);
	printf("│ 회 원 등 록│");
	gotoxy(20, 20);
	printf("└────────────┘");
	gotoxy(22, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// 마우스 활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 8 && yy == 5) {
			gotoxy(12, 5);
			scanf("%s", user.ID);
			gotoxy(12, 8);
			scanf("%s", user.PW);
			gotoxy(14, 11);
			scanf("%s", user.name);
			gotoxy(25, 14);
			scanf("%s", user.birth);
			gotoxy(26, 17);
			scanf("%s", user.phone);
			gotoxy(22, 22);
			while (1) {
				if (be_input())
				{
					if (get_input(&key, &pos) != 0)
					{
						MOUSE_EVENT;
						x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
						yy = pos.Y;
					}
				}
				if (x >= 20 && x <= 35 && yy >= 18 && yy <= 20) {
					gotoxy(20, 18);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("┌────────────┐");
					gotoxy(20, 19);
					printf("│ 회 원 등 록│");
					gotoxy(20, 20);
					printf("└────────────┘");
					Sleep(200);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					Sleep(200);
					fp = fopen("user.txt", "a");
					fprintf(fp, "\n%s,%s,%s,%s,%s", user.name, user.ID, user.PW, user.birth, user.phone);
					fclose(fp);
					map2();
					gotoxy(18, 10);
					printf("회원 등록 완료!");
					gotoxy(22, 22);
					Sleep(2000);
					setting_user(id);
					break;
				}
				else if (x >= 3 && x <= 10 && yy == 1) {
					gotoxy(3, 1);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("뒤로가기");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					Sleep(200);
					adminmenu(id);
					break;
				}
				else if (x >= 45 && yy == 1) {
					gotoxy(45, 1);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("종료");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					Sleep(200);
					gotoxy(33, 22);
					exit(0);
					break;
				}
			}
		}
	}
}
// 회원 검색
void search_user(char id[]) {
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;
	char info[30];

	map2();
	gotoxy(3, 20);
	printf("뒤로가기");
	gotoxy(45, 20);
	printf("확인");
	gotoxy(22, 3);
	printf("회원 검색");
	gotoxy(9, 4);
	printf("──────────────────────────────────");
	gotoxy(8, 10);
	printf("조회하실 회원의 정보를 입력해주세요.");
	gotoxy(8, 12);
	printf("☞");
	gotoxy(11, 12);
	scanf("%s", info);
	gotoxy(13, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 10 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			setting_user(id);
			break;
		}
		else if (x >= 45 && yy == 20) {
			gotoxy(45, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("확인");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			look_user(id, info);
			break;
		}
	}
}
// 회원 조회
void look_user(char id[], char info[]) {
	FILE* fp;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0,i = 0, j = 0, index = 0;
	USER test[100];

	fp = fopen("user.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].name, test[i].ID, test[i].PW, test[i].birth, test[i].phone);
		//removeRow(test[i].ID);
		if (strchr(test[i].name, '\n')) {
			for (int k = 1; k < strlen(test[i].name) + 1; k++) {
				test[i].name[k - 1] = test[i].name[k];
			}
		}
		i++;
	}
	fclose(fp);

	for (int j = 0; j < i; j++) {
		if (strcmp(test[j].name, info) == 0 || strcmp(test[j].ID, info) == 0 || strcmp(test[j].birth, info) == 0 || strcmp(test[j].phone, info) == 0)  {
			index = j;
			break;
		}
	}

	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("회원 정보");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(3, 20);
	printf("수정");
	gotoxy(45, 20);
	printf("삭제");
	gotoxy(8, 5);
	printf("ID: %s", test[index].ID);
	gotoxy(8, 8);
	printf("PW: %s", test[index].PW);
	gotoxy(8, 11);
	printf("이름: %s", test[index].name);
	gotoxy(8, 14);
	printf("생년월일(6자리): %s", test[index].birth);
	gotoxy(8, 17);
	printf("전화번호: %s", test[index].phone);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 7 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			setting_user(id);
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(23, 22);
			exit(0);
			break;
		}
		else if (x >= 3 && x <= 10 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("수정");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_user(info);
			break;
		}
		else if (x >= 45 && yy == 20) {
			gotoxy(45, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("삭제");
			Sleep(200);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			delete_user(id, info);
			break;
		}
	}
}
// 회원 수정
void setting_user2(char id[], char info[]) {
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0;

	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(22, 3);
	printf("정보 수정");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(3, 20);
	printf("로그아웃");
	gotoxy(10, 9);
	printf("ㆍ 비밀번호 변경");
	gotoxy(10, 13);
	printf("ㆍ 전화번호 변경");

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 3 && x <= 10 && yy == 1) {
			gotoxy(3, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("뒤로가기");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			look_user(id,info);
			break;
		}
		else if (x >= 45 && yy == 1) {
			gotoxy(45, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("종료");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			exit(0);
			break;
		}
		else if (x >= 3 && x <= 15 && yy == 20) {
			gotoxy(3, 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("로그아웃");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			mainscreen();
			break;
		}
		else if (x >= 10 && x <= 30 && yy == 9) {
			gotoxy(10, 9);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 비밀번호 변경");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_PW(info);
			break;
		}
		else if (x >= 10 && x <= 30 && yy == 13) {
			gotoxy(10, 13);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("ㆍ 전화번호 변경");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			change_phone(info);
			break;
		}
	}
}
// 회원 삭제
void delete_user(char id[], char info[]) {
	FILE* fp;
	DWORD mode;
	WORD key;
	COORD pos;
	int event, x = 0, yy = 0, i = 0, j = 0, index = 0;
	USER test[100];

	fp = fopen("user.txt", "r");

	while (1) {
		if (feof(fp))
			break;
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].name, test[i].ID, test[i].PW, test[i].birth, test[i].phone);
		//removeRow(test[i].ID);
		if (strchr(test[i].name, '\n')) {
			for (int k = 1; k < strlen(test[i].name) + 1; k++) {
				test[i].name[k - 1] = test[i].name[k];
			}
		}
		i++;
	}
	fclose(fp);

	for (int j = 0; j < i; j++) {
		if (strcmp(test[j].name, info) == 0 || strcmp(test[j].ID, info) == 0 || strcmp(test[j].birth, info) == 0 || strcmp(test[j].phone, info) == 0) {
			index = j;
			break;
		}
	}
	map2();
	gotoxy(3, 1);
	printf("뒤로가기");
	gotoxy(45, 1);
	printf("종료");
	gotoxy(21, 3);
	printf("회원 삭제");
	gotoxy(10, 4);
	printf("────────────────────────────────");
	gotoxy(15, 10);
	printf("정말 삭제하시겠습니까?");
	gotoxy(13, 13);
	printf("┌─────┐");
	gotoxy(13, 14);
	printf("│  예 │");
	gotoxy(13, 15);
	printf("└─────┘");
	gotoxy(28, 13);
	printf("┌─────────┐");
	gotoxy(28, 14);
	printf("│  아니오 │");
	gotoxy(28, 15);
	printf("└─────────┘");
	gotoxy(22, 22);

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		if (be_input())
		{
			if (get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				yy = pos.Y;
			}
		}
		if (x >= 13 && x <= 24 && yy >= 13 && yy <= 15) {
			gotoxy(13, 13);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("┌─────┐");
			gotoxy(13, 14);
			printf("│  예 │");
			gotoxy(13, 15);
			printf("└─────┘");
			Sleep(300);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			fp = fopen("user.txt", "w");

			for (j = 0; j < index; j++) {
				fprintf(fp, "%s,%s,%s,%s,%s", test[j].name, test[j].ID, test[j].PW, test[j].birth, test[j].phone);
			}
			fclose(fp);

			fp = fopen("user.txt", "a");

			for (j = index + 1; j < i; j++) {
				fprintf(fp, "%s,%s,%s,%s,%s", test[j].name, test[j].ID, test[j].PW, test[j].birth, test[j].phone);
			}
			fclose(fp);
			map2();
			gotoxy(15, 10);
			printf("삭제가 완료되었습니다.");
			Sleep(2000);
			setting_book(id);
			break;
		}
		else if (x >= 28 && x <= 43 && yy >= 13 && yy <= 15) {
			gotoxy(28, 13);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("┌─────────┐");
			gotoxy(28, 14);
			printf("│  아니오 │");
			gotoxy(28, 15);
			printf("└─────────┘");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			map2();
			gotoxy(15, 10);
			printf("삭제가 취소되었습니다.");
			Sleep(2000);
			setting_book(id);
			break;
		}
	}
}
int main() {
	mainscreen();
}