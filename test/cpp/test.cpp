#include <iostream>
#include <random>
#include <chrono>
#include <ctime>
using namespace std;

#include "../../quicksort/cpp/quicksort.h"

#define SIZE 50

// Function prototypes
int *random_array(int size);
void print_array(int *arr, int size);
void test_algorithm(void(func)(int *, int, bool(int, int)), string title);

int main()
{
    // Seed the random number generator

    srand(time(NULL));

    // Test the algorithms

    test_algorithm(quicksort<int>, "Quicksort");

    return 0;
}

int *random_array(int size)
{
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
        arr[i] = i;

    for (int i = 0; i < size; i++)
    {
        int j = rand() % size;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    return arr;
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void test_algorithm(void(func)(int *, int, bool(int, int)), string title)
{
    cout << "Testing algorithm: " << title << endl;

    int *arr = random_array(SIZE);

    cout << "Before sorting: ";
    print_array(arr, SIZE);

    auto start = chrono::system_clock::now();

    func(arr, SIZE, [](int a, int b)
         { return a < b; });

    auto end = chrono::system_clock::now();

    cout << "After sorting: ";
    print_array(arr, SIZE);

    cout << "Time elapsed: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
}
