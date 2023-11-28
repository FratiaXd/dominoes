#include <iostream>
#include <chrono>
#include "../headers/collection.h"
#include <utility>
#include <map>

using std::chrono::steady_clock;
// using std::chrono::milliseconds;
// using std::chrono::microseconds;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;


nanoseconds timingTest_unorderedmap_constructor(unsigned long long int numberOfDominoes, std::string filename)
{
    std::string starting = "C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/" + filename + "/" + filename + "-starting-domino.txt";
    std::string restLine = "C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/" + filename + "/" + filename + "-input-uncoloured.txt";
    
    steady_clock::time_point startTime = steady_clock::now();

    CollectionEf one(starting, restLine);

    steady_clock::time_point finishTime = steady_clock::now();

    nanoseconds timeTaken = duration_cast<nanoseconds>(finishTime - startTime);

    nanoseconds meanTimePerLookup = timeTaken / numberOfDominoes;

    return meanTimePerLookup;
}

nanoseconds timingTest_unorderedmap_sorting(unsigned long long int numberOfDominoes, std::string filename)
{
    std::string starting = "C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/" + filename + "/" + filename + "-starting-domino.txt";
    std::string restLine = "C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/" + filename + "/" + filename + "-input-uncoloured.txt";

    CollectionEf one(starting, restLine);

    steady_clock::time_point startTime = steady_clock::now();

    one.sortCollection();

    steady_clock::time_point finishTime = steady_clock::now();

    nanoseconds timeTaken = duration_cast<nanoseconds>(finishTime - startTime);

    nanoseconds meanTimePerLookup = timeTaken / numberOfDominoes;

    return meanTimePerLookup;
}



int main()
{
    const unsigned long long int numberOfDominoes = 1000;

    const std::string name = "1K";

    nanoseconds meanTimePerLookup1 = timingTest_unorderedmap_constructor(numberOfDominoes, name);
    nanoseconds meanTimePerLookup2 = timingTest_unorderedmap_sorting(numberOfDominoes, name);

    std::cout << "Dictionary being tested: std::unordered_map"                                          << std::endl;
    std::cout << "Performing " << numberOfDominoes << " random lookups."                                << std::endl;
    std::cout << "Mean time taken per constructor: " << meanTimePerLookup1.count() << " nanoseconds."   << std::endl;
    std::cout << "Mean time taken per sorting: " << meanTimePerLookup2.count() << " nanoseconds."       << std::endl;

    return 0;
}

