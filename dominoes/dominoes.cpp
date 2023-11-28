// dominoes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "../headers/collection.h"
#include "collectionWorst.h"

int main()
{
    /*Collection d("C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/1K/1K-starting-domino.txt",
        "C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/1K/1K-input-uncoloured.txt");*/

    Collection d("../../dominoes-test_data/3K/3K-starting-domino.txt",
        "../../dominoes-test_data/3K/3K-input-uncoloured.txt");

    std::cout << std::endl;
    //d.displayM();
    d.sortCollection();
    d.displayCollection();
    std::cout << std::endl;
}

