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
	//FIND DOMINO
	//compare to each domino in unsorted
	//compare to both sides
	//ADD DOMINO
	//if the opposite side is correct then swap
	//if match then push back that domino to sorted
	//erase from unsorted
	if (unsorted.empty()) {
		return { "", "" };
	}
	std::list<Domino>::iterator it = findDomino(sorted.back().right, true);

}

Domino Collection::placeLeft()
{
	if (unsorted.empty()) {
		return { "", "" };
	}

}

std::list<Domino>::iterator Collection::findDomino(std::string& end, bool isDirectionRight)
{
	//find any domino side
	//then swap
	std::list<Domino>::iterator it;
	for (it = unsorted.begin(); it != unsorted.end(); ++it) {
		if (it->left == end || it->right == end) {
			return it;
		}
	}
}

Domino Collection::addDomino(std::list<Domino>::iterator it, bool isDirectionRight)
{
	if (isDirectionRight && it->left == sorted.back().right) {

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