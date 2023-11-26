#pragma once
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <sstream>

struct Domino {
	std::string left;
	std::string right;

	std::string generateKey()
	{
		return left + ":" + right;
	}
};

class CollectionEf
{
private:
	std::list<Domino> sorted;
	std::unordered_map<std::string, std::unordered_set<std::string>> matching;
	std::unordered_map<std::string, Domino> unsorted;
public:
	CollectionEf(std::string, std::string);
	void addDomino(Domino);
	void displayCollection();
	void sortCollection();
	bool isCompleted();
	Domino addToLeft(std::string);
	Domino addToRight(std::string);
	void removeFromUnsorted(std::string);
};