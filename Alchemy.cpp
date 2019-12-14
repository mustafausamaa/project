#include "Alchemy.h"
#include"Element.h"
#include <iostream>


Alchemy::Alchemy(int y){
		ruleCount=0;
		rules=new Rule*[y];
		for (int i = 0; i < y; i++)
		{
			rules[i]=NULL;
		}
	}

Element Alchemy::combine(Element E1,Element E2){
	bool z=0;
	for (int i = 0; i < ruleCount; i++)
	{
		z=rules[i]->match(E1,E2);
		if (z==1){
			return rules[i]->combine(E1,E2);
		}
	}
	for (int i = 0; i < ruleCount; i++)
	{
		z=rules[i]->match(E2,E1);
		if (z==1){
			return rules[i]->combine(E2,E1);
		}
	}
	if (z==0)
		return Element(this,"Nothing");

	}


	Element Alchemy::operator[](std::string x){
		return Element(this,x);
	}

	Rule*& Alchemy::operator[](int indx){
		return rules[indx];
	}


	Alchemy::~Alchemy(){
		delete []rules;
	}