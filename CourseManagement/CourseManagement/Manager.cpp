#include<iostream>
#include <vector>
#include <utility>
#include "Header.h"
using namespace std;
//2. Them mon hoc vao 1 ki
void Course::addCourse(string name, string id){
	//Course* course = new Course(name, id);
    Course course (name, id);
	courseArchives.push_back(course);
}

//3 . 
void Course::RegisterofStudent(Student* student, string nameSubject) {
    auto courseIt = find_if(courseArchives.begin(),
        courseArchives.end(), [&](const Course& course) {
            return course.getName() == nameSubject;
        });

    if (courseIt != courseArchives.end()) {
        courseIt->listofstudent.push_back(*student);
        allStudentinCourse.emplace_back(*courseIt, courseIt->listofstudent);
    }

    else {
        cout << "Error: Course not found." << endl;
    }
}


// That is Bug !!
//void Course::RegisterofStudent(Student* student, string nameSubject) {
//    for (Course& cr : courseArchives) { 
//        if (cr.getName() == nameSubject) { 
//            cr.listofstudent.push_back(*student); 
//            cr.allStudentinCourse.push_back(make_pair(cr, cr.listofstudent));
//            return; 
//        }
//    }
//    cout << "Error: Course not found." << std::endl;
//}




void Course::displayCourse() {
	for (int i = 0; i < courseArchives.size(); i++) {
		cout << "Danh sach cac mon hoc trong 1 ki : " << endl;
		cout << "Ten mon hoc : "+courseArchives[i].getName() << endl;
		cout << "Ma mon hoc : " + courseArchives[i].getId() << endl;
	}
}


void Course::displayStudentRegister() {

    if (allStudentinCourse.empty()) {
        cout << "Oops, Khong co khoa hoc nay !!" << endl;
        return;
    }
    cout << "So luong cac khoa hoc dang mo : " << allStudentinCourse.size() << std::endl;

    for (const auto& pair : allStudentinCourse) { // iterate over the pairs of (course, students) in the course
        cout << "Ten mon hoc : " << pair.first.getName() << ", Ma mon hoc : " << pair.first.getId() << endl;
        cout << "Danh sach sinh vien dang ki: " << std::endl;
        for (auto& student : pair.second) { // iterate over the students in the pair
            cout << "\t" << "MSSV: " << student.getId() << "\tTen sinh vien : " + student.getName() << endl;
        }
        cout << endl;
    }

    // Bad choice
    /*for (const auto& course : allStudentinCourse) {
       cout << course.first.getName() << " students:" << endl;
       for (const auto& student : course.second) {
          cout << "\t" << student.getName() << " (" << student.getId() << ")" << endl;
       }
    }*/


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
