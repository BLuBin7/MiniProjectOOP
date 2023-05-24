#pragma warning(disable: 4996)
#include"Diem.h"
#include<math.h>
using namespace std;
//istream& operator >> (istream& is, Diem &diem) {
//    cout << "nhap x: ";
//    is >> diem.x;
//    cout << "nhap y: ";
//    is >> diem.y;
//    return is;
//}
//
//ostream& operator <<(ostream& os, Diem &diem) {
//    os << diem.x << "" << diem.y << endl;
//    return os;
//}


double Diem::kc(Diem d1) {
    cout << "khoang cach giua 2 diem la:";
    // con tro tro den bien thi dung mui ten (->)
    // doi tuong tro den doi tuong thi dung cham(.)
    // ham pow dung de tinh luy thua(o day la mu 2
    double kq = sqrt(pow(this->x - d1.x, 2) + pow(this->y - d1.y, 2));
    return kq;
}

double Diem::dientich(Diem d1, Diem d2) {
    double xab = this->x - d1.x;
    double yab = this->y - d1.y;

    double xac = this->x - d2.x;
    double yac = this->y - d2.y;
    
    double kq = 1 / 2 * (xab * yac - yab * xac);
    cout << "Dien tich tam giac la:" <<kq<< endl;
    return kq;
}

//Object A , d1 B, d2 C
double Diem::chuvi(Diem d1, Diem d2) {
    double xab = this->x - d1.x;
    double yab = this->y - d1.y;

    double xac = this->x - d2.x;
    double yac = this->y - d2.y;

    double xbc = d1.x - d2.x;
    double ybc = d1.y - d2.y;

    double chuvi = sqrt(pow(xab + xac + xbc, 2) + pow(yab + yac + ybc, 2));
    cout << "Chu vi la : "<<chuvi;
    return chuvi;
}