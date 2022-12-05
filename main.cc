#include <iostream>
#include <pthread.h>
#include <time.h>
#include "thread_algo.h"
using std::cout;

vector<int> inputvect;
int sz; // input size

typedef struct Data
{
    vector<int> left;
    vector<int> right;
} sort_thread;

// function for sorting threads
void *Sort(void *arg)
{

    vector<int> thread_vect = *((vector<int> *)arg);

    int threshold = 10;
    int size = thread_vect.size();
    if (size <= threshold)
        selectionSort(*((vector<int> *)arg));

    else
    {
        //mergeSort(*((vector<int> *)arg), 0, size - 1);
        quickSort(*((vector<int> *)arg), 0, size - 1);
    }
    return NULL;
}

// function for merging thread
void *merge_thread(void *arg)
{
    Data sort_vect = *((Data *)arg);
    vector<int> left = sort_vect.left;
    vector<int> right = sort_vect.right;
    inputvect.clear();
    merge(inputvect, left, right);
    return NULL;
}

int main()
{
    clock_t t1, t2; // clock variable to compute time
    cout<<"Enter Array Size \n";
    cin>>sz;
    // creating random vector
    for (int i = 0; i < sz; i++)
    {
        inputvect.push_back(rand() % 100);
    }
    cout << "unsorted array is: \n";
    for (int i = 0; i < sz; i++)
        cout << inputvect[i] << "  ";
    cout << "\n";

    // distribute the main VECTOR in two parts for each thread
    vector<int> leftthread, rightthread;
    int mid = (int)sz / 2;
    cout << "mid:" << mid << "\n";
    for (int i = 0; i < mid; i++)
        leftthread.push_back(inputvect[i]);
    for (int i = mid; i < sz; i++)
        rightthread.push_back(inputvect[i]);

    t1 = clock();                                       // start time calculation (only thread execution is considered)
    pthread_t sthread0, sthread1;                       // declaring sorting threads
    pthread_create(&sthread0, NULL, Sort, &leftthread); // creating sorting threads
    pthread_create(&sthread1, NULL, Sort, &rightthread);
    if (sthread0 < 0 || sthread0 < 0) // checking for thread creation success
    {
        std::cerr << "error in sort thread creation";
    }
    else
    {
        // providing a join so that above two threads i.e. sorting threads
        // so that we have sorted vectors before executing merge thread
        pthread_join(sthread1, NULL);
        pthread_t mergethread;
        // storing left and right sorted vector
        //  in struct for passing to merge thread
        Data Sort_thread = {leftthread, rightthread};
        pthread_create(&mergethread, NULL, merge_thread, &Sort_thread); // creating merge thread
        if (mergethread < 0)                                            // checking for thread creation success
        {
            std::cerr << "error in mergethread creation";
        }
        else
        {
            pthread_join(mergethread, NULL); // providing a join to wait for merge thread execution
        }
    }
    t2 = clock(); // end time calculation
    cout << "Sorted Array \n";
    for (int i = 0; i < sz; i++)
        cout << inputvect[i] << "   ";
    cout << "\n";

    cout << "Time Taken=" << (t2 - t1);

    return 0;
}
