#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include "Colors.h"
#include "CursorPos.h"

using namespace std;

vector<string> mlbLogo(21);
vector<string> cubLogo(33);
vector<string> soxLogo(29);
string pos;
char posChar(79);
int intCol = 0;

//***********************
//* Selector Function	*
//*---------------------*
//*Selects the color	*
//***********************
void selFun() {

	// 1 = white
	// 2 = blue
	// 3 = red
	// 4 = black

	if (posChar == 'W')
	{
		intCol = 1;
	}
	else if (posChar == 'B')
	{
		intCol = 2;
	}
	else if (posChar == 'R')
	{
		intCol = 3;
	}
	else
	{
		intCol = 4;
	}

	switch (intCol)
	{
	case 1:
		color(255);
		break;
	case 2:
		color(153);
		break;
	case 3:
		color(204);
		break;
	case 4:
		color(0);
		break;
	default:
		cout << "Something went wrong...\n";
		break;
	}

}

//***************************
//* Print Graphic Function	*
//*-------------------------*
//*Prints the specified	logo*
//*vec - logo vector		*
//*size - vector size		*
//*len - element length		*
//***************************
void pGraph(vector<string> &vec, int size, int len) {

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < len; j++) {

			pos = vec[i];
			posChar = pos[j];

			selFun();

			cout << posChar;

		}

		cout << endl;

	}

}

//***********************
//*  MLB Logo Function	*
//*---------------------*
//*Prints the MLB logo	*
//***********************
void mlb() {

	mlbLogo = { "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWRRRRRRRRRRRRRRRRRRRRRRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWRRRRRRRRRRRRRRRRRRRRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWBBBBBBBWWWWWWRRRRRRRRRRRRRRRRRRRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWBBBBBWWWWWWRRRRRRRRRRRRRRRRRRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWBBBBBBWWWWWRRRRRRRRRRRRRRRRRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWBBBBBBBWWWWWRRRRRRRRRRRRRRRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWBBBBBBBWWWWWRRRRRRRRRRRRRRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWWWBBBBBBBBBBWWWWRRRRRRRRRRRRRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWBBBBBBBBBBBBWWWWRRRRRRRRRRRRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWBBBBBBBBBBBWWWWWWRRRRRRRRRRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRRRRRRRRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRRRRRRRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRRRRRRRW",
		"WBBBBBBBWWWWBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRRRRW",
		"WBBBBBBWWWWWWBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRRRW",
		"WBBBBBBBWWWWBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRRRRRW",
		"WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRRRRRRRRRRRRRW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" };

	pGraph(mlbLogo, (mlbLogo.size()), 78);

	dCol();

}

void cubG() {

	cubLogo = { "                  WBBBBBBBBBBBBBBBBBBBBBBW                  ",
		"               WBBBBBBBBBBBBBBBBBBBBBBBBBBBBW               ",
		"            WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBW             ",
		"           WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBW           ",
		"         WBBBBBBBBBBBBBWWWWWWWWWWWWWBBBBBBBBBBBBBBW         ",
		"       WBBBBBBBBBBBBWWWWWRRRRRRRRRRWWWWWBBBBBBBBBBBW        ",
		"      WBBBBBBBBBBBWWWRRRRRRRRRRRRRRRRRWWWWBBBBBBBBBBW       ",
		"     WBBBBBBBBBBWWWRRRRRRRRRRRRRRRRRRRRRWWWWBBBBBBBBBW      ",
		"    WBBBBBBBBBWWWRRRRRRRRRRRRRRRRRRRRRRRRRWWWBBBBBBBBBW     ",
		"   WBBBBBBBBBWWWRRRRRRRRRRRRRRRRRRRRRRRRRRRRWWBBBBBBBBBW    ",
		"   WBBBBBBBBWWWRRRRRRRRRRWWWWWWWWWRRRRRRRRRWWWWBBBBBBBBBW   ",
		"  WBBBBBBBBWWWRRRRRRRRRWWWWWWWWWWWWWRRRRRWWWWWWWBBBBBBBBW   ",
		"  WBBBBBBBBWWRRRRRRRRRWWWWWWWWWWWWWWWWRWWWWWWWWWWBBBBBBBBW  ",
		" WBBBBBBBBWWWRRRRRRRWWRRRWWRRRWRRRRRRRWWRRRRRRRWWBBBBBBBBW  ",
		" WBBBBBBBBWWRRRRRRRRWWRRRWWRRRWRRRRRRRRWRRRRRRRWWBBBBBBBBW  ",
		" WBBBBBBBBWWRRRRRRRRWWRRRWWRRRWRRRWWRRRWRRRWWWWWWWBBBBBBBW  ",
		" WBBBBBBBBWWRRRRRRRRWWRRRWWRRRWRRRRRRRWWRRRRRRRWWWBBBBBBBW  ",
		" WBBBBBBBBWWRRRRRRRRWWRRRWWRRRWRRRWWRRRWWWWWRRRWWWBBBBBBBW  ",
		" WBBBBBBBBWWRRRRRRRRWWRRRRRRRRWRRRRRRRWWRRRRRRRWWBBBBBBBBW  ",
		"  WBBBBBBBWWWRRRRRRRRWWWWWWWWWWWWWWWWWWWWWWWWWWWWBBBBBBBW   ",
		"  WBBBBBBBBWWRRRRRRRRRWWWWWWWWWWWWWWWWRRWWWWWWWWWBBBBBBBW   ",
		"  WBBBBBBBBWWWRRRRRRRRRWWWWWWWWWWWWWRRRRRWWWWWWWBBBBBBBBW   ",
		"   WBBBBBBBBWWWRRRRRRRRRRRWWWWWWWWRRRRRRRRRWWWWBBBBBBBBW    ",
		"    WBBBBBBBBWWWRRRRRRRRRRRRRRRRRRRRRRRRRRRRWWBBBBBBBBBW    ",
		"    WBBBBBBBBBWWWRRRRRRRRRRRRRRRRRRRRRRRRRWWWBBBBBBBBBW     ",
		"     WBBBBBBBBBBWWWRRRRRRRRRRRRRRRRRRRRRWWWWBBBBBBBBBW      ",
		"      WBBBBBBBBBBWWWWWRRRRRRRRRRRRRRRRWWWWBBBBBBBBBBW       ",
		"       WBBBBBBBBBBBBWWWWWWRRRRRRRRWWWWWWBBBBBBBBBBBW        ",
		"         WBBBBBBBBBBBBBWWWWWWWWWWWWWBBBBBBBBBBBBBW          ",
		"           WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBW           ",
		"             WBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBW             ",
		"               WBBBBBBBBBBBBBBBBBBBBBBBBBBBW                ",
		"                  WBBBBBBBBBBBBBBBBBBBBBW                   " };

	pGraph(cubLogo, (cubLogo.size()), 60);

	dCol();

}

void soxG() {

	soxLogo = { "                                                        WWWW           ",
		"                                                    WWWWWWWWWW         ",
		"                                                WWWWWWWWWWWWWW         ",
		"                                           WWWWWWWWWWWWWWWWWW          ",
		"                                       WWWW       WWWWWWWWWW           ",
		"                                    WWWWWW WWWWWW WWWWWWW              ",
		"                               WWWWWWWW WWWWWWWWWWWW WW                ",
		"                           WWWWWWWWWW WWWWWWWWWWWWWWWWWWWWW            ",
		"                       WWWWWWWWWWWWW WWWWWWWWWWWWWWWWWWWWWWWW          ",
		"                   WWWWWWWWWWWWWWWW  WWWWWWWWWWWWWWWWWW                ",
		"               WWWWWWWWWWWWWWWWWW   WWWWWWWWWWWWWWWWWWWW               ",
		"            WWWWWWWWWWWWWW           WWWWWWWWWWWWWWWWWW                ",
		"     RRRRRR  WWWWWWWWW                WWWWWWWWWWWWWWWW                 ",
		"WW  RRRRRRRR  WWWWWWWWWWWWWWWWWWWWWW WWWWWWWWWWWWWWWw                  ",
		"WW  RRRRRRRR  WWWWWWWWWWWWWWWWWWWWWW WWWWWWWWWWWWWWWWWWWWWW            ",
		"WW  RRRRRRRR  WWWWWWWWWWWWWWWWWWWWW WWWWWWWWWWWWWWWWWWWWWWWWWWW        ",
		"     RRRRRR          WWWWWWWWWWWWWW WWWWWWWWWWWWWWWWWWWWWWWWWWWWW      ",
		"                                    W    WWWWWWWWWWWWWWWWWWWWWWWWWWWW  ",
		"                                          WWWWWWWWWWWWWWWWWWWWWWWWWWWw ",
		"                                         WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"                                                       WWWWWWW         ",
		" WWWWWWWWWWWWWWWWWWWWW  WWWWWWWWWWWWWWWWWWWWW  WWWWWWWW  WWW  WWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWW WWWWWWWWWWWWWWWWWWWWWWW WWWWWWWWWW   WWWWWWWWWWW",
		"WWWWWW                 WWWWWW           WWWWWW      WWWWWWWWWWWWWW     ",
		"WWWWWWWWWWWWWWWWWWWWW  WWWWWW           WWWWWW       WWWWWWWWWWWW      ",
		" WWWWWWWWWWWWWWWWWWWWW WWWWWW           WWWWWW        WWWWWWWWWW       ",
		"                WWWWWW WWWWWW           WWWWWW      WWWWWWWWWWWWWW     ",
		"WWWWWWWWWWWWWWWWWWWWWW WWWWWWWWWWWWWWWWWWWWWWW WWWWWWWWWWW  WWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWW   WWWWWWWWWWWWWWWWWWWWW  WWWWWWWWWW    WWWWWWWWWW" };

	pGraph(soxLogo, (soxLogo.size()), 71);

	dCol();

}

#pragma region BIG_LETTERS
//***************************
//*	 Big Letter Variables	*
//***************************

//***********************
//*	    Dalek Vars		*
//***********************
string d1 = "                    Exterminate!\n";
string d2 = "                   /\n";
string d3 = "              ___\n";
string d4 = "      D>=G==='   '.\n";
string d5 = "            |======|\n";
string d6 = "            |======|\n";
string d7 = "        )--/]IIIIII]\n";
string d8 = "           |_______|\n";
string d9 = "           C O O O D\n";
string d10 = "          C O  O  O D\n";
string d11 = "         C  O  O  O  D\n";
string d12 = "         C__O__O__O__D\n";
string d13 = "        [_____________]\n";

//***********************
//*	  Police Box Vars	*
//***********************
string pb[30] = { "                 _.--._\n",
"                 _|__|_\n",
"     _____________|__|_____________\n",
"  .-'______________________________'-.\n",
"  | |________POLICE___BOX__________| |\n",
"  |  |============================|  |\n",
"  |  | .-----------..-----------. |  |\n",
"  |  | |  _  _  _  ||  _  _  _  | |  |\n",
"  |  | | | || || | || | || || | | |  |\n",
"  |  | | |_||_||_| || |_||_||_| | |  |\n",
"  |  | | | || || | || | || || | | |  |\n",
"  |  | | |_||_||_| || |_||_||_| | |  |\n",
"  |  | |  _______  ||  _______  | |  |\n",
"  |  | | |       | || |       | | |  |\n",
"  |  | | |       | || |       | | |  |\n",
"  |  | | |       | || |       | | |  |\n",
"  |  | | |_______| || |_______| | |  |\n",
"  |  | |  _______ @||@ _______  | |  |\n",
"  |  | | |       | || |       | | |  |\n",
"  |  | | |       | || |       | | |  |\n",
"  |  | | |       | || |       | | |  |\n",
"  |  | | |_______| || |_______| | |  |\n",
"  |  | |  _______  ||  _______  | |  |\n",
"  |  | | |       | || |       | | |  |\n",
"  |  | | |       | || |       | | |  |\n",
"  |  | | |       | || |       | | |  |\n",
"  |  | | |_______| || |_______| | |  |\n",
"  |  | '-----------''-----------' |  |\n",
" _|__|/__________________________\\|__|_ \n",
"'----'----------------------------'----'\n" };

//***********************
//*	  Baseball Vars		*
//***********************
string b1 = " ____                 _           _ _ \n";
string b2 = "|  _ \\               | |         | | |\n";
string b3 = "| |_) | __ _ ___  ___| |__   __ _| | |\n";
string b4 = "|  _ < / _` / __|/ _ \\ '_ \\ / _` | | |\n";
string b5 = "| |_) | (_| \\__ \\  __/ |_) | (_| | | |\n";
string b6 = "|____/ \\__,_|___/\\___|_.__/ \\__,_|_|_|\n";

//***********************
//*		Menu Vars		*
//***********************
string mg1 = " __  __                  \n";
string mg2 = "|  \\/  |                 \n";
string mg3 = "| \\  / | ___ _ __  _   _ \n";
string mg4 = "| |\\/| |/ _ \\ '_ \\| | | |\n";
string mg5 = "| |  | |  __/ | | | |_| |\n";
string mg6 = "|_|  |_|\\___|_| |_|\\__,_|\n";

//***********************
//*		VS. Vars		*
//***********************
string v1 = "\t\t____    ____      _______.    \n";
string v2 = "\t\t\\   \\  /   /     /       |    \n";
string v3 = "\t\t \\   \\/   /     |   (----`    \n";
string v4 = "\t\t  \\      /       \\   \\        \n";
string v5 = "\t\t   \\    /    .----)   |    __ \n";
string v6 = "\t\t    \\__/     |_______/    (__)\n";

//***********************
//*		Rules Vars		*
//***********************
string ru1 = "      ___           ___           ___       ___           ___     \n";
string ru2 = "     /  /\\         /  /\\         /  /\\     /  /\\         /  /\\    \n";
string ru3 = "    /  /::\\       /  /:/        /  /:/    /  /::\\       /  /::\\   \n";
string ru4 = "   /  /:/\\:\\     /  /:/        /  /:/    /  /:/\\:\\     /__/:/\\:\\  \n";
string ru5 = "  /  /::\\ \\:\\   /  /:/        /  /:/    /  /::\\ \\:\\   _\\_ \\:\\ \\:\\ \n";
string ru6 = " /__/:/\\:\\_\\:\\ /__/:/     /\\ /__/:/    /__/:/\\:\\ \\:\\ /__/\\ \\:\\ \\:\\\n";
string ru7 = " \\__\\/~|::\\/:/ \\  \\:\\    /:/ \\  \\:\\    \\  \\:\\ \\:\\_\\/ \\  \\:\\ \\:\\_\\/\n";
string ru8 = "    |  |:|::/   \\  \\:\\  /:/   \\  \\:\\    \\  \\:\\ \\:\\    \\  \\:\\_\\:\\  \n";
string ru9 = "    |  |:|\\/     \\  \\:\\/:/     \\  \\:\\    \\  \\:\\_\\/     \\  \\:\\/:/  \n";
string ru10 = "    |__|:|~       \\  \\::/       \\  \\:\\    \\  \\:\\        \\  \\::/   \n";
string ru11 = "     \\__\\|         \\__\\/         \\__\\/     \\__\\/         \\__\\/    \n";

//***********************
//*	    Print "Menu"	*
//*---------------------*
//*Prints the menu big	*
//*letters graphic		*
//***********************
void menG() {

	gotoxy(0, 6);
	color(7);
	cout << mg1 << mg2 << mg3 << mg4 << mg5 << mg6 << endl;
	dCol();

}

//***********************
//*	    Print Rules		*
//*---------------------*
//*Prints the rules big	*
//*letters graphic		*
//***********************
void rus() {

	color(11);
	cout << ru1 << ru2 << ru3 << ru4 << ru5
		<< ru6 << ru7 << ru8 << ru9 << ru10
		<< ru11 << endl << endl;
	dCol();

}

//***********************
//*	   Print Baseball	*
//*---------------------*
//*Prints the baseball	*
//*big letters graphic	*
//***********************
void bbG() {

	gotoxy(0, 0);
	color(14);
	cout << b1 << b2 << b3 << b4 << b5 << b6;

}

//***********************
//*	     Print VS. 		*
//*---------------------*
//*Prints the VS. big	*
//*letters graphic		*
//***********************
void vsG() {

	color(12);
	cout << endl << endl << endl << endl << endl << endl;
	cout << v1 << v2 << v3 << v4 << v5 << v6 << endl;
	dCol();

}

//***********************
//*	   Dalek Graphic 	*
//*---------------------*
//*Prints the Dalek pic	*
//***********************
void dalek() {

	color(6);
	cout << d1 << d2 << d3 << d4 << d5
		<< d6 << d7 << d8 << d9 <<
		d10 << d11 << d12 << d13;
	dCol();

}

//***********************
//*	Police Box Graphic 	*
//*---------------------*
//*Prints the police box*
//*pic					*
//***********************
void policeBox() {

	color(9);
	for (int i = 0; i < 30; i++)
	{
		gotoxy(39, i);
		cout << pb[i];
	}
	dCol();

}

#pragma endregion BIG_LETTERS