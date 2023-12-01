#pragma once

// Function prototypes

template <typename T>
void heapsort(T *arr, int size, bool(isLess)(T, T));

template <typename T>
void heapsort_build_max_heap(T *arr, int size, bool(isLess)(T, T));

template <typename T>
void heapsort_heapify(T *arr, int size, int parent_index, bool(isLess)(T, T));

template <typename T>
void heapsort_swap(T *arr, int i, int j);

// Function definitions

template <typename T>
void heapsort(T *arr, int size, bool(isLess)(T, T))
{
    heapsort_build_max_heap<T>(arr, size, isLess);

    for (int i = size - 1; i >= 0; i--)
    {
        heapsort_swap<T>(arr, 0, i);
        heapsort_heapify<T>(arr, i, 0, isLess);
    }
}

template <typename T>
void heapsort_build_max_heap(T *arr, int size, bool(isLess)(T, T))
{
    for (int i = size - 1; i >= 0; i--)
        heapsort_heapify<T>(arr, size, i, isLess);
}

template <typename T>
void heapsort_heapify(T *arr, int size, int parent_index, bool(isLess)(T, T))
{
    int left_child_index = 2 * parent_index + 1;
    int right_child_index = 2 * parent_index + 2;

    int largest_index = parent_index;

    if (left_child_index < size && isLess(arr[largest_index], arr[left_child_index]))
    {
        largest_index = left_child_index;
    }

    if (right_child_index < size && isLess(arr[largest_index], arr[right_child_index]))
    {
        largest_index = right_child_index;
    }

    heapsort_swap<T>(arr, parent_index, largest_index);

    if (largest_index != parent_index)
    {
        heapsort_heapify<T>(arr, size, largest_index, isLess);
    }
}

template <typename T>
void heapsort_swap(T *arr, int i, int j)
{
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}