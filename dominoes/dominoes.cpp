// dominoes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "../headers/collection.h"
#include "collectionWorst.h"

int main()
{
    Collection d("C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/1K/1K-starting-domino.txt",
        "C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/1K/1K-input-uncoloured.txt");

    std::cout << std::endl;
    d.displayM();
    //d.sortCollection();
    std::cout << std::endl;
    //d.displayCollection();
    //readFiles1("C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/example/example-starting-domino.txt");
    //readFiles2("C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/example/example-input-uncoloured.txt");
}

