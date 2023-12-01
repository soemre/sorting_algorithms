#pragma once

// Function prototypes

template <typename T>
void insertionsort(T *arr, int size, bool(isLess)(T, T));

template <typename T>
void insertionsort_swap(T *arr, int i, int j);

// Function definitions

template <typename T>
void insertionsort(T *arr, int size, bool(isLess)(T, T))
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (!isLess(arr[j], arr[j - 1]))
                break;

            insertionsort_swap<T>(arr, j, j - 1);
        }
    }
}

template <typename T>
void insertionsort_swap(T *arr, int i, int j)
{
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}