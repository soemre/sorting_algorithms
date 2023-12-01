#pragma once

#include "quicksort.h"

#include <thread>

// Function prototypes

template <typename T>
void quicksort_thread(T *arr, int size, bool(isLess)(T, T));

template <typename T>
void quicksort_thread_c(T *arr, int min, int max, bool(isLess)(T, T));

// Function definitions

template <typename T>
void quicksort_thread(T *arr, int size, bool(isLess)(T, T))
{
    quicksort_thread_c<T>(arr, 0, size, isLess);
}

template <typename T>
void quicksort_thread_c(T *arr, int min, int max, bool(isLess)(T, T))
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

    static int thread_count = 0;

    if (thread_count < 8)
    {
        thread_count += 2;

        std::thread th1(quicksort_thread_c<T>, arr, min, pivot_index, isLess);
        std::thread th2(quicksort_thread_c<T>, arr, pivot_index + 1, max, isLess);

        th1.join();
        th2.join();

        thread_count -= 2;
    }
    else
    {
        quicksort_thread_c<T>(arr, min, pivot_index, isLess);
        quicksort_thread_c<T>(arr, pivot_index + 1, max, isLess);
    }
}