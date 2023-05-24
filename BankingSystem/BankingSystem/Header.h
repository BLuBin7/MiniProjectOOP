#pragma once
#include<iostream>
#include<ctime>
#pragma warning(disable: 4996)
using namespace std;
class Date {
	int _day ;
	int _year ;
	int _month ;
	int _hour ;
	int _min ;
	int _sec ;
public:
	int getDay() const {
		return this->_day;
	}

	int getSec() {
		return this->_sec;
	}

	int getYear() {
		return this->_year;
	}

	int getMonth() {
		return this->_month;
	}

	int getHour() {
		return this->_hour;
	}

	int getMin() {
		return this->_min;
	}

	void setYear(int value) {
		this->_year = value;
	}

	void setMonth(int value)  {
		this->_month = value;
	}
	
	void setDay(int value)  {
		this->_day = value;
	}

	void setHour(int value) {
		this->_hour = value;
	}

	void setMin(int value) {
		this->_min = value;
	}

	void setSec(int value) {
		this->_sec = value;
	}
	Date(){}
	Date(int day, int month,int year, int hour, int min, int sec) {
		this->setDay(day);
		this->setMonth(month);
		this->setYear(year);
		this->setHour(hour);
		this->setMin(min);
		this->setSec(sec);
	}
	void toString();
};

class Status {

};
class User {
private :
	 string _idAccount;
	 string _idUser;
	 Date _dateOperenAccount;
	 double _balanceintheaAccount;
public:
	User();
	User(int idaccount, int iduser, Date dateopen, int balance) {
		this->_idAccount = idaccount;
		this->_idUser = iduser;
		this->_dateOperenAccount = dateopen;
		this->_balanceintheaAccount = balance;
	}
	string getidAccount() {
		return this->_idAccount;
	}
	
};

class transaction {
private:
	int _idTrace;
	int _idAccount;
	Date _dateTrace;
	double _money;
	Status status;
public:
	void withdrawMoney();
	void deposit();
	void transfermoney();
};


