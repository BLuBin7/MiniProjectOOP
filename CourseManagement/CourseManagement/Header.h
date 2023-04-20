#pragma once
#include<iostream>
using namespace std;
class Student {
private:
	string name;
	string id;

public:
	Student(string name, string id) : name(name), id(id){}
	
	string getName() {
		return this->name;
	}

	void setName(string value){
		this->name = value;
	}

	string getId() {
		return this->id;
	}

	void setId(string value) {
		this->id = value;
	}


};

class Person {
private:
	string name;
public:
	 Person(string name): name(name){}

	 string getName() {
		 return this->name;
	 }

	 void setName(string value) {
		 this->name = value;
	 }

};

class Semester {
private:
	string name;
public:
	Semester(string name) : name(name){}

	string getName() {
		return this->name;
	}
	
	void setName(string value) {
		this->name = value;
	}

};

class Course {
private:
	string name;
	string id;

public:
	Course(string name, string id): name(name), id(id){}
	string getName() {
		return this->name;
	}

	void setName(string value) {
		this->name = value;
	}

	string getId() {
		return this->id;
	}

	void setId(string value) {
		this->id = value;
	}
};