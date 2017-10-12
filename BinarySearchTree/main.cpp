#include <iostream>
#include <ctime>
#include "binarysearch.h"
#include "BST.h"
#include <stack>
#include "SequenceST.h"
#include <cstring>

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

    bst.levelOrder();
    cout<<"**************"<<endl ;
    //bst.preOrderByrecusion();
    //bst.preOrderWithoutRecusion();
   // cout<<"**************"<<endl ;
    //bst.inOrerByRecusion();
   // bst.inOrderWithoutRecusion();
    //cout<<"**************"<<endl ;
    ///bst.postOrderRecusion();
    //bst.postOrderWithoutRecusion();

   // cout<< " 是否找到 key  : "<<bst.containWithoutRecusion(0)<<endl ;
    //cout<< " 是否找到 key  : "<<bst.containByRecusion(0)<<endl ;

    //cout<< " value =  : "<<*bst.searchWithoutRecusion(0)<<endl ;
    //cout<< " value =  : "<<*bst.searchByRecsion(0)<<endl ;

    //cout<<"min = "<<*bst.min()<<endl ;
    //out<<"max = "<<*bst.max()<<endl ;

    //bst.removeMin();
    //bst.removeMinByRecusion();
   // bst.levelOrder();

    //cout<<"**************"<<endl ;
    //bst.removeMax();
    //bst.removeMaxByRecusion();
   // bst.levelOrder();

    //bst.remove(2);
    //bst.removeByMerge(9);
    //bst.levelOrder();
   // cout<<"dfaaa"<<endl ;

    SequenceST<string ,int> sst ;

    sst.insertNode("hello ",1);
    sst.insertNode("hello ",11);
    sst.insertNode("hello11",2);
    sst.insertNode("hello11",22);
    sst.insertNode("hello22",3);
    sst.insertNode("hello22",33);
    sst.insertNode("hello33",4);
    sst.insertNode("hello33",44);
    sst.insertNode("hello44",5);
    sst.insertNode("hello44",55);
    sst.insertNode("hello55",6);
    sst.insertNode("hello55",66);
    sst.insertNode("hello66",7);
    sst.insertNode("hello66",77);
    sst.insertNode("hello77",8);
    sst.insertNode("hello77",88);
    sst.insertNode("hello88",9);
    sst.insertNode("hello88",99);
    sst.insertNode("hello99",10);
    sst.insertNode("hello99",1010);

    sst.print();

    cout<<"**************"<<endl ;
    cout<< "是否存在 key = hello11 的值 ： "<<sst.contain("hello11")<<endl ;

    cout<<"**************"<<endl ;
    cout<< "是否存在 key = hello11 ,value =  ： "<<*sst.search("hello11")<<endl ;

    cout<<"**************"<<endl ;
    sst.remove("hello11");
    sst.print();









    delete [] arr;
    return 0;
}