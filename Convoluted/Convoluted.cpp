#include <iostream>
#include "collectionC.h"

int main()
{
    CollectionC a("../../dominoes-test_data/10K/10K-starting-domino.txt",
        "../../dominoes-test_data/10K/10K-input-coloured.txt");
    a.displayLine();
}
