#include "collection.h"
#include <string>

//struct Collection::Domino
//{
//	std::string left;
//	std::string right;
//};

Collection::Collection(Domino& start, std::list<Domino>& dominoes)
{
	sorted.push_front(start);
	unsorted = dominoes;
}

Domino Collection::placeRight()
{
	if (unsorted.empty()) {
		return { "", "" };
	}
	for (Domino i : unsorted) {
		if (sorted.back().right == i.left) {
			sorted.push_back(i);
			return i;
		}
	}
}

Domino Collection::placeLeft()
{
	if (unsorted.empty()) {
		return { "", "" };
	}

}

bool Collection::isCompleted()
{
	return unsorted.empty();
}

void Collection::displayCollection()
{
	for (Domino i : sorted) {
		std::cout << i.left << " " << i.right << std::endl;
	}
}