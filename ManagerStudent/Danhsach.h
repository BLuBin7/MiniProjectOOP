#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

class Student {
private:
	string ID;
	string ten;
	int DTB;

public:
	//Getter and Setter
	string getID() {
		return ID;
	}

	void setID(string value) {
		this->ID = value;
	}

	string getTen() {
		return ten;
	}

	void setTen(string value) {
		this->ten = value;
	}

	int getDTB() {
		return DTB;
	}

	void setDTB(int value) {
		this->DTB = value;
	}


	//Construtor
	Student() {
		this->ID = "";
		this->ten = "";
		this->DTB = 0;
	}

	Student(string ID, string ten, int DTB) {
		this->ID = ID;
		this->ten = ten;
		this->DTB = DTB;
	}

	Student(string name, float dtb) : ten(name), DTB(dtb) {}

	//Operation
	void toString() {
		cout << this->getID() << " " << this->getTen() << " " << this->getDTB() << endl;
	}

	bool operator < (const Student& other) const {
		return DTB < other.DTB;
	}
	bool operator > (const Student& other) const {
		return DTB > other.DTB;
	}

};

class Danhsach {
private:
	vector<Student> danhsach;
public:
	//Constructor
	Danhsach(vector<Student> value) {
		this->danhsach = value;
	}

	Danhsach() {}

	// Operation
	// choice == 1
	void themsinhvien(Student& value);

	void swap(Student& a, Student& b);

	// choice == 2
	void xoaSinhVien(string sv);

	// choice == 3
	bool timsinhvien(string sv);

	// choice == 4
	void xuatdanhsach();

	// choice == 5
	void lamrongds();

	//choice == 6
	void sapXepTheoDTBthapdencao();

	//choice == 7
	void sapXepTheoDTBcaodenthap();

};