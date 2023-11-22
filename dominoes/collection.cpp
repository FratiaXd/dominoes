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
	std::list<Domino>::iterator it = findDomino(sorted.back().right, true);
	return addDomino(it, true);
}

Domino Collection::placeLeft()
{
	if (unsorted.empty()) {
		return { "", "" };
	}
	std::list<Domino>::iterator it = findDomino(sorted.front().left, false);
	return addDomino(it, false);
}

std::list<Domino>::iterator Collection::findDomino(std::string& end, bool isDirectionRight)
{
	std::list<Domino>::iterator it;
	for (it = unsorted.begin(); it != unsorted.end(); ++it) {
		if (it->left == end || it->right == end) {
			return it;
		}
	}
}

Domino Collection::addDomino(std::list<Domino>::iterator it, bool isDirectionRight)
{
	if (it != unsorted.end()) {
		if ((isDirectionRight && it->right == sorted.back().right) || (!isDirectionRight && it->left == sorted.front().left)) {
			std::swap(it->left, it->right);
		}

		if (isDirectionRight) {
			sorted.push_back(*it);
		} else {
			sorted.push_front(*it);
		}

		unsorted.erase(it);
		
		if (isDirectionRight) {
			std::cout << sorted.back().left << " " << sorted.back().right << std::endl;
			return sorted.back();
		} else {
			std::cout << sorted.front().left << " " << sorted.front().right << std::endl;
			return sorted.front();
		}
	}
	return { "", "" };
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