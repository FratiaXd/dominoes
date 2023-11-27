#include "../headers/collection.h"

class Collection
{
private:
	std::list<Domino> unsorted;
	std::list<Domino> sorted;
	std::list<Domino>::iterator findDomino(std::string&, bool);
	Domino addDomino(std::list<Domino>::iterator, bool);
	Domino readDomino(std::string);
public:
	Collection(std::string, std::string);
	void sortCollection();
	Domino placeRight();
	Domino placeLeft();
	bool isCompleted();
	void displayCollection();
	std::list<Domino> readFiles(std::string);
};
