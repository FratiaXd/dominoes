#pragma once
#include <iostream>
#include <list>

class Collection
{
private:
	struct Domino;
	Domino* start;
	std::list<Domino> unsorted;
	std::list<Domino> sorted;
public:
	Collection(Domino*, std::list<Domino>);
	Domino placeRight();
	Domino placeLeft();
	bool isCompleted();
	void displayCollection();
};