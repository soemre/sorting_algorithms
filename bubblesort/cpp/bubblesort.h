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
    for (int i = 0; i < size; i++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (isLess(arr[i + 1], arr[i]))
            {
                bubblesort_swap<T>(arr, i, i + 1);
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