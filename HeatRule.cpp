#include "HeatRule.h"
#include "Rule.h"
#include <string>

HeatRule::HeatRule(Alchemy* x) {
	HeatRule::alchemy = x;
}
bool HeatRule::match(Element E1, Element E2) {
	if (E1.operator std::string == "heat")
		return 1;
	return 0;
}

Element HeatRule::combine(Element E1, Element E2) {

	std::string x = "hot";
	x += E2.operator std::string;

	Element xx = alchemy->operator[](x);
	return xx;
}
