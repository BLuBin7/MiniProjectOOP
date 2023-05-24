#include<iostream>
#include<ctime>
#include "Header.h"
using namespace std;
// minimize bugs
#pragma warning(disable: 4996)

int main() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int choice = 0;
	do {
		cout << "1. New User" << endl;
		cin >> choice;
		if (choice == 1) {
			Date* day = new Date(ltm->tm_mday, ltm->tm_mon, ltm->tm_year, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
			int iduser, idaccount;
			double balance = 0;
			cout << "Id User" << endl;
			cin >> iduser;
			cout << "Id Account" << endl;
			cin >> idaccount;
			cout << "So du :" << balance << endl;
			cout << "Successful" << endl;
			cout << "Day open account";
			day->toString();
		}
	} while (choice != 0);
}