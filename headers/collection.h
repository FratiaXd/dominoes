#pragma once
#ifndef COLLECTION_H
#define COLLECTION_H

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

	Domino() = default;
	Domino(std::string leftSide, std::string rightSide) {
		leftSide = left;
		rightSide = right;
	}

	std::string generateKey()
	{
		return left + ":" + right;
	}
};

template<typename MatchingMapType, typename UnorderedMapType>
class CollectionBase
{
private:
	std::list<Domino> sorted;
	//std::unordered_map<std::string, std::unordered_set<std::string>> matching;
	//std::unordered_map<std::string, Domino> unsorted;
	MatchingMapType matching;
	UnorderedMapType unsorted;
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

#endif // !COLLECTION_H