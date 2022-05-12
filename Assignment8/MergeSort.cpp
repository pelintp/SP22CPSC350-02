#include "MergeSort.h"

void merge(double numbers[], int left, int mid, int right) {

    int leftTotal = mid - left + 1;
    int rightTotal = right - mid;

    double leftPart[leftTotal], rightPart[rightTotal];

    int i, j, k;

    // copy first half to left part
    for (i = 0; i < leftTotal; i++) {
        leftPart[i] = numbers[left + i];
    }

    // copy second half to right part
    for (j = 0; j < rightTotal; j++) {
        rightPart[j] = numbers[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    // try to merge both part
    while (i < leftTotal && j < rightTotal) {
        if (leftPart[i] <= rightPart[j]) {
            // if left value is lower or equal, copy it
            numbers[k] = leftPart[i++];
        } else {
            // if right value is lower, copy it
            numbers[k] = rightPart[j++];
        }
        k++;
    }

    // copy all left remaining if any
    while (i < leftTotal) {
        numbers[k++] = leftPart[i++];
    }

    // copy all right remaining if any
    while (j < rightTotal) {
        numbers[k++] = rightPart[j++];
    }
}

void mergeSort(double numbers[], int left, int right) {
    if (left >= right) return;

    // find mid point index
    int mid = left + (right - left) / 2;

    mergeSort(numbers, left, mid);
    mergeSort(numbers, mid + 1, right);

    merge(numbers, left, mid, right);
}
