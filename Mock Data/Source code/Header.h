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

	void setDay(int value) {
		this->_day = value; 
	}

	void setMonth(int value) { 
		this->_month = value; 
	}

	void setYear(int value) { 
		this->_year = value; 
	}

	string toString();
};

class Student {
private:
	string _id;
	Fullname _name;
	double _GPA;
	string _tel;
	string _email;
	date _DOB;
	string _address;
public:
	Student() {
		this->_id = "";
		this->_GPA = 0;
		this->_tel = "";
		this->_email = "";
		this->_address = "";
	}

	Student(string id, Fullname name, double GPA, string tel, string email, date DOB, string address) {
		this->_id = id;
		this->_name = name;
		this->_GPA = GPA;
		this->_tel = tel;
		this->_email = email;
		this->_DOB = DOB;
		this->_address = address;
	}

	string getId() {
		return _id;
	}

	Fullname getName() {
		return _name;
	}

	double getGPA() {
		return this->_GPA;
	}

	string getTel() {
		return this->_tel;
	}

	string getEmail() {
		return this->_email;
	}

	date getDOB() {
		return this->_DOB;
	}

	string getAddress() {
		return this->_address;
	}

	void setId(string id) {
		this->_id = id;
	}

	void setName(Fullname name) {
		this->_name = name;
	}

	void setGPA(double GPA) {
		this->_GPA = GPA;
	}

	void setTel(string tel) {
		this->_tel = tel;
	}

	void setEmail(string Email) {
		this->_email = Email;
	}

	void setDOB(date DOB) {
		_DOB = DOB;
	}

	void setAddress(string add) {
		this->_address = add;
	}

	string toStringFull();
	string toStringShort();
	~Student() {};
};

class readStudent {
private:
	Student _S;
public:
	readStudent(fstream&, int&);

	Student getS() { 
		return _S; 
	}

	~readStudent() { };
};


class FakeFullnameGenerator {
private:
	vector<string> _CommonlastNames;
	vector<string> _firstNames;
	vector<string> _middleNames;
	vector<string> _lastNames;
	RandomIntegerGenerator _rng;
public:
	FakeFullnameGenerator();
	Fullname next();
};

class FakeGPA {
private:
	RandomIntegerGenerator _rng;
public:
	double rand_gpa();
};

class FakeInterger {
public:
	int rand();
};

class FakeId {
private:
	RandomIntegerGenerator _rng;
public:
	string rand_id(int, int);
};

class FakeEmail {
private:
	vector<string> _domain;
	Number _rng;
public:
	FakeEmail();
	string next(string);
};

class FakeTel {
private:
	vector<string> mb;
	vector<string> vt;
	vector<string> vn;
	vector<string> vnmb;
	RandomIntegerGenerator _rng;
public:
	FakeTel();
	string rand_tel();
};

class FakeBirthday {
};

