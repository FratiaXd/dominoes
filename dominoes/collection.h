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
	std::list<Domino>::iterator findDomino(std::string&, bool);
	Domino addDomino(std::list<Domino>::iterator, bool);
	bool isCompleted();
	void displayCollection();
};