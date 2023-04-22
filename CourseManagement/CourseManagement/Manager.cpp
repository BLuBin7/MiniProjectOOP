#include<iostream>
#include <vector>
#include <utility>
#include "Header.h"
using namespace std;
//2. Them mon hoc vao 1 ki
void Course::addCourse(string name, string id){
	Course* course = new Course(name, id);
	courseArchives.push_back(*course);
}

//3 . 
void Course::RegisterofStudent(Student* student, string nameSubject) {
    for (Course& cr : courseArchives) { 
        if (cr.getName() == nameSubject) { 
            cr.listofstudent.push_back(*student); 
            cr.allStudentinCourse.push_back(make_pair(cr, cr.listofstudent));
            return; 
        }
    }
    cout << "Error: Course not found." << std::endl;
}

void Course::displayCourse() {
	for (int i = 0; i < courseArchives.size(); i++) {
		cout << "Danh sach cac mon hoc trong 1 ki : " << endl;
		cout << "Ten mon hoc : "+courseArchives[i].getName() << endl;
		cout << "Ma mon hoc : " + courseArchives[i].getId() << endl;
	}
}


//void Course::displayStudentRegister() {
//    for (auto& pair : allStudentinCourse) { // iterate over the pairs of (course, students) in the course
//        cout << "Course: " << pair.first.getName() << ", " << pair.first.getId() << endl;
//        cout << "Students: " << std::endl;
//        for (auto& student : pair.second) { // iterate over the students in the pair
//            cout << "\t" << student.getName() << ", ID: " << student.getId() << endl;
//        }
//        cout << endl;
//    }
//}

void Course::displayStudentRegister() {

    cout << allStudentinCourse;
    
    for (auto& pair : allStudentinCourse) { // iterate over the pairs of (course, students) in the course
        cout << "Course: " << pair.first.getName() << ", " << pair.first.getId() << endl;
        cout << "Students: " << std::endl;
        for (auto& student : pair.second) { // iterate over the students in the pair
            cout << "\t" << student.getName() << ", ID: " << student.getId() << endl;
        }
        cout << endl;
    }
}





//ostream& operator << (ostream& os, const Course& course)
//{
//	os << "Course: " << course.getName() << ", " << course.getId() << std::endl;
//	return os;
//}
//
//ostream& operator << (ostream& os,  const Student& student)
//{
//	os << "Student: " << student.getName() << ", ID: " << student.getId() << std::endl;
//	return os;
//}

//ostream& operator << (ostream& os, const std::vector<std::pair<Course, std::vector<Student>>>& courses)
//{
//	for (const auto& course : courses)
//	{
//		os << course.first << "Students: " << std::endl;
//		for (const auto& student : course.second)
//		{
//			os << "\t" << student;
//		}
//		os << std::endl;
//	}
//	return os;
//}
