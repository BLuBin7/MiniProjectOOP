#include<iostream>
#include "Header.h"
using namespace std;

static void displayallchoice() {
	cout << "1. Them cuon sach" << endl;
	cout << "2. Dang ki the thu vien " << endl;
	cout << "3. Hien thi sach co san de muon" << endl;
	cout << "4. Hien thi sach co san" << endl;
	cout << "5. Muon 1 cuon sach" << endl;
	cout << "6. Tra 1 cuon sach" << endl;
}


int main() {

	Book b1("1", "ABC", "Java", NULL);
	Book* b2 = new Book("2", "DEF", "C++", NULL);
	Book* b3 = new Book("3", "FGH", "PYTHON", NULL);

	Library* lib = new Library("thu vien HCMUS");
	// // addOneBook truyen vao kieu con tro nen

	// //test #1
	// // b1 ko la con tro thi truyen tham chieu vao
	lib->addOneBook(&b1);
	// // b2 la con tro nen khong can truyen gi het
	lib->addOneBook(b2);
	lib->addOneBook(b3);

	// test #2 
	cout << "Nhap ten nguoi dang ki : " << endl;
	string name, namelend;
	getline(cin, name);
	lib->registerOneBook(name);
	//lib->display();
	// test #3 
	// lib->displayAvailable();
	// test #4
	// test #5

	BorrowerRecord* br = new BorrowerRecord();
	cout << "Nhap ten nguoi muon : " << endl;
	getline(cin, namelend);
	lib->lendOneBook("2", namelend);

	lib->displayBookOnLoan();
	lib->displayAvailable();
	lib->registerOneBook("2");


	/*
	int choice = 0;
	do {
		 Library *lib = new Library("thu vien HCMUS");
		displayallchoice();
		cout <<"nhap lua chon"<<endl;
		cin >> choice;
		// xao bo nho dem
		cin.ignore(choice);

		if(choice == 1){
			string author,title,catalogue;
			cout<<"Nhap so sach"<<endl;
			getline(cin,catalogue);

			cout<< "Nhap ten tac gia"<<endl;
			getline(cin,author);
			cout<<"Nhap ten sach"<<endl;
			getline(cin,title);

			Book *b1 = new Book(catalogue,author,title);
			lib->addOneBook(b1);
			lib->displayallbook();
			lib->display();
		}

		if(choice == 2){
			cout <<"Nhap ten nguoi dang ki : "<<endl;
			string name ;
			getline(cin,name);
			lib->registerOneBook(name);
			lib->display();
		}
		if(choice == 3){
			// lib->displayAvailable();
		}

	}while(choice!=0);

	*/
}