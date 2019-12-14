#include "Element.h"
#include <iostream>
using namespace std;

Element::Element(Alchemy* xx, std::string y) {
	alchemy = xx;
	x = y;
}



bool Element::operator ==(Element E2) {
	bool z = 0;
	if (E2.alchemy == this->alchemy) {
		z = 1;
		for (int i = 0; i < size(x); i++)
		{
			if (x[i] != E2.x[i])
				return false;
		}
	}
	return z;
}

//	The casting operator string that returns the name of this element.

Element Element::operator+(Element E2)
{
	return E2;
}

Element :: operator std::string() {
	return this->x;
}