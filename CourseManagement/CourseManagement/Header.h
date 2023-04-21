#pragma once
#include<iostream>
#include<vector>
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
class Course;
class Semester {
private:
	string name;
	vector<Course> courseArchivesonSemester;

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
	vector<Student> listofstudent;
	vector<Course> courseArchives;
public:
	Course(string name, string id): name(name), id(id){}
	string getName() {
		return this->name;
	}

	Course(string name, string id, vector<Student> listofstudent) {
		this->setName(name);
		this->setId(id);
		this->listofstudent = listofstudent;
	}
	Course(string name) : name(name) {}

	Course(){}
	void setName(string value) {
		this->name = value;
	}

	string getId() {
		return this->id;
	}

	void setId(string value) {
		this->id = value;
	}

	vector<Student> getListofStudent() {
		return this->listofstudent;
	}

	

	

	void registerSv(string nameSubject);

	// 2. them mon hoc
	void addCourse(string name, string id);
	// 3. Sinh vien dang ki mon hoc
	void RegisterofStudent(Student* student, string nameSubject);
	
	void displayCourse();
	void displayStudentRegister();
};