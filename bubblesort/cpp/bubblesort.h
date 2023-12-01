#pragma once

// Function declarations

template <typename T>
void bubblesort(T *arr, int size, bool(isLess)(T, T));

template <typename T>
void bubblesort_swap(T *arr, int i, int j);

// Function definitions

template <typename T>
void bubblesort(T *arr, int size, bool(isLess)(T, T))
{
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (isLess(arr[j + 1], arr[j]))
            {
                bubblesort_swap<T>(arr, j, j + 1);
            }
        }
    }
}

template <typename T>
void bubblesort_swap(T *arr, int i, int j)
{
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}