//
// Created by answer on 17-9-15.
//

#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H

/**
 * 归并排序：
 * 时间复杂度; O(nlgn)
 * 空间复杂度：O(n)
 * 稳定性：稳定排序
 *
 */


#include <iostream>
#include "SortTestHelper.h"
using namespace std ;

namespace  MERGE{
    //对[l ,mid] ,[mid+1 ,r]范围的两部分进行归并
    template <typename T>
    void  merge(T arr[] ,int l ,int mid ,int r ){

        T aux[r-l+1];

        for (int i = l; i <= r; ++i) {
            aux[i-l] = arr[i];
        }
        int  i = l , j = mid+1 ;
        for (int k = l; k <= r ; ++k) {

            if(i > mid){
                arr[k] = aux[j-l] ;
                j++ ;
            }else if( j > r){
                arr[k] = aux[i-l] ;
                i++ ;
            }else if (aux[i-l] < aux[j-l]) {
                arr[k] = aux[i-l] ;
                i++ ;
            }else{
                arr[k] = aux[j-l] ;
                j++ ;
            }

        }
    }

//对区间[l,r]范围内的元素进行插入排序
    template <typename  T>
    void insertSort(T arr[] ,int l ,int r){

        for (int i = l+1 ; i <= r ; ++i) {

            T e = arr[i] ;
            int j  ;
            for(j = i  ; j > l && arr[j-1] > e ; j--)
                swap(arr[j],arr[j-1]);
            arr[j] = e ;

        }
    }

//使用递归进行归并排序，对[l,r]范围的元素进行分割
    template <typename T>
    void __mergeSort(T arr[] , int l,int r){

        //利用递归进行分割，如果能减少递归层次，可以优化排序算法
        //当数据量较少的时候，序列近乎有序的概率就增大，此时可以 利用插入排序替代
        //if (l >= r ) return ;
        if ( r- l >= 10 ){
            insertSort(arr, l ,r );
            return;
        }

        int mid =  l + (r - l)/2 ; // (l + r)/2 求mid时候，当l ,r 都非常大的时候可能导致溢出
        __mergeSort(arr,l,mid);
        __mergeSort(arr,mid+1,r);

        //归并排序的优化，如果 arr[mid] < = arr[mid+1 ]，就说明该序列是有序的，就不需要进行归并操作
        if(arr[mid] > arr[mid+1 ])
            merge(arr,l,mid,r);
    }

    template <typename T>
    void mergeSort(T arr[] , int len ){
        __mergeSort(arr,0 ,len-1);
    }
}

#endif //MERGESORT_MERGESORT_H
