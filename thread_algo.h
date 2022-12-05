#ifndef __thread_algo__h
#define __thread_algo__h
#include <vector>
using std::vector;

void merge(vector<int> &arr, vector<int> &left, vector<int> &right);
void swap(int &x, int &y);
void merge(vector<int> &arr, int low, int mid, int high);
void mergeSort(vector<int> &vect, int l, int h);
void quickSort(vector<int> &vect, int l, int h);
int partition(vector<int> &array, int low, int high);
void selectionSort(vector<int> &arr);
#endif
