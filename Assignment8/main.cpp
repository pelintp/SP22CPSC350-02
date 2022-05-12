#include <iostream>
#include <fstream>
#include <time.h>

#include "QuickSort.h"
#include "MergeSort.h"
#include "SelectionSort.h"

using namespace std;

void mergeSortTest(string fileName);

void quickSortTest(string fileName);

void selectionSortTest(string fileName);

double *readInput(string fileName, int *total);

int main(int argc, char **args) {

    // argument validation
    if (argc != 2) {
        cout << "Please enter input file name only." << endl;
        return 0;
    }

    // input file existence checking.
    char *fileName = args[1];
    ifstream fin(fileName);
    if (fin.fail()) {
        cout << "input file not found" << endl;
        return 0;
    }
    fin.close();

    // run the tests.
    quickSortTest(fileName);
    mergeSortTest(fileName);
    selectionSortTest(fileName);

    return 0;
}

void quickSortTest(string fileName) {
    time_t start, end;
    start = time(NULL);

    cout << "Quick Sort Test" << endl;

    int total;
    double *numbers = readInput(fileName, &total);
    int i;

    printf("UNSORTED: ");
    for (i = 0; i < total; ++i) {
        cout << numbers[i] << " ";
    }

    cout << endl;

    quickSort(numbers, 0, total - 1);

    printf("SORTED: ");
    for (i = 0; i < total; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    end = time(NULL);
    printf("Time taken %.2f seconds", difftime(end, start));
    cout << endl;
    cout << endl;
}

void mergeSortTest(string fileName) {
    time_t start, end;
    start = time(NULL);

    cout << "Merge Sort Test" << endl;

    int total;
    double *numbers = readInput(fileName, &total);
    int i;

    printf("UNSORTED: ");
    for (i = 0; i < total; ++i) {
        cout << numbers[i] << " ";
    }

    cout << endl;

    mergeSort(numbers, 0, total - 1);

    printf("SORTED: ");
    for (i = 0; i < total; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    end = time(NULL);
    printf("Time taken: %.2f seconds", difftime(end, start));
    cout << endl;
    cout << endl;
}

void selectionSortTest(string fileName) {
    time_t start, end;
    start = time(NULL);

    cout << "Selection Sort Test" << endl;

    int total;
    double *numbers = readInput(fileName, &total);
    int i;

    printf("UNSORTED: ");
    for (i = 0; i < total; ++i) {
        cout << numbers[i] << " ";
    }

    cout << endl;

    selectionSort(numbers, total);

    printf("SORTED: ");
    for (i = 0; i < total; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    end = time(NULL);
    printf("Time taken: %.2f seconds", difftime(end, start));
    cout << endl;
    cout << endl;
}

double* readInput(string fileName, int *total) {
    ifstream fin(fileName);
    int t;
    fin >> t;
    *total = t;

    // declare dynamic arrays
    double *numbers = new double[*total];
    int i = 0;
    while (t--) {
        // store to dy
        fin >> numbers[i++];
    }

    // close input file before returning.
    fin.close();
    return numbers;
}
