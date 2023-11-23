// dominoes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "collection.h"

int main()
{
    /*std::list<Domino> dominoes = {
        {"club", "diamond"}, {"heart", "spade"}, {"spade", "club"}
    };
    Domino one({ "diamond", "heart" });
    Collection dominoLine(one, dominoes);
    
    dominoLine.placeRight();
    dominoLine.placeLeft();
    dominoLine.placeLeft();
    dominoLine.placeLeft();
    std::cout << dominoLine.isCompleted() << std::endl;
    std::cout << std::endl;
    dominoLine.displayCollection();*/

    Collection d("C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/example/example-starting-domino.txt",
        "C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/example/example-input-uncoloured.txt");


    d.placeLeft();
    d.placeRight();
    std::cout << std::endl;
    d.displayCollection();
    //readFiles1("C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/example/example-starting-domino.txt");
    //readFiles2("C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/example/example-input-uncoloured.txt");
}

