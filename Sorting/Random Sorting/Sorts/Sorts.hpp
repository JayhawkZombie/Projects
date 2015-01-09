
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
T* Sorts<T>::mergeSort(T arr[], int size)
{
    int mid{0};
    /** need to check if the array is of an even size or an odd size */

    if (size%2 == 0)
    {
        /** size of array is even */
        /** need to sort the left and right side of the array */
        //sort the left side
        mergeSort(arr, size/2);
        //sort the right side

    }
    else
    {
        /** size of array is odd */
    }
}

template<typename T>
T* Sorts<T>::merge(T* left, T*right, int sizeLeft, int sizeRight)
{

}
