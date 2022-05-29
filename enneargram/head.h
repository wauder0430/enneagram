#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define cls system("cls")
#define pause system("pause")

void Setcolor(int color);
void CursorView(char show);
void gotoxy(int x, int y);

void Setcolor(int color)//글씨 색 변경을 위한 함수
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void CursorView(char show)//커서 안보이게 하기
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y)//xy좌표
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
