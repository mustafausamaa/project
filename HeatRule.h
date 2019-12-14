#pragma once
#include "Rule.h"


class HeatRule : public Rule
{
	
public:
	Alchemy* alchemy;
	HeatRule(Alchemy *x);

	bool match(Element E1,Element E2);
	
	virtual Element combine(Element E1,Element E2);
};
