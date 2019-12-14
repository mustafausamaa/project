#pragma once
#include"Alchemy.h"
#include<iostream>
using namespace std;
class Alchemy;
class Element {
	Alchemy* alchemy;
	std::string x;
	friend class Alchemy;
protected:

	Element(Alchemy* xx, std::string y);

public:
	bool operator ==(Element E2);

	//	The casting operator string that returns the name of this element.

	Element operator + (Element E2);

	Element :: operator std::string();

};

