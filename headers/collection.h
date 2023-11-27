#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <map>

struct Domino {
	std::string left;
	std::string right;

	std::string generateKey()
	{
		return left + ":" + right;
	}
};