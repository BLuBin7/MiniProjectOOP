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

// class RandomIntegerGenerator
int RandomIntegerGenerator::next() {
	int result = rand();
	return result;
}

int RandomIntegerGenerator::next(int ceiling) {
	int result = rand() % ceiling;
	return result;
}

int RandomIntegerGenerator::next(int left, int right) {
	int result = rand() % (right - left + 1) + left;
	return result;
}

// class Number 
unsigned long Number::RandomInteger(long left, long right) {
	unsigned long x = rand() & 0xff;
	//	khoang cach giua mot dong la 8 bit
	x |= (rand() & 0xff) << 8;
	x |= (rand() & 0xff) << 16;
	x |= (rand() & 0xff) << 24;
	unsigned long a = x % (right - left + 1) + left;
	return a;
}

string Student::toStringFull() {
	stringstream ss;
	ss << "Student: " << id() << " - " << name().toString() << endl;
	ss << "\tGPA=" << fixed << setprecision(2) << GPA() << ", " << "Telephone: " << tel() << endl;
	ss << "\tEmail=" << email() << endl;
	ss << "\tDOB=" << DOB().toString() << endl;
	ss << "\tAddress=" << address() << endl;
	string s = ss.str();
	return s;
}

string Student::toStringShort() {
	stringstream ss;
	ss << id() << " - " << name().toString();
	ss << ", GPA: " << fixed << setprecision(2) << GPA() << endl;
	string s = ss.str();
	return s;
}