#ifndef SORTS_H
#define SORTS_H

template<typename T>
class Sorts
{
public:
    void bubbleSort(T arr[], int size);
    T* mergeSort(T arr[], int size);
private:
    T* merge(T* left, T*right, int sizeLeft, int sizeRight);
};

#include "Sorts.hpp"

#endif
