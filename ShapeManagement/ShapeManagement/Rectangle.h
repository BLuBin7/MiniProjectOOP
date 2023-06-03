#pragma once
#include <iostream>
using namespace std;
class Rectangle {
protected :
	float width, height;
public:
	Rectangle(float w, float h);
	float Arena();
	void input(istream& inDevice);
};