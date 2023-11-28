#include "../headers/collection.h"

template<typename MatchingMapType, typename UnorderedMapType>
CollectionBase<MatchingMapType, UnorderedMapType>::CollectionBase(std::string startFile, std::string restFile)
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

template<typename MatchingMapType, typename UnorderedMapType>
void CollectionBase<MatchingMapType, UnorderedMapType>::addDomino(Domino newDomino)
{
	std::string key = newDomino.generateKey();
	unsorted[key] = newDomino;
	matching[newDomino.left].insert(key);
	matching[newDomino.right].insert(key);
}

template<typename MatchingMapType, typename UnorderedMapType>
Domino CollectionBase<MatchingMapType, UnorderedMapType>::addToLeft()
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

template<typename MatchingMapType, typename UnorderedMapType>
Domino CollectionBase<MatchingMapType, UnorderedMapType>::addToRight()
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

template<typename MatchingMapType, typename UnorderedMapType>
void CollectionBase<MatchingMapType, UnorderedMapType>::sortCollection()
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

template<typename MatchingMapType, typename UnorderedMapType>
bool CollectionBase<MatchingMapType, UnorderedMapType>::isCompleted()
{
	return unsorted.empty();
}

template<typename MatchingMapType, typename UnorderedMapType>
void CollectionBase<MatchingMapType, UnorderedMapType>::displayCollection()
{
	for (const Domino& i : sorted) {
		std::cout << i.left << ":" << i.right << " ";
	}
}

template<typename MatchingMapType, typename UnorderedMapType>
void CollectionBase<MatchingMapType, UnorderedMapType>::removeFromUnsorted(std::string key)
{
	Domino dominoToErase = unsorted[key];
	matching[dominoToErase.left].erase(key);
	matching[dominoToErase.right].erase(key);
	unsorted.erase(key);
}

template class CollectionBase<std::unordered_map<std::string, std::unordered_set<std::string>>, std::unordered_map<std::string, Domino>>;
template class CollectionBase<std::map<std::string, std::set<std::string>>, std::map<std::string, Domino>>;