#include<iostream>
#include <string>
#include <string.h>
#include <cctype>
#include <algorithm>
#include <regex>
#include <iomanip>
#include "Header.h"
#pragma warning(disable : 4996)

using namespace std;

int RandomIntegerGenerator::next() {
	int result = rand();
	return result;
}

int RandomIntegerGenerator::next(int ceiling) {
	int result = rand() % ceiling;
	return result;
}