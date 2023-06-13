#include <iostream>
#include <vector>
using namespace std;
class Employee;

class Employee {
private:
	int thePayrollNumber;
	double theMonthlySalary;
	string theName;
public:
	Employee(int pay, double salary, string name) {
		this->thePayrollNumber = pay;
		this->theMonthlySalary = salary;
		this->theName = name;
	}

	double getMonthlySalary() {
		return theMonthlySalary;
	}

	void display() {
		cout << "\t ThePayrollNumber :" << thePayrollNumber << endl;
		cout << "\t TheMonthlySalary :" <<theMonthlySalary<<endl;
		cout << "\t TheName :" <<theName<<endl;
	}
};

class Programmer : Employee{
private :
	int thePayrollNumber;
	double theMonthlySalary;
	string theName;
	string thelanguage;
public:
	double getMonthlySalary() {
		return theMonthlySalary;
	}

	Programmer(int thePayrollNumber, double theMonthlySalary,
		string theName, string theLanguage) : Employee(thePayrollNumber, theMonthlySalary, theName), thelanguage(theLanguage) {

	}

	void setLanguage(string value) {
		this->thelanguage = value;
	}

	void display() {
		Employee::display();
		cout <<"\t TheLanguage :" <<thelanguage<<endl;
		cout << "-----------------------------------------" << endl;
	}
};



class ProjectLeader {

};

class SoftwareHouse {
private:
	string Name;
	vector<Programmer> allprogrammer;
public:
	void addProgrammer(Programmer programmer) {
		allprogrammer.push_back(programmer);
	}

	void setName(string name) {
		this->Name = name;
	}

	SoftwareHouse(string Name) {
		this->setName(Name);
	}

	void display() {
		cout << "SoftwareHouse " << Name<<endl;
		for (Programmer all : allprogrammer) {
			all.display();
		}
	}
};

int main() {
	Employee ee(1, 50, "fdd");
	Programmer gg(1, 50, "A", "C++");
	Programmer gg2(2, 51, "B", "C++");

	SoftwareHouse sh("Java");
	sh.addProgrammer(gg);
	sh.addProgrammer(gg2);

	sh.display();
}