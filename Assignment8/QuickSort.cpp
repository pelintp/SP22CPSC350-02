#include "QuickSort.h"

int partition(double numbers[], int lowIndex, int highIndex) {
    // Pick middle element as pivot
    int midpoint = lowIndex + (highIndex - lowIndex) / 2;
    double pivot = numbers[midpoint];

    bool done = false;
    while (!done) {
        while (numbers[lowIndex] < pivot) {
            lowIndex += 1;
        }

        // Decrement highIndex while pivot < numbers[highIndex]
        while (pivot < numbers[highIndex]) {
            highIndex -= 1;
        }

        // If zero or one elements remain, then all numbers are
        // partitioned. Return highIndex.
        if (lowIndex >= highIndex) {
            done = true;
        } else {
            // Swap numbers[lowIndex] and numbers[highIndex]
            double temp = numbers[lowIndex];
            numbers[lowIndex] = numbers[highIndex];
            numbers[highIndex] = temp;

            // Update lowIndex and highIndex
            lowIndex += 1;
            highIndex -= 1;
        }
    }

    return highIndex;
}

void quickSort(double numbers[], int lowIndex, int highIndex) {
    // Base case: If the partition size is 1 or zero
    // elements, then the partition is already sorted
    if (lowIndex >= highIndex) {
        return;
    }

    // partition the data within the array. Value lowEndIndex
    // returned from partitioning is the index of the low
    // partition's last element.
    int lowEndIndex = partition(numbers, lowIndex, highIndex);

    // Recursively sort low partition (lowIndex to lowEndIndex)
    // and high partition (lowEndIndex + 1 to highIndex)
    quickSort(numbers, lowIndex, lowEndIndex);
    quickSort(numbers, lowEndIndex + 1, highIndex);
}
