#include "UI.h"



void size_set(int width, int length)
{
    string sys_cmd;
    string cols, lines;
    char buff[255];

    cols = to_string(width);
    lines = to_string(length);

    sys_cmd = "mode con cols=" + cols + " lines=" + lines;
    const char* convert = sys_cmd.c_str();

    system(convert);

}

void goto_point(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD point;
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(handle, point);
}

void draw_line()
{
    goto_point(0, 0);
    cout << "\n========================================================================\n\n\n\n";

    goto_point(0, 13);
    cout << "\n\n\n\n========================================================================\n";

    goto_point(0, 5);
}

void show_mainmenu()
{
    draw_line();
    cout << "\t\t\t\t메뉴\n";
    cout << "\t\t[번호를 입력하시면 게임이 실행됩니다.]\n";
    cout << "\t\t\t1. Player vs COM\n";
    cout << "\t\t\t2. Player vs Player\n";
    cout << "\t\t\t3. Exit\n\n";
    cout << "\t\t\tchoice : ";
}

void setcolor(unsigned short text, unsigned short back)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 1));
}