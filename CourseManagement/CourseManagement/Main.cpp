#include<iostream>
#include"Header.h"
#include<map>
#include<string>
using namespace std;
static void displayChoice() {
	cout << "1. Tao mot hoc ki." << endl;
	cout << "2. Them cac mon hoc vao hoc ki" << endl;
	cout << "3. Dang ki mon hoc " << endl;
	cout << "4. In tong so luong cac mon va danh sach sinh vien dang ki" << endl;
	cout << "5. In ra danh sach cac mon dang mo trong hoc ki" << endl;
	cout << "Nhap lua chon : " << endl;
}
int main() {
	int choice;
	Course* course = new Course();

	do {
		displayChoice();
		cin >> choice;
		cin.ignore();
		if (choice == 1) {
			string name;
			cout << "Nhap ten hoc ki : " << endl;
			getline(cin, name);
			Semester *semester = new Semester(name);
		}
		if (choice == 2) {
			string name, id;
			cout << "Nhap ten mon hoc : " << endl;
			getline(cin, name);
			cout << "Nhap ma mon hoc : " << endl;
			getline(cin,id);
			course->addCourse(name, id);
			course->displayCourse();
		}
		if (choice == 3) {
			string name, id, nameSubject;
			cout << "Nhap ten sinh vien : " << endl;
			getline(cin, name);
			cout << "Nhap MSSV : " << endl;
			getline(cin, id);
			cout << "Nhap ten mon hoc can dang ki : " << endl;
			getline(cin, nameSubject);

			Student* student = new Student(name, id);
			
			course->RegisterofStudent(student, nameSubject);
			course->displayStudentRegister();
			
		}
		if (choice == 4) {
			course->displayStudentRegister();
		}
		if (choice == 5) {
			course->displayCourse();
		}
	} while (choice != 0);
}