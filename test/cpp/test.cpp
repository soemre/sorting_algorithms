#include <iostream>
#include <random>
#include <chrono>
#include <ctime>
#include <string>
using namespace std;

#include "../../quicksort/cpp/quicksort.h"
#include "../../quicksort/cpp/quicksort_thread.h"
#include "../../bubblesort/cpp/bubblesort.h"
#include "../../mergesort/cpp/mergesort.h"
#include "../../selectionsort/cpp/selectionsort.h"
#include "../../insertionsort/cpp/insertionsort.h"
#include "../../heapsort/cpp/heapsort.h"

// Function prototypes
int *random_array(int size);
void print_array(int *arr, int size);
bool check_sorted(int *arr, int size);
void test_algorithm(void(func)(int *, int, bool(int, int)), string title);

int SIZE = 100000;
bool LOGGING = false;

int main(int argc, char **argv)
{
    // Parse command line arguments

    for (int i = 0; i < argc; i++)
    {
        if (string(argv[i]) == "-s")
            SIZE = stoi(argv[i + 1]);

        if (string(argv[i]) == "-l")
            LOGGING = true;
    }

    // Seed the random number generator

    srand(time(NULL));

    // Test the algorithms

    cout << "\x1b[94mTesting algorithms with array size: \x1b[92m" << SIZE << "\x1b[0m" << endl
         << endl;

    test_algorithm(quicksort<int>, "Quick Sort");

    test_algorithm(quicksort_thread<int>, "Quick Sort Thread");

    test_algorithm(mergesort<int>, "Merge Sort");

    test_algorithm(heapsort<int>, "Heap Sort");

    test_algorithm(insertionsort<int>, "Insertion Sort");

    test_algorithm(selectionsort<int>, "Selection Sort");

    test_algorithm(bubblesort<int>, "Bubble Sort");

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
}

void test_algorithm(void(func)(int *, int, bool(int, int)), string title)
{
    cout << "\x1b[94mTesting algorithm: \x1b[93m" << title << "\x1b[0m" << endl;

    int *arr = random_array(SIZE);

    if (LOGGING)
    {
        cout << "\x1b[94mBefore sorting: \x1b[97m";
        print_array(arr, SIZE);
        cout << "\x1b[0m" << endl;
    }

    auto start = chrono::system_clock::now();

    func(arr, SIZE, [](int a, int b)
         { return a < b; });

    auto end = chrono::system_clock::now();

    if (LOGGING)
    {
        cout << "\x1b[94mAfter sorting: \x1b[97m";
        print_array(arr, SIZE);
        cout << "\x1b[0m" << endl;
    }

    chrono::system_clock::duration time_elapsed = end - start;

    cout << "\x1b[94mTime elapsed: \x1b[97m" << chrono::duration_cast<chrono::nanoseconds>(time_elapsed).count() << " ns (" << chrono::duration_cast<chrono::milliseconds>(time_elapsed).count() << " ms)\x1b[0m" << endl;

    cout << "\x1b[94mStatus: " << (check_sorted(arr, SIZE) ? "\x1b[92mPASSED\x1b[0m" : "\x1b[91mFAILED\x1b[0m") << endl
         << endl;

    delete[] arr;
}

bool check_sorted(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;

    return true;
}