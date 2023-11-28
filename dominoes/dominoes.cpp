// dominoes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../headers/collection.h"

int main()
{
    CollectionBase<std::map<std::string, std::set<std::string>>, 
        std::map<std::string, Domino>> d("../../dominoes-test_data/3K/3K-starting-domino.txt",
        "../../dominoes-test_data/3K/3K-input-uncoloured.txt");

    std::cout << std::endl;
    d.sortCollection();
    d.displayCollection();
    std::cout << std::endl;
}

