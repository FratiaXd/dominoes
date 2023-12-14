#include <iostream>
#include <chrono>
#include "../headers/collection.h"
#include "../headers/collectionC.h"
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

milliseconds timingTest_convoluted_constructor(std::string filename)
{
    std::string starting = "../../dominoes-test_data/" + filename + "/" + filename + "-starting-domino.txt";
    std::string restLine = "../../dominoes-test_data/" + filename + "/" + filename + "-input-coloured.txt";

    steady_clock::time_point startTime = steady_clock::now();

    CollectionC one(starting, restLine);

    steady_clock::time_point finishTime = steady_clock::now();

    milliseconds timeTaken = duration_cast<milliseconds>(finishTime - startTime);

    return timeTaken;
}

int main()
{
    const std::string name = "1K";

    milliseconds timeForConstructorUnorMap = timingTest_unorderedmap_constructor(name);
    milliseconds timeForSortingUnorMap = timingTest_unorderedmap_sorting(name);
    milliseconds timeOverallUnorMap = timeForConstructorUnorMap + timeForSortingUnorMap;

    milliseconds timeForConstructorMap = timingTest_orderedmap_constructor(name);
    milliseconds timeForSortingMap = timingTest_orderedmap_sorting(name);
    milliseconds timeOverallMap = timeForConstructorMap + timeForSortingMap;

    milliseconds timeConvolutedConstructor = timingTest_convoluted_constructor(name);

    std::cout << "Domino collection size: " << name << std::endl << std::endl << std::endl;

    std::cout << "Implementation being tested: std::unordered_map"                                                  << std::endl;
    std::cout << "Time taken for constructor: " << timeForConstructorUnorMap.count() << " microseconds."   << std::endl;
    std::cout << "Time taken for sorting: " << timeForSortingUnorMap.count() << " microseconds."           << std::endl;
    std::cout << "Time taken overall: " << timeOverallUnorMap.count() << " microseconds."                << std::endl << std::endl;

    std::cout << "Implementation being tested: std::map"                                                    << std::endl;
    std::cout << "Time taken for constructor: " << timeForConstructorMap.count() << " microseconds."     << std::endl;
    std::cout << "Time taken for sorting: " << timeForSortingMap.count() << " microseconds."             << std::endl;
    std::cout << "Time taken overall: " << timeOverallMap.count() << " microseconds."                  << std::endl << std::endl;

    std::cout << "Implementation being tested: Convoluted algorithm" << std::endl;
    std::cout << "Time taken overall (constructor): " << timeConvolutedConstructor.count() << " microseconds." << std::endl << std::endl;

    return 0;
}

