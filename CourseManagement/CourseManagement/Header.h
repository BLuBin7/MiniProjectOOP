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
	
	string getName() const {
		return this->name;
	}

	void setName(string value){
		this->name = value;
	}

	string getId() const {
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
	vector<pair<Course,vector<Student>>> allStudentinCourse ;
public:
	Course(string name, string id): name(name), id(id){}
	string getName() const {
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

	// dat const de thuc thi duoc ostream dung lenh "const"
	string getId() const {
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

	friend ostream& operator << (ostream& os, const Course& course)
	{
		os << "Course: " << course.getName() << ", " << course.getId() << std::endl;
		return os;
	}

	friend ostream& operator << (ostream& os, const Student& student)
	{
		os << "Student: " << student.getName() << ", ID: " << student.getId() << std::endl;
		return os;
	}

	friend ostream& operator << (ostream& os, const std::vector<std::pair<Course, std::vector<Student>>>& courses) {
		for (const auto& course : courses)
		{
			os << course.first << "Students: " << std::endl;
			for (const auto& student : course.second)
			{
				os << "\t" << &student;
			}
			os << std::endl;
		}
		return os;
	}
};