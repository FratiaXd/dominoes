// dominoes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "collection.h"

int main()
{
    std::list<Domino> dominoes = {
        {"club", "diamond"}, {"heart", "spade"}, {"spade", "club"}
    };
    Domino one({ "diamond", "heart" });
    Collection dominoLine(one, dominoes);
    dominoLine.placeRight();
    dominoLine.displayCollection();
}

