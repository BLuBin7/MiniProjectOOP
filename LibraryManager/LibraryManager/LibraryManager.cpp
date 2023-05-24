#include<iostream>
#include<string>
#include<vector>
#include"Header.h"
//khong gian dinh danh
using namespace std;
#pragma warning(disable : 4996)

// 1
void Library::addOneBook(Book* book) {
	this->stock.push_back(book);
}

//2 
string Library::registerOneBook(string name) {
	BorrowerRecord* br = new BorrowerRecord(name);
	this->borrower.push_back(br);
	return name;

}

//3 
void Library::displayAvailable() {
	// Option 1
	cout << "Book available for loan : " << endl;
	for (int i = 0; i < this->stock.size(); i++) {
		//tro den display trong Book
		if (this->stock[i]->getBorrower() == NULL) {
			this->stock[i]->display();
		}
	}

	// Option 2
	// for(auto &bookavailable : this->stock) {
	// 	bookavailable->display();
	// }
}

//4 
void Library::displayBookOnLoan() {
	//Option 1
	cout << "Book on loan : " << endl;
	for (int i = 0; i < this->stock.size(); i++) {
		//tro den display trong Book
		if (this->stock[i]->getBorrower() != NULL) {
			this->stock[i]->display();
		}
	}

	//Option 2
	// for(auto &bookavailable : this->stock) {
	//     if (bookavailable->getBorrower() != NULL) {
	// 		bookavailable->display();
	// 	}
	// }
}

//5. Lend one book
void Library:: lendOneBook(string number, string name) {
	for (BorrowerRecord* br : this->borrower) {
		// TH1 : đã đăng kí
		if (this->registerOneBook(name) == br->getTheName()) {
			// window + >
			cout << "Successful : find register " << endl;

			// tao bien dem de dem so sach da duyet
			int count = 0;
			// Option 1
			for (auto it = stock.begin(); it != stock.end(); ++it) {
				count++;
				// it là con trỏ nên khai báo cần có " *it "
				if ((*it)->getNumber() == number) {
					// xoa sach trong stock
					stock.erase(stock.begin() + count - 1);
					// Must include a break here
					cout << "Borrowed successfully: "
						<< "\tbook borrower: " << name
						<< "\tBook Title: " << (*it)->getTitle() << endl;
					borrower.push_back(new BorrowerRecord(name));
					break;
				}
			}

			// Option 2
			// for(Book *book : this->stock){
			// 	count ++;
			// 	if(book->getNumber() == number)
			//  	{
			// 		stock.erase(stock.begin()+count-1);
			// 		cout<<"Borrowed successfully : "<<
			// 				"\tbook borrower : "<<name<<
			// 				"\tBook Title :"<<book->getTitle() <<endl;
			// 		// tìm thấy người mượn sách thì break luôn
			// 		break;
			// 	 }
			// }

		}
		else {
			cout << "Error , because no one has registered with this name" << endl;
		}
	}
}



void Library::returnOneBook(string number) {
	string name = this->getName();
	for (int i = 0; i < borrower.size(); i++) {
		if (borrower[i]->getaCatalogNumber() == number ||
			this->registerOneBook(name) == borrower[i]->getaCatalogNumber()) {
			borrower.erase(borrower.begin() + i);
		}
	}
}
