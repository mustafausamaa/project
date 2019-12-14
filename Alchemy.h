#pragma once
#include"Rule.h"
#include <iostream>
#include "Element.h"
#include "Rule.h"
using namespace std;
class Element;
class Rule;
class Alchemy {
	int ruleCount;
	Rule** rules;
public:
	Alchemy(int y);
	/*
	v. Add the function combine that takes two Element parameters element1 and
	element2 and returns an Element. Inside the function loop through every rule and
	using its function match, check if it matches (element1, element2) and if it
	matches, return the result of calling the rule’s combine function on (element1,
	element2). If it didn’t match, try matching it with (element2, element1) and if it
	matched, return the result of calling the rule’s combine function on (element2,
	element1). If the elements didn’t match any rule, return an Element with the name
	“nothing”.

	*/
	virtual  Element combine(Element E1, Element E2);

	Element operator[](string x);

	Rule*& operator[](int indx);
	~Alchemy();
};
