#include <iostream>
#include <ctime>
#include "binarysearch.h"

using namespace std ;





int main() {

    int n = 1000000 ;
    int *arr = new int [n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i ;
    }

    clock_t start = clock();

    int index =  BinarySearch::binarySearch(arr, n , 2) ;

    clock_t  end = clock();
    cout << "Binary Search (Without Recursion): " << double(end - start) / CLOCKS_PER_SEC << " s"<<"  index = " << index <<endl;

    index = -1 ;
    clock_t start1 = clock();

    index = BinarySearch::binarySearchByRecusion(arr, n , 2) ;

    clock_t  end1 = clock();
    cout << "Binary Search (By Recursion): " << double(end1 - start1) / CLOCKS_PER_SEC << " s"<<"  index = " << index <<endl;



    delete [] arr;
    return 0;
}