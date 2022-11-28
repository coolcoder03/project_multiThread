
#include "thread_algo.h"

void swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}

// merge function overloading to merge two sorted thread results
void merge(vector<int> &input, vector<int> &leftthread, vector<int> &rightthread)
{
    int indexLeft = 0,   // Initial index of left vector
        indexRight = 0,  // Initial index of rightvector
        indexMerged = 0; // Initial index of merge vector

    // Merge the sorted threads results back into  original input while sorting
    while (indexLeft < leftthread.size() && indexRight < rightthread.size())
    {
        if (leftthread[indexLeft] <= rightthread[indexRight])
        {
            input[indexMerged] = leftthread[indexLeft];
            indexLeft++;
        }
        else
        {
            input[indexMerged] = rightthread[indexRight];
            indexRight++;
        }
        indexMerged++;
    }
    // Copy the remaining elements of left thread result, if left
    while (indexLeft < leftthread.size())
    {
        input[indexMerged] = leftthread[indexLeft];
        indexLeft++;
        indexMerged++;
    }
    // Copy the remaining elements of right thread result, if left
    while (indexRight < rightthread.size())
    {
        input[indexMerged] = rightthread[indexRight];
        indexRight++;
        indexMerged++;
    }
}

// merge sort
// merge funtion for merge Sort
void merge(vector<int> &vector, int const left, int const mid,
           int const right)
{
    int leftvectorSize = mid + 1 - left;
    int rightvectorSize = right - mid;

    // temp vectors are created
    std::vector<int> leftvector, rightvector;

    // Copy data to temp vectors from main vector
    for (int i = 0; i < leftvectorSize; i++)
        leftvector.push_back(vector[left + i]);

    for (int j = 0; j < rightvectorSize; j++)
        rightvector.push_back(vector[mid + 1 + j]);

    int indexLeft = 0,      // Initial index of left vector
        indexRight = 0;     // Initial index of rightvector
    int indexMerged = left; // Initial index of merge vector

    // Merge the temp vector back into  original vector while sorting
    while (indexLeft < leftvectorSize && indexRight < rightvectorSize)
    {
        if (leftvector[indexLeft] <= rightvector[indexRight])
        {
            vector[indexMerged] = leftvector[indexLeft];
            indexLeft++;
        }
        else
        {
            vector[indexMerged] = rightvector[indexRight];
            indexRight++;
        }
        indexMerged++;
    }
    // Copy the remaining elements of left vector , if left
    while (indexLeft < leftvectorSize)
    {
        vector[indexMerged] = leftvector[indexLeft];
        indexLeft++;
        indexMerged++;
    }
    // Copy the remaining elements of right vector, if left
    while (indexRight < rightvectorSize)
    {
        vector[indexMerged] = rightvector[indexRight];
        indexRight++;
        indexMerged++;
    }
}
// Divide the vector into two subvectors, sort them and merge them
void mergeSort(vector<int> &vect, int l, int h)
{
    if (l >= h)
        return; // Returns recursively

    int mid = l + (h - l) / 2;
    mergeSort(vect, l, mid);
    mergeSort(vect, mid + 1, h);
    merge(vect, l, mid, h);
}

// selction Sort :for input less than equal to 100
void selectionSort(vector<int> &vect)
{
    int min_idx;
    int n = vect.size();

    // One by one move boundary of unsorted subvector
    for (int i = 0; i < (n - 1); i++)

    {
        // Find the minimum element in unsorted subvector
        min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (vect[j] < vect[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        if (min_idx != i)
            swap(vect[min_idx], vect[i]);
    }
}

// Quick sort
// function to rearrange vector (find the partition point)
int partition(vector<int> &vector, int low, int high)
{

    // select the rightmost element as pivot
    int pivot = vector[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the vector
    // compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (vector[j] <= pivot)
        {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(vector[i], vector[j]);
        }
    }

    // swap pivot with the greater element at i
    swap(vector[i + 1], vector[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(vector<int> &vector, int low, int high)
{
    if (low < high)
    {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(vector, low, high);

        // recursive call on the left of pivot
        quickSort(vector, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(vector, pi + 1, high);
    }
}