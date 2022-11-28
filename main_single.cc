#include <iostream>
#include <time.h>
#include <pthread.h>
#include "thread_algo.h"
using std::cout;

void *singleThread_sort(void *arg)
{
    vector<int> vect = *((vector<int> *)arg);
    quickSort(*((vector<int> *)arg), 0, vect.size() - 1);
    return NULL;
}

int main()
{
    vector<int> inputvect;
    int sz = 50;
    clock_t t1, t2;
    for (int i = 0; i < sz; i++)
    {
        inputvect.push_back(rand() % 100);
    }
    cout << "unsorted array is: \n";
    for (int i = 0; i < sz; i++)
        cout << inputvect[i] << "  ";
    cout << "\n";
    t1 = clock();
    pthread_t singlethread; // single thread creation to compare performance

    pthread_create(&singlethread, NULL, singleThread_sort, &inputvect);
    if (singlethread < 0)
    {
        std::cerr << "thread creation failed";
        exit(1);
    }
    pthread_join(singlethread, NULL);

    t2 = clock();
    cout << "Sorted Array \n";
    for (int i = 0; i < sz; i++)
        cout << inputvect[i] << "   ";
    cout << "\n";
    cout << "Time Taken=" << (t2 - t1);
    return 0;
}
