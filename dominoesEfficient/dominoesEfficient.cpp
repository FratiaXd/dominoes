#include "../headers/collection.h"
#include <iostream>

int main(int argc, char* argv[])
{
    CollectionBase<std::unordered_map<std::string, std::unordered_set<std::string>>,
        std::unordered_map<std::string, Domino>> d(argv[1], argv[2]);

    d.sortCollection();
}

