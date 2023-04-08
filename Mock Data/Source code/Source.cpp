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

string date::toString() {
	stringstream ss;
	ss.fill('0');
	ss << setw(2) << _day << '/' << setw(2) << _month << '/' << setw(4) << _year;
	string s = ss.str();
	return s;
}

readStudent::readStudent(fstream& f, int& pos) {
	f.seekg(pos, ios::beg);
	string s1, s2, s3, s4; char c[256]; double d; int i, j, k;

	//Set id
	f.seekg(9, ios_base::cur); //"Student " co 9 ky tu
	f.getline(c, 256, '-');
	s1 = string(c);
	s1.erase(prev(s1.end())); //Xoa dau cach
	_S.setid(s1);

	//Set Name
	f.seekg(1, ios_base::cur); //Nhay 1 dau cach
	f.getline(c, 256, '\n');
	s1 = string(c);
	s2 = s1.substr(0, s1.find(' '));
	s3 = s1.substr(s1.rfind(' ') + 1, s1.length() - s1.rfind(' ') - 1);
	s4 = s1.substr(s1.find(' ') + 1, s1.rfind(' ') - s1.find(' ') - 1);
	Fullname name(s3, s4, s2);
	_S.setName(name);
	pos = f.tellg();

	//Set GPA
	f.seekg(8, ios_base::cur);
	f.getline(c, 256, ',');
	d = atof(c); _S.setGPA(d);
	//Set Tel
	f.seekg(11, ios_base::cur);
	f.getline(c, 256, '\n');
	s1 = string(c); _S.setTel(s1);
	//Set Email
	f.seekg(10, ios_base::cur);
	f.getline(c, 256, '\n');
	s1 = string(c); _S.setEmail(s1);

	//Set DOB
	f.seekg(8, ios_base::cur);
	f.getline(c, 3, '/');
	i = atoi(c);  //Set Day
	f.getline(c, 3, '/');
	j = atoi(c); //Set Month
	f.getline(c, 5, '\n');
	k = atoi(c); //Set Year
	date DOB(i, j, k);
	_S.setDOB(DOB);

	//Set Address
	f.seekg(12, ios_base::cur);
	f.getline(c, 256, '\n');
	s1 = string(c); _S.setAddress(s1);
	pos = f.tellg();

}

FakeFullnameGenerator::FakeFullnameGenerator() {
	_CommonlastNames = { "Nguyen", "Le", "Bui", "Pham", "Vu", "Vo", "Hoang", "Huynh", "Do", "Phan", "Dang", "Tran", "Ho", "Ngo", "Duong", "Ly" };//Ho

	fstream of;
	string Ho_phu;
	of.open("Ho.txt");
	//int nn = 1;
	while (of >> Ho_phu) {//////////// Doc file ho pho bien
		//nn++;
		_lastNames.push_back(Ho_phu);
	}

	of.close();
	//nn--;

	fstream oof;
	string lot;
	oof.open("Tenlot.txt");
	//int nn = 1;
	while (oof >> lot) {//////////// Doc file ten lot
		//nn++;
		_middleNames.push_back(lot);
	}
	oof.close();

	fstream ff;
	string name;
	ff.open("Ten.txt");
	//nn = 1;
	while (ff >> name) {//////////// Doc file ten
		_firstNames.push_back(name);
		//nn++;
	}
	ff.close();
	//nn--;
}

Fullname FakeFullnameGenerator::next() {
	int a = _rng.next(90);
	int b1 = _rng.next(9);
	double b = (double)((double)b1 / 10);

	string last = "";
	double random = ((double)rand()) / RAND_MAX;
	double ab = 100 * random;
	if (ab > 0 && ab <= 38.4) {
		last = _CommonlastNames[0];
	}

	else if (ab <= 48.7) {
		last = _CommonlastNames[1];
	}

	else if (ab <= 56.9) {
		last = _CommonlastNames[2];
	}

	else if (ab <= 63.6) {
		last = _CommonlastNames[3];
	}

	else if (ab <= 69.1) {
		int c = _rng.next(1, 2);
		if (c == 1)
			last = _CommonlastNames[4];
		else
			last = _CommonlastNames[5];
	}
}
