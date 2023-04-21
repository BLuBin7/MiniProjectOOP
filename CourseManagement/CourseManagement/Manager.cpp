#include<iostream>
#include "Header.h"
using namespace std;
//2. Them mon hoc vao 1 ki
void Course::addCourse(string name, string id){
	Course* course = new Course(name, id);
	courseArchives.push_back(*course);
}

//3 . 
void Course::RegisterofStudent(Student *student,string nameSubject) {
	for (Course cr : courseArchives) {
		if (cr.getName() == nameSubject) {
			listofstudent.push_back(*student);
		}
	}
}

void Course::displayCourse() {
	for (int i = 0; i < courseArchives.size(); i++) {
		cout << "Danh sach cac mon hoc trong 1 ki : " << endl;
		cout << "Ten mon hoc : "+courseArchives[i].getName() << endl;
		cout << "Ma mon hoc : " + courseArchives[i].getId() << endl;
	}
}

void Course::displayStudentRegister() {
	for (Course cr : courseArchives) {
		for (Student sv : listofstudent) {
			cr.RegisterofStudent(&sv,cr.getName());
			cout << "Danh sach sinh vien trong mon "+cr.getName() << endl;
			cout << "Danh sach sinh vien dang ki : " + sv.getName() << endl;;
		}
	}
}
