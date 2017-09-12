#include <iostream>
#include "SortTestHelper.h"

using namespace std ;

template <typename  T>
void bubbleSort(T arr[] ,int len){

//    for (int i = 0; i < len ; ++i) {
//
//        for(int j = 0 ; j < len -i -1 ; j++){
//
//            if (arr[j] > arr[j+1])
//                swap(arr[j],arr[j+1]);
//        }
//    }

    //冒泡排序优化，如果某一趟排序过程中，没有交换任何两个元素的位置，可以判定该序列是有序的
    //采用标志位flag ，来判断某一趟排序中是否发生元素位置的交换
    bool  flag = false ;
    for(int i = 0 ; i < len ; i++){

        flag = false;
        for (int j = 0; j < len -i -1  ; ++j) {

            if (arr[j] > arr[j+1]){
                flag = true ;
                swap(arr[j],arr[j+1]);
            }

        }
        if (!flag) return;
    }
}



int main() {

    int n = 10000 ;
    int * arr = SortTestHelper::generateRandomArray(n ,0 ,n);
    //bubbleSort(arr,n);
    //SortTestHelper::printArry(arr,n);
    SortTestHelper::testSort("冒泡排序",bubbleSort,arr,n);

    return 0;
}