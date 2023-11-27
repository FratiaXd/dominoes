#include "../headers/collection.h"

class CollectionEf
{
private:
	std::list<Domino> sorted;
	std::unordered_map<std::string, std::unordered_set<std::string>> matching;
	std::unordered_map<std::string, Domino> unsorted;
public:
	CollectionEf(std::string, std::string);
	void addDomino(Domino);
	void displayCollection();
	void sortCollection();
	bool isCompleted();
	Domino addToLeft(std::string);
	Domino addToRight(std::string);
	void removeFromUnsorted(std::string);
};