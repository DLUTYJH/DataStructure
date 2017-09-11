#include <iostream>
#include "SortTestHelper.h"
using namespace std ;

template <typename T>
void insertSort(T arr[] , int len){

    for(int i = 1 ; i < len ; i++){

        //为每个arr[i]找到最终合适的位置
//        for(int j = i ; j > 0 ; j --){
//            if(arr[j] < arr[j-1])
//                swap(arr[j],arr[j-1]);
//            else break ;
//        }


        //为每个arr[i]找到最终合适的位置

        //优化，减少复制操作进行优化
        T e = arr[i];
        int j = i ;
        for( j = i ; j > 0 && arr[j-1] > e ; j--){
            arr[j] = arr[j-1] ;
        }
        arr[j] = e ;
    }
}

int main() {

    int n = 10000000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    //insertSort(arr, n);

    //SortTestHelper::printArry(arr,n);

    SortTestHelper::testSort("直接插入排序",insertSort,arr ,n);

    delete[] arr ;
    return 0;

}