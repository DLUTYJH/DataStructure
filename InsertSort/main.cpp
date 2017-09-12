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


template <typename T>
void shellSort(T arr[] , int len){

    int d = len / 2 ;

    while (d >= 1 ){
        int k = 0 ;

        //遍历d个分组
        for( k = 0 ; k < d ; k ++){

            //分别对每个分组进行直接插入排序
            for (int i = k+d; i < len; i += d) {

                T e = arr[i] ;
                int j ;
                for (j = i; j > 0 && arr[j-d] > e; j-=d) {
                        arr[j] = arr[j-d];
                }
                arr[j] = e ;
            }
        }
        d /= 2 ;
    }
}



int main() {

    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    int *copyArr = SortTestHelper::copyRandomArray(arr,n);
    //insertSort(arr, n);

    //SortTestHelper::printArry(arr,n);

    SortTestHelper::testSort("直接插入排序",insertSort,arr ,n);

    //shellSort(arr, n);
    //SortTestHelper::printArry(arr, n );

    SortTestHelper::testSort("希尔排序",shellSort ,copyArr , n);

    delete[] arr ;
    delete[] copyArr ;
    return 0;

}