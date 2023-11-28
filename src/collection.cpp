#include "../headers/collection.h"

CollectionEf::CollectionEf(std::string startFile, std::string restFile)
{
	std::ifstream firsthandle{ startFile };
	std::string text;
	if (std::getline(firsthandle, text)) {
		std::stringstream ss(text);
		Domino piece;
		std::getline(ss, piece.left, ':');
		std::getline(ss, piece.right, ':');
		sorted.push_back(piece);
	}
	firsthandle.close();

	std::ifstream resthandle{ restFile };
	while (std::getline(resthandle, text)) {
		std::stringstream ss(text);
		Domino piece;
		std::getline(ss, piece.left, ':');
		std::getline(ss, piece.right, ':');
		addDomino(piece);
	}
	resthandle.close();
}

void CollectionEf::addDomino(Domino newDomino)
{
	std::string key = newDomino.generateKey();
	unsorted[key] = newDomino;
	matching[newDomino.left].insert(key);
	matching[newDomino.right].insert(key);
}

Domino CollectionEf::addToLeft()
{
	std::string dominoSide = sorted.front().left;
	auto it = matching.find(dominoSide);
	if (it != matching.end()) {
		for (std::string key : it->second) {
			Domino unsortedDomino = unsorted[key];
			if (unsortedDomino.left == dominoSide) {
				std::swap(unsortedDomino.left, unsortedDomino.right);
			}
			if (unsortedDomino.right == dominoSide) {
				sorted.push_front(unsortedDomino);
				removeFromUnsorted(key);
				return unsortedDomino;
			}
		}
	}
	return Domino();
}

Domino CollectionEf::addToRight()
{
	std::string dominoSide = sorted.back().right;
	auto it = matching.find(dominoSide);
	if (it != matching.end()) {
		for (std::string key : it->second) {
			Domino unsortedDomino = unsorted[key];
			if (unsortedDomino.right == dominoSide) {
				std::swap(unsortedDomino.left, unsortedDomino.right);
			}
			if (unsortedDomino.left == dominoSide) {
				sorted.push_back(unsortedDomino);
				removeFromUnsorted(key);
				return unsortedDomino;
			}
		}
	}
	return Domino();
}

void CollectionEf::sortCollection()
{
	if (unsorted.empty()) {
		std::cout << "Collection not found" << std::endl;
		return;
	}
	bool addSuccess = true;
	while (!isCompleted() && addSuccess) {
		Domino leftDomino = addToLeft();
		Domino rightDomino = addToRight();
		if (leftDomino.left.empty() || rightDomino.right.empty()) {
			addSuccess = false;
		}
	}
}

bool CollectionEf::isCompleted()
{
	return unsorted.empty();
}

void CollectionEf::displayCollection()
{
	for (const Domino& i : sorted) {
		std::cout << i.left << ":" << i.right << " ";
	}
}

void CollectionEf::removeFromUnsorted(std::string key)
{
	Domino dominoToErase = unsorted[key];
	matching[dominoToErase.left].erase(key);
	matching[dominoToErase.right].erase(key);
	unsorted.erase(key);
}