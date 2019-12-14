#pragma once
#include "Element.h"
class Element;

class Rule{

public:
	virtual bool match(Element E1,Element E2)=0;
	virtual Element combine(Element E1,Element E2)=0;
};