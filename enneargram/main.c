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
#define MAX 100//�Է¹����� �ִ� �ִ��л���

struct std{ //�л����� �Է��� ���� ����ü
    int ID;
    char name[10];
    int nature;
};
typedef struct std STD;
STD arra[MAX];//�л����� ����ü�� ���� ����

struct que{//���� ����� ������ ���� ����ü
    char qu[500];    //��������
};
typedef struct que QUE;
QUE arr[10];
int t_score[9]={0,0,0,0,0,0,0,0,0}; //test���� ���̴� ������ ����
int t_nature[9]={1,2,3,4,5,6,7,8,9};

int cursor();
int moving; //� �޴��� ���õƴ��� ����
int moving2; //modi ������ �޴� ����
int moving3; //sorting ������ �޴� ����
int T_NUM = 0;  //�Էµ� ��ü �л� ��

//���� int stdcount(); //������ ���� �Է� �� �л����� ����
int info_ip();  //�л����� �Է� �Լ�
int test(); //�ɸ��˻� �Լ�
int test2(); //�ɸ��˻� �Լ�
int result();
int test_i;// test�Լ����� �й� �ް� ���°�� ������ִ��� ã�� �Լ� result������ ��
int list();//�Էµ� ����Ʈ�� �����ִ� �Լ�
int modify();//���������� ���� �Լ�
int modify_c();//modifyĿ��
int sorting();//������������ ��������
int sorting_c();//sorting���� Ŀ��
int del();//������������ ������
int ID_sorting();//�й����� �Լ�
int NATURE_sorting();//�������� �Լ�
int main()
{
    system("title ���Ͼ�׷� �ɸ��˻� - ��ǻ�Ͱ��а�");
    system("COLOR 07");
    int close = 0;//    ���Ḧ ���� ����
    while(1){
    printf("======�޴� ����======");
    Setcolor(11);
    gotoxy(0, 1); printf("1. �����Է�");
    Setcolor(15);
    gotoxy(0, 2); printf("2. �˻����");
    gotoxy(0, 3); printf("3. �˻���");
    gotoxy(0, 4); printf("4. ����Ʈ");
    gotoxy(0, 5); printf("5. ����");
    gotoxy(0, 6); printf("6. ����");
    cursor();// ���Ʒ� �Է¿� ���� Ŀ�� ���̱� �Լ�
    switch(moving){
        case 0 : //�����Է�
            info_ip(); cls;
            break;
        case 1 : //�ɸ��˻�
            test(); cls;
            break;
        case 2 : //�˻��� Ȯ��
            result(); cls;
            break;
        case 3 : //����Ʈ
            list(); cls;
            break;
        case 4 : //��������
            modify(); cls;
            break;
        case 5 : //����
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
                    if(POS_menu < 5)    //1~5�������� �̵��� �� �ְ� ����
                    POS_menu++;
                }
                else if(key == UP && 0 <= POS_menu && POS_menu <=5){
                    if(POS_menu > 0)
                    POS_menu--;
                }
        switch(POS_menu){
            case 0:
                Setcolor(11);
                gotoxy(0, 1); printf("1. �����Է�");
                Setcolor(15);
                gotoxy(0, 2); printf("2. �˻����");
                gotoxy(0, 3); printf("3. �˻���");
                gotoxy(0, 4); printf("4. ����Ʈ");
                gotoxy(0, 5); printf("5. ����");
                gotoxy(0, 6); printf("6. ����");
            break;
            case 1:
                Setcolor(11);
                gotoxy(0, 2); printf("2. �˻����");
                Setcolor(15);
                gotoxy(0, 1); printf("1. �����Է�");
                gotoxy(0, 3); printf("3. �˻���");
                gotoxy(0, 4); printf("4. ����Ʈ");
                gotoxy(0, 5); printf("5. ����");
                gotoxy(0, 6); printf("6. ����");
            break;
            case 2:
                Setcolor(11);
                gotoxy(0, 3); printf("3. �˻���");
                Setcolor(15);
                gotoxy(0, 1); printf("1. �����Է�");
                gotoxy(0, 2); printf("2. �˻����");
                gotoxy(0, 4); printf("4. ����Ʈ");
                gotoxy(0, 5); printf("5. ����");
                gotoxy(0, 6); printf("6. ����");
            break;
            case 3:
                Setcolor(11);
                gotoxy(0, 4); printf("4. ����Ʈ");
                Setcolor(15);
                gotoxy(0, 1); printf("1. �����Է�");
                gotoxy(0, 2); printf("2. �˻����");
                gotoxy(0, 3); printf("3. �˻���");
                gotoxy(0, 5); printf("5. ����");
                gotoxy(0, 6); printf("6. ����");
            break;
            case 4:
                Setcolor(11);
                gotoxy(0, 5); printf("5. ����");
                Setcolor(15);
                gotoxy(0, 1); printf("1. �����Է�");
                gotoxy(0, 2); printf("2. �˻����");
                gotoxy(0, 3); printf("3. �˻���");
                gotoxy(0, 4); printf("4. ����Ʈ");
                gotoxy(0, 6); printf("6. ����");
            break;
            case 5:
                Setcolor(11);
                gotoxy(0, 6); printf("6. ����");
                Setcolor(15);
                gotoxy(0, 1); printf("1. �����Է�");
                gotoxy(0, 2); printf("2. �˻����");
                gotoxy(0, 3); printf("3. �˻���");
                gotoxy(0, 4); printf("4. ����Ʈ");
                gotoxy(0, 5); printf("5. ����");

            break;

            }//����ġ ������ �ڸ�
        }//���� ġ��
    }//����Ű �ޱ�
    moving = POS_menu;
    cls;
    return 0;
}

int info_ip()//�л����� �Է�
{
    FILE *fp;
    int i;

    fp = fopen("std.txt", "r");
				if (fp == NULL) {
                        printf("�л�����(�й� �̸�) �Է�:");
                        scanf("%d %s", &arra[T_NUM].ID, arra[T_NUM].name);
                        T_NUM++;  // �л� �� 1 ����
                        fflush(stdin); //�л����� �Է�

                        fp = fopen("std.txt", "w");
                        if (fp == NULL) {
                            printf("���Ͽ��� ����\n");
                            return -1;
                        }
                        arra[0].nature = 10; //���� ������ ���� �������� ������ ����
                        fprintf(fp,"%d %s %d\n", arra[0].ID, arra[0].name ,arra[0].nature); //ó�� �Է� ��������� ������ 0
                        fclose(fp); //�л����� ����

				}
				else{
                    T_NUM = 0;
                    for(i = 0; i < MAX; i++) { // ���Ϸκ��� �л������� �ϳ��� �ݺ��ؼ� ����
                        if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                                break;// ���Ͽ� ���� �����ϸ�
                        T_NUM++;// �л� �� ����
                    }
                    fclose(fp);

                    printf("�л�����(�й� �̸�) �Է�:");   //�л����� �Է�
                    scanf("%d %s", &arra[T_NUM].ID, arra[T_NUM].name);
                    for(i = 0; i < T_NUM; i++){
                        if(arra[i].ID == arra[T_NUM].ID){
                            cls;
                            printf("�̹� ��ϵ� �й��Դϴ�\n");
                            pause;
                            return -1;
                        }
                    }
                    arra[T_NUM].nature = 10;//�ʱⰪ ����
                    T_NUM++;  // �л� �� 1 ����
                    fflush(stdin);

                    fp = fopen("std.txt", "w");//�л����� ����
                        if (fp == NULL) {
                            printf("���Ͽ��� ����\n");
                            return -1;
                        }
                    for(i = 0; i < T_NUM; i++){ // �迭 �󿡼� �̵�
                            fprintf(fp,"%d %s %d\n", arra[i].ID, arra[i].name, arra[i].nature);
                        }
                    fclose(fp);
				}


}

int test()
{
    int i=0;
    int j;
    int search; //�й��Է�
    FILE *fp;

    test_i = 0;
    printf("�й��� �Է��ϼ��� :");
    scanf("%d", &search); fflush;
    fp = fopen("std.txt", "r");
    T_NUM = 0;
    for(i = 0; i < MAX; i++) {// ���Ϸκ��� �л������� �ϳ��� �ݺ��ؼ� ����
            if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                break;// ���Ͽ� ���� �����ϸ�
            T_NUM++;// �л� �� ����
            }
    fclose(fp);
    cls;

    for(i = 0; i < T_NUM; i++)
        {
            if(arra[i].ID == search)
                break;
        }
        if(i >= T_NUM){
            printf("��ϵ��� ���� �й��Դϴ�\n");
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
    for(i = 0; i < MAX; i++) {// ���Ϸκ��� �л������� �ϳ��� �ݺ��ؼ� ����
            if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                break;// ���Ͽ� ���� �����ϸ�
            T_NUM++;// �л� �� ����
            }
    fclose(fp);

    arra[test_i].nature = t_nature[0];
    fp = fopen("std.txt","w");
        for(i = 0; i < T_NUM; i++)
        fprintf(fp, "%d %s %d\n", arra[i].ID, arra[i].name, arra[i].nature);
    fclose(fp);

    int cl=1;
    for(i = 0; i < 9; i++){// ���� �ٽ� �ʱ�ȭ
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

    for(j=0, k=0; k < 10; j+=4, k++){// j y��ǥ k����ü
        gotoxy(0, j); printf("%s", arr[k].qu);
        j+=2;
        gotoxy(0, j); Setcolor(11); printf("1. �� ");
        gotoxy(10, j); Setcolor(15); printf("2. �ƴϿ�\n");



        key = _getch();

        if(key == ENTER)    //���͸� �׳� �Է� �޾��� ��
            s_c2++;
        if(key == 0x00 || key ==0xE0){  //�ƴϿ並 �Է¹��� ��

            while(key != ENTER){
                    key = _getch();
            if(key == LEFT){
                Setcolor(11);
                gotoxy(0, j); printf("1. �� ");
                Setcolor(15);
                gotoxy(10, j); printf("2. �ƴϿ�\n");
                s_c=1;
            }

            else if(key == RIGHT){
                Setcolor(15);
                gotoxy(0, j); printf("1. �� ");
                Setcolor(11);
                gotoxy(10, j); printf("2. �ƴϿ�\n");
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
        printf("�˻簡 �������ϴ�.\n");
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

    printf("�й��� �Է��ϼ��� :");
    scanf("%d", &search); fflush;

    fp = fopen("std.txt", "r");
    T_NUM = 0;
    for(i = 0; i < MAX; i++) {// ���Ϸκ��� �л������� �ϳ��� �ݺ��ؼ� ����
            if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                break;// ���Ͽ� ���� �����ϸ�
            T_NUM++;// �л� �� ����
            }
    fclose(fp);
    cls;

    for(i = 0; i < T_NUM; i++)
        {
            if(arra[i].ID == search)
                break;
        }
    if(i >= T_NUM){
        printf("��ϵ��� ���� �й��Դϴ�\n");
        pause;
    }

    cls;

    switch(arra[i].nature){
        case 1 :
            system("COLOR 02");
            file = fopen("1typeinfo.txt", "r");
            if (file == NULL) {
                printf("���Ͽ��� ����\n");
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
                printf("���Ͽ��� ����\n");
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
                printf("���Ͽ��� ����\n");
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
                printf("���Ͽ��� ����\n");
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
                printf("���Ͽ��� ����\n");
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
                printf("���Ͽ��� ����\n");
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
                printf("���Ͽ��� ����\n");
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
                printf("���Ͽ��� ����\n");
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
                printf("���Ͽ��� ����\n");
            return -1;
            }
            while (fgets(line, sizeof(line), file) != NULL ) {
                printf("%s", line);
            }
            fclose(file);
            gotoxy(0, 0);
            pause; break;
        case 10 :
            printf("�˻����� �����ϴ�.\n");
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
    for(i = 0; i < MAX; i++) {// ���Ϸκ��� �л������� �ϳ��� �ݺ��ؼ� ����
            if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                break;// ���Ͽ� ���� �����ϸ�
            T_NUM++;// �л� �� ����
            }
    fclose(fp);

    printf("====== ����Ʈ ======\n");
    for(i = 0; i < T_NUM; i++)
        printf("%d  %s  %d����\n", arra[i].ID, arra[i].name, arra[i].nature);
    pause;
}
int modify()
{
    Setcolor(11);
    gotoxy(0, 0); printf("����");
    Setcolor(15);
    gotoxy(0, 1); printf("����");
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
                    if(modi_menu < 1)    //1~5�������� �̵��� �� �ְ� ����
                    modi_menu++;
                }
                else if(key == UP && 0 <= modi_menu && modi_menu <=1){
                    if(modi_menu > 0)
                    modi_menu--;
                }
        switch(modi_menu){
            case 0:
                Setcolor(11);
                gotoxy(0, 0); printf("����");
                Setcolor(15);
                gotoxy(0, 1); printf("����");
            break;
            case 1:
                Setcolor(11);
                gotoxy(0, 1); printf("����");
                Setcolor(15);
                gotoxy(0, 0); printf("����");
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
    gotoxy(0, 0); printf("�й� ����");
    Setcolor(15);
    gotoxy(0, 1); printf("���� ����");
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
                    if(sort_menu < 1)    //1~5�������� �̵��� �� �ְ� ����
                    sort_menu++;
                }
                else if(key == UP && 0 <= sort_menu && sort_menu <=1){
                    if(sort_menu > 0)
                    sort_menu--;
                }
        switch(sort_menu){
            case 0:
                Setcolor(11);
                gotoxy(0, 0); printf("�й� ����");
                Setcolor(15);
                gotoxy(0, 1); printf("���� ����");
            break;
            case 1:
                Setcolor(11);
                gotoxy(0, 1); printf("���� ����");
                Setcolor(15);
                gotoxy(0, 0); printf("�й� ����");
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
    for(i = 0; i < MAX; i++) {// ���Ϸκ��� �л������� �ϳ��� �ݺ��ؼ� ����
            if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                break;// ���Ͽ� ���� �����ϸ�
            T_NUM++;// �л� �� ����
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
    fp = fopen("std.txt", "w");//�л����� ����
        if (fp == NULL) {
            printf("���Ͽ��� ����\n");
            return -1;
        }
        for(i = 0; i < T_NUM; i++){ // �迭 �󿡼� �̵�
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
    for(i = 0; i < MAX; i++) {// ���Ϸκ��� �л������� �ϳ��� �ݺ��ؼ� ����
            if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                break;// ���Ͽ� ���� �����ϸ�
            T_NUM++;// �л� �� ����
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
    fp = fopen("std.txt", "w");//�л����� ����
        if (fp == NULL) {
            printf("���Ͽ��� ����\n");
            return -1;
        }
        for(i = 0; i < T_NUM; i++){ // �迭 �󿡼� �̵�
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
    for(i = 0; i < MAX; i++) {// ���Ϸκ��� �л������� �ϳ��� �ݺ��ؼ� ����
            if(EOF == fscanf(fp,"%d %s %d", &arra[i].ID, arra[i].name, &arra[i].nature))
                break;// ���Ͽ� ���� �����ϸ�
            T_NUM++;// �л� �� ����
            }
    fclose(fp);

    printf("������ �л� �й� �Է�:");
	scanf("%d", &id);
	cls;
	fflush(stdin);
	for (i = 0; i < T_NUM; i++) {   // �迭�� ��� ���ҿ� ���Ͽ� �ݺ�ó��
		if (arra[i].ID == id)  // ������ �й� ã��
			break;
	}
	if (i >= T_NUM){   // �迭 ���� ����
		printf("�������� �ʴ� �й��Դϴ�.\n");
		pause;
	}
	else {
        for(; i < T_NUM-1; i++) // �ش� ���Ҹ� ���ְ� �� �� ���ҵ��� ��� ������ ��ĭ�� �̵�
			arra[i] = arra[i+1];
			T_NUM--;  // �л� �� 1 ����
	}

	fp = fopen("std.txt", "w");//�л����� ����
            if (fp == NULL) {
                printf("���Ͽ��� ����\n");
            return -1;
            }
            for(i = 0; i < T_NUM; i++){ // �迭 �󿡼� �̵�
                fprintf(fp,"%d %s %d\n", arra[i].ID, arra[i].name, arra[i].nature);
            }
            fclose(fp);

}
