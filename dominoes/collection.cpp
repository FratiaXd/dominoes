#include "collection.h"

Collection::Collection(std::string firstDominoPath, std::string restDominoPath)
{
	sorted = readFiles(firstDominoPath);
	unsorted = readFiles(restDominoPath);
}

void Collection::sortCollection() 
{
	if (unsorted.empty()) {
		std::cout << "Collection not found" << std::endl;
		return;
	}
	while (!isCompleted()) {
		placeLeft();
		placeRight();
	}
	displayCollection();
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
			//std::cout << sorted.back().left << " " << sorted.back().right << std::endl;
			return sorted.back();
		} else {
			//std::cout << sorted.front().left << " " << sorted.front().right << std::endl;
			return sorted.front();
		}
	}
	return {};
}

bool Collection::isCompleted()
{
	return unsorted.empty();
}

void Collection::displayCollection()
{
	for (Domino i : sorted) {
		std::cout << i.left << ":" << i.right << " ";
	}
}

std::list<Domino> Collection::readFiles(std::string dominoPath)
{
	std::ifstream filehandle{ dominoPath };
	std::list<Domino> fileDominoes;
	if (filehandle.fail()) {
		std::cout << "Specified file does not exist" << std::endl;
		return fileDominoes;
	}
	std::string text;
	while (std::getline(filehandle, text)) {
		Domino a = readDomino(text);
		fileDominoes.push_back(a);
		//std::cout << a.left << "  " << a.right << std::endl;
	}
	return fileDominoes;
}

Domino Collection::readDomino(std::string text)
{
	Domino value;
	std::stringstream ss(text);
	std::getline(ss, value.left, ':');
	std::getline(ss, value.right, ':');
	return value;
}