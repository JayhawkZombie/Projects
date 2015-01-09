#include <fstream>
#include <iostream>
#include "Sorts.h"
#include <chrono>
#include <string>

int main(int argc, char *argv[])
{
    std::ifstream IN(argv[1]);
    if (IN.fail())
    {
        std::cout << "Error opening " << argv[1] << ". File does not exist" << std::endl;
    }

    int size;
    IN >> size;
    std::cout << "Array size is " << size << std::endl;

    int element;
    int *arr = new int[size];
    int i = 0;
    while (!IN.eof() && i < size)
    {
        IN >> element;
        arr[i] = element;
        std::cout << arr[i] << "\n";
        i++;
    }
    std::cout << "Filled the array with " << i << " elements" << std::endl;
    Sorts<int> mySorts;

    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;
    std::chrono::duration<double> elapsed;


   // std::cout << "Starting bubbleSort" << std::endl;
    start = std::chrono::system_clock::now();
//std::cout << "\n" << "\n" << "\n" << std::endl;


/** TEST ARRAY NUMBERS 10 down to 2 in descending order
    int arr2[10];
    for (int i = 0; i < 9; i++)
    {
        arr2[i] = 10-i;
        std::cout << arr2[i] << "\n";
    }
*/


    mySorts.bubbleSort(arr, size);

    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout << "Bubble sort finished in " << elapsed.count() << " seconds." << std::endl;

    std::ofstream SORTED("bubbleSorted.txt");


    for (int i = 0; i < size; i++)
    {
        SORTED << arr[i] << "\n";
    }

    IN.close();
    SORTED.close();

    delete[] arr;
    return 0;
}

