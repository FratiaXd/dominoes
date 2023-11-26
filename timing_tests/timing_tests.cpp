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


nanoseconds timingTest_list(unsigned long long int mapSize, unsigned long long int numberOfLookups, std::string filename)
{
    std::string starting = "C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/" + filename + "/" + filename + "-starting-domino.txt";
    std::string rest = "C:/Users/Owner/Documents/UNI_Y3/SOFT_ENG/dominoes-test_data/" + filename + "/" + filename + "-input-uncoloured.txt";
    /*  If no seed value is given, each KeyItemGenerator object will produce the same sequence of keys/items.
     *  If we want different pseudo-random keys/items from each object (and each program run), then we should
     *  provide a seed value.
     *
     *  For example:
     *
     *   unsigned int seed = steady_clock::now().time_since_epoch().count();
     *   KeyItemGenerator gen = KeyItemGenerator(seed);
    */

    Collection toSort(starting, rest);

    //for (unsigned long long int i = 0; i < mapSize; ++i)
    //{
    //    
    //    /* Note: std::map::insert() differs slightly from Dictionary::insert(),
    //     * in that it does not overwrite the item if the key already exists.
    //     */
    //}

    
    steady_clock::time_point startTime = steady_clock::now();

    toSort.sortCollection();


    //for (unsigned long long int i = 0; i < numberOfLookups; ++i)
    //{
    //    /* Note: std::map::find() differs slightly from Dictionary::lookup(),
    //     * in that it returns an *iterator* to the key/item pair.
    //     */
    //}

    steady_clock::time_point finishTime = steady_clock::now();

    nanoseconds timeTaken = duration_cast<nanoseconds>(finishTime - startTime);

    nanoseconds meanTimePerLookup = timeTaken / numberOfLookups;

    return meanTimePerLookup;
}



int main()
{
    std::cout << "Hello World!\n";
}

