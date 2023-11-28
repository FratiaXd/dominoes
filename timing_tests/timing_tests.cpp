#include <iostream>
#include <chrono>
#include "../headers/collection.h"
#include <utility>
#include <map>
#include "../dominoes/collectionWorst.h"

using std::chrono::steady_clock;
// using std::chrono::milliseconds;
// using std::chrono::microseconds;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;


nanoseconds timingTest_unorderedmap_constructor(unsigned long long int numberOfDominoes, std::string filename)
{
    std::string starting = "../../dominoes-test_data/" + filename + "/" + filename + "-starting-domino.txt";
    std::string restLine = "../../dominoes-test_data/" + filename + "/" + filename + "-input-uncoloured.txt";
    
    steady_clock::time_point startTime = steady_clock::now();

    CollectionEf one(starting, restLine);

    steady_clock::time_point finishTime = steady_clock::now();

    nanoseconds timeTaken = duration_cast<nanoseconds>(finishTime - startTime);

    nanoseconds meanTimePerLookup = timeTaken / numberOfDominoes;

    return meanTimePerLookup;
}

nanoseconds timingTest_unorderedmap_sorting(unsigned long long int numberOfDominoes, std::string filename)
{
    std::string starting = "../../dominoes-test_data/" + filename + "/" + filename + "-starting-domino.txt";
    std::string restLine = "../../dominoes-test_data/" + filename + "/" + filename + "-input-uncoloured.txt";

    CollectionEf one(starting, restLine);

    steady_clock::time_point startTime = steady_clock::now();

    one.sortCollection();

    steady_clock::time_point finishTime = steady_clock::now();

    nanoseconds timeTaken = duration_cast<nanoseconds>(finishTime - startTime);

    nanoseconds meanTimePerLookup = timeTaken / numberOfDominoes;

    return meanTimePerLookup;
}

nanoseconds timingTest_orderedmap_constructor(unsigned long long int numberOfDominoes, std::string filename)
{
    std::string starting = "../../dominoes-test_data/" + filename + "/" + filename + "-starting-domino.txt";
    std::string restLine = "../../dominoes-test_data/" + filename + "/" + filename + "-input-uncoloured.txt";

    steady_clock::time_point startTime = steady_clock::now();

    Collection one(starting, restLine);

    steady_clock::time_point finishTime = steady_clock::now();

    nanoseconds timeTaken = duration_cast<nanoseconds>(finishTime - startTime);

    nanoseconds meanTimePerLookup = timeTaken / numberOfDominoes;

    return meanTimePerLookup;
}

nanoseconds timingTest_orderedmap_sorting(unsigned long long int numberOfDominoes, std::string filename)
{
    std::string starting = "../../dominoes-test_data/" + filename + "/" + filename + "-starting-domino.txt";
    std::string restLine = "../../dominoes-test_data/" + filename + "/" + filename + "-input-uncoloured.txt";

    Collection one(starting, restLine);

    steady_clock::time_point startTime = steady_clock::now();

    one.sortCollection();

    steady_clock::time_point finishTime = steady_clock::now();

    nanoseconds timeTaken = duration_cast<nanoseconds>(finishTime - startTime);

    nanoseconds meanTimePerLookup = timeTaken / numberOfDominoes;

    return meanTimePerLookup;
}

int main()
{
    const unsigned long long int numberOfDominoes = 10000;

    const std::string name = "10K";

    nanoseconds meanTimePerConstructorUnor = timingTest_unorderedmap_constructor(numberOfDominoes, name);
    nanoseconds meanTimePerSortingUnor = timingTest_unorderedmap_sorting(numberOfDominoes, name);
    nanoseconds meanTimePerLookupUnor = meanTimePerConstructorUnor + meanTimePerSortingUnor;

    nanoseconds meanTimePerConstructorOr = timingTest_orderedmap_constructor(numberOfDominoes, name);
    nanoseconds meanTimePerSortingOr = timingTest_orderedmap_sorting(numberOfDominoes, name);
    nanoseconds meanTimePerLookupOr = meanTimePerConstructorOr + meanTimePerSortingOr;

    std::cout << "Dictionary being tested: std::unordered_map"                                          << std::endl;
    std::cout << "Performing " << numberOfDominoes << " random lookups."                                << std::endl;
    std::cout << "Mean time taken per constructor: " << meanTimePerConstructorUnor.count() << " nanoseconds."   << std::endl;
    std::cout << "Mean time taken per sorting: " << meanTimePerSortingUnor.count() << " nanoseconds."       << std::endl;
    std::cout << "Mean time taken overall: " << meanTimePerLookupUnor.count() << " nanoseconds." << std::endl << std::endl;

    std::cout << "Dictionary being tested: std::ordered_map" << std::endl;
    std::cout << "Performing " << numberOfDominoes << " random lookups." << std::endl;
    std::cout << "Mean time taken per constructor: " << meanTimePerConstructorOr.count() << " nanoseconds." << std::endl;
    std::cout << "Mean time taken per sorting: " << meanTimePerSortingOr.count() << " nanoseconds." << std::endl;
    std::cout << "Mean time taken overall: " << meanTimePerLookupOr.count() << " nanoseconds." << std::endl << std::endl;

    return 0;
}

