#include "../headers/collection.h"

class Collection
{
private:
	std::list<Domino> sorted;
	std::map<std::string, std::set<std::string>> matching;
	std::map<std::string, Domino> unsorted;
public:
	Collection(std::string, std::string);
	void addDomino(Domino);
	void displayCollection();
	void sortCollection();
	bool isCompleted();
	Domino addToLeft(std::string);
	Domino addToRight(std::string);
	void removeFromUnsorted(std::string);
	void displayM();
};