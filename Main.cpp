#include <iostream>
#include <string>
#include "Alchemy.h"
#include "MixRule.h"
#include "HeatRule.h"

int main()
{
	const int ruleCount = 9;
	Alchemy alchemy(ruleCount);
	alchemy[0] = new MixRule(alchemy["iron"], alchemy["air"], alchemy["rust"]);
	alchemy[1] = new MixRule(alchemy["seed"], alchemy["water"], alchemy["plant"]);
	alchemy[2] = new MixRule(alchemy["air"], alchemy["air"], alchemy["wind"]);
	alchemy[3] = new MixRule(alchemy["water"], alchemy["plant"], alchemy["tree"]);
	alchemy[4] = new MixRule(alchemy["wind"], alchemy["tree"], alchemy["wood"]);
	alchemy[5] = new MixRule(alchemy["fire"], alchemy["water"], alchemy["steam"]);
	alchemy[6] = new MixRule(alchemy["wood"], alchemy["air"], alchemy["fire"]);
	alchemy[7] = new MixRule(alchemy["heat"], alchemy["fuel"], alchemy["fire"]);
	alchemy[8] = new HeatRule(&alchemy);
	
	while(true) {
		std::string element1, element2;
		std::cin >> element1;
		if (element1 == "exit") break;
		std::cin >> element2;
		std::cout << std::string(alchemy[element1] + alchemy[element2]) << std::endl;
	}

	for (int index = 0; index < ruleCount; index++) delete alchemy[index];

	return 0;
}