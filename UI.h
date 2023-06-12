#pragma once
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>

using namespace std;

/* 함수 목록 */
void size_set(int, int);   // 콘솔창의 크기 제어
void goto_point(int, int); // 콘솔창의 커서 위치 변경
void draw_line();          // 콘솔창에 라인 그리기
void show_mainmenu();      // 메인메뉴 불러오기
void setcolor(unsigned short , unsigned short ); // 콘솔창 글씨 색깔 변경