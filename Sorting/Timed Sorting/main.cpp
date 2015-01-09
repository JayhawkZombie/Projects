/**
 * @file main.cpp Sorts Lab07
 * @author Kurt Slagle
 * @date November 14th, 2014
 * @due Novemer 14th, 2014
 *
 */

#include <iostream>
#include <string>
#include <chrono>
#include <functional>
#include <ctime>
#include <cassert>
#include <climits>
#include "Sort.h"
#include "SortInfo.h"

/**
 * Given a function ptr to a sort, will return the time sort took to complete
 */
template<typename T> double sortTimer(std::function<void(T[], int)> sort, T arr[], int size)
{


    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point timeEnd;
    std::chrono::duration<double> elapsed;
    start = std::chrono::system_clock::now();
    sort(arr, size);
    timeEnd = std::chrono::system_clock::now();
    elapsed = timeEnd - start;
    assert(Sorts<T>::isSorted(arr, size));
    return elapsed.count();

}

/**
 * @brief sortTimingInfo
 * @param sortInfo
 * @param timeLimit, SortInto<int> &sortInfo
 */
void sortTimingInfo(SortInfo<int> &sortInfo, double timeLimit)
{
    double timeTaken{0.0d};
    int numbersSorted{0};

    //std::cerr << "Time Limit Is: " << timeLimit << std::endl;

    for (int i = 1; i < INT_MAX; i++)
    {
        int *arr = new int[i];

        //make random array
        for (int j = 0; j < i; j++)
        {

            static std::default_random_engine generator(time(nullptr));
            static std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);

            int randomNum{0};
            randomNum = distribution(generator);

            arr[j] = randomNum;

        }

        timeTaken = sortTimer(sortInfo.getSort(), arr, i);

        if (timeTaken < timeLimit)
        {
            sortInfo.setCount(i);
            sortInfo.setTime(timeTaken);
            numbersSorted++;
            delete [] arr;
        }
        else
        {
            delete [] arr;
            break;
        }

    }

    std::cout << sortInfo.getName() << " was able to sort " << sortInfo.getCount() << " numbers in " << sortInfo.getTime() << " seconds." << std::endl;

}

int main()
{
    SortInfo<int> sorts[] = { SortInfo<int>( Sorts<int>::bogoSort, "Bogo Sort"),
                    SortInfo<int>( Sorts<int>::bubbleSort, "Bubble Sort"),
                    SortInfo<int>( Sorts<int>::insertionSort, "Insertion Sort"),
                    SortInfo<int>( Sorts<int>::selectionSort, "Selection Sort"),
                    SortInfo<int>( Sorts<int>::mergeSort, "Merge Sort"),
                    SortInfo<int>( Sorts<int>::quickSort, "Quick Sort"),
                    SortInfo<int>( Sorts<int>::quickSortMedian, "Quick Sort (median)")
                    };
    double timeToSort{0.0};

    /** generate random array for bogo to sort */
    int randomNumber{0};
    static std::default_random_engine generator(time(nullptr));
    static std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);
    int arr[7];
    for (int i = 0; i < 7; i++)
    {
        randomNumber = distribution(generator);
        arr[i] = randomNumber;
    }

    std::cout << "Bogo Sort will attempt to sort 7 numbers:" << std::endl;

    timeToSort = sortTimer<int>(sorts[0].getSort(), arr, 7);

    std::cout << "BogoSort sorted in: " << timeToSort << " seconds." << std::endl;

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "In the same time or less, the following sorts were able to perform: " << std::endl;

    sortTimingInfo(sorts[1], timeToSort);

    sortTimingInfo(sorts[2], timeToSort);

    sortTimingInfo(sorts[3], timeToSort);

    sortTimingInfo(sorts[4], timeToSort);

    sortTimingInfo(sorts[5], timeToSort);

    sortTimingInfo(sorts[6], timeToSort);


    return 0;
}
