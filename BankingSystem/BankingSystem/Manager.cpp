#include <iostream>
#include <vector>
#include "Header.h"

using namespace std;
void Date::toString() {
	cout << _day <<"/"
		<< + _month 
		<< "/"<<1900+ _year 
		<<":\t"<< _hour
		<< ":"<< _min 
		<< ":"<< _sec<<endl;
}


