#include <iostream>
#include <ctime>
#include "binarysearch.h"
#include "BST.h"
#include <stack>

using namespace std ;





int main() {

    int n = 10 ;
    int *arr = new int [n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i ;
    }

//    clock_t start = clock();
//
//    int index =  BinarySearch::binarySearch(arr, n , 2) ;
//
//    clock_t  end = clock();
//    cout << "Binary Search (Without Recursion): " << double(end - start) / CLOCKS_PER_SEC << " s"<<"  index = " << index <<endl;
//
//    index = -1 ;
//    clock_t start1 = clock();
//
//    index = BinarySearch::binarySearchByRecusion(arr, n , 2) ;
//
//    clock_t  end1 = clock();
//    cout << "Binary Search (By Recursion): " << double(end1 - start1) / CLOCKS_PER_SEC << " s"<<"  index = " << index <<endl;

    BST<int ,int > bst ;
    bst.insertNodeByRecusion(2,2);
    bst.insertNodeByRecusion(1,2);
    bst.insertNodeByRecusion(0,-3);
    bst.insertNodeByRecusion(9,2);
    bst.insertNodeByRecusion(10,444);
    bst.insertNodeByRecusion(8,2);

    //bst.levelOrder();
    cout<<"**************"<<endl ;
    //bst.preOrderByrecusion();
    //bst.preOrderWithoutRecusion();
    cout<<"**************"<<endl ;
    //bst.inOrerByRecusion();
   // bst.inOrderWithoutRecusion();
    cout<<"**************"<<endl ;
    //bst.postOrderRecusion();
    bst.postOrderWithoutRecusion();

    cout<< " 是否找到 key  : "<<bst.containWithoutRecusion(0)<<endl ;
    cout<< " 是否找到 key  : "<<bst.containByRecusion(0)<<endl ;

    cout<< " value =  : "<<*bst.searchWithoutRecusion(0)<<endl ;
    cout<< " value =  : "<<*bst.searchByRecsion(0)<<endl ;

    cout<<"min = "<<*bst.min()<<endl ;
    cout<<"max = "<<*bst.max()<<endl ;



    delete [] arr;
    return 0;
}