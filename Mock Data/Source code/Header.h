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

class date {
private:
	int _day;
	int _month;
	int _year;
public:
	date() {
		_day = 1;
		_month = 1;
		_year = 1970;
	}

	date(int day, int month, int year) {
		if (year < 0 || month < 0 || month> 12 || day < 0 || day> 31)
		{
			cout << "Ngay khong hop le";
		}
		else
		{
			switch (month)
			{
			case 1: this->_month = month;
			case 3: this->_month = month;
			case 5: this->_month = month;
			case 7: this->_month = month;
			case 8: this->_month = month;
			case 10: this->_month = month;
			case 12:
				ngaymax = 31;
				this->_month = month;
				break;
			case 2:
				if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
					ngaymax = 29;
				else
					ngaymax = 28;
				break;
			case 4: this->_month = month;
			case 6: this->_month = month;
			case 9: this->_month = month;
			case 11: this->_month = month;
				ngaymax = 30;
				break;
			}
			if (day <= ngaymax)
			{
				this->_day = day;
			}
			else
			{
				cout << "Ngay khong hop le !" << "\n";
			}
		}
	}

	int getDay() { 
		return this->_day; 
	}

	int getMonth() { 
		return this->_month; 
	}

	int getYear() { 
		return this->_year; 
	}

	void setDay(int day) {
		this->_day = day; 
	}
