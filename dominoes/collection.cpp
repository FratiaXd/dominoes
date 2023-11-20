#include "collection.h"
#include <string>

struct Collection::Domino
{
	std::string left;
	std::string right;
};

Collection::Collection(Domino* start, std::list<Domino> dominoes)
{
	start = start;
	unsorted = dominoes;
}

Collection::Domino Collection::placeRight()
{

}

Collection::Domino Collection::placeLeft()
{

}

bool Collection::isCompleted()
{
	return unsorted.empty();
}

void Collection::displayCollection()
{

}