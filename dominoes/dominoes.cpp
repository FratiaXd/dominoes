// dominoes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../headers/collection.h"

int main(int argc, char* argv[])
{
    CollectionBase<std::map<std::string, std::set<std::string>>, 
        std::map<std::string, Domino>> d(argv[1], argv[2]);

    d.sortCollection();
}

