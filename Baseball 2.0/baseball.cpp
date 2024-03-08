// Name: Matt Galvan
// Summary: Baseball game version 2.0
//
// - Made improvements to printing the graphics in Graphics.h
// - Added Colors.h
// - Used <random> instead of rand() for more accurate number generation - placed in RNG.h
// - Added HitChance.h
// - Reworked r() to incorporate HitChance.h
// - Added CursorPos.h, RNG.h
// - Added a pitch counter to the bottom right of the scoreboard
// - Add pitcher's name to the bottom right of the scoreboard
// 
// 
// TODO:
// - Make the players structure into a class
//		- Calculate stats from this instead of a function
//		- Need to add more stats and players
// - Rework the random number outcomes
//		- Have 2 sererate 1-20 numbers for hittable and nonhittable pitches
//		- Incorporate ground outs, outs at second and 3rd, etc.
// - Add on base graphics
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <Windows.h>
#include "Colors.h"
#include "Graphics.h"
#include "HitChance.h"
#include "RNG.h"
#include "CursorPos.h"
#pragma comment(lib, "winmm.lib")

using namespace std;

//***********************
//*     Prototypes		*
//***********************
void reset();
void calc();
void wl();
void validate(string);

#pragma region VARS

#pragma region IO_FILE_VARS
//***************************************************
//*				  I/O File variables				*
//*-------------------------------------------------*
//*fc = game counter file							*
//*ofs = report file								*
//*sstats = stats file								*
//*file1 = file to read in player names and stats,	*
//*			used in players().						*
//*flie2 = game 2 report file name					*
//*file3 = game 2 stats csv file name				*
//*file4 = game 1 report file name					*
//*file5 = game 1 stats csv file name				*
//*file6 = copy of game 1 stats file name			*
//*file7 = game counter file name					*
//*drFile = Dr. Who player stats					*
//*game2 = false: it's game 1, true: it's game 2	*
//*game = holds game number							*
//***************************************************
ifstream fc("filecounter.txt");
ofstream ofs;
fstream sstats;
string file1;
string file2 = "Galvan_Game2_Lab23.txt";
string file3 = "Galvan_Game2_Stats.csv";
string file4 = "Galvan_lab23.txt";
string file5 = "Galvan_Stats.csv";
string file6 = "Galvan_Game2_Stats_Copy.csv";
string file7 = "filecounter.txt";
string drFile = "DrWho.csv";
string fin1 = "1", fin2 = "2";
boolean game2 = false;
int game;
#pragma endregion IO_FILE_VARS

#pragma region OUTPUT_FILE_VARS
//***************************************
//*			Output File variables		*
//*-------------------------------------*
//*no = eof message						*
//*hard = student name					*
//*coding = date and course number		*
//*of = what was printed in the report	*
//*anything = final message				*
//*labn = lab number					*
//*hdr1 = header text					*
//*ftr1 = footer text					*
//*g1 = game 1 text						*
//*g2 = game 2 text						*
//***************************************
string no = "EoF Message ";
string hard = " Matt Galvan ";
string coding = "5/09/2016, CIS 2541-003 ";
string of = "Baseball stats and scoreboard ";
string anything = "Goodbye. ";
string labn = "Lab27";
string hdr1 = "Player stats and scoreboard for Baseball";
string ftr1 = "Printed the player stats and scoreboard";
string g1 = "Game 1";
string g2 = "Game 2";
#pragma endregion OUTPUT_FILE_VARS

#pragma region BOXES_VARS
//***************************
//*		  Box variables		*
//*-------------------------*
//*box1 = the - for boxes	*
//*box2 = the | for boxes	*
//***************************
string box1 = "-";
string box2 = "|";
#pragma endregion BOXES_VARS

#pragma region CHAR_VARS
//***********************
//* Character variables	*
//*---------------------*
//*col = a :			*
//*com = a ,			*
//***********************
string col = ":";
string com = ",";
#pragma endregion CHAR_VARS

#pragma region PLAYER_STRUCTURE
//***************************
//*	    Player Structure	*
//*-------------------------*
//*Creates the player		*
//*structure				*
//*							*
//*name = player name		*
//*hr = home runs			*
//*so = strike outs			*
//*s = singles				*
//*d = doubles				*
//*t = triples				*
//*ab = at bats				*
//*oba = on base average	*
//*bavg = batting average	*
//*onBase = true if player	*
//*			is on base		*
//*bp = base position		*
//*		0 - not on base		*
//*		1 - first base		*
//*		2 - second base		*
//*		3 - third base		*
//*		4+- home base		*
//***************************
struct plr
{
	string name;
	int hr;
	int so;
	int s;
	int d;
	int t;
	int ab;
	double oba;
	double bavg;
	bool onBase;
	int bp;
};
#pragma endregion PLAYER_STRUCTURE

//************************
//*Lab Specific Variables*
//************************
#pragma region PLAYER_VARS
//***************************
//*    Player Variables		*
//*-------------------------*
//*p = player structure		*
//*plrs = player info vector*
//***************************
plr p;
vector<plr> plrs(18);
#pragma endregion PLAYER_VARS

#pragma region STATS_VARS
//*******************************************
//*				Stats Variables				*
//*-----------------------------------------*
//*stats = stats heading					*
//*ps = Player Stats text					*
//*temp = holds temp info when reading in	*
//*			player info. Used in players()	*
//*avg = holds oba and bavg for a player	*
//*******************************************
string stats[9] = { "Player", "HR", "SO", "S", "D", "T", "AB", "OBA", "BAVG" };
string ps = "Player Stats";
string temp;
double avg;
#pragma endregion STATS_VARS

#pragma region TEAM_VARS
//***************************
//*		 Team Variables		*
//*-------------------------*
//*tA, tB = team names		*
//*batA, batB = who's up to	*
//*				bat			*
//*bat = who's up to bat,	*
//*		passed into hit()	*
//***************************
string tA = "White Sox";
string tB = "Cubs";
int batA = 0, batB = 9, bat;
#pragma endregion TEAM_VARS

#pragma region COLOR_VARS
//***************************
//*	    Color Variables		*
//*-------------------------*
//*k = used to select color	*
//*		number for color()	*
//*sc = teamA color number	*
//*		for scoreboard		*
//*cc = teamB color number	*
//*		for scoreboard		*
//***************************
int k, sc = 8, cc = 9;
#pragma endregion COLOR_VARS

#pragma region MENU_VARS
//*******************************
//*		  Menu Variables		*
//*-----------------------------*
//*one, two, three, four, five	*
//*six = menu choices text		*
//*q = quit text				*
//*sel = Selection text			*
//*inv = invalid choice text	*
//*in = inning text				*
//*ng = game in progress text	*
//*curInn = current inning text	*
//*load = cheat option			*
//*warn = used in newgame()		*
//*opt = string selection option*
//*ecode = enter code string	*
//*menu_item = menu item number	*
//*x2 = default x for menu items*
//*running = used to quit		*
//*option = opt converted to int*
//*******************************
string one = "1. Play 1 inning (Sloooooow)";
string two = "2. Play the rest of the game";
string three = "3. Play full game (Fast!)";
string four = "4. View Player Stats";
string five = "5. View Scoreboard";
string six = "6. Rules";
string seven = "7. Enter Code";
string q = "8. Quit";
string sel = "SELECT: ";
string inv = "Invalid selection. Try again.";
string in = "Inning";
string ng = "There is no game currently in progress.";
string curInn = "Current Inning: ";
string load = "Loading new players...";
string warn = "Starting a new game will clear the previous scores and will not save them to the .txt file. Would you like to continue (y or n)? ";
string ecode = "Enter code: ";
string opt;
int menu_item = 0, x2 = 13, option;
bool running = true;
#pragma endregion MENU_VARS

#pragma region GAME_PLAY_VARS
//*******************************
//*		Game Play Variables		*
//*-----------------------------*
//*String variables that are	*
//*used during game play. If you*
//*can't figure out what they're*
//*used for, you need to go back*
//*to 1400.						*
//*up = is true while the batter*
//*		is up to bat			*
//*isTie = if it's a tie game	*
//*isOver = is the game over?	*
//*aUp, bUp = team up to bat	*
//*num = holds random number	*
//*strike, ball, outs = holds	*
//*		those numbers for each	*
//*		at bat					*
//*inNum = holds inning number	*
//*n = number of innings to play*
//*wb = used to determine if	*
//*		someone is on the next	*
//*		base during a walk		*
//*x = default x coordinate		*
//*		position				*
//*slp1, slp2 = holds values for*
//*				sleep commands	*
//*spc = Sox pitch counter		*
//*cpc = Cubs pitch counter		*
//*******************************
string tau = "White Sox are up to bat\n";
string tbu = "Cubs are up to bat\n";
string strikeStr = "Strikes : ";
string ballStr = "Balls   : ";
string outStr = "Outs    : ";
string abStr = "At Bat  : ";
string pscore = " has scored!";
string ha = " hit a ";
string ga = " got a ";
string ghr = " got a hit, resulting in a ";
string ge = " got to first on an ";
string hs = "SINGLE!";
string hd = "DOUBLE!";
string ht = "TRIPLE!";
string homer = "HOME RUN!";
string hw = "WALK!";
string he = "ERROR.";
string hso = " STRUCK OUT.";
string fo = "FLY OUT.";
string ins = "Inning: ";
string w = " won the game!";
string tie = "Due to some shady practices, the White Sox have been awarded an extra point and have won the game!";
bool up = true, isTie = false, isOver = false, aUp = false, bUp = false;
int num, strike = 0, ball = 0, outs = 0, inNum = 1, n = 0, wb = 1, x = 14, slp1, slp2, spc = 0, cpc = 0;
#pragma endregion GAME_PLAY_VARS

#pragma region SCOREBOARD_VARS
//***************************
//*	 Scoreboard Variables	*
//*-------------------------*
//*sb = scoreboard text		*
//*inning = holds scoreboard*
//*			header text		*
//*scoreA, scoreB = holds	*
//*		game scoring and	*
//*		stats for each team	*
//***************************
string sb = "Scoreboard";
string inning[12] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "R", "H", "E" };
int scoreA[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int scoreB[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#pragma endregion SCOREBOARD_VARS

#pragma region RULES_VARS
//***************************
//*		Rules Variables		*
//*-------------------------*
//*Variables for printing	*
//*the rules screen.		*
//***************************
string key = "Stats Key:\nHR   = Home Runs\nSO   = Strike Outs\nS    = Single\nD    = Double\nT    = Triple\nAB   = At Bats\nOBA  = On Base Average\nBAVG = Batting Average";
string rnd1 = "|-------------------------------|\n";
string rnd2 = "|  1 |Foul\t|  2 |Single\t|\n";
string rnd3 = "|  3 |Foul\t|  4 |Double\t|\n";
string rnd4 = "|  5 |Foul\t|  6 |Triple\t|\n";
string rnd5 = "|  7 |Foul\t|  8 |Home Run\t|\n";
string rnd6 = "|  9 |Strike\t| 10 |Ball\t|\n";
string rnd7 = "| 11 |Strike\t| 12 |Ball\t|\n";
string rnd8 = "| 13 |Strike\t| 14 |Ball\t|\n";
string rnd9 = "| 15 |Strike\t| 16 |Ball\t|\n";
string rnd10 = "| 17 |Strike\t| 18 |Ball\t|\n";
string rnd11 = "| 19 |Fly Out\t| 20 |Error\t|\n";
#pragma endregion RULES_VARS
#pragma endregion VARS

//***********************
//*    Pause Function	*
//*---------------------*
//*Creates 2 blank lines*
//*then pauses the game *
//***********************
void pause() {
	cout << endl << endl;
	system("PAUSE");
}

//************************
//* Open Files Function  *
//*----------------------*
//*Opens correct files	 *
//************************
void oFiles() {

	fc >> game;
	if (game == 2) {
		file1 = "Galvan_Stats.csv";
		ofs.open(file2, ios::app);
		sstats.open(file3);
		fc.close();
		game2 = true;
	}
	else {
		file1 = "PlayerInfo.csv";
		fc.close();
		ofs.open(file4);
		sstats.open(file5);
	}

}

//***********************
//*Player Stats Function*
//*---------------------*
//*Reads in player stats*
//***********************
void players() {

	fstream csv(file1);

	for (int i = 0; i < (int)plrs.size(); i++)
	{
		getline(csv, temp, ',');
		plrs[i].name = temp;
		getline(csv, temp, ',');
		plrs[i].hr = atoi(temp.c_str());
		getline(csv, temp, ',');
		plrs[i].so = atoi(temp.c_str());
		getline(csv, temp, ',');
		plrs[i].s = atoi(temp.c_str());
		getline(csv, temp, ',');
		plrs[i].d = atoi(temp.c_str());
		getline(csv, temp, ',');
		plrs[i].t = atoi(temp.c_str());
		getline(csv, temp, ',');
		plrs[i].ab = atoi(temp.c_str());
		getline(csv, temp, ',');
		plrs[i].oba = atof(temp.c_str());
		getline(csv, temp, '\n');
		plrs[i].bavg = atof(temp.c_str());
		p.onBase = false;
		p.bp = 0;
	}
	csv.close();

}

#pragma region TXT_FILE_FUNCTIONS
//***********************
//*	  .txt file Box		*
//*		 Function		*
//*---------------------*
//*Creates the - part of*
//*the boxes			*
//***********************
void box() {

	ofs << box2;

	for (int i = 1; i < 83; i++)
	{
		ofs << box1;
	}

	ofs << box2 << endl;

}

//***********************
//*	  .txt blank Box	*
//*		 Function		*
//*---------------------*
//*Creates blank boxes	*
//***********************
void blankBox() {

	ofs << box2 << right << setw(83) <<
		box2 << endl;

}


//***********************
//*		Console Box		*
//*		 Function		*
//*---------------------*
//*Creates the boxes for*
//*the console			*
//***********************
void cbox(int z) {

	cout << box2;

	for (int i = 1; i < z; i++)
	{
		cout << box1;
	}

	cout << box2 << endl;

}


//***********************
//*	     EOF Message	*
//***********************
void eof() {

	box();

	ofs << box2 << no << hard << coding
		<< of << setw(4) << box2 << endl
		<< box2 << anything << labn <<
		setw(69) << box2 << endl;

	box();

}


//***********************
//*	  Header Message	*
//***********************
void hdr() {

	box();

	ofs << box2 << hdr1 << hard <<
		coding << labn <<
		box2 << endl;

	box();

	blankBox();

}


//***********************
//*    Footer Message	*
//***********************
void ftr() {

	box();

	ofs << box2 << left << setw(82) << ftr1 <<
		box2 << endl;

	box();

	blankBox();

}
#pragma endregion TXT_FILE_FUNCTIONS

//***********************
//*	Console Stats Header*
//*   Output Function 	*
//*---------------------*
//*Prints out the header*
//*for the player stats *
//***********************
void hout() {

	cout << box2 << left << setw(20) << stats[0] <<
		box2 << setw(5) << stats[1] <<
		box2 << setw(5) << stats[2] <<
		box2 << setw(5) << stats[3] <<
		box2 << setw(5) << stats[4] <<
		box2 << setw(5) << stats[5] <<
		box2 << setw(5) << stats[6] <<
		box2 << setw(5) << stats[7] <<
		box2 << setw(5) << stats[8] <<
		box2 << endl;

}

//***********************
//*	   Console Stats	*
//*   Output Function 	*
//*---------------------*
//*Prints out the player*
//*stats on the console *
//***********************
void psprint(int i) {

	cout << box2 << left << setw(20) << plrs[i].name << box2;
	cout << setw(5) << right << plrs[i].hr << box2
		<< setw(5) << plrs[i].so << box2
		<< setw(5) << plrs[i].s << box2
		<< setw(5) << plrs[i].d << box2
		<< setw(5) << plrs[i].t << box2
		<< setw(5) << plrs[i].ab << box2
		<< setw(5) << plrs[i].oba << box2
		<< setw(5) << plrs[i].bavg << box2
		<< endl;

}

//***********************
//*	  Text File Stats	*
//*   Output Function 	*
//*---------------------*
//*Prints out the player*
//*stats to the output  *
//*file					*
//***********************
void psoprint(int i) {

	ofs << box2 << left << setw(26) << plrs[i].name << box2;
	ofs << setw(6) << right << plrs[i].hr << box2
		<< setw(6) << plrs[i].so << box2
		<< setw(6) << plrs[i].s << box2
		<< setw(6) << plrs[i].d << box2
		<< setw(6) << plrs[i].t << box2
		<< setw(6) << plrs[i].ab << box2
		<< setw(6) << plrs[i].oba << box2
		<< setw(6) << plrs[i].bavg << box2
		<< endl;

}

//***********************
//*	   Stats Console	*
//*   Output Function 	*
//*---------------------*
//*Prints the stats to  *
//*the console			*
//***********************
void sout() {

	system("CLS");

	cbox(69);
	cout << box2 << left << setw(68) << tA << box2 << endl;
	cbox(69);
	hout();
	cbox(69);
	for (int i = 0; i < 9; i++)
	{
		psprint(i);
	}
	cbox(69);
	cout << box2 << left << setw(68) << tB << box2 << endl;
	cbox(69);
	hout();
	cbox(69);
	for (int i = 9; i < (int)plrs.size(); i++)
	{
		psprint(i);
	}
	cbox(69);

	pause();

}

//***********************
//*	   Player Stats		*
//*   Output Function 	*
//*---------------------*
//*Prints the stats to  *
//*the output file		*
//***********************
void pout() {

	box();
	ofs << box2 << left << setw(82) << ps << box2 << endl;
	box();
	ofs << box2 << left << setw(82) << tA << box2 << endl;
	box();
	ofs << box2 << left << setw(26) << stats[0] <<
		box2 << setw(6) << stats[1] <<
		box2 << setw(6) << stats[2] <<
		box2 << setw(6) << stats[3] <<
		box2 << setw(6) << stats[4] <<
		box2 << setw(6) << stats[5] <<
		box2 << setw(6) << stats[6] <<
		box2 << setw(6) << stats[7] <<
		box2 << setw(6) << stats[8] <<
		box2 << endl;
	box();
	for (int i = 0; i < 9; i++)
	{
		psoprint(i);
	}
	box();
	box();
	ofs << box2 << left << setw(82) << tB << box2 << endl;
	box();
	ofs << box2 << left << setw(26) << stats[0] <<
		box2 << setw(6) << stats[1] <<
		box2 << setw(6) << stats[2] <<
		box2 << setw(6) << stats[3] <<
		box2 << setw(6) << stats[4] <<
		box2 << setw(6) << stats[5] <<
		box2 << setw(6) << stats[6] <<
		box2 << setw(6) << stats[7] <<
		box2 << setw(6) << stats[8] <<
		box2 << endl;
	box();
	for (int i = 9; i < (int)plrs.size(); i++)
	{
		psoprint(i);
	}
	box();

}

//***********************
//*	   Score Console	*
//*   Output Function 	*
//*---------------------*
//*Prints the scoreboard*
//*to the console		*
//***********************
void sboard() {

	gotoxy(0, 0);

	cbox(69);
	cout << box2 << left << setw(20) << in << box2;
	//*******************************************************
	//*Prints and creates the inning number blinking effect	*
	//*******************************************************
	for (int i = 0; i < 12; i++)
	{
		if ((i + 1) == inNum)
		{
		//	if (k == 6)
		//	{
		//		k = 14;
			color(14);
		//	}
		//	else {
		//		k = 6;
		//	}
		//	color(k);
		}
		cout << setw(3) << right << inning[i];
		dCol();
		cout << box2;
	}
	cout << endl;
	cbox(69);
	cout << box2;
	//***************************************************************
	//*If team A is up, creates the inning number blinking effect	*
	//***************************************************************
	if (aUp) {
	//	if (sc == 23)
	//	{
	//		sc = 7;
	//	}
	//	else {
	//		sc = 23;
	//	}
		sc = 23;
	}
	else {
		sc = 7;
	}
	color(sc);
	cout << left << setw(20) << tA;
	dCol();
	cout << box2;
	//***************************************************************
	//*Prints the inning score. Changes color to black if it is not *
	//*the current or past inning									*
	//***************************************************************
	for (int i = 0; i < 12; i++)
	{
		if (scoreA[i] == 0 && i < 9 && i >(inNum - 1))
		{
			color(0);
		}
		cout << right << setw(3) << scoreA[i];
		dCol();
		cout << box2;
	}
	cout << endl;
	cbox(69);
	cout << box2;
	//***************************************************************
	//*If team B is up, creates the inning number blinking effect	*
	//***************************************************************
	if (bUp) {
	//	if (cc == 23)
	//	{
	//		cc = 11;
	//	}
	//	else {
	//		cc = 23;
	//	}
		cc = 23;
	}
	else {
		cc = 11;
	}
	color(cc);
	cout << left << setw(20) << tB;
	dCol();
	cout << box2;
	//***************************************************************
	//*Prints the inning score. Changes color to black if it is not *
	//*the current or past inning									*
	//***************************************************************
	for (int i = 0; i < 12; i++)
	{
		if (scoreB[i] == 0 && i < 9 && i >(inNum - 1))
		{
			color(0);
		}
		cout << right << setw(3) << scoreB[i];
		dCol();
		cout << box2;
	}
	cout << endl;
	cbox(69);

	//***************************************************************
	//*Prints pitcher name and pitch count							*
	//***************************************************************
	if (aUp)
	{
		gotoxy(45, 7); cout << "Pitcher :" << right << setw(16) << "J. Lester";
		gotoxy(45, 8); cout << "Pitches :" << right << setw(16) << cpc;
	}
	else {
		gotoxy(45, 7); cout << "Pitcher :" << right << setw(16) << "J. Quintana";
		gotoxy(45, 8); cout << "Pitches :" << right << setw(16) << spc;
	}
	
	gotoxy(0, 7);
	cout << strikeStr << strike << endl;
	cout << ballStr << ball << endl;
	cout << outStr << endl << endl;

}

//***********************
//*		Scoreboard		*
//*   Output Function 	*
//*Prints the scoreboard*
//*to the output file	*
//***********************
void sbout() {

	box();
	ofs << box2 << left << setw(82) << sb << box2 << endl;
	box();
	ofs << box2 << left << setw(22) << in << box2;
	//***********************
	//*Scoreboard header	*
	//***********************
	for (int i = 0; i < 12; i++)
	{
		ofs << setw(4) << right << inning[i] << box2;
	}
	ofs << endl;
	box();
	ofs << box2 << left << setw(22) << tA << box2;
	//***********************
	//*Team A score			*
	//***********************
	for (int i = 0; i < 12; i++)
	{
		ofs << right << setw(4) << scoreA[i] << box2;
	}
	ofs << endl;
	box();
	ofs << box2 << left << setw(22) << tB << box2;
	//***********************
	//*Team B score			*
	//***********************
	for (int i = 0; i < 12; i++)
	{
		ofs << right << setw(4) << scoreB[i] << box2;
	}
	ofs << endl;
	box();
	blankBox();

}

#pragma region PLAY_BALL
//***********************
//*	  Score Function	*
//*---------------------*
//*Determines who scored*
//*for which team		*
//***********************
void score(int i) {

	gotoxy(0, (x + 2));

	if (i < 9)
	{
		scoreA[(inNum - 1)] += 1;
		scoreA[9] += 1;
	}
	else {
		scoreB[(inNum - 1)] += 1;
		scoreB[9] += 1;
	}
	plrs[i].bp = 0;
	plrs[i].onBase = false;
	cout << plrs[i].name << left << setw(50) << pscore;
	Sleep(slp1);

}

//***********************
//*	    Hit Function	*
//*---------------------*
//*Advances the players *
//*to the correct base	*
//*after each hit		*
//***********************
void hit(int bat, int addB) {

	up = false;
	plrs[bat].onBase = true;
	plrs[bat].bp += addB;

	if (bat < 9)
	{
		scoreA[10]++;
	}
	else {
		scoreB[10]++;
	}

	for (int i = 0; i < (int)plrs.size(); i++)
	{
		if (i != bat)
		{
			if (plrs[i].onBase) {
				plrs[i].bp += addB;
			}

		}
		if (plrs[i].bp >= 4)
		{
			score(i);
		}
	}

}

//***********************
//*	   Walk Function	*
//*---------------------*
//*Advances the players *
//*to the appropriate	*
//*base after a walk (a	*
//*player does not go to*
//*the next base unless *
//*they are occupying	*
//*the next base)		*
//***********************
void walk(int bat) {

	plrs[bat].s++;
	up = false;
	plrs[bat].onBase = true;
	plrs[bat].bp++;
	for (int i = 0; i < (int)plrs.size(); i++)
	{
		if (i == bat) continue;

		if (plrs[i].bp == wb)
		{
			plrs[i].bp++;
			wb++;
			for (int j = 0; j < (int)plrs.size(); j++)
			{
				if (j == bat || j == i) continue;
				if (plrs[j].bp == wb)
				{
					plrs[j].bp++;
					wb++;
					for (int l = 0; l < (int)plrs.size(); l++)
					{
						if (l == bat || l == j || l == i) continue;
						if (plrs[l].bp == wb)
						{
							plrs[l].bp++;
						}
					}
				}
			}
		}
	}
	wb = 1;
	for (int i = 0; i < (int)plrs.size(); i++)
	{
		if (plrs[i].bp >= 4)
		{
			score(i);
		}
	}

}

//***********************
//*Reset Inning Function*
//*---------------------*
//*Resets strike and	*
//*ball variables. Also *
//*resets if the playser*
//*is up for each inning*
//***********************
void reset() {

	strike = 0;
	ball = 0;
	up = true;

}

//***********************
//*Rand Number Function *
//*---------------------*
//*Determines outcome of*
//*each pitch/at bat	*
//***********************
bool isHit = false;

void r(int bat, int pitchC) {

	gotoxy(0, x);
	cout << "Here comes pitch " << pitchC << left << setw(70) << "...";
	Sleep(slp2);

	isHit = hitChk(.255);

	if (isHit)
	{
		do {
			num = rng(1, 20);
		} while ((num % 2) != 0);
	}
	else
	{
		do {
			num = rng(1, 20);
		} while ((num % 2) == 0);
	}

	switch (num)
	{
	case 1:
	case 3:
	case 5:
	case 7:
		//***************************************
		//*Foul ball							*
		//*If foul and not strike 2, increase	*
		//*number of strikes					*
		//***************************************
		gotoxy(0, x);
		cout << plrs[bat].name << ha << left << setw(70) << "FOUL BALL.";
		if (strike < 2)
		{
			strike += 1;
		}
		break;
	case 2:
		//***************
		//*Single		*
		//***************
		gotoxy(0, x);
		cout << plrs[bat].name << ha << left << setw(70) << hs;
		plrs[bat].s++;
		hit(bat, 1);
		break;
	case 4:
		//***************
		//*Double		*
		//***************
		gotoxy(0, x);
		cout << plrs[bat].name << ha << left << setw(70) << hd;
		plrs[bat].d++;
		hit(bat, 2);
		break;
	case 6:
		//***************
		//*Triple		*
		//***************
		gotoxy(0, x);
		cout << plrs[bat].name << ha << left << setw(70) << ht;
		plrs[bat].t++;
		hit(bat, 3);
		break;
	case 8:
		//***************
		//*Home Run		*
		//***************
		gotoxy(0, x);
		cout << plrs[bat].name << ha << left << setw(70) << homer;
		plrs[bat].hr++;
		hit(bat, 4);
		break;
	case 9:
	case 11:
	case 13:
	case 15:
	case 17:
		//***************
		//*Strike		*
		//***************
		strike += 1;
		gotoxy(0, x);
		cout << "Strike " << left << setw(70) << strike;
		break;
	case 10:
	case 12:
	case 14:
	case 16:
	case 18:
		//***************
		//*Ball			*
		//***************
		ball += 1;
		gotoxy(0, x);
		cout << "Ball " << left << setw(70) << ball;
		//***************
		//*If ball 4, go*
		//*to walk()	*
		//***************
		if (ball >= 4)
		{
			gotoxy(0, x);
			cout << plrs[bat].name << ga << left << setw(70) << hw;
			walk(bat);
		}
		break;
	case 19:
		//***************
		//*Fly Out		*
		//***************
		gotoxy(0, x);
		cout << plrs[bat].name << ghr << left << setw(70) << fo;
		up = false;
		outs++;
		break;
	case 20:
		//***************
		//*Error		*
		//***************
		gotoxy(0, x);
		cout << plrs[bat].name << ge << left << setw(70) << he;
		if (bat < 9)
		{
			scoreB[11]++;
		}
		else {
			scoreA[11]++;
		}
		hit(bat, 1);
		break;
	default:
		break;
	}

	sboard();
	Sleep(slp2);

	if (strike >= 3)
	{
		outs++;
		up = false;
		plrs[bat].so++;
		gotoxy(0, x);
		cout << plrs[bat].name << left << setw(70) << hso;
		Sleep(slp2);
	}
	Sleep(slp1);

}

//***********************
//*	   Team A at bat	*
//*---------------------*
//*This is what happens	*
//*when team A is up to *
//*bat					*
//***********************
void abA() {

	reset();
	outs = 0;
	aUp = true;
	bUp = false;
	gotoxy(10, 9);
	cout << outs;
	//***************************************
	//*Reset every player's base position	*
	//***************************************
	for (int i = 0; i < (int)plrs.size(); i++)
	{
		plrs[i].onBase = false;
		plrs[i].bp = 0;
	}
	//***************************************
	//*While there are less than 3 outs...	*
	//***************************************
	do {
		plrs[batA].ab++;
		//***************************************
		//*While the batter is still up to bat..*
		//***************************************
		do {
			sboard();
			//cout << strikeStr << strike << endl;
			//cout << ballStr << ball << endl;
			//cout << outStr << endl << endl;
			cout << abStr << left << setw(30) << plrs[batA].name << endl;
			Sleep(slp1);
			cpc++;
			r(batA, cpc);
		} while (up);
		if (batA == 8)
		{
			batA = 0;
		}
		else {
			batA++;
		}
		reset();
		gotoxy(10, 9);
		cout << outs;
	} while (outs < 3);

}

//***********************
//*	   Team B at bat	*
//*---------------------*
//*This is what happens	*
//*when team B is up to *
//*bat					*
//***********************
void abB() {

	reset();
	outs = 0;
	aUp = false;
	bUp = true;
	gotoxy(10, 9);
	cout << outs;
	//***************************************
	//*Reset every player's base position	*
	//***************************************
	for (int i = 0; i < (int)plrs.size(); i++)
	{
		plrs[i].onBase = false;
		plrs[i].bp = 0;
	}
	//***************************************
	//*While there are less than 3 outs...	*
	//***************************************
	do {
		plrs[batB].ab++;
		//***************************************
		//*While the batter is still up to bat..*
		//***************************************
		do {
			sboard();
			//cout << strikeStr << strike << endl;
			//cout << ballStr << ball << endl;
			//cout << outStr << endl << endl;
			cout << abStr << left << setw(30) << plrs[batB].name << endl;
			Sleep(slp1);
			spc++;
			r(batB, spc);
		} while (up);
		if (batB == 17)
		{
			batB = 9;
		}
		else {
			batB++;
		}
		reset();
		gotoxy(10, 9);
		cout << outs;
	} while (outs < 3);

}

//***********************
//*		 Play Ball		*
//*---------------------*
//*Keeps track of which *
//*team is up to bat	*
//***********************
void play(int n) {

	for (int i = (inNum - 1); i < n; i++)
	{
		cout << ins << inNum << endl << endl;
		cout << left << setw(70) << tau << endl;
		Sleep(slp2);
		abA();
		Sleep(slp2);
		system("CLS");
		cout << left << setw(70) << tbu << endl;
		Sleep(slp2);
		abB();
		Sleep(slp2);
		system("CLS");
		inNum++;
	}
	calc();
	sboard();
	gotoxy(0, 20);
	pause();
	if (inNum > 9 && (scoreA[9] == scoreB[9])) {
		isTie = true;
		system("CLS");
		cout << tie;
		scoreA[9]++;
	}
	if (inNum > 9 && !isTie) wl();

}

#pragma endregion PLAY_BALL

//***********************
//*  Win/Loss Function  *
//*---------------------*
//*Shows who won/lost	*
//*with graphics and	*
//*sound				*
//***********************
void wl() {

	system("CLS");

	if (scoreA[9] > scoreB[9]) {
		PlaySound(TEXT("sox.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		soxG();
		Sleep(2000);
		cout << endl << endl << tA << w;
	}
	else {
		cubG();
		PlaySound(TEXT("boo.wav"), NULL, SND_FILENAME);
		PlaySound(TEXT("cubs.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		Sleep(2000);
		cout << endl << endl << tB << w;
	}
	pause();
	PlaySound(TEXT("troy.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	isOver = true;
	inNum = 1;
}

//***********************
//*Calculations Function*
//*---------------------*
//*Calculates the on	*
//*base and batting avg	*
//***********************
void calc() {

	for (int i = 0; i < (int)plrs.size(); i++)
	{
		avg = (double)((double)plrs[i].s + plrs[i].d + plrs[i].t + plrs[i].hr) / plrs[i].ab;
		plrs[i].oba = avg;
		plrs[i].bavg = avg;
	}

}

//***********************
//*	   Rules Function	*
//*---------------------*
//*Prints the rules out	*
//***********************
void rules() {

	system("CLS");

	rus();
	color(269);
	cout << key << endl;
	pause();
	gotoxy(0, 13);
	color(14);
	cout << rnd1 << rnd2 << rnd1 <<
		rnd3 << rnd1 << rnd4 << rnd1 <<
		rnd5 << rnd1 << rnd6 << rnd1 <<
		rnd7 << rnd1 << rnd8 << rnd1 <<
		rnd9 << rnd1 << rnd10 << rnd1
		<< rnd11 << rnd1;
	dCol();
	pause();

}

//***********************
//*	  Sound Function 	*
//*---------------------*
//*Determines which WAV	*
//*file to play each	*
//*inning				*
//***********************
void pls() {

	switch (inNum)
	{
	case 1:
		PlaySound(TEXT("inn1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case 2:
		PlaySound(TEXT("inn2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case 3:
		PlaySound(TEXT("inn3.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case 4:
		PlaySound(TEXT("inn4.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case 5:
		PlaySound(TEXT("inn5.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case 6:
		PlaySound(TEXT("inn6.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case 7:
		PlaySound(TEXT("inn7.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case 8:
		PlaySound(TEXT("inn8.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case 9:
		PlaySound(TEXT("inn9.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	default:
		break;
	}

}

//***********************
//*	 New Game Function 	*
//*---------------------*
//*Checks if user wants *
//*to reset the score & *
//*start a new game.	*
//***********************
void newgame() {

	do
	{
		gotoxy(0, 21);
		cout << warn;
		cin >> opt;
		if (opt == "y" || opt == "Y" || opt == "n" || opt == "N") {
		}
		else {
			opt = "";
		}

	} while (opt == "");

	if (opt == "y" || opt == "Y") {
		for (int i = 0; i < 12; i++)
		{
			scoreA[i] = 0;
			scoreB[i] = 0;
		}
		reset();
		batA = 0;
		batB = 9;
		outs = 0;
		isOver = false;
	}
}

//***************************************
//*		    Selection Validation		*
//***************************************
//*Validate the user's selection by		*
//*turning opt into an int from a string*
//***************************************
void validate(string opt) {

	if (opt != "12345") {
		option = 0;
	} else {
		option = atoi(opt.c_str());
	}

}

//***********************
//*		  Back To		*
//*	   Menu Function 	*
//*---------------------*
//*Clears screen, prints*
//*baseball and menu	*
//*graphics, resets the	*
//*default cursor pos.	*
//***********************
void b2menu() {

	system("CLS");
	bbG();
	menG();
	gotoXY(1, 13);
	cout << "->";
	x2 = 13;
	menu_item = 0;

}

//***********************
//*	   Menu Function 	*
//*---------------------*
//*Prints the menu onto	*
//*the screen. See 		*
//*variable information	*
//*on lines 198-225		*
//***********************
void menu() {

	system("CLS");

	bbG();
	menG();

	gotoXY(1, 13);
	cout << "->";

	while (running) {

		gotoxy(3, 13);
		cout << one;
		gotoxy(3, 14);
		cout << two;
		gotoxy(3, 15);
		cout << three;
		gotoxy(3, 16);
		cout << four;
		gotoxy(3, 17);
		cout << five;
		gotoxy(3, 18);
		cout << six;
		gotoxy(3, 19);
		cout << seven;
		gotoxy(3, 20);
		cout << q;

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x2 != 20) //down button pressed
		{
			gotoXY(1, x2); cout << "  ";
			x2++;
			gotoXY(1, x2); cout << "->";
			menu_item++;
			continue;

		}

		if (GetAsyncKeyState(VK_UP) && x2 != 13) //up button pressed
		{
			gotoXY(1, x2); cout << "  ";
			x2--;
			gotoXY(1, x2); cout << "->";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item)
			{
			case 0: {
				//*******************
				//*Play 1 inning	*
				//*******************
				if (isOver)
				{
					newgame();
				}
				else {
					slp1 = 300;
					slp2 = 2000;
					system("CLS");
					if (plrs[1].name != "K-9") pls();
					play(inNum);
				}
				b2menu();
				break;
			}

			case 1: {
				//***************************************
				//*Play to the end of the current game	*
				//***************************************
				if (isOver)
				{
					newgame();
				}
				else {
					system("CLS");
					if (plrs[1].name != "K-9") PlaySound(TEXT("fastinn.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					if (inNum == 1)
					{
						cout << ng;
					}
					else {
						slp1 = 0;
						slp2 = 0;
						play(9);
					}
				}
				b2menu();
				break;
			}
			case 2: {
				//*******************
				//*Play full game	*
				//*******************
				if (isOver)
				{
					newgame();
				}
				else {
					system("CLS");
					if (plrs[1].name != "K-9") PlaySound(TEXT("fastinn.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					slp1 = 0;
					slp2 = 0;
					play(9);
				}
				b2menu();
				break;
			}
			case 3: {
				//*******************
				//*Print stats		*
				//*******************
				sout();
				b2menu();
				break;
			}
			case 4: {
				//*******************
				//*Print scoreboard	*
				//*******************
				system("CLS");
				sboard();
				pause();
				b2menu();
				break;
			}
			case 5: {
				//*******************
				//*View the rules	*
				//*******************
				rules();
				b2menu();
				break;
			}
			case 6: {
				//*******************
				//*Cheat code		*
				//*******************
				gotoxy(3, 21);
				cout << ecode;
				cin >> opt;
				validate(opt);
				if (option == 12345)
				{
					system("CLS");
					PlaySound(TEXT("spaceballs.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << load;
					file1 = drFile;
					players();
					Sleep(11000);
					gotoxy(0, 5);
					dalek();
					PlaySound(TEXT("drwhotheme.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					pause();
				}
				else {
					cout << inv;
				}
				b2menu();
				gotoxy(20, 13);
				policeBox();
				break;
			}
			case 7: {
				//*******************
				//*Quit				*
				//*******************
				running = false;
				break;
			}
			}
		}
	}
}

//***********************
//*    Open Function	*
//*---------------------*
//*Plays the opening	*
//*sound and graphics	*
//***********************
void open() {

	PlaySound(TEXT("anykey.wav"), NULL, SND_FILENAME | SND_ASYNC);
	pause();
	PlaySound(TEXT("worldseries.wav"), NULL, SND_FILENAME | SND_ASYNC);
	system("CLS");
	mlb();
	Sleep(2000);
	system("CLS");
	cubG();
	Sleep(2000);
	system("CLS");
	vsG();
	Sleep(2000);
	system("CLS");
	soxG();
	pause();
	PlaySound(TEXT("troy.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	cout << setprecision(3) << fixed;
	ofs << setprecision(3) << fixed;
	sstats << setprecision(3) << fixed;

}

//***********************
//*	  Output File for	*
//*	   player stats		*
//***********************
void ostats() {

	ofstream statcopy(file6);

	for (int i = 0; i < (int)plrs.size(); i++)
	{
		sstats << plrs[i].name << com;
		sstats << plrs[i].hr << com;
		sstats << plrs[i].so << com;
		sstats << plrs[i].s << com;
		sstats << plrs[i].d << com;
		sstats << plrs[i].t << com;
		sstats << plrs[i].ab << com;
		sstats << plrs[i].oba << com;
		sstats << plrs[i].bavg << endl;
		statcopy << plrs[i].name << com;
		statcopy << plrs[i].hr << com;
		statcopy << plrs[i].so << com;
		statcopy << plrs[i].s << com;
		statcopy << plrs[i].d << com;
		statcopy << plrs[i].t << com;
		statcopy << plrs[i].ab << com;
		statcopy << plrs[i].oba << com;
		statcopy << plrs[i].bavg << endl;
	}

}

//***********************
//*	   Output File		*
//*---------------------*
//*Creates the output	*
//*files				*
//***********************
void output() {

	if (!game2) {
		hdr();
		box();
		ofs << box2 << left << setw(82) << g1 << box2 << endl;
		pout();
		sbout();
		box();
		ftr();
		eof();
		ofs.close();
		ofs.open(file2);
		hdr();
		box();
		ofs << box2 << left << setw(82) << g1 << box2 << endl;
		pout();
		sbout();
		box();
		box();
		ofstream fc(file7);
		fc << fin2;
	} else {
		ofs << box2 << left << setw(82) << g2 << box2 << endl;
		pout();
		sbout();
		ftr();
		box();
		eof();
		ofstream fc(file7);
		fc << fin1;
	}

}

//***********************
//*   Close Function	*
//*---------------------*
//*Closes all open files*
//***********************
void clFiles() {

	sstats.close();
	ofs.close();
	fc.close();

}

//*******************************
//*		   Main Function		*
//*-----------------------------*
//*sets hConsole for colors		*
//*initializes random numbers	*
//*initializes file names		*
//*creates player list			*
//*plays opening graphics		*
//*calls the menu function		*
//*calls the output function	*
//*calls ostats() function		*
//*pauses on exit				*
//*closes all files				*
//*******************************
int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	oFiles();
	players();
	open();
	menu();
	output();
	ostats();
	pause();
	clFiles();
	return 0;
}