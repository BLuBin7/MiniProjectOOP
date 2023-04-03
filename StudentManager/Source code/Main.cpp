#include<iostream>
#include<map>
#include<vector>
#include<string>
#include"Danhsach.h"
using namespace std;


static void display() {
	cout << ("------------------------------") << endl;
	cout << ("--MENU--") << endl;
	cout << ("1. Them Sinh Vien") << endl;
	cout << ("2. Xoa Sinh Vien") << endl;
	cout << ("3. Tim Sinh Vien") << endl;
	cout << ("4. Xuat danh sach sinh vien") << endl;
	cout << ("5. Lam rong danh sach") << endl;
	cout << ("6. Xap sep theo DTB thap den cao") << endl;
	cout << ("7. Xap xep theo DTB cao den thap") << endl;
	cout << ("8. Tim kiem sinh vien") << endl;
	cout << ("9. Xuat ds co diem tu cao den thap") << endl;
	cout << ("0. Exit") << endl;
	cout << ("------------------------------") << endl;
}


int main() {


	Danhsach* ds = new Danhsach();

	//neu khoi tao la toan tu  "new" thi phai truyen con tro *, nen co dau -> 
	//con neu khong thi khong can, va -> doi thanh " . "
	/*ds->themsinhvien(*sv);
	ds->xuatdanhsach(*sv);*/

	int choice = 0;

	do {
		display();
		//xoa bo nho dem
		//fflush(stdin); ( xai trong C)

		//hoac
		/*string gh;
		string gg;
		cin >> gh;
		cin.ignore();( xai trong C++)
		getline chi xai cho chuuoi "string"
		getline(cin, gg);*/

		cin >> choice;
		// xoa bo nho dem truoc khi getline
		// do la se co "choice" va "/n" neu khong xoa bo nho dem no se gan "/n" cho bien "mssv"
		// va no se nhay toi "nhap ten"
		cin.ignore();


		if (choice == 1) {
			string mssv, ten;
			float dtb;

			//cach 1
			/*cout << "nhap mssv" << endl;
			cin >> mssv;

			cout << "nhap ten" << endl;
			cin >> ten;

			cout << "nhap dtb" << endl;
			cin >> dtb;*/


			//cach 2
			cout << "nhap mssv" << endl;
			getline(cin, mssv);

			cout << "nhap ten" << endl;
			getline(cin, ten);

			// Xoa khoi bo nho dem 32767 ky tu, hoac den khi gap ky tu '\n'
			// cin.ignore(32767, '\n');
			cout << "nhap dtb" << endl;
			cin >> dtb;




			Student* sv = new Student(mssv, ten, dtb);
			ds->themsinhvien(*sv);
			ds->xuatdanhsach();
		}

		if (choice == 2) {
			string sv;
			cout << "nhap ten sinh vien can xoa" << endl;
			getline(cin, sv);

			ds->xoaSinhVien(sv);
			ds->xuatdanhsach();

		}

		if (choice == 3) {
			string svcantim;
			cout << "nhap ten sinh vien can tim" << endl;
			getline(cin, svcantim);
			ds->timsinhvien(svcantim);
		}

		if (choice == 4) {
			ds->xuatdanhsach();
		}

		if (choice == 5) {
			string luachon;
			cout << " Ban co chac muon lam rong danh sach ?(Y/N)" << endl;
			getline(cin, luachon);
			if (luachon == "Y" || luachon == "y") {
				ds->lamrongds();
				cout << "da xoa thanh cong" << endl;
			}
			else {
				display();
			}
		}

		if (choice == 6) {
			ds->sapXepTheoDTBthapdencao();
			ds->xuatdanhsach();
		}
		if (choice == 6) {
			ds->sapXepTheoDTBcaodenthap();
			ds->xuatdanhsach();
		}
	} while (choice != 0);
	//while nho co dau " , "

	return 0;



}