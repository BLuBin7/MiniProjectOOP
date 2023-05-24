#pragma once
#include <iostream>
#include <ostream>
using namespace std;

class Diem
{
    private:
        double x;
        double y;
    public:
        Diem(double x, double y) {
        this->setX(x);
        this->setY(y);
        }
        ~Diem();
        double getX() {
            return this->x;
        }

        double getY() {
            return this->y;
        }

        void setX(double value) {
            this->x = value;
        }

        void setY(double value) {
            this->y = value;
        }


    // lop friend cho phep truy cap het tat ca phan tu trong class
   /* friend istream& operator>>(istream& is, Diem &diem);
    friend ostream& operator<<(ostream& os, Diem &diem);*/
    
    double kc(Diem d1);
    double dientich(Diem d1, Diem d2);
    double chuvi(Diem d1, Diem d2);
};
