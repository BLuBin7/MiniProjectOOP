#include "Rectangle.h"
Rectangle::Rectangle(float w,float h) {
	width = w;
	height = h;
}

float Rectangle::Arena() {
	return width * height;
}

void Rectangle::input(istream& inDevice) {
	inDevice >> width >> height;
}