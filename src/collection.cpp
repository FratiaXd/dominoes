#include "../headers/collection.h"

//Constructor for Domino collection
template<typename MatchingMapType, typename UnorderedMapType>
CollectionBase<MatchingMapType, UnorderedMapType>::CollectionBase(std::string startFile, std::string restFile)
{
	//Reads first domino from the provided file
	std::ifstream firsthandle{ startFile };
	std::string text;
	if (std::getline(firsthandle, text)) {
		std::stringstream ss(text);
		Domino piece;
		std::getline(ss, piece.left, ':');
		std::getline(ss, piece.right, ':');
		sorted.push_back(piece);					//Adds domino as a first element to the sorted collection list
	}
	firsthandle.close();

	//Reads the rest of the dominoes from the provided file
	std::ifstream resthandle{ restFile };
	while (std::getline(resthandle, text)) {
		std::stringstream ss(text);
		Domino piece;
		std::getline(ss, piece.left, ':');
		std::getline(ss, piece.right, ':');
		addDomino(piece);							//Adds dominoes to the unsorted and matching map/unordered_map depending on the time complexity case
	}
	resthandle.close();
}

//Automated sorting algorithm stepping left, right, left etc..
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
	//displayCollection();
}

//Generates key and adds it together with the domino to the map/unordered_map
template<typename MatchingMapType, typename UnorderedMapType>
void CollectionBase<MatchingMapType, UnorderedMapType>::addDomino(Domino& newDomino)
{
	std::string key = newDomino.generateKey();
	unsorted[key] = newDomino;
	//Uses each side of the domino to create separate keys for matching map/unordered_map
	//Saves all dominoes that contain the same value on left/right sides as domino side key inside set/unordered_set   
	matching[newDomino.left].insert(key);
	matching[newDomino.right].insert(key);
}

//Finds first domino that can be added to the left side of the sorted domino list and adds it
template<typename MatchingMapType, typename UnorderedMapType>
Domino CollectionBase<MatchingMapType, UnorderedMapType>::addToLeft()
{
	std::string dominoSide = sorted.front().left;					//Finds domino value on the left(dominoSide) inside the sorted list
	auto it = matching.find(dominoSide);							//Finds iterator value for matching map/unordered_map where key is the same as dominoSide value
	if (it != matching.end()) {
		for (std::string key : it->second) {						//Loops through selected set/unordered_set by previously found iterator value for matching map/unordered_map
			Domino unsortedDomino = unsorted[key];
			if (unsortedDomino.left == dominoSide) {					//Swaps domino if positioned backwards
				std::swap(unsortedDomino.left, unsortedDomino.right);
			}
			if (unsortedDomino.right == dominoSide) {					
				sorted.push_front(unsortedDomino);
				removeFromUnsorted(key);							//Removes now sorted domino from matching and unsorted
				return unsortedDomino;
			}
		}
	}
	return Domino();
}

//Mirrors addToLeft()
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

//Checks if there are any dominoes left in the unsorted
template<typename MatchingMapType, typename UnorderedMapType>
bool CollectionBase<MatchingMapType, UnorderedMapType>::isCompleted()
{
	return unsorted.empty();
}

//Displays the sorted collection
template<typename MatchingMapType, typename UnorderedMapType>
void CollectionBase<MatchingMapType, UnorderedMapType>::displayCollection()
{
	for (const Domino& i : sorted) {
		std::cout << i.left << ":" << i.right << " ";
	}
}

//Erases sorted domino from matching and unsorted
template<typename MatchingMapType, typename UnorderedMapType>
void CollectionBase<MatchingMapType, UnorderedMapType>::removeFromUnsorted(std::string& key)
{
	Domino dominoToErase = unsorted[key];
	matching[dominoToErase.left].erase(key);
	matching[dominoToErase.right].erase(key);
	unsorted.erase(key);
}

//Average-case template is unordered_map and unordered_set
template class CollectionBase<std::unordered_map<std::string, std::unordered_set<std::string>>, std::unordered_map<std::string, Domino>>;

//Worst-case template is map and set
template class CollectionBase<std::map<std::string, std::set<std::string>>, std::map<std::string, Domino>>;