#pragma once
#include <iostream>
#include <list>

struct Domino {
	std::string left;
	std::string right;
};

class Collection
{
private:
	//Domino first;
	std::list<Domino> unsorted;
	std::list<Domino> sorted;
public:
	Collection(Domino&, std::list<Domino>&);
	Domino placeRight();
	Domino placeLeft();
	bool isCompleted();
	void displayCollection();
};