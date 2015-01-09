/**
 * @file Sort.hpp Sorts Lab07
 * @author Kurt Slagle
 * @date November 14th, 2014
 * @due Novemer 14th, 2014
 *
 */

//#include "Sort.h" //only for writing code - will comment out when compiling

#include <random>
#include <ctime>
#include <iostream>

template<typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{
//char a;
int numIters = 0;
    while (!isSorted(arr, size))
    {
        shuffle(arr, size);
        numIters++;

//DEBUGGING CODE BELOW
/*
        std::cin >> a;
        std::cerr << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << std::endl;
        for (int i = 0; i <= size - 1; ++i)
        {
            std::cerr << "arr[" << i << "]" << arr[i] << " ";
        }
    std::cerr << std::endl;
    */
    }


    //std::cout << "In " << numIters << " iterations." << std::endl;

}

template<typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
    if (size == 0 || size == 1)
        return;
    else
    {
        T element;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if (arr[j] > arr[j+1])
                {
                    /** swap the values here */
                   // std::cout << arr[j] << " greater than " << arr[j+1] << std::endl;
                    element = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = element;
                   // std::cout << "Swapped to get " << arr[j] << " and " << arr[j+1] << std::endl;
                }
            }
        }
    }
}

template<typename T>
void Sorts<T>::shuffle(T arr[], int size)
{
    static std::default_random_engine generator(time(nullptr));
    static std::uniform_int_distribution<int> distribution(0, size - 1);

    int randomNumber{0};

    for (int i = 0; i <= size - 1; i++)
    {
        randomNumber = distribution(generator);

        T temp = arr[i];
        arr[i] = arr[randomNumber];
        arr[randomNumber] = temp;

    }
}

template<typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
if (size == 0 || size == 1)
    return true;
for(int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }

    return true;
}

template<typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
    int value{0}, w{0};

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
            {
                value = arr[i];
                w = i;
                while (w != j)
                {
                    arr[w] = arr[w-1];
                    w--;
                }
                arr[j] = value;
            }
        }
    }

    return;
}

/** Just my personal input - we do NOT need 5 functions to perform quickSort - this is highly ineffecient, and rather counterintuitive */

template<typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
    quickSortRec(arr,0,size - 1, false);
}

template<typename T>
void Sorts<T>::quickSortMedian(T arr[], int size)
{
    quickSortRec(arr, 0, size - 1, true);
}

template<typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
    int median = (first + last) / 2; /** assuming the array is small enough to avoid overflow */
    T temp = arr[last];
    arr[last] = arr[median];
    arr[median] = temp;
}

template<typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{
    if (first >= last)
        return;
    int pivotPos = partition(arr, first, last, median);
    quickSortRec(arr, first, pivotPos - 1, median);
    quickSortRec(arr, pivotPos + 1, last, median);
}

template<typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{
    if (median)
        setMedianPivot(arr, first, last);
    int pivot = arr[last];
    int pivotPos = first;

    for (int i = first; i < last; i++)
    {
        if (arr[i] <= pivot)
        {
            //swap
            T temp = arr[i];
            arr[i] = arr[pivotPos];
            arr[pivotPos] = temp;
            pivotPos++;
        }
    }
    //swap
    T temp = arr[pivotPos];
    arr[pivotPos] = arr[last];
    arr[last] = temp;

    return pivotPos;

}

template<typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
    int minimumIndex{0};

    for (int i = 0;i < size - 1; i++)
    {
        minimumIndex = i;
        for(int j = i; j < size; j++)
        {
            if (arr[j] < arr[minimumIndex])
                minimumIndex = j;
        }

        if (minimumIndex != i)
        {
            /** swap arr[i] and arr[minimumIndex] */

            T temp = arr[i];
            arr[i] = arr[minimumIndex];
            arr[minimumIndex] = temp;
        }
    }
}

template<typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
    if (size < 2)
        return;
    int middle = size / 2;
    T* left = arr;
    T* right = arr + middle;
    int leftSize = middle;
    int rightSize = size - middle;
    mergeSort(left, leftSize);
    mergeSort(right, rightSize);
    merge(left, right, leftSize, rightSize);
}


/** WHY CAN'T WE INCLUDE T arr[] IN THE MERGE FUNCTION?!*/
/** THAT WOULD MAKE THIS IMPLEMENTATION SO MUCH MORE SIMPLE */
template<typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2)
{
    T* temp = new T[size1 + size2];

    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (a1[i] <= a2[j])
        {
            temp[k] = a1[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a2[j];
            k++;
            j++;
        }
    }

    while (i < size1)
    {
        temp[k] = a1[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        temp[k] = a2[j];
        j++;
        k++;
    }


    /** copy values into left and right */

    for (int i = 0; i < size1 + size2; i++)
    {
        a1[i] = temp[i];
    }

    delete [] temp;
}

