#include "MixRule.h"


MixRule::MixRule(Element e1, Element e2, Element e3)
	:input1(e1), input2(e2), output(e3)
{
}
bool MixRule::match(Element E1, Element E2) {
	if (E1 == input1 && E2 == input2)
		return 1;
	return 0;
}

Element MixRule::combine(Element E1, Element E2)
{
	return output;
}
