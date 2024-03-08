#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

//*******************
//* Used for goto() *
//*******************
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

#pragma region Cursor_Position
//***********************
//*	  Cursor Position	*
//*		 Function		*
//*---------------------*
//*Changes the cursor	*
//*position to print to	*
//*the console screen in*
//*a specific coordinate*
//***********************
void gotoxy(int column, int line) {
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);
}

//*******************************
//*wherex(), wherey() return	*
//*the current position of the	*
//*cursor						*
//*******************************
int wherex() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD                      result;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
		))
		return -1;
	result = csbi.dwCursorPosition;
	return result.X;
}

int wherey() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD                      result;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
		))
		return -1;
	result = csbi.dwCursorPosition;
	return result.Y;
}

//Menu cursor position
void gotoXY(int x2, int y)
{
	CursorPosition.X = x2;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
#pragma endregion Cursor_Position