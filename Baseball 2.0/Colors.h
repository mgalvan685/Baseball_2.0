#pragma once

#include <Windows.h>

WORD Attributes = 0;
HANDLE hConsole;

//***********************
//*	   Change Colors	*
//***********************
void color(int k) {

	SetConsoleTextAttribute(hConsole, k);

}

//***********************
//*	   Default Color	*
//*---------------------*
//*Sets the text color	*
//*light green			*
//***********************
void dCol() {

	SetConsoleTextAttribute(hConsole, 10);

}