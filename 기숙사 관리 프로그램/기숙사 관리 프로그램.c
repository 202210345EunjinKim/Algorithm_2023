#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>

typedef struct {
    char st_id[20];
    char name[30];
    char PW[20];
    char birth[20];
    char region[50];
    char score[20];
} USER; // 餌辨濠 薑爾

typedef struct {
    char st_id[20];
    char name[30];
    char region[50];
    char room[10];
} ROOM; // 寞 薑爾

typedef struct {
    char region[50];
    int distance;
} REGION; // 雖羲 剪葬 薑爾

typedef struct {
    char st_id[20];
    char name[30];
    char region[50];
    char score[20];
}APPLY; // 褐羶 з儅 薑爾

// 薑溺 晦棟
int find(REGION* region, APPLY* user1);
void swap_user(APPLY* user1, APPLY* user2);
int partition(APPLY* arr, int low, int high, REGION* region);
void quickSort(APPLY* arr, int low, int high, REGION* region);


void gotoxy();
void map();
void map2(); // 裘 纔舒葬
void basic(); // 詭檣�飛�
void login(); // 煎斜檣
void new_login_check(); // з廓 醞犒�挫�
void new_login(char st_id[]); // �蛾灠㊣�

void student_menu(char st_id[]); // з儅 詭景
void apply_dorm(char st_id[]); // з儅ver. 晦熨餌 褐羶
void apply_student_roommate_search(char st_id[]); // з儅ver. 瑛詭檜お 匐儀
void apply_student_roommate(char st_id[], char roommate_st_id[]); // з儅ver. 瑛詭檜お 褐羶
void look_student_room(char st_id[]); // з儅ver. 寞寡薑 褻��
void look_student(char st_id[]); // з儅ver. 薑爾 �挫�
void change_student(char st_id[]); // з儅ver. 薑爾 熱薑
void change_student_name(char st_id[]); // з儅ver. 熱薑_檜葷
void change_student_PW(char st_id[]); // з儅ver. 熱薑_綠塵廓��
void change_student_region(char st_id[]); // з儅ver. 熱薑_雖羲
void change_student_score(char st_id[]); // з儅ver. 熱薑_з薄

void manager_menu(char st_id[]); // 婦葬濠 詭景
void look_manager_ApplicationList(char st_id); // 婦葬濠ver. 褐羶 貲欽 褻�� (apply.txt)
void manager_assignroom(char st_id[]); // 婦葬濠ver. 寞寡薑 晦棟
void look_manager_room(char st_id[]); // 婦葬濠ver. 瞪羹 貲欽 褻�� (room.txt)
void search_student(); // 婦葬濠ver. з儅 匐儀
void look_student2(char st_id[]); // 婦葬濠ver. 薑爾 �挫�
void change_student2(char st_id[]); // 婦葬濠ver. 薑爾 熱薑
void change_student_name2(char st_id[]); // 婦葬濠ver. 熱薑_檜葷
void change_student_PW2(char st_id[]); // 婦葬濠ver. 熱薑_綠塵廓��
void change_student_region2(char st_id[]); // 婦葬濠ver. 熱薑_雖羲
void change_student_score2(char st_id[]); // 婦葬濠ver. 熱薑_з薄
void delete_student(char st_id[]); // 餉薯
void removeRow(char* a);
void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 裘 纔舒葬
void map() {
    system("cls");
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收汕\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("汝收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收汙\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收汛\n");
}
void map2() {
    system("cls");
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收汕\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("汝收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收汙\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("弛                                                        弛\n");
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收汛\n");

}
// 詭檣�飛�
void basic()
{
    int choice;
    map();
    gotoxy(19, 3);
    printf("忙式式式式式式式式式式式式式式式式式式式式忖");
    gotoxy(19, 4);
    printf("弛   晦熨餌 Щ煎斜極  弛");
    gotoxy(19, 5);
    printf("戌式式式式式式式式式式式式式式式式式式式式戎");
    gotoxy(20, 8);
    printf("1. 煎斜檣");
    gotoxy(20, 11);
    printf("2. �蛾灠㊣�");
    gotoxy(20, 14);
    printf("3. 謙猿");
    gotoxy(9, 19);
    printf(" 詭景 廓�ㄧ� 殮溘ж撮蹂: ");
    gotoxy(34, 19);
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        login();
    case 2:
        new_login_check();
    case 3:
        exit(1);
    default:
        gotoxy(2, 19);
        printf("                                              ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        basic();
    }
}
// 煎斜檣
void login() {
    FILE* fp;
    USER user[100];
    char test_id[20];
    char test_pw[20];
    int i = 0, j;
    int choice = 0;

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", user[i].st_id, user[i].name, user[i].PW, user[i].birth, user[i].region, user[i].score);
        //removeRow(test[i].ID);
        if (strchr(user[i].st_id, '\n')) {
            for (int k = 1; k < strlen(user[i].st_id) + 1; k++) {
                user[i].st_id[k - 1] = user[i].st_id[k];
            }
        }
        i++;

    }
    fclose(fp);

    map();
    gotoxy(19, 3);
    printf("忙式式式式式式式式式式式式式式式式式忖");
    gotoxy(19, 4);
    printf("弛   煎   斜   檣  弛");
    gotoxy(19, 5);
    printf("戌式式式式式式式式式式式式式式式式式戎");
    gotoxy(12, 9);
    printf("з廓 : ");
    gotoxy(12, 13);
    printf("PW : ");
    gotoxy(19, 9);
    scanf("%s", test_id);
    gotoxy(17, 13);
    scanf("%s", test_pw);

    for (j = 0; j < i; j++) {
        // з儅 煎斜檣
        if ((strcmp(user[j].st_id, test_id) == 0)) {
            if ((strcmp(user[j].PW, test_pw) == 0)) {
                map();
                gotoxy(22, 9);
                printf("煎斜檣 諫猿!");
                Sleep(1000);
                student_menu(test_id);
            }
            else if ((strcmp(user[j].PW, test_pw) != 0)) {
                map();
                gotoxy(11, 9);
                printf("殮溘ж褐 綠塵廓�ㄟ� 橾纂ж雖 彊蝗棲棻.");
                Sleep(3000);
                login();
            }
        }
        // 婦葬濠 煎斜檣
        if (strcmp("123456789", test_id) == 0) {
            if (strcmp("1111", test_pw) == 0) {
                map();
                gotoxy(22, 9);
                printf("煎斜檣 諫猿!");
                Sleep(1000);
                manager_menu(test_id);
            }
        }
    }

    map();
    gotoxy(18, 9);
    printf("蛔煙脹 薑爾陛 橈蝗棲棻.");
    gotoxy(4, 19);
    printf("�蛾灠㊣埬� 霞чж衛啊蝗棲梱? (0. 菴煎陛晦, 1. 蕨): ");
    gotoxy(55, 19);
    scanf("%d", &choice);

    switch (choice) {
    case 0:
        basic();
    case 1:
        new_login_check();
    }

}
// з廓 醞犒�挫�
void new_login_check() {
    FILE* fp;
    USER test[100];
    char st_id[20];
    int choice = 0, i = 0, j;
    char new_st_id[30];

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].PW, test[i].birth, test[i].region, test[i].score);
        //removeRow(test[i].ID);
        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    map();
    gotoxy(14, 2);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 3);
    printf("弛         �� 錳 陛 殮       弛\n");
    gotoxy(14, 4);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(14, 9);
    printf(" з廓擊 殮溘п輿撮蹂. ");
    gotoxy(14, 11);
    printf(" Ｃ ");
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦, 1. �挫�): ");
    gotoxy(19, 11);
    scanf("%s", new_st_id);
    gotoxy(52, 19);
    scanf("%d", &choice);

    switch (choice) {
    case 0:
        basic();
    case 1:
        for (j = 0; j < i; j++) {
            if (strcmp(test[j].st_id, new_st_id) == 0) {
                map();
                gotoxy(20, 9);
                printf("醞犒脹 з廓殮棲棻.");
                gotoxy(16, 11);
                printf("棻艇 з廓擊 殮溘п輿撮蹂.");
                Sleep(3000);
                new_login_check();
            }
        }
        map();
        gotoxy(17, 9);
        printf("餌辨 陛棟и з廓殮棲棻.");
        Sleep(3000);
        new_login(new_st_id);
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        new_login_check();
    }
}
// �蛾灠㊣�
void new_login(char st_id[]) {
    FILE* fp;
    USER user;
    int choice = 0;

    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛        �� 錳 陛 殮        弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(14, 5);
    printf(" з廓: %s", st_id);
    gotoxy(14, 7);
    printf(" 檜葷: ");
    gotoxy(14, 9);
    printf(" 綠塵廓��: ");
    gotoxy(14, 11);
    printf(" 儅喇錯橾: ");
    gotoxy(14, 13);
    printf(" 雖羲: ");
    gotoxy(14, 15);
    printf(" з薄: ");
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦, 1. �挫�): ");
    gotoxy(21, 7);
    scanf("%s", user.name);
    gotoxy(25, 9);
    scanf("%s", user.PW);
    gotoxy(25, 11);
    scanf("%s%*c", user.birth);
    gotoxy(21, 13);
    gets(user.region);
    gotoxy(21, 15);
    scanf("%s", user.score);
    gotoxy(52, 19);
    scanf("%d", &choice);

    switch (choice) {
    case 0:
        new_login_check();
    case 1:
        fp = fopen("user.txt", "a");
        fprintf(fp, "\n%s,%s,%s,%s,%s,%s", st_id, user.name, user.PW, user.birth, user.region, user.score);
        fclose(fp);
        gotoxy(2, 19);
        printf("                                                      ");
        gotoxy(9, 19);
        printf("�蛾灠㊣埬� 諫猿腎歷蝗棲棻.");
        Sleep(3000);
        basic();
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        new_login(st_id);
    }
}
// з儅 詭景
void student_menu(char st_id[]) {

    int choice = 0;
    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛        з 儅 詭 景        弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(14, 6);
    printf(" 1. 晦熨餌 褐羶 ");
    gotoxy(14, 10);
    printf(" 2. 寞 寡薑 褻�� ");
    gotoxy(14, 14);
    printf(" 3. з儅 薑爾 熱薑 ");
    gotoxy(6, 19);
    printf(" 詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 給嬴陛晦): ");
    gotoxy(46, 19);
    scanf("%d", &choice);

    switch (choice) {
    case 0:
        basic();
    case 1:
        apply_dorm(st_id);
    case 2:
        look_student_room(st_id);
    case 3:
        look_student(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                       ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        student_menu(st_id);
    }
}
// з儅ver. 晦熨餌 褐羶
void apply_dorm(char st_id[]) {
    FILE* fp;
    USER test[100];
    APPLY test2[100];
    int choice = 0;
    int i = 0, j = 0, index = 0, w = 0;

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].PW, test[i].birth, test[i].region, test[i].score);
        // removeRow(test[i].st_id);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    for (int j = 0; j < i; j++) {
        if (strcmp(test[j].st_id, st_id) == 0) {
            index = j;
            break;
        }
    }
    map();
    gotoxy(17, 8);
    printf("晦熨餌蒂 褐羶ж衛啊蝗棲梱?");
    gotoxy(14, 10);
    printf("忙式式式式式式式式式式式式忖");
    gotoxy(14, 11);
    printf("弛    1. 蕨   弛");
    gotoxy(14, 12);
    printf("戌式式式式式式式式式式式式戎");
    gotoxy(29, 10);
    printf("忙式式式式式式式式式式式式忖");
    gotoxy(29, 11);
    printf("弛  2. 嬴棲螃 弛");
    gotoxy(29, 12);
    printf("戌式式式式式式式式式式式式戎");
    gotoxy(9, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂:");
    gotoxy(34, 19);
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        fp = fopen("apply.txt", "r");
        while (1) {
            if (feof(fp))
                break;
            fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]s", test2[i].st_id, test2[i].name, test2[i].region, test2[i].score);
            // removeRow(test[i].st_id);

            if (strchr(test2[i].st_id, '\n')) {
                for (int k = 1; k < strlen(test2[i].st_id) + 1; k++) {
                    test2[i].st_id[k - 1] = test2[i].st_id[k];
                }
            }
            i++;
        }
        fclose(fp);
        for (w = 0; w < i; w++) {
            fp = fopen("apply.txt", "r");
            if (strcmp(test2[w].st_id, st_id) == 0) {
                fclose(fp);
                gotoxy(2, 19);
                printf("                                                      ");
                gotoxy(11, 19);
                printf("檜嘐 褐羶擊 ж樟蝗棲棻.");
                Sleep(3000);
                gotoxy(2, 19);
                printf("                                                      ");
                gotoxy(5, 19);
                printf("瑛詭檜お蒂 褐羶ж衛啊蝗棲梱? (0. 嬴棲螃, 1. 蕨): ");
                scanf("%d", &choice);

                switch (choice) {
                case 0:
                    student_menu(st_id);
                case 1:
                    apply_student_roommate_search(st_id);
                default:
                    gotoxy(2, 19);
                    printf("                                                       ");
                    gotoxy(5, 19);
                    printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
                    Sleep(3000);
                    apply_dorm(st_id);
                }
            }
        }
        fp = fopen("apply.txt", "a");
        fprintf(fp, "\n%s,%s,%s,%s", st_id, test[index].name, test[index].region, test[index].score);
        fclose(fp);
        gotoxy(2, 19);
        printf("                                                      ");
        gotoxy(11, 19);
        printf("晦熨餌 褐羶檜 諫猿腎歷蝗棲棻.");
        Sleep(3000);
        gotoxy(2, 19);
        printf("                                                      ");
        gotoxy(5, 19);
        printf("瑛詭檜お蒂 褐羶ж衛啊蝗棲梱? (0. 嬴棲螃, 1. 蕨): ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            student_menu(st_id);
        case 1:
            apply_student_roommate_search(st_id);
        default:
            gotoxy(2, 19);
            printf("                                                       ");
            gotoxy(5, 19);
            printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
            Sleep(3000);
            apply_dorm(st_id);
        }
    case 2:
        student_menu(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                       ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        apply_dorm(st_id);
    }

}
// з儅ver. 瑛詭檜お 匐儀
void apply_student_roommate_search(char st_id[]) {
    FILE* fp;
    APPLY roommate[100];
    USER test[100];
    char roommate_st_id[20];
    int choice = 0;
    int i = 0, w = 0, ind = 0;

    // 瑛詭檜お 渠鼻
    fp = fopen("apply.txt", "r");
    while (fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]\n", roommate[i].st_id, roommate[i].name, roommate[i].region, roommate[i].score) != EOF) {
        i++;
    }
    fclose(fp);

    // 檜葷 轎溘
    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[w].st_id, test[w].name, test[w].PW, test[w].birth, test[w].region, test[w].score);
        // removeRow(test[i].st_id);

        if (strchr(test[w].st_id, '\n')) {
            for (int k = 1; k < strlen(test[w].st_id) + 1; k++) {
                test[w].st_id[k - 1] = test[w].st_id[k];
            }
        }
        w++;
    }
    fclose(fp);



    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛        瑛 詭 褐 羶        弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(9, 9);
    printf("錳ж衛朝 瑛詭檜お曖 з廓擊 殮溘п 輿撮蹂.");
    gotoxy(9, 11);
    printf("Ｃ ");
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦 1. �挫�): ");
    gotoxy(13, 11);
    scanf("%s", roommate_st_id);
    gotoxy(52, 19);
    scanf("%d", &choice);

    for (int j = 0; j < w; j++) {
        if (strcmp(test[j].st_id, roommate_st_id) == 0) {
            ind = j;
            break;
        }
    }


    switch (choice) {
    case 0:
        student_menu(st_id);
    case 1:
        map();
        gotoxy(14, 9);
        printf("%s椒擊 瑛詭檜お煎 褐羶м棲棻.", test[ind].name);
        gotoxy(5, 19);
        printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦 1. �挫�): ");
        gotoxy(52, 19);
        scanf("%d", &choice);

        if (choice == 0) {
            student_menu(st_id);
        }
        else if (choice == 1) {
            for (int j = 0; j < i; j++) {
                if (strcmp(roommate[j].st_id, roommate_st_id) == 0) {
                    apply_student_roommate(st_id, roommate_st_id);
                }
            }
            gotoxy(2, 19);
            printf("                                                    ");
            gotoxy(6, 19);
            printf("%s椒擎 晦熨餌 褐羶檜 腎橫氈雖 彊蝗棲棻.", test[ind].name);
            Sleep(3000);
            apply_student_roommate_search(st_id);

        }
        else {
            gotoxy(2, 19);
            printf("                                                    ");
            gotoxy(5, 19);
            printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
            Sleep(3000);
            apply_student_roommate_search(st_id);
        }
    default:
        gotoxy(2, 19);
        printf("                                                       ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        apply_student_roommate_search;
    }
}
// з儅ver. 瑛詭檜お 褐羶 晦棟
void apply_student_roommate(char st_id[], char roommate_st_id[]) {
    FILE* fp;
    USER test[100];
    APPLY applyList[100];
    APPLY roommate[100];
    ROOM roomList[100];
    int i = 0, j = 0, w = 0, u = 0, m = 0, index = 0, ind = 0, choice = 0, length = 0, first_index = 0, second_index = 0, roomnumber = 0;
    char roomnumber2[20];

    // 褐羶濠
    fp = fopen("apply.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]s", applyList[u].st_id, applyList[u].name, applyList[u].region, applyList[u].score);

        if (strchr(applyList[u].st_id, '\n')) {
            for (int k = 1; k < strlen(applyList[u].st_id) + 1; k++) {
                applyList[u].st_id[k - 1] = applyList[u].st_id[k];
            }
        }
        u++;
    }
    fclose(fp);

    // 瑛詭檜お 渠鼻
    fp = fopen("apply.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]s", roommate[m].st_id, roommate[m].name, roommate[m].region, roommate[m].score);

        if (strchr(roommate[m].st_id, '\n')) {
            for (int k = 1; k < strlen(roommate[m].st_id) + 1; k++) {
                roommate[m].st_id[k - 1] = roommate[m].st_id[k];
            }
        }
        m++;
    }
    fclose(fp);


    // 檜葷 轎溘
    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[w].st_id, test[w].name, test[w].PW, test[w].birth, test[w].region, test[w].score);
        // removeRow(test[i].st_id);

        if (strchr(test[w].st_id, '\n')) {
            for (int k = 1; k < strlen(test[w].st_id) + 1; k++) {
                test[w].st_id[k - 1] = test[w].st_id[k];
            }
        }
        w++;
    }
    fclose(fp);

    // user.txt縑憮 瑛詭檜お 檜葷 瓊晦
    for (int j = 0; j < w; j++) {
        if (strcmp(test[j].st_id, roommate_st_id) == 0) {
            ind = j;
            break;
        }
    }
    // 褐羶 貲欽縑憮 瑛詭檜お 瓊晦
    for (j = 0; j < m; j++) {
        if (strcmp(roommate[j].st_id, roommate_st_id) == 0) {
            index = j;
            break;
        }
    }

    // 瑛詭檜お 褐羶 褒ぬ (瑛詭檜お陛 檜嘐 寞 寡薑檜 腎橫氈朝 唳辦)
    // room.txt縑憮 瑛詭檜お 瓊晦
    fp = fopen("room.txt", "r");
    i = 0;
    while (fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]\n", roomList[i].st_id, roomList[i].name, roomList[i].region, roomList[i].room) != EOF) {
        i++;
    }
    fclose(fp);

    length = i;

    for (j = 0; j < i; j++) {
        if (strcmp(roomList[j].st_id, roommate_st_id) == 0) {
            map();
            gotoxy(14, 9);
            printf("%s椒擊 瑛詭檜お煎 褐羶м棲棻.", test[ind].name);
            gotoxy(6, 19);
            printf("%s椒擎 檜嘐 寞 寡薑檜 腎橫氈蝗棲棻.", test[ind].name);
            Sleep(3000);
            apply_student_roommate_search(st_id);
        }
    }
    // 瑛詭檜お 撩奢
    // 寞 寡薑

    // apply.txt縑憮 褐羶濠 嬪纂 �挫�
    for (j = 0; j < u; j++) {
        if (strcmp(applyList[j].st_id, st_id) == 0) {
            first_index = j;
            break;
        }
    }

    // apply.txt縑憮 瑛詭檜お 嬪纂 �挫�
    for (j = 0; j < m; j++) {
        if (strcmp(roommate[j].st_id, roommate_st_id) == 0) {
            second_index = j;
            break;
        }
    }

    roomnumber = (length / 2) + 100;


    fp = fopen("room.txt", "a");
    fprintf(fp, "\n%s,%s,%s,%d", applyList[first_index].st_id, applyList[first_index].name, applyList[first_index].region, roomnumber + 1);
    fprintf(fp, "\n%s,%s,%s,%d", roommate[second_index].st_id, roommate[second_index].name, roommate[second_index].region, roomnumber + 1);
    fclose(fp);

    i = 0;

    fp = fopen("room.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]s", roomList[i].st_id, roomList[i].name, roomList[i].region, roomList[i].room);

        if (strchr(roomList[i].st_id, '\n')) {
            for (int k = 1; k < strlen(roomList[i].st_id) + 1; k++) {
                roomList[i].st_id[k - 1] = roomList[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    for (j = 0; j < i; j++) {
        if (strcmp(roomList[j].st_id, st_id) == 0) {
            index = j;
            break;
        }
    }
    for (j = 0; j < i; j++) {
        if (strcmp(roomList[j].st_id, roommate_st_id) == 0) {
            ind = j;
            break;
        }
    }


    map();
    gotoxy(21, 8);
    printf("瑛詭檜お 褐羶 諫猿!");
    gotoxy(14, 10);
    printf("%s椒婁 %s椒擎 %s��殮棲棻.", roomList[index].name, roomList[ind].name, roomList[index].room);
    Sleep(3000);
    student_menu(st_id);
}
// з儅ver. 寞寡薑 褻��                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
void look_student_room(char st_id[]) {
    FILE* fp;
    ROOM test[100];
    int i = 0, j = 0, index = -1;
    int choice = 0;

    fp = fopen("room.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]\n", test[i].st_id, test[i].name, test[i].region, test[i].room);
        // removeRow(test[i].st_id);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    for (int j = 0; j < i; j++) {
        if (strcmp(test[j].st_id, st_id) == 0) {
            map();
            gotoxy(15, 9);
            printf("%s椒曖 寞擎 %s��殮棲棻.", test[j].name, test[j].room);
            gotoxy(6, 19);
            printf(" 詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 給嬴陛晦): ");
            gotoxy(46, 19);
            scanf("%d", &choice);

            switch (choice) {
            case 0:
                student_menu(st_id);
            default:
                gotoxy(2, 19);
                printf("                                                    ");
                gotoxy(5, 19);
                printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
                Sleep(3000);
                look_student_room(st_id);
            }
        }
    }
    map();
    gotoxy(13, 8);
    printf("嬴霜 晦熨餌 褐羶擊 ж雖 彊戲樟剪釭,");
    gotoxy(16, 10);
    printf("寞 寡薑檜 腎橫氈雖 彊蝗棲棻.");
    Sleep(3000);
    student_menu(st_id);
}
// з儅ver. 薑爾 �挫�
void look_student(char st_id[]) {
    FILE* fp;
    USER test[100];
    int choose = 0;
    int i = 0, j = 0, index = 0;

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].PW, test[i].birth, test[i].region, test[i].score);
        removeRow(test[i].st_id);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    for (int j = 0; j < i; j++) {
        if (strcmp(test[j].st_id, st_id) == 0) {
            index = j;
            break;
        }
    }

    map();
    gotoxy(19, 1);
    printf("旨收收收收收收收收收收收收收收收收收收收收旬");
    gotoxy(19, 2);
    printf("早  з 儅 薑 爾 �� 檣 早");
    gotoxy(19, 3);
    printf("曲收收收收收收收收收收收收收收收收收收收收旭");
    gotoxy(20, 5);
    printf("з廓: %s", test[index].st_id);
    gotoxy(20, 7);
    printf("檜葷: %s", test[index].name);
    gotoxy(20, 9);
    printf("綠塵廓��: %s", test[index].PW);
    gotoxy(20, 11);
    printf("儅喇錯橾: %s", test[index].birth);
    gotoxy(20, 13);
    printf("雖羲: %s", test[index].region);
    gotoxy(20, 15);
    printf("з薄: %s", test[index].score);
    gotoxy(5, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦 1. 熱薑): ");
    gotoxy(52, 19);
    scanf("%d", &choose);

    switch (choose) {
    case 0:
        student_menu(st_id);
    case 1:
        change_student(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                       ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        look_student(st_id);
    }
}
// з儅ver. 薑爾 熱薑 詭景
void change_student(char st_id[]) {
    int choice = 0;
    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛        薑 爾 熱 薑        弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(15, 5);
    printf("1. 檜葷");
    gotoxy(15, 8);
    printf("2. 綠塵廓��");
    gotoxy(15, 11);
    printf("3. 雖羲");
    gotoxy(15, 14);
    printf("4. з薄");
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦, 5. 諫猿): ");
    gotoxy(52, 19);
    scanf("%d%*c", &choice);

    switch (choice) {
    case 0:
        look_student(st_id);
    case 1:
        change_student_name(st_id);
    case 2:
        change_student_PW(st_id);
    case 3:
        change_student_region(st_id);
    case 4:
        change_student_score(st_id);
    case 5:
        map();
        gotoxy(22, 9);
        printf("薑爾 熱薑 諫猿");
        Sleep(2000);
        student_menu(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        change_student(st_id);
    }
}
// з儅ver . 熱薑 й 檜葷
void change_student_name(char st_id[]) {
    FILE* fp;
    USER test[100];
    int choose = 0;
    char new_name[100];
    int i = 0, j = 0, index = 0;

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].PW, test[i].birth, test[i].region, test[i].score);
        removeRow(test[i].st_id);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    for (int j = 0; j < i; j++) {
        if (strcmp(test[j].st_id, st_id) == 0) {
            index = j;
            break;
        }
    }

    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛        薑 爾 熱 薑        弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(14, 9);
    printf("億煎遴 檜葷擊 殮溘п 輿撮蹂.");
    gotoxy(14, 11);
    printf("Ｃ ");
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦 1. �挫�): ");
    gotoxy(18, 11);
    scanf("%s", new_name);
    gotoxy(52, 19);
    scanf("%d", &choose);

    switch (choose) {
    case 0:
        change_student(st_id);
    case 1:
        strcpy(test[index].name, new_name);
        fp = fopen("user.txt", "w");
        for (int j = 0; j < i; j++) {
            fprintf(fp, "\n%s,%s,%s,%s,%s,%s", test[j].st_id, test[j].name, test[j].PW, test[j].birth, test[j].region, test[j].score);
        }
        fclose(fp);
        change_student(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        change_student_name(st_id);
    }

}
// з儅ver . 熱薑 й 綠塵廓��
void change_student_PW(char st_id[]) {
    FILE* fp;
    USER test[100];
    int choose = 0;
    char new_PW[100];
    int i = 0, j = 0, index = 0;

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].PW, test[i].birth, test[i].region, test[i].score);
        removeRow(test[i].st_id);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    for (int j = 0; j < i; j++) {
        if (strcmp(test[j].st_id, st_id) == 0) {
            index = j;
            break;
        }
    }

    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛        薑 爾 熱 薑        弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(13, 9);
    printf("億煎遴 綠塵廓�ㄧ� 殮溘п 輿撮蹂.");
    gotoxy(13, 11);
    printf("Ｃ ");
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦 1. �挫�): ");
    gotoxy(17, 11);
    scanf("%s", new_PW);
    gotoxy(52, 19);
    scanf("%d", &choose);

    switch (choose) {
    case 0:
        change_student(st_id);
    case 1:
        strcpy(test[index].PW, new_PW);
        fp = fopen("user.txt", "w");
        for (int j = 0; j < i; j++) {
            fprintf(fp, "\n%s,%s,%s,%s,%s,%s", test[j].st_id, test[j].name, test[j].PW, test[j].birth, test[j].region, test[j].score);
        }
        fclose(fp);
        change_student(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        change_student_PW(st_id);
    }
}
// з儅ver . 熱薑 й 雖羲
void change_student_region(char st_id[]) {
    FILE* fp;
    USER test[100];
    int choose = 0;
    char new_region[100];
    int i = 0, j = 0, index = 0;

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].PW, test[i].birth, test[i].region, test[i].score);
        removeRow(test[i].st_id);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛        薑 爾 熱 薑        弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(14, 9);
    printf("億煎遴 雖羲擊 殮溘п 輿撮蹂.");
    gotoxy(14, 11);
    printf("Ｃ ");
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦 1. �挫�): ");
    gotoxy(18, 11);
    gets(new_region);
    gotoxy(52, 19);
    scanf("%d", &choose);

    switch (choose) {
    case 0:
        change_student(st_id);
    case 1:
        strcpy(test[index].region, new_region);
        fp = fopen("user.txt", "w");
        for (int j = 0; j < i; j++) {
            fprintf(fp, "\n%s,%s,%s,%s,%s,%s", test[j].st_id, test[j].name, test[j].PW, test[j].birth, test[j].region, test[j].score);
        }
        fclose(fp);
        change_student(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        change_student_region(st_id);
    }

}
// з儅ver . 熱薑 й з薄
void change_student_score(char st_id[]) {
    FILE* fp;
    USER test[100];
    int choose = 0;
    char new_score[100];
    int i = 0, j = 0, index = 0;

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].PW, test[i].birth, test[i].region, test[i].score);
        removeRow(test[i].st_id);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    for (int j = 0; j < i; j++) {
        if (strcmp(test[j].st_id, st_id) == 0) {
            index = j;
            break;
        }
    }

    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛        薑 爾 熱 薑        弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(14, 9);
    printf("億煎遴 з薄擊 殮溘п 輿撮蹂.");
    gotoxy(14, 11);
    printf("Ｃ ");
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦 1. �挫�): ");
    gotoxy(18, 11);
    scanf("%s", new_score);
    gotoxy(52, 19);
    scanf("%d", &choose);

    switch (choose) {
    case 0:
        change_student(st_id);
    case 1:
        strcpy(test[index].score, new_score);
        fp = fopen("user.txt", "w");
        for (int j = 0; j < i; j++) {
            fprintf(fp, "\n%s,%s,%s,%s,%s,%s", test[j].st_id, test[j].name, test[j].PW, test[j].birth, test[j].region, test[j].score);
        }
        fclose(fp);
        change_student(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        change_student_score(st_id);
    }
}

// 婦葬濠 詭景
void manager_menu(char st_id[]) {
    int choice = 0;

    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛       婦 葬 濠 詭 景      弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(14, 6);
    printf(" 1. 晦熨餌 褐羶 貲欽 褻��");
    gotoxy(14, 9);
    printf(" 2. 晦熨餌 褐羶 з儅 寞寡薑");
    gotoxy(14, 12);
    printf(" 3. 瞪羹 貲欽 褻��");
    gotoxy(14, 15);
    printf(" 4. з儅 匐儀 (熱薑, 餉薯) ");
    gotoxy(6, 19);
    printf(" 詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 給嬴陛晦): ");
    scanf("%d", &choice);

    switch (choice) {
    case 0:
        basic();
    case 1:
        look_manager_ApplicationList(st_id);
    case 2:
        manager_assignroom(st_id);
    case 3:
        look_manager_room(st_id);
    case 4:
        search_student();
    default:
        gotoxy(2, 19);
        printf("                                                     ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        manager_menu(st_id);
    }
}
// 婦葬濠ver. 褐羶 貲欽 褻�� (apply.txt)
void look_manager_ApplicationList(char st_id[]) {
    FILE* fp;
    APPLY test[100];
    int i = 0, choice = 0;
    int y = 9;

    fp = fopen("apply.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]\n", test[i].st_id, test[i].name, test[i].region, test[i].score);
        i++;
    }
    fclose(fp);

    map2();
    gotoxy(18, 1);
    printf("旨收收收收收收收收收收收收收收收收收收收收旬");
    gotoxy(18, 2);
    printf("早  褐 羶 貲 欽 �� 檣 早");
    gotoxy(18, 3);
    printf("曲收收收收收收收收收收收收收收收收收收收收旭");
    gotoxy(7, 7);
    printf("%-12s %-14s %-11s %-10s", "з廓", "檜葷", "雖羲", "з薄");

    for (int j = 0; j < i; j++) {
        gotoxy(4, y++);
        gotoxy(4, y++);
        printf("%-14s %-12s %-14s %-10s", test[j].st_id, test[j].name, test[j].region, test[j].score);
    }
    gotoxy(6, 28);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦): ");
    gotoxy(46, 28);
    scanf("%d", &choice);

    switch (choice) {
    case 0:
        manager_menu(st_id);
    default:
        gotoxy(2, 28);
        printf("                                                       ");
        gotoxy(5, 28);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        look_manager_ApplicationList(st_id);
    }
}

// 薑溺 晦棟
int find(REGION* region, APPLY* user1) {
    for (int i = 0; i < sizeof(region) / sizeof(REGION); i++) {
        if (strcmp(user1[i].region, region[i].region) == 0) {
            return region[i].distance;
        }
    }
    return 0;
}
void swap_user(APPLY* user1, APPLY* user2, REGION* region) {
    int user1_distance = find(region, user1);
    int user2_distance = find(region, user2);

    if (user1_distance >= user2_distance) {
        APPLY tmp = *user1;
        *user1 = *user2;
        *user2 = tmp;
    }
}
void quickSort(APPLY* arr, int low, int high, REGION* region) {
    if (low < high) {
        int pi = partition(arr, low, high, region);
        quickSort(arr, low, pi - 1, region);
        quickSort(arr, pi + 1, high, region);
    }
}
int partition(APPLY* arr, int low, int high, REGION* region) {
    APPLY pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (region[j].distance <= region[high].distance) {
            i++;
            swap_user(&arr[i], &arr[j], region);
        }
    }

    swap_user(&arr[i + 1], &arr[high], region);
    return i + 1;
}
// 婦葬濠ver.寞寡薑 晦棟
void manager_assignroom(char st_id[]) {
    FILE* fp;
    APPLY test[100];
    REGION region[100];
    int i = 0, j = 0, k = 0;
    int choice = 0, index = 0;

    fp = fopen("region.txt", "r");
    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%d\n", region[k].region, &region[k].distance);
        k++;
    }
    fclose(fp);

    fp = fopen("apply.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].region, test[i].score);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    map();
    gotoxy(14, 6);
    printf("晦熨餌蒂 褐羶и з儅菟擊 渠鼻戲煎");
    gotoxy(19, 8);
    printf("寞寡薑擊 ж衛啊蝗棲梱?");
    gotoxy(13, 10);
    printf("忙式式式式式式式式式式式式式忖");
    gotoxy(13, 11);
    printf("弛 1. 嬴 棲 螃 弛");
    gotoxy(13, 12);
    printf("戌式式式式式式式式式式式式式戎");
    gotoxy(31, 10);
    printf("忙式式式式式式式式式式式式式忖");
    gotoxy(31, 11);
    printf("弛     2. 蕨   弛");
    gotoxy(31, 12);
    printf("戌式式式式式式式式式式式式式戎");
    gotoxy(9, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂: ");
    gotoxy(34, 19);
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        manager_menu(st_id);
    case 2:
        quickSort(test, 0, i - 1, region);

        fp = fopen("room.txt", "w");

        for (j = 0; j < i; j += 2) {
            fprintf(fp, "%s,%s,%s,%d\n", test[j].st_id, test[j].name, test[j].region, (j / 2) + 101);
            if (j + 1 < i) {
                fprintf(fp, "%s,%s,%s,%d\n", test[j + 1].st_id, test[j + 1].name, test[j + 1].region, (j / 2) + 101);
            }
        }

        fclose(fp);

        map();
        gotoxy(22, 9);
        printf("寞寡薑 諫猿!");
        Sleep(2000);
        manager_menu(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        manager_assignroom(st_id);
    }
}

// 婦葬濠ver. 瞪羹 貲欽 褻�� (room.txt)
void look_manager_room(char st_id[]) {
    FILE* fp;
    ROOM test[100];
    int i = 0, choice = 0;
    int y = 9;

    fp = fopen("room.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]\n", test[i].st_id, test[i].name, test[i].region, test[i].room);
        i++;
    }
    fclose(fp);

    map2();
    gotoxy(18, 1);
    printf("旨收收收收收收收收收收收收收收收收收收收收旬");
    gotoxy(18, 2);
    printf("早  瞪 羹 貲 欽 �� 檣 早");
    gotoxy(18, 3);
    printf("曲收收收收收收收收收收收收收收收收收收收收旭");
    gotoxy(10, 7);
    printf("%-15s %-15s %-15s", "з廓", "檜葷", "寞�ˉ�");

    for (int j = 0; j < i; j++) {
        gotoxy(7, y++);
        gotoxy(7, y++);
        printf("%-17s %-17s %-10s", test[j].st_id, test[j].name, test[j].room);
    }
    gotoxy(6, 28);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦): ");
    gotoxy(46, 28);
    scanf("%d", &choice);

    switch (choice) {
    case 0:
        manager_menu(st_id);
    default:
        gotoxy(2, 28);
        printf("                                                       ");
        gotoxy(5, 28);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        look_manager_room(st_id);
    }
}
// 婦葬濠ver. з儅 匐儀
void search_student() {
    FILE* fp;
    USER test[100];
    char st_id[100];
    int choice = 0;
    int i = 0, j = 0, index = 0;

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].PW, test[i].birth, test[i].region, test[i].score);
        removeRow(test[i].st_id);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛        з 儅 匐 儀        弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(15, 9);
    printf("з儅曖 з廓擊 殮溘п 輿撮蹂.");
    gotoxy(15, 11);
    printf("Ｃ ");
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦 1. �挫�): ");
    gotoxy(18, 11);
    scanf("%s", st_id);
    gotoxy(52, 19);
    scanf("%d", &choice);

    switch (choice) {
    case 0:
        manager_menu(st_id);
    case 1:
        for (int j = 0; j < i; j++) {
            if (strcmp(test[j].st_id, st_id) == 0) {
                look_student2(st_id);
            }
        }
        map();
        gotoxy(17, 9);
        printf("з儅擊 瓊擊 熱 橈蝗棲棻.");
        Sleep(2000);
        search_student();
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        search_student();
    }
}
// 婦葬濠ver. 薑爾 �挫�
void look_student2(char st_id[]) {
    FILE* fp;
    USER test[100];
    int choose = 0;
    int i = 0, j = 0, index = 0;

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].PW, test[i].birth, test[i].region, test[i].score);
        removeRow(test[i].st_id);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    for (int j = 0; j < i; j++) {
        if (strcmp(test[j].st_id, st_id) == 0) {
            index = j;
            break;
        }
    }

    map();
    gotoxy(19, 1);
    printf("旨收收收收收收收收收收收收收收收收收收收收旬");
    gotoxy(19, 2);
    printf("早  з 儅 薑 爾 �� 檣 早");
    gotoxy(19, 3);
    printf("曲收收收收收收收收收收收收收收收收收收收收旭");
    gotoxy(20, 5);
    printf("з廓: %s", test[index].st_id);
    gotoxy(20, 7);
    printf("檜葷: %s", test[index].name);
    gotoxy(20, 9);
    printf("綠塵廓��: %s", test[index].PW);
    gotoxy(20, 11);
    printf("儅喇錯橾: %s", test[index].birth);
    gotoxy(20, 13);
    printf("雖羲: %s", test[index].region);
    gotoxy(20, 15);
    printf("з薄: %s", test[index].score);
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘 (0. 菴煎陛晦 1. 熱薑 2. 餉薯): ");
    gotoxy(52, 19);
    scanf("%d%*c", &choose);

    switch (choose) {
    case 0:
        manager_menu(st_id);
    case 1:
        change_student2(st_id);
    case 2:
        delete_student(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                        ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        look_student2(st_id);
    }
}
// 婦葬濠ver. 薑爾 熱薑 詭景
void change_student2(char st_id[]) {
    int choice = 0;
    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛        薑 爾 熱 薑        弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(15, 5);
    printf("1. 檜葷");
    gotoxy(15, 8);
    printf("2. 綠塵廓��");
    gotoxy(15, 11);
    printf("3. 雖羲");
    gotoxy(15, 14);
    printf("4. з薄");
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦, 5. 諫猿): ");
    gotoxy(52, 19);
    scanf("%d%*c", &choice);

    switch (choice) {
    case 0:
        look_student2(st_id);
    case 1:
        change_student_name2(st_id);
    case 2:
        change_student_PW2(st_id);
    case 3:
        change_student_region2(st_id);
    case 4:
        change_student_score2(st_id);
    case 5:
        map();
        gotoxy(22, 9);
        printf("薑爾 熱薑 諫猿");
        Sleep(2000);
        manager_menu(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        change_student2(st_id);
    }
}
// 婦葬濠ver . 熱薑 й 檜葷
void change_student_name2(char st_id[]) {
    FILE* fp;
    USER test[100];
    int choose = 0;
    char new_name[100];
    int i = 0, j = 0, index = 0;

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].PW, test[i].birth, test[i].region, test[i].score);
        removeRow(test[i].st_id);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    for (int j = 0; j < i; j++) {
        if (strcmp(test[j].st_id, st_id) == 0) {
            index = j;
            break;
        }
    }

    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛        薑 爾 熱 薑        弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(11, 9);
    printf("з儅曖 億煎遴 檜葷擊 殮溘п 輿撮蹂.");
    gotoxy(11, 11);
    printf("Ｃ ");
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦 1. �挫�): ");
    gotoxy(15, 11);
    scanf("%s", new_name);
    gotoxy(52, 19);
    scanf("%d", &choose);

    switch (choose) {
    case 0:
        change_student2(st_id);
    case 1:
        strcpy(test[index].name, new_name);
        fp = fopen("user.txt", "w");
        for (int j = 0; j < i; j++) {
            fprintf(fp, "\n%s,%s,%s,%s,%s,%s", test[j].st_id, test[j].name, test[j].PW, test[j].birth, test[j].region, test[j].score);
        }
        fclose(fp);
        change_student2(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        change_student_name2(st_id);
    }

}
// 婦葬濠ver . 熱薑 й 綠塵廓��
void change_student_PW2(char st_id[]) {
    FILE* fp;
    USER test[100];
    int choose = 0;
    char new_PW[100];
    int i = 0, j = 0, index = 0;

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].PW, test[i].birth, test[i].region, test[i].score);
        removeRow(test[i].st_id);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    for (int j = 0; j < i; j++) {
        if (strcmp(test[j].st_id, st_id) == 0) {
            index = j;
            break;
        }
    }

    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛        薑 爾 熱 薑        弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(10, 9);
    printf("з儅曖 億煎遴 綠塵廓�ㄧ� 殮溘п 輿撮蹂.");
    gotoxy(10, 11);
    printf("Ｃ ");
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦 1. �挫�): ");
    gotoxy(14, 11);
    scanf("%s", new_PW);
    gotoxy(52, 19);
    scanf("%d", &choose);

    switch (choose) {
    case 0:
        change_student2(st_id);
    case 1:
        strcpy(test[index].PW, new_PW);
        fp = fopen("user.txt", "w");
        for (int j = 0; j < i; j++) {
            fprintf(fp, "\n%s,%s,%s,%s,%s,%s", test[j].st_id, test[j].name, test[j].PW, test[j].birth, test[j].region, test[j].score);
        }
        fclose(fp);
        change_student2(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        change_student_PW2(st_id);
    }
}
// 婦葬濠ver . 熱薑 й 雖羲
void change_student_region2(char st_id[]) {
    FILE* fp;
    USER test[100];
    int choose = 0;
    char new_region[100];
    int i = 0, j = 0, index = 0;

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].PW, test[i].birth, test[i].region, test[i].score);
        removeRow(test[i].st_id);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛        薑 爾 熱 薑        弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(11, 9);
    printf("з儅曖 億煎遴 雖羲擊 殮溘п 輿撮蹂.");
    gotoxy(11, 11);
    printf("Ｃ ");
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦 1. �挫�): ");
    gotoxy(15, 11);
    gets(new_region);
    gotoxy(52, 19);
    scanf("%d", &choose);

    switch (choose) {
    case 0:
        change_student2(st_id);
    case 1:
        strcpy(test[index].region, new_region);
        fp = fopen("user.txt", "w");
        for (int j = 0; j < i; j++) {
            fprintf(fp, "\n%s,%s,%s,%s,%s,%s", test[j].st_id, test[j].name, test[j].PW, test[j].birth, test[j].region, test[j].score);
        }
        fclose(fp);
        change_student2(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        change_student_region2(st_id);
    }

}
// 婦葬濠ver . 熱薑 й з薄
void change_student_score2(char st_id[]) {
    FILE* fp;
    USER test[100];
    int choose = 0;
    char new_score[100];
    int i = 0, j = 0, index = 0;

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].PW, test[i].birth, test[i].region, test[i].score);
        removeRow(test[i].st_id);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    for (int j = 0; j < i; j++) {
        if (strcmp(test[j].st_id, st_id) == 0) {
            index = j;
            break;
        }
    }

    map();
    gotoxy(14, 1);
    printf("牟收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
    gotoxy(14, 2);
    printf("弛        薑 爾 熱 薑        弛\n");
    gotoxy(14, 3);
    printf("汎收收收收收收收收收收收收收收收收收收收收收收收收收收收汛");
    gotoxy(11, 9);
    printf("з儅曖 億煎遴 з薄擊 殮溘п 輿撮蹂.");
    gotoxy(11, 11);
    printf("Ｃ ");
    gotoxy(4, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂. (0. 菴煎陛晦 1. �挫�): ");
    gotoxy(15, 11);
    scanf("%s", new_score);
    gotoxy(52, 19);
    scanf("%d", &choose);

    switch (choose) {
    case 0:
        change_student2(st_id);
    case 1:
        strcpy(test[index].score, new_score);
        fp = fopen("user.txt", "w");
        for (int j = 0; j < i; j++) {
            fprintf(fp, "\n%s,%s,%s,%s,%s,%s", test[j].st_id, test[j].name, test[j].PW, test[j].birth, test[j].region, test[j].score);
        }
        fclose(fp);
        change_student2(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        change_student_score(st_id);
    }
}

// 婦葬濠ver. 餉薯
void delete_student(char st_id[]) {
    FILE* fp;
    USER test[100];
    APPLY test2[100];
    ROOM test3[100];
    int choice = 0;
    int i = 0, j = 0, a = 0, b = 0, index = 0, index2 = 0, index3 = 0;

    fp = fopen("user.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]s", test[i].st_id, test[i].name, test[i].PW, test[i].birth, test[i].region, test[i].score);
        // removeRow(test[i].st_id);

        if (strchr(test[i].st_id, '\n')) {
            for (int k = 1; k < strlen(test[i].st_id) + 1; k++) {
                test[i].st_id[k - 1] = test[i].st_id[k];
            }
        }
        i++;
    }
    fclose(fp);

    fp = fopen("apply.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]s", test2[a].st_id, test2[a].name, test2[a].region, test2[a].score);

        if (strchr(test2[a].st_id, '\n')) {
            for (int k = 1; k < strlen(test2[a].st_id) + 1; k++) {
                test2[a].st_id[k - 1] = test2[a].st_id[k];
            }
        }
        a++;
    }
    fclose(fp);

    fp = fopen("room.txt", "r");

    while (1) {
        if (feof(fp))
            break;
        fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]s", test3[b].st_id, test3[b].name, test3[b].region, test3[b].room);

        if (strchr(test3[b].st_id, '\n')) {
            for (int k = 1; k < strlen(test3[b].st_id) + 1; k++) {
                test3[b].st_id[k - 1] = test3[b].st_id[k];
            }
        }
        b++;
    }
    fclose(fp);

    for (int j = 0; j < i; j++) {
        if (strcmp(test[j].st_id, st_id) == 0) {
            index = j;
            break;
        }
    }

    for (int j = 0; j < a; j++) {
        if (strcmp(test2[j].st_id, st_id) == 0) {
            index2 = j;
            break;
        }
    }

    for (int j = 0; j < b; j++) {
        if (strcmp(test3[j].st_id, st_id) == 0) {
            index3 = j;
            break;
        }
    }
    map();
    gotoxy(18, 8);
    printf("薑蜓 餉薯ж衛啊蝗棲梱?");
    gotoxy(14, 10);
    printf("忙式式式式式式式式式式式忖");
    gotoxy(14, 11);
    printf("弛 1.菴煎陛晦弛");
    gotoxy(14, 12);
    printf("戌式式式式式式式式式式式戎");
    gotoxy(29,10);
    printf("忙式式式式式式式式式式式忖");
    gotoxy(29,11);
    printf("弛  2. 餉 薯 弛");
    gotoxy(29, 12);
    printf("戌式式式式式式式式式式式戎");
    gotoxy(9, 19);
    printf("詭景 廓�ㄧ� 殮溘ж撮蹂: ");
    gotoxy(34, 19);
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        look_student2(st_id);
    case 2:
        // user.txt 餉薯
        fp = fopen("user.txt", "w");

        for (j = 0; j < index; j++) {
            fprintf(fp, "\n%s,%s,%s,%s,%s,%s", test[j].st_id, test[j].name, test[j].PW, test[j].birth, test[j].region, test[j].score);
        }
        fclose(fp);

        fp = fopen("user.txt", "a");

        for (j = index + 1; j < i; j++) {
            fprintf(fp, "\n%s,%s,%s,%s,%s,%s", test[j].st_id, test[j].name, test[j].PW, test[j].birth, test[j].region, test[j].score);
        }
        fclose(fp);

        // apply.txt 餉薯
        fp = fopen("apply.txt", "w");

        for (j = 0; j < index2; j++) {
            fprintf(fp, "\n%s,%s,%s,%s", test2[j].st_id, test2[j].name, test2[j].region, test2[j].score);
        }
        fclose(fp);

        fp = fopen("apply.txt", "a");

        for (j = index2 + 1; j < a; j++) {
            fprintf(fp, "\n%s,%s,%s,%s", test2[j].st_id, test2[j].name, test2[j].region, test2[j].score);
        }
        fclose(fp);

        // room.txt 餉薯
        fp = fopen("room.txt", "w");

        for (j = 0; j < index3; j++) {
            fprintf(fp, "\n%s,%s,%s,%s", test3[j].st_id, test3[j].name, test3[j].region, test3[j].room);
        }
        fclose(fp);

        fp = fopen("room.txt", "a");

        for (j = index3 + 1; j < b; j++) {
            fprintf(fp, "\n%s,%s,%s,%s", test3[j].st_id, test3[j].name, test3[j].region, test3[j].room);
        }
        fclose(fp);

        map();
        gotoxy(22, 10);
        printf("з儅 餉薯 諫猿!");
        Sleep(2000);
        manager_menu(st_id);
    default:
        gotoxy(2, 19);
        printf("                                                    ");
        gotoxy(5, 19);
        printf(" п渡腎朝 詭景 廓�ㄟ� 襄營ж雖 彊蝗棲棻. ");
        Sleep(3000);
        delete_student(st_id);
    }
}
int main(void)
{
    basic();
}
void removeRow(char* a) {
    int len = strlen(a);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (count > len) {
            break;
        }
        if (a[i] == "\n") {
            count += 2;
        }
        else {
            count += 1;
        }
        a[i] = a[count - 1];
    }
}