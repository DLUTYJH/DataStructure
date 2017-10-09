#include <iostream>
#include "SortTestHelper.h"

/**
 * 快速排序：
 * 时间复杂度： 最好： O(nlogn),平均;O(nlogn),最坏:O(n^2),虽然快速排序的最坏的时间复杂度是O(n^2)，但是在实际排序过程中，都是优于归并排序
 * 空间复杂度： O(nlogn )
 * 稳定性: 不稳定
 *
 */

using namespace std ;

//返回一个索引，使得arr[l.....p-1]< arr[p] ,arr[p] < arr[p+1 ,r ]
template <typename  T >
int  __partition(T arr[] , int l , int r ){

    T v = arr[l] ;

    int p = l ; //arr[l.....p]<= arr[p] ,arr[p] < arr[p+1 ,r ]分界点

    for (int i = l + 1 ; i <= r  ; ++i) {
        if(arr[i] < v )
            swap(arr[++p],arr[i]);
    }
    swap(arr[p],arr[l]);
    return p ;
}

/**
 * partition的第二种实现思路
 * @tparam T
 * @param arr
 * @param l
 * @param r
 * @return
 */
template <typename  T >
int  __partition(T arr[] , int l , int r , bool flag ){
    T v = arr[l] ;

    while(l < r){

        while (r >l && arr[r] > v )r -- ;
        arr[l] = arr[r];

        while (l < r  && arr[l] <=  v )l++ ;
        arr[r] = arr[l] ;
    }
    arr[l] = v ;

    return l ;
}

//对[l,r]区间进行快速排序
template <typename  T>
void __quickSort(T arr[] ,int l ,int r){

    if(l >= r ) return ;

    int p = __partition(arr, l , r , true); //p的位置就是哨兵元素的最终位置
    __quickSort(arr, l ,p-1 );//对区间[l.p-1]进行递归
    __quickSort(arr, p+1 ,r);//对区间[p+1 , r]进行递归
}

template <typename T >
void quickSort(T arr[] , int len){
    __quickSort(arr, 0 ,len - 1 );
}




int main() {
    int n = 10 ;
    int * arr = SortTestHelper::generateRandomArray(n,0,n);
    //int arr[] = {5,8,3,1,6,7,4,9};

    quickSort(arr, n);

    SortTestHelper::printArry(arr, n );

    //SortTestHelper::testSort("自底向上的优化归并排序",quickSort,arr,n);

    delete[] arr;
    return 0;
}