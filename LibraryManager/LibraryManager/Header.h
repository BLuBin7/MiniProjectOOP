#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//do tao class Book trc nen phai define, sau do no se tham chieu lai
class BorrowerRecord;

class Book {
private:
	string number;
	string author;
	string title;

	BorrowerRecord* br;

public:
	//Contructor
	Book(string number) {
		this->setNumber(number);
	}

	Book(string number, string author, string title, BorrowerRecord* br) {
		this->setNumber(number);
		this->setAuthor(author);
		this->setTitle(title);
		//ban dau ch co nen == null
		this->setBorrower(NULL);
	}

	Book() :Book("NA", "NA", "NA", NULL) {
	}


	void setBorrower(BorrowerRecord* br) {
		this->br = br;
	}

	BorrowerRecord* getBorrower() {
		return this->br;
	}

	//Access Method : Getter & Setter
	void setNumber(string value) {
		//con tr? this
		this->number = value;
	}

	string getNumber() {
		return this->number;
	}

	void setAuthor(string value) {
		this->author = value;
	}

	string getAuthor() {
		return this->author;
	}

	void setTitle(string value) {
		this->title = value;
	}

	string getTitle() {
		return this->title;
	}



	/*BorrowerRecord* getBorrower() {
		return this->br;
	}*/



	void display() {
		cout << "Book" << endl;
		cout << "\tNumber: " << this->getNumber() << endl;
		cout << "\tAuthor: " << this->getAuthor() << endl;
		cout << "\tTitle: " << this->getTitle() << endl;
	}
};

class Library {
private:
	string name;
	vector<Book*> stock;

	vector<BorrowerRecord*> borrower;

public:

	Library(string name, vector<Book*> stock, vector<BorrowerRecord*> br) {
		this->name = name;
		this->stock = stock;
		this->borrower = br;
	}

	Library(string name) {
		this->setName(name);
	}

	void setName(string value) {
		this->name = value;
	}

	string getName() {
		return this->name;
	}

	//1. Add oneBook
	void addOneBook(Book* book);


	//2. Register borrower
	string registerOneBook(string name);


	//3. Display available book
	void displayAvailable();

	//4. Display available book on loan
	void displayBookOnLoan();

	//5. lend one book
	// tim ma sach va tim ng muon sach
	void lendOneBook(string number, string name);

	void display() {
		cout << this->getName() << endl;
		for (int i = 0; i < stock.size(); i++) {
			stock[i]->display();
		}
		cout << "Borrower" << endl;
		for (int i = 0; i < stock.size(); i++) {
			stock[i]->display();
		}
	}
};

class BorrowerRecord {
private:
	string theName;
	vector<Book*> thebook;
public:
	BorrowerRecord(string name) {
		this->setTheName(name);
	}

	BorrowerRecord() : BorrowerRecord("NA") {}

	string getTheName() {
		return this->theName;
	}

	void setTheName(string value) {
		this->theName = value;
	}



	void display() {
		cout << "Borrower :" << endl;
		cout << "\nName" << this->getTheName() << endl;
	}


	// add moi lien ket voi Book
	void attackbook(Book abook);
	// xoa moi lien ket voi Book
	void detack(Book abook);

};