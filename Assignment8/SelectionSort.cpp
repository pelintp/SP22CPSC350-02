#include "SelectionSort.h"

void selectionSort(double numbers[], int total) {
    int i, j, minNumberIndex;

    // insert at first and move pointer to replace right
    for (i = 0; i < total - 1; i++) {
        minNumberIndex = i;
        // find actual min item location from i
        for (j = i + 1; j < total; j++)
            if (numbers[j] < numbers[minNumberIndex])
                minNumberIndex = j;

        // place min number to i
        double temp = numbers[minNumberIndex];
        numbers[minNumberIndex] = numbers[i];
        numbers[i] = temp;
    }
}