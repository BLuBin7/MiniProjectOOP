#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <sstream>
using namespace std;

class Number {
public:
	unsigned long RandomInteger(long, long);
};

class RandomIntegerGenerator {
public:
	int next();
	int next(int);
	int next(int, int);
};

class Fullname {
private:
	string _firstname;
	string _middlename;
	string _lastname;
public:
	Fullname() {
		_firstname = "";
		_middlename = "";
		_lastname = "";
	}
	Fullname(string first, string middle, string last) {
		_firstname = first;
		_middlename = middle;
		_lastname = last;
	}
	string toString() {
		stringstream builder;

		builder << _lastname << " "
			<< _middlename << " "
			<< _firstname;

		string result = builder.str();
		return result;
	}
	string getlname() { 
		return this->_lastname; 
	}

	string getmname() { 
		return this->_middlename; 
	}

	string getfname() { 
		return this->_firstname; 
	}

	void setLname(string value) {
		this->_lastname = value;
	}

	void setMname(string value) { 
		this->_middlename = value; 
	}

	void setFname(string value) { 
		this->_firstname = value; 
	}

};


