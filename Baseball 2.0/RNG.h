#pragma once
#include <random>

using namespace std;

int rng(int min, int max) {

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(min, max);

	return dist(rd);

}
