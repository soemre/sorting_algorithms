#pragma once

#include <math.h>

// Function declarations

template <typename T>
void mergesort(T *arr, int size, bool(isLess)(T, T));

template <typename T>
void mergesort(T *arr, int min, int max, bool(isLess)(T, T));

template <typename T>
void mergesort_merge(T *arr, int min, int mid, int max, bool(isLess)(T, T));

// Function definitions

template <typename T>
void mergesort(T *arr, int size, bool(isLess)(T, T))
{
    mergesort<T>(arr, 0, size, isLess);
}

template <typename T>
void mergesort(T *arr, int min, int max, bool(isLess)(T, T))
{
    if ((max - min) <= 1)
        return;

    int mid = (max - min) / 2 + min;

    mergesort<T>(arr, min, mid, isLess);
    mergesort<T>(arr, mid, max, isLess);

    mergesort_merge<T>(arr, min, mid, max, isLess);
}

template <typename T>
void mergesort_merge(T *arr, int min, int mid, int max, bool(isLess)(T, T))
{
    int f_ptr = 0;
    int s_ptr = mid - min;

    T *temp_arr = new T[max - min];

    for (int i = 0; i < max - min; i++)
        temp_arr[i] = arr[i + min];

    for (int i = min; i < max; i++)
    {
        if (f_ptr < mid - min && s_ptr < max - min)
        {
            if (isLess(temp_arr[f_ptr], temp_arr[s_ptr]))
            {
                arr[i] = temp_arr[f_ptr++];
            }
            else
            {
                arr[i] = temp_arr[s_ptr++];
            }
        }
        else if (f_ptr >= mid - min)
        {
            arr[i] = temp_arr[s_ptr++];
        }
        else
        {
            arr[i] = temp_arr[f_ptr++];
        }
    }

    delete[] temp_arr;
}