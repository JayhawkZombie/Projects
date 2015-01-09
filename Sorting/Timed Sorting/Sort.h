/**
 * @file Sort.h Sorts Lab07
 * @author Kurt Slagle
 * @date November 14th, 2014
 * @due Novemer 14th, 2014
 *
 */

#ifndef SORT_H
#define SORT_H

template<typename T>
class Sorts
{
public:
    /**
    * @function bogoSort
    * @return none
    * @param array of type T, int (size of array)
    * @pre takes array of type T
    * @post sorts the array using BogoSort
    */
    static void bogoSort(T arr[], int size);
    /**
    * @function bubbleSort
    * @return none
    * @param array of type T, int (size of array)
    * @pre takes array of type T
    * @post sorts the array using bubbleSort
    */
    static void bubbleSort(T arr[], int size);
    /**
    * @function insertionSort
    * @return none
    * @param array of type T, int (size of array)
    * @pre takes array of type T
    * @post sorts the array using insertionSort
    */
    static void insertionSort(T arr[], int size);
    /**
    * @function mergeSort
    * @return none
    * @param array of type T, int (size of array)
    * @pre takes array of type T
    * @post sorts the array using mergeSort
    */
    static void mergeSort(T arr[], int size);
    /**
    * @function quickSort
    * @return none
    * @param array of type T, int (size of array)
    * @pre takes array of type T
    * @post sorts the array using quickSort with median flag of false
    */
    static void quickSort(T arr[], int size);
    /**
    * @function quickSortMedian
    * @return none
    * @param array of type T, int (size of array)
    * @pre takes array of type T
    * @post sorts the array using quickSort with median flag true
    */
    static void quickSortMedian(T arr[], int size);
    /**
    * @function selectionSort
    * @return none
    * @param array of type T, int (size of array)
    * @pre takes array of type T
    * @post sorts the array using selectionSort
    */
    static void selectionSort(T arr[], int size);
    /**
    * @function isSorted
    * @return bool
    * @param array of type T, int (size of array)
    * @pre takes array of type T
    * @post returns true if array is sorted, false otherwise
    */
    static bool isSorted(T arr[], int size);

private:
    /**
    * @function merge
    * @return none
    * @param 2 arrays of type T, 2 int (size of each array)
    * @pre takes array of type T
    * @post merges the two arrays
    */
    static void merge(T* a1, T* a2, int size1, int size2);
    /**
    * @function quickSortRec
    * @return none
    * @param array of type T, int (first element), int (last element), bool for median flag
    * @pre takes array of type T
    * @post sorts - send array to partition and sorts it
    */
    static void quickSortRec(T arr[], int first, int last, bool median);
    /**
    * @function setMedianPivot
    * @return none
    * @param array of type T, int (first), int (last)
    * @pre takes array of type T
    * @post sets the pivot as the median value of the array
    */
    static void setMedianPivot(T arr[], int first, int last);
    /**
    * @function bubbleSort
    * @return none
    * @param array of type T, int (first), int (last), bool for median flag
    * @pre takes array of type T
    * @post partitions the array
    */
    static int partition(T arr[], int first, int last, bool median);
    /**
    * @function bubbleSort
    * @return none
    * @param array of type T, int (size of array)
    * @pre takes array of type T
    * @post randomly shuffles the array
    */
    static void shuffle(T arr[], int size);
};


#include "Sort.hpp"

#endif
