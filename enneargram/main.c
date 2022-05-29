#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include "head.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#define MAX 100//입력받을수 있는 최대학생수

struct std{ //학생정보 입력을 위한 구조체
    int ID;
    char name[10];
    int nature;
};
typedef struct std STD;
STD arra[MAX];//학생정보 구조체를 위한 설정

struct que{//문제 저장과 점수를 위한 구조체
    char qu[500];    //문제저장
};
typedef struct que QUE;
QUE arr[10];
int t_score[9]={0,0,0,0,0,0,0,0,0}; //test에서 쓰이는 점수와 성격
int t_nature[9]={1,2,3,4,5,6,7,8,9};

int cursor();
int moving; //어떤 메뉴가 선택됐는지 저장
int moving2; //modi 에서의 메뉴 선택
int moving3; //sorting 에서의 메뉴 선택
int T_NUM = 0;  //입력된 전체 학생 수

//보류 int stdcount(); //파일을 열고 입력 된 학생수를 측정
int info_ip();  //학생정보 입력 함수
int test(); //심리검사 함수
int test2(); //심리검사 함수
int result();
int test_i;// test함수에서 학번 받고 몇번째에 저장되있는지 찾는 함수 result에서도 씀
int list();//입력된 리스트를 보여주는 함수
int modify();//정보수정을 위한 함수
int modify_c();//modify커서
int sorting();//정보수정에서 소팅으로
int sorting_c();//sorting에서 커서
int del();//정보수정에서 삭제로
int ID_sorting();//학번정렬 함수
int NATURE_sorting();//성격정렬 함수
int main()
{
    system("title 에니어그램 심리검사 - 컴퓨터공학과");
    system("COLOR 07");
    int close = 0;//    종료를 위한 변수
    while(1){
    printf("======메뉴 선택======");
    Setcolor(11);
    gotoxy(0, 1); printf("1. 정보입력");
    Setcolor(15);
    gotoxy(0, 2); printf("2. 검사실행");
    gotoxy(0, 3); printf("3. 검사결과");
    gotoxy(0, 4); printf("4. 리스트");
    gotoxy(0, 5); printf("5. 수정");
    gotoxy(0, 6); printf("6. 종료");
    cursor();// 위아래 입력에 따른 커서 보이기 함수
    switch(moving){
        case 0 : //정보입력
            info_ip(); cls;
            break;
        case 1 : //심리검사
            test(); cls;
            break;
        case 2 : //검사결과 확인
            result(); cls;
            break;
        case 3 : //리스트
            list(); cls;
            break;
        case 4 : //정보수정
            modify(); cls;
            break;
        case 5 : //종료
            close = 1;
            break;
        }
        if(close == 1)
            break;
    }

}

int cursor()
{
    int POS_menu = 0;
    CursorView(0);
    int key;

    key = _getch();
    if(key == ENTER)
        POS_menu = 0;
    else if(key == 0x00 || key ==0xE0){
         while(key != ENTER){
                key = _getch();
                if(key == DOWN && 0 <= POS_menu && POS_menu <=5){
                    if(POS_menu < 5)    //1~5번까지만 이동할 수 있게 조건
                    POS_menu++;
                }
                else if(key == UP && 0 <= POS_menu && POS_menu <=5){
                    if(POS_menu > 0)
                    POS_menu--;
                }
        switch(POS_menu){
            case 0:
                Setcolor(11);
                gotoxy(0, 1); printf("1. 정보입력");
                Setcolor(15);
                gotoxy(0, 2); printf("2. 검사실행");
                gotoxy(0, 3); printf("3. 검사결과");
                gotoxy(0, 4); printf("4. 리스트");
                gotoxy(0, 5); printf("5. 수정");
                gotoxy(0, 6); printf("6. 종료");
            break;
            case 1:
                Setcolor(11);
                gotoxy(0, 2); printf("2. 검사실행");
                Setcolor(15);
                gotoxy(0, 1); printf("1. 정보입력");
                gotoxy(0, 3); printf("3. 검사결과");
                gotoxy(0, 4); printf("4. 리스트");
                gotoxy(0, 5); printf("5. 수정");
                gotoxy(0, 6); printf("6. 종료");
            break;
            case 2:
                Setcolor(11);
                gotoxy(0, 3); printf("3. 검사결과");
                Setcolor(15);
                gotoxy(0, 1); printf("1. 정보입력");
                gotoxy(0, 2); printf("2. 검사실행");
                gotoxy(0, 4); printf("4. 리스트");
                gotoxy(0, 5); printf("5. 수정");
                gotoxy(0, 6); printf("6. 종료");
            break;
            case 3:
                Setcolor(11);
                gotoxy(0, 4); printf("4. 리스트");
                Setcolor(15);
                gotoxy(0, 1); printf("1. 정보입력");
                gotoxy(0, 2); printf("2. 검사실행");
                gotoxy(0, 3); printf("3. 검사결과");
                gotoxy(0, 5); printf("5. 수정");
                gotoxy(0, 6); printf("6. 종료");
            break;
            case 4:
                Setcolor(11);
                gotoxy(0, 5); printf("5. 수정");
                Setcolor(15);
                gotoxy(0, 1); printf("1. 정보입력");
                gotoxy(0, 2); printf("2. 검사실행");
                gotoxy(0, 3); printf("3. 검사결과");
                gotoxy(0, 4); printf("4. 리스트");
                gotoxy(0, 6); printf("6. 종료");
            break;
            case 5:
                Setcolor(11);
                gotoxy(0, 6); printf("6. 종료");
                Setcolor(15);
                gotoxy(0, 1); printf("1. 정보입력");
                gotoxy(0, 2); printf("2. 검사실행");
                gotoxy(0, 3); printf("3. 검사결과");
                gotoxy(0, 4); printf("4. 리스트");
                gotoxy(0, 5); printf("5. 수정");

            break;

            }//스위치 끝나는 자리
        }//엔터 치기
    }//방향키 받기
    moving = POS_menu;
    cls;
    return 0;
}

int info_ip()//학생정보 입력
{
    FILE *fp;
    int i;

    fp = fopen("std.txt", "r");
				if (fp == NULL) {
                        printf("학생정보(학번 이름) 입력:");
                        scanf("%d %s", &arra[T_NUM].ID, arra[T_NUM].name);
                        T_NUM++;  // 학생 수 1 증가
                        fflush(stdin); //학생정보 입력

                        fp = fopen("std.txt", "w");
                        if (fp == NULL) {
                            printf("파일열기 실패\n");
                            return -1;
                        }
                        arra[0].nature = 10; //성격 유형을 아직 배정받지 못함을 뜻함
                        fprintf(fp,"%d %s %d\n", arra[0].ID, arra[0].name ,arra[0].nature); //처음 입력 받은사람은 무조건 0
                        fclose(fp); //학생정보 저장

				}
				else{
                    T_NUM = 0;
                    for(i = 0; i < MAX; i++) { // 파일로부터 학생정보를 하나씩 반복해서 읽음
                        if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                                break;// 파일에 끝에 도달하면
                        T_NUM++;// 학생 수 증가
                    }
                    fclose(fp);

                    printf("학생정보(학번 이름) 입력:");   //학생정보 입력
                    scanf("%d %s", &arra[T_NUM].ID, arra[T_NUM].name);
                    for(i = 0; i < T_NUM; i++){
                        if(arra[i].ID == arra[T_NUM].ID){
                            cls;
                            printf("이미 등록된 학번입니다\n");
                            pause;
                            return -1;
                        }
                    }
                    arra[T_NUM].nature = 10;//초기값 설정
                    T_NUM++;  // 학생 수 1 증가
                    fflush(stdin);

                    fp = fopen("std.txt", "w");//학생정보 저장
                        if (fp == NULL) {
                            printf("파일열기 실패\n");
                            return -1;
                        }
                    for(i = 0; i < T_NUM; i++){ // 배열 상에서 이동
                            fprintf(fp,"%d %s %d\n", arra[i].ID, arra[i].name, arra[i].nature);
                        }
                    fclose(fp);
				}


}

int test()
{
    int i=0;
    int j;
    int search; //학번입력
    FILE *fp;

    test_i = 0;
    printf("학번을 입력하세요 :");
    scanf("%d", &search); fflush;
    fp = fopen("std.txt", "r");
    T_NUM = 0;
    for(i = 0; i < MAX; i++) {// 파일로부터 학생정보를 하나씩 반복해서 읽음
            if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                break;// 파일에 끝에 도달하면
            T_NUM++;// 학생 수 증가
            }
    fclose(fp);
    cls;

    for(i = 0; i < T_NUM; i++)
        {
            if(arra[i].ID == search)
                break;
        }
        if(i >= T_NUM){
            printf("등록되지 않은 학번입니다\n");
            pause;
            return -1;
        }

    test_i = i;

        for(i = 0; i < 9; i++)
        test2(i);

    for(i=7; i >= 0; i--)
        for(j=0; j <= i; j++)
            if(t_score[j] < t_score[j+1]){
                int tmp;
                tmp = t_score[j];
                t_score[j] = t_score[j+1];
                t_score[j+1] = tmp;
                tmp = t_nature[j];
                t_nature[j] = t_nature[j+1];
                t_nature[j+1] = tmp;
                }

    fp = fopen("std.txt", "r");
    T_NUM = 0;
    for(i = 0; i < MAX; i++) {// 파일로부터 학생정보를 하나씩 반복해서 읽음
            if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                break;// 파일에 끝에 도달하면
            T_NUM++;// 학생 수 증가
            }
    fclose(fp);

    arra[test_i].nature = t_nature[0];
    fp = fopen("std.txt","w");
        for(i = 0; i < T_NUM; i++)
        fprintf(fp, "%d %s %d\n", arra[i].ID, arra[i].name, arra[i].nature);
    fclose(fp);

    int cl=1;
    for(i = 0; i < 9; i++){// 유형 다시 초기화
        t_nature[i] = cl;
        cl++;
    }

    return 0;
}

int test2(int x)
{
    CursorView(0);
    int POS = 2;
    char str[500];
    int i, j, k;
    FILE *fp;
    int de_score=0;
    int a=0;
    int key;
    int s_c=1;
    int s_c2=0;


    switch (x) {
        case 0:
            fp = fopen ("q_type1.txt", "rt");
            for(i=0; i < 10; i++){
                fgets(str, sizeof(str), fp);
                strcpy(arr[i].qu, str);
            }fclose(fp);
            break;
        case 1:
            fp = fopen ("q_type2.txt", "rt");
            for(i=0; i < 10; i++){
                fgets(str, sizeof(str), fp);
                strcpy(arr[i].qu, str);
            }fclose(fp);
            break;
        case 2:
            fp = fopen ("q_type3.txt", "rt");
            for(i=0; i < 10; i++){
                fgets(str, sizeof(str), fp);
                strcpy(arr[i].qu, str);
            }fclose(fp);
            break;
        case 3:
            fp = fopen ("q_type4.txt", "rt");
            for(i=0; i < 10; i++){
                fgets(str, sizeof(str), fp);
                strcpy(arr[i].qu, str);
            }fclose(fp);
            break;
        case 4:
            fp = fopen ("q_type5.txt", "rt");
            for(i=0; i < 10; i++){
                fgets(str, sizeof(str), fp);
                strcpy(arr[i].qu, str);
            }fclose(fp);
            break;
        case 5:
            fp = fopen ("q_type6.txt", "rt");
            for(i=0; i < 10; i++){
                fgets(str, sizeof(str), fp);
                strcpy(arr[i].qu, str);
            }fclose(fp);
            break;
        case 6:
            fp = fopen ("q_type7.txt", "rt");
            for(i=0; i < 10; i++){
                fgets(str, sizeof(str), fp);
                strcpy(arr[i].qu, str);
            }fclose(fp);
            break;
        case 7:
            fp = fopen ("q_type8.txt", "rt");
            for(i=0; i < 10; i++){
                fgets(str, sizeof(str), fp);
                strcpy(arr[i].qu, str);
            }fclose(fp);
            break;
        case 8:
            fp = fopen ("q_type9.txt", "rt");
            for(i=0; i < 10; i++){
                fgets(str, sizeof(str), fp);
                strcpy(arr[i].qu, str);
            }fclose(fp);
            break;
    }

    for(j=0, k=0; k < 10; j+=4, k++){// j y좌표 k구조체
        gotoxy(0, j); printf("%s", arr[k].qu);
        j+=2;
        gotoxy(0, j); Setcolor(11); printf("1. 예 ");
        gotoxy(10, j); Setcolor(15); printf("2. 아니오\n");



        key = _getch();

        if(key == ENTER)    //엔터를 그냥 입력 받았을 때
            s_c2++;
        if(key == 0x00 || key ==0xE0){  //아니요를 입력받을 때

            while(key != ENTER){
                    key = _getch();
            if(key == LEFT){
                Setcolor(11);
                gotoxy(0, j); printf("1. 예 ");
                Setcolor(15);
                gotoxy(10, j); printf("2. 아니오\n");
                s_c=1;
            }

            else if(key == RIGHT){
                Setcolor(15);
                gotoxy(0, j); printf("1. 예 ");
                Setcolor(11);
                gotoxy(10, j); printf("2. 아니오\n");
                s_c=2;
            }

            }

            if(s_c == 1)
                s_c2++;
            Setcolor(15);
        }

        } // for end


        t_score[x] = s_c2;
        s_c2=0;

    cls;
    if(x ==8){
        printf("검사가 끝났습니다.\n");
        pause;
        cls;
    }

}

int result()
{
    FILE *fp;
    FILE *file;
    int resultshow;
    int i;
    int search;
    char line[255];

    printf("학번을 입력하세요 :");
    scanf("%d", &search); fflush;

    fp = fopen("std.txt", "r");
    T_NUM = 0;
    for(i = 0; i < MAX; i++) {// 파일로부터 학생정보를 하나씩 반복해서 읽음
            if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                break;// 파일에 끝에 도달하면
            T_NUM++;// 학생 수 증가
            }
    fclose(fp);
    cls;

    for(i = 0; i < T_NUM; i++)
        {
            if(arra[i].ID == search)
                break;
        }
    if(i >= T_NUM){
        printf("등록되지 않은 학번입니다\n");
        pause;
    }

    cls;

    switch(arra[i].nature){
        case 1 :
            system("COLOR 02");
            file = fopen("1typeinfo.txt", "r");
            if (file == NULL) {
                printf("파일열기 실패\n");
            return -1;
            }
            while (fgets(line, sizeof(line), file) != NULL ) {
                printf("%s", line);
            }
            fclose(file);
            gotoxy(0, 0);
            pause; break;
        case 2 :
            system("COLOR 02");
            file = fopen("2typeinfo.txt", "r");
            if (file == NULL) {
                printf("파일열기 실패\n");
            return -1;
            }
            while (fgets(line, sizeof(line), file) != NULL ) {
                printf("%s", line);
            }
            fclose(file);
            gotoxy(0, 0);
            pause; break;
        case 3 :
            system("COLOR 02");
            file = fopen("3typeinfo.txt", "r");
            if (file == NULL) {
                printf("파일열기 실패\n");
            return -1;
            }
            while (fgets(line, sizeof(line), file) != NULL ) {
                printf("%s", line);
            }
            fclose(file);
            gotoxy(0, 0);
            pause; break;
        case 4 :
            system("COLOR 02");
            file = fopen("4typeinfo.txt", "r");
            if (file == NULL) {
                printf("파일열기 실패\n");
            return -1;
            }
            while (fgets(line, sizeof(line), file) != NULL ) {
                printf("%s", line);
            }
            fclose(file);
            gotoxy(0, 0);
            pause; break;
        case 5 :
            system("COLOR 02");
            file = fopen("5typeinfo.txt", "r");
            if (file == NULL) {
                printf("파일열기 실패\n");
            return -1;
            }
            while (fgets(line, sizeof(line), file) != NULL ) {
                printf("%s", line);
            }
            fclose(file);
            gotoxy(0, 0);
            pause; break;
        case 6 :
            system("COLOR 02");
            file = fopen("6typeinfo.txt", "r");
            if (file == NULL) {
                printf("파일열기 실패\n");
            return -1;
            }
            while (fgets(line, sizeof(line), file) != NULL ) {
                printf("%s", line);
            }
            fclose(file);
            gotoxy(0, 0);
            pause; break;
        case 7 :
            system("COLOR 02");
            file = fopen("7typeinfo.txt", "r");
            if (file == NULL) {
                printf("파일열기 실패\n");
            return -1;
            }
            while (fgets(line, sizeof(line), file) != NULL ) {
                printf("%s", line);
            }
            fclose(file);
            gotoxy(0, 0);
            pause; break;
        case 8 :
            system("COLOR 02");
            file = fopen("8typeinfo.txt", "r");
            if (file == NULL) {
                printf("파일열기 실패\n");
            return -1;
            }
            while (fgets(line, sizeof(line), file) != NULL ) {
                printf("%s", line);
            }
            fclose(file);
            gotoxy(0, 0);
            pause; break;
        case 9 :
            system("COLOR 02");
            file = fopen("9typeinfo.txt", "r");
            if (file == NULL) {
                printf("파일열기 실패\n");
            return -1;
            }
            while (fgets(line, sizeof(line), file) != NULL ) {
                printf("%s", line);
            }
            fclose(file);
            gotoxy(0, 0);
            pause; break;
        case 10 :
            printf("검사결과가 없습니다.\n");
            pause;
    }
    system("COLOR 07");

}

int list()
{
    int i;
    FILE *fp;

    fp = fopen("std.txt", "r");
    T_NUM = 0;
    for(i = 0; i < MAX; i++) {// 파일로부터 학생정보를 하나씩 반복해서 읽음
            if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                break;// 파일에 끝에 도달하면
            T_NUM++;// 학생 수 증가
            }
    fclose(fp);

    printf("====== 리스트 ======\n");
    for(i = 0; i < T_NUM; i++)
        printf("%d  %s  %d유형\n", arra[i].ID, arra[i].name, arra[i].nature);
    pause;
}
int modify()
{
    Setcolor(11);
    gotoxy(0, 0); printf("정렬");
    Setcolor(15);
    gotoxy(0, 1); printf("삭제");
    modify_c();
    switch(moving2){
        case 0 :
            sorting(); cls;
            break;
        case 1 :
            del(); cls;
            break;
    }
}
int modify_c()
{
    int key;
    int modi_menu = 0;

    key = _getch();
    if(key == ENTER)
        modi_menu = 0;
    else if(key == 0x00 || key ==0xE0){
         while(key != ENTER){
                key = _getch();
                if(key == DOWN && 0 <= modi_menu && modi_menu <=1){
                    if(modi_menu < 1)    //1~5번까지만 이동할 수 있게 조건
                    modi_menu++;
                }
                else if(key == UP && 0 <= modi_menu && modi_menu <=1){
                    if(modi_menu > 0)
                    modi_menu--;
                }
        switch(modi_menu){
            case 0:
                Setcolor(11);
                gotoxy(0, 0); printf("정렬");
                Setcolor(15);
                gotoxy(0, 1); printf("삭제");
            break;
            case 1:
                Setcolor(11);
                gotoxy(0, 1); printf("삭제");
                Setcolor(15);
                gotoxy(0, 0); printf("정렬");
            break;
        }

        }
    }
    moving2 = modi_menu;
    cls;

}

int sorting()
{
    Setcolor(11);
    gotoxy(0, 0); printf("학번 정렬");
    Setcolor(15);
    gotoxy(0, 1); printf("성격 정렬");
    sorting_c();
    switch(moving3){
        case 0 :
            ID_sorting(); cls;
            break;
        case 1 :
            NATURE_sorting(); cls;
            break;
    }

}

int sorting_c()
{
    int key;
    int sort_menu = 0;

    key = _getch();
    if(key == ENTER)
        sort_menu = 0;
    else if(key == 0x00 || key ==0xE0){
         while(key != ENTER){
                key = _getch();
                if(key == DOWN && 0 <= sort_menu && sort_menu <=1){
                    if(sort_menu < 1)    //1~5번까지만 이동할 수 있게 조건
                    sort_menu++;
                }
                else if(key == UP && 0 <= sort_menu && sort_menu <=1){
                    if(sort_menu > 0)
                    sort_menu--;
                }
        switch(sort_menu){
            case 0:
                Setcolor(11);
                gotoxy(0, 0); printf("학번 정렬");
                Setcolor(15);
                gotoxy(0, 1); printf("성격 정렬");
            break;
            case 1:
                Setcolor(11);
                gotoxy(0, 1); printf("성격 정렬");
                Setcolor(15);
                gotoxy(0, 0); printf("학번 정렬");
            break;
        }

        }
    }
    moving3 = sort_menu;
    cls;

}

int ID_sorting()
{
    int i, j;
    FILE *fp;

    fp = fopen("std.txt", "r");
    T_NUM = 0;
    for(i = 0; i < MAX; i++) {// 파일로부터 학생정보를 하나씩 반복해서 읽음
            if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                break;// 파일에 끝에 도달하면
            T_NUM++;// 학생 수 증가
            }
    fclose(fp);

    for(i = T_NUM-2; i >= 0; i--)
        for(j = 0; j <= i; j++)
            if(arra[j].ID > arra[j+1].ID) {
                STD tmp2;
                tmp2 = arra[j];
                arra[j] = arra[j+1];
                arra[j+1] = tmp2;
            }
    fp = fopen("std.txt", "w");//학생정보 저장
        if (fp == NULL) {
            printf("파일열기 실패\n");
            return -1;
        }
        for(i = 0; i < T_NUM; i++){ // 배열 상에서 이동
            fprintf(fp,"%d %s %d\n", arra[i].ID, arra[i].name, arra[i].nature);
        }
    fclose(fp);

}

int NATURE_sorting()
{
    int i, j;
    FILE *fp;

    fp = fopen("std.txt", "r");
    T_NUM = 0;
    for(i = 0; i < MAX; i++) {// 파일로부터 학생정보를 하나씩 반복해서 읽음
            if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                break;// 파일에 끝에 도달하면
            T_NUM++;// 학생 수 증가
            }
    fclose(fp);

    for(i = T_NUM-2; i >= 0; i--){
        for(j = 0; j <= i; j++)
            if(arra[j].ID > arra[j+1].ID) {
                STD tmp2;
                tmp2 = arra[j];
                arra[j] = arra[j+1];
                arra[j+1] = tmp2;
            }
    }
    for(i = T_NUM-2; i >= 0; i--){
        for(j = 0; j <= i; j++)
            if(arra[j].nature > arra[j+1].nature) {
                STD tmp2;
                tmp2 = arra[j];
                arra[j] = arra[j+1];
                arra[j+1] = tmp2;
            }
    }
    fp = fopen("std.txt", "w");//학생정보 저장
        if (fp == NULL) {
            printf("파일열기 실패\n");
            return -1;
        }
        for(i = 0; i < T_NUM; i++){ // 배열 상에서 이동
            fprintf(fp,"%d %s %d\n", arra[i].ID, arra[i].name, arra[i].nature);
        }
    fclose(fp);

}

int del()
{
    int i, id;
    FILE *fp;

    fp = fopen("std.txt", "r");
    T_NUM = 0;
    for(i = 0; i < MAX; i++) {// 파일로부터 학생정보를 하나씩 반복해서 읽음
            if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                break;// 파일에 끝에 도달하면
            T_NUM++;// 학생 수 증가
            }
    fclose(fp);

    printf("삭제할 학생 학번 입력:");
	scanf("%d", &id);
	cls;
	fflush(stdin);
	for (i = 0; i < T_NUM; i++) {   // 배열의 모든 원소에 대하여 반복처리
		if (arra[i].ID == id)  // 동일한 학번 찾기
			break;
	}
	if (i >= T_NUM){   // 배열 끝에 도달
		printf("존재하지 않는 학번입니다.\n");
		pause;
	}
	else {
        for(; i < T_NUM-1; i++) // 해당 원소를 없애고 그 후 원소들을 모두 앞으로 한칸씩 이동
			arra[i] = arra[i+1];
			T_NUM--;  // 학생 수 1 감소
	}

	fp = fopen("std.txt", "w");//학생정보 저장
            if (fp == NULL) {
                printf("파일열기 실패\n");
            return -1;
            }
            for(i = 0; i < T_NUM; i++){ // 배열 상에서 이동
                fprintf(fp,"%d %s %d\n", arra[i].ID, arra[i].name, arra[i].nature);
            }
            fclose(fp);

}
