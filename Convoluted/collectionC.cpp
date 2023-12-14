#include "collectionC.h"

CollectionC::CollectionC(std::string starting, std::string rest)
{
	std::ifstream firsthandle{ starting };
	std::string text;
	if (std::getline(firsthandle, text)) {
		std::stringstream ss(text);
		std::pair<std::string, std::string> piece;
		std::getline(ss, piece.first, ':');
		std::getline(ss, piece.second, ':');
		listP.push_back(std::make_pair(piece.second, 0));
		firstDomino = piece;
	}
	firsthandle.close();

	int dominoesTotal = 1;

	std::ifstream secondhandle{ rest };
	while (std::getline(secondhandle, text)) {
		std::stringstream ss(text);
		std::pair<std::string, std::string> piece;
		std::getline(ss, piece.first, ':');
		std::getline(ss, piece.second, ':');
		listA.push_back(piece);
		dominoesTotal++;
	}
	secondhandle.close();

	int distance = 1;

	while (distance < dominoesTotal) {
		std::list<std::pair<std::string, std::string>> listB = listA;
		std::list<std::pair<std::string, std::string>> listC;

		listA.sort(sortBySecondString);
		listB.sort(sortByFirstString);
		listP.sort(sortByFirstElement);
		
		std::list<std::pair<std::string, std::string>>::iterator itA = listA.begin();
		std::list<std::pair<std::string, int>>::iterator itP = listP.begin();
		std::list<std::pair<std::string, std::string>>::iterator itB = listB.begin();

		while (itB != listB.end()) {
			if (itA != listA.end() && itB->first == itA->second) {
				listC.push_back(std::make_pair(itA->first, itB->second));
				itB++;
				itA++;
			}
			else if (itP != listP.end() && itB->first == itP->first) {
				listP.push_front(std::make_pair(itB->second, itP->second + distance));
				itB++;
				itP++;
			}
			else if (itP != listP.end() && itB->first > itP->first) {
				itP++;
			}
			else if (itA != listA.end() && itB->first > itA->second) {
				itA++;
			}
		}

		listA = listC;
		distance = distance * 2;
	}

	listP.sort(sortBySecondElement);

	for (const std::pair<std::string, int>& val : listP) {
		if (listResults.empty()) {
			listResults.push_back(std::make_pair(firstDomino.first, val.first));
		}
		else {
			listResults.push_back(std::make_pair(listResults.back().second, val.first));
		}
	}
}
void CollectionC::displayLine()
{
	for (const std::pair<std::string, std::string>& i : listResults) {
		std::cout << i.first << ":" << i.second << " ";
	}
}

static bool sortByFirstString(const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) 
{
	return a.first < b.first;
}

static bool sortBySecondString(const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) 
{
	return a.second < b.second;
}

static bool sortByFirstElement(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
{
	return a.first < b.first;
}

static bool sortBySecondElement(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
{
	return a.second < b.second;
}