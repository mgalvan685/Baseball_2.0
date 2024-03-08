#pragma once

// Take a random number, 1-1000
// Take player batting avg * 1000
// If random number is less than the batting avg...
// It's a hit
// Otherwise, it's a strike

// http://www.baseball-reference.com/leagues/MLB/pitch.shtml

#include <random>
#include "RNG.h"

using namespace std;

bool htbl(int);

//***************************************************
//*				  Pitch/Hit variables				*
//*-------------------------------------------------*
//*pitch - percentage pitch is hitable				*
//*hitChance - percentage batter will hit the ball	*
//*bavg - batting average * 1000					*
//***************************************************
int pitch, hitChance, bavg;

bool isHitable, wasHit;

//*******************************
//*		Hit Check Function		*
//*-----------------------------*
//*Checks if the player hit the *
//* pitch or not.				*
//*-----------------------------*
//*pitch - pitch hitability		*
//*avg - player batting average	*
//*******************************
bool hitChk(double bavg) {

	bavg = bavg * 1000;

	pitch = rng(100, 900);

	// Use pitcher's ERA to determine if the pitch is
	// hitable or not. For now, use 3.97 (2017 avg ERA)
	// Chance is 100-900 because the ERA is calculated for
	// 9 innings, so this should be more accurate...theoretically
	if (pitch <= 397)
	{
		// hitable
		//isHitable = true;
		wasHit = htbl(bavg);
	}
	else
	{
		// ball, hit by a pitch or wild pitch
		//isHitable = false;
		wasHit = false;
	}

	return wasHit;

}


//*******************************
//*		 Hitable Function		*
//*-----------------------------*
//*Calculates the outcom of the *
//*hitable pitch.				*
//*******************************
bool htbl(int avg) {

	hitChance = rng(1, 1000);

	if (avg >= hitChance)
	{
		// hit
		return true;
	}
	else
	{
		return false;
	}

}
