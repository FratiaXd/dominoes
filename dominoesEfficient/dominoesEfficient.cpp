#include "../headers/collection.h"
#include <iostream>

int main()
{
    //C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/3K/3K-starting-domino.txt
   /* CollectionEf d("C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/3K/3K-starting-domino.txt",
        "C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/3K/3K-input-uncoloured.txt");*/

    CollectionEf d("../../dominoes-test_data/3K/3K-starting-domino.txt", 
        "../../dominoes-test_data/3K/3K-input-uncoloured.txt");
    d.sortCollection();
    std::cout << std::endl;
    d.displayCollection();
    std::cout << std::endl;
}

