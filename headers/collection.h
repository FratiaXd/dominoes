#pragma once

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

struct Domino {
	std::string left;
	std::string right;

	std::string generateKey()
	{
		return left + ":" + right;
	}
};

//template<typename MapType, typename SetType>
class CollectionBase
{
private:
	std::list<Domino> sorted;
	std::unordered_map<std::string, std::unordered_set<std::string>> matching;
	std::unordered_map<std::string, Domino> unsorted;
public:
	CollectionBase(std::string, std::string);
	void addDomino(Domino);
	void displayCollection();
	void sortCollection();
	bool isCompleted();
	Domino addToLeft();
	Domino addToRight();
	void removeFromUnsorted(std::string);
};