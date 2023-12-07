#include <iostream>
#include <chrono>
#include "../headers/collection.h"
#include <utility>

using std::chrono::steady_clock;
using std::chrono::milliseconds;
//using std::chrono::microseconds;
//using std::chrono::nanoseconds;
using std::chrono::duration_cast;


milliseconds timingTest_unorderedmap_constructor(std::string filename)
{
    std::string starting = "../../dominoes-test_data/" + filename + "/" + filename + "-starting-domino.txt";
    std::string restLine = "../../dominoes-test_data/" + filename + "/" + filename + "-input-uncoloured.txt";
    
    steady_clock::time_point startTime = steady_clock::now();

    CollectionBase<std::unordered_map<std::string, std::unordered_set<std::string>>,
        std::unordered_map<std::string, Domino>> one(starting, restLine);

    steady_clock::time_point finishTime = steady_clock::now();

    milliseconds timeTaken = duration_cast<milliseconds>(finishTime - startTime);

    return timeTaken;
}

milliseconds timingTest_unorderedmap_sorting(std::string filename)
{
    std::string starting = "../../dominoes-test_data/" + filename + "/" + filename + "-starting-domino.txt";
    std::string restLine = "../../dominoes-test_data/" + filename + "/" + filename + "-input-uncoloured.txt";

    CollectionBase<std::unordered_map<std::string, std::unordered_set<std::string>>,
        std::unordered_map<std::string, Domino>> one(starting, restLine);

    steady_clock::time_point startTime = steady_clock::now();

    one.sortCollection();

    steady_clock::time_point finishTime = steady_clock::now();

    milliseconds timeTaken = duration_cast<milliseconds>(finishTime - startTime);

    return timeTaken;
}

milliseconds timingTest_orderedmap_constructor(std::string filename)
{
    std::string starting = "../../dominoes-test_data/" + filename + "/" + filename + "-starting-domino.txt";
    std::string restLine = "../../dominoes-test_data/" + filename + "/" + filename + "-input-uncoloured.txt";

    steady_clock::time_point startTime = steady_clock::now();

    CollectionBase<std::map<std::string, std::set<std::string>>,
        std::map<std::string, Domino>> one(starting, restLine);

    steady_clock::time_point finishTime = steady_clock::now();

    milliseconds timeTaken = duration_cast<milliseconds>(finishTime - startTime);

    return timeTaken;
}

milliseconds timingTest_orderedmap_sorting(std::string filename)
{
    std::string starting = "../../dominoes-test_data/" + filename + "/" + filename + "-starting-domino.txt";
    std::string restLine = "../../dominoes-test_data/" + filename + "/" + filename + "-input-uncoloured.txt";

    CollectionBase<std::map<std::string, std::set<std::string>>,
        std::map<std::string, Domino>> one(starting, restLine);

    steady_clock::time_point startTime = steady_clock::now();

    one.sortCollection();

    steady_clock::time_point finishTime = steady_clock::now();

    milliseconds timeTaken = duration_cast<milliseconds>(finishTime - startTime);

    return timeTaken;
}

int main()
{
    const unsigned long long int numberOfDominoes = 60;

    const std::string name = "300";

    milliseconds timeForConstructorUnorMap = timingTest_unorderedmap_constructor(name);
    milliseconds timeForSortingUnorMap = timingTest_unorderedmap_sorting(name);
    milliseconds timeOverallUnorMap = timeForConstructorUnorMap + timeForSortingUnorMap;

    milliseconds timeForConstructorMap = timingTest_orderedmap_constructor(name);
    milliseconds timeForSortingMap = timingTest_orderedmap_sorting(name);
    milliseconds timeOverallMap = timeForConstructorMap + timeForSortingMap;

    std::cout << "Dictionary being tested: std::unordered_map"                                                  << std::endl;
    std::cout << "Domino collection size: " << numberOfDominoes                                                 << std::endl;
    std::cout << "Time taken for constructor: " << timeForConstructorUnorMap.count() << " microseconds."   << std::endl;
    std::cout << "Time taken for sorting: " << timeForSortingUnorMap.count() << " microseconds."           << std::endl;
    std::cout << "Time taken overall: " << timeOverallUnorMap.count() << " microseconds."                << std::endl << std::endl;

    std::cout << "Dictionary being tested: std::map"                                                    << std::endl;
    std::cout << "Domino collection size: " << numberOfDominoes                                                 << std::endl;
    std::cout << "Time taken for constructor: " << timeForConstructorMap.count() << " microseconds."     << std::endl;
    std::cout << "Time taken for sorting: " << timeForSortingMap.count() << " microseconds."             << std::endl;
    std::cout << "Time taken overall: " << timeOverallMap.count() << " microseconds."                  << std::endl << std::endl;

    return 0;
}

