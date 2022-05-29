#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define cls system("cls")
#define pause system("pause")

void Setcolor(int color);
void CursorView(char show);
void gotoxy(int x, int y);

void Setcolor(int color)//�۾� �� ������ ���� �Լ�
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void CursorView(char show)//Ŀ�� �Ⱥ��̰� �ϱ�
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y)//xy��ǥ
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
