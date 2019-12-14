#pragma once
#include<iostream>
using namespace std;
#include"Rule.h"
#include"Element.h"
//#include"Alchemy.h"
/*4- Create a class MixRule that inherits Rule and has three members: input1, input2,
output of type Element.
i. Add a constructor that takes input1, input2 and output.
ii. Override match to return true if and only if element1 equals input1 and element2
equals input2.
iii. Override the combine function to return output.*/

class MixRule : public Rule
{
	Element input1;
	Element input2;
	Element	output;
public:
	MixRule(Element e1,Element e2, Element e3);
	
	bool match(Element E1,Element E2);
	
	virtual Element combine(Element E1,Element E2);

};