#include<iostream>
#include<map>
#include<vector>
#include<string>
#include"Danhsach.h"
using namespace std;
#pragma warning(disable : 4996)

// choice == 1
void Danhsach::themsinhvien(Student& value) {
	danhsach.push_back(value);
}


void Danhsach::swap(Student& a, Student& b) {
	Student temp = a;
	a = b;
	b = temp;
}


// choice == 2
void Danhsach::xoaSinhVien(string sv) {
	// cach 1
	// xoa thi khong can const

	for (Student sinhvien : danhsach) {
		if (timsinhvien(sv) == true) {
			//begin la xoa phan tu dau tien vua tim duoc, o day khong nen dung end(do khong co end)
			danhsach.erase(danhsach.begin());
			cout << "da xoa" << endl;

		}
		else {
			cout << "khong tim thay" << endl;
		}
	}

	//cach 2
		// xoa thi khong can const                               ++it
		/*for (auto it = danhsach.begin(); it != danhsach.end(); it++) {
			if (it->getTen() == sv) {
				it = danhsach.erase(it);
				cout << "da xoa" << endl;
			}
			else {
				cout << "khong tim thay" << endl;
			}
		}
		*/

}

// choice == 3
bool Danhsach::timsinhvien(string sv) {
	for (Student sinhvien : danhsach) {
		if (sinhvien.getTen() == sv) {
			cout << "find" << endl;
			return true;
		}
		else {
			cout << " not found" << endl;
			return false;
		}
		//return (sinhvien.getTen() == sv) ? true : false;
	}
}

// choice == 4
void Danhsach::xuatdanhsach() {
	for (Student sv : danhsach) {
		sv.toString();
	}
}

// choice == 5
void Danhsach::lamrongds() {
	for (Student sv : danhsach) {
		danhsach.clear();
	}
}

//choice == 6
void Danhsach::sapXepTheoDTBthapdencao() {
	int n = danhsach.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (danhsach[j] > danhsach[j + 1]) {
				swap(danhsach[j], danhsach[j + 1]);
			}
		}
	}
}

//choice == 7
void Danhsach::sapXepTheoDTBcaodenthap() {
	int n = danhsach.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (danhsach[j] < danhsach[j + 1]) {
				swap(danhsach[j], danhsach[j + 1]);
			}
		}
	}
}

