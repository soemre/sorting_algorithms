#pragma once

// Function prototypes

template <typename T>
void quicksort(T *arr, int size, bool(isLess)(T, T));

template <typename T>
void quicksort(T *arr, int min, int max, bool(isLess)(T, T));

template <typename T>
void quicksort_swap(T *arr, int i, int j);

// Function definitions

template <typename T>
void quicksort(T *arr, int size, bool(isLess)(T, T))
{
    quicksort<T>(arr, 0, size, isLess);
}

template <typename T>
void quicksort(T *arr, int min, int max, bool(isLess)(T, T))
{
    if (max - min <= 1)
        return;

    int pivot_index = max - 1;
    int left_pointer_index = min;

    quicksort_swap<T>(arr, pivot_index, max - 1);
    pivot_index = max - 1;

    for (int i = min; i < max - 1; i++)
    {
        if (!isLess(arr[pivot_index], arr[i]))
        {
            quicksort_swap<T>(arr, left_pointer_index, i);
            left_pointer_index++;
        }
    }

    quicksort_swap<T>(arr, left_pointer_index, pivot_index);
    pivot_index = left_pointer_index;

    quicksort<T>(arr, min, pivot_index, isLess);
    quicksort<T>(arr, pivot_index + 1, max, isLess);
}

template <typename T>
void quicksort_swap(T *arr, int i, int j)
{
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}