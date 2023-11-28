// convolutedAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "convoluted.h"

int main()
{
    Convoluted a("../../dominoes-test_data/1K/1K-starting-domino.txt",
        "../../dominoes-test_data/1K/1K-input-coloured.txt");
    a.display();
}
