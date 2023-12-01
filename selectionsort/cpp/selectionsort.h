#pragma once

// Function prototypes

template <typename T>
void selectionsort(T *arr, int size, bool(isLess)(T, T));

template <typename T>
void selectionsort_swap(T *arr, int i, int j);

// Function definitions

template <typename T>
void selectionsort(T *arr, int size, bool(isLess)(T, T))
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < size; j++)
        {
            if (isLess(arr[j], arr[min_index]))
            {
                min_index = j;
            }
        }

        selectionsort_swap<T>(arr, i, min_index);
    }
}

template <typename T>
void selectionsort_swap(T *arr, int i, int j)
{
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}