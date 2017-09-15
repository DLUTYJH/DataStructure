
#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"
using namespace std ;

/**
 * 自底向上的优化归并排序
 * @tparam T
 * @param arr
 * @param len
 */
template <typename  T>
void mergeSortBU(T arr [] , int len){

    for (int sz = 1; sz <= len; sz+=sz) { //外层循环，对序列进行分割

        for(int i = 0 ; i+sz < len  ; i+=(sz+sz)){  //内层循环，对每个分组分别进行归并

            //对[i,i+sz-1 ] 和 [i+sz,i+sz+sz-1]范围进行归并
            MERGE::merge(arr, i , i+sz-1 , min(i+sz+sz-1,len-1));
        }

    }

}


int main() {
    int n = 1000000 ;
    int * arr = SortTestHelper::generateRandomArray(n,0,n);
    //mergeSort(arr,n);
    //SortTestHelper::printArry(arr,n);

    //SortTestHelper::testSort("归并排序",mergeSort,arr,n);

    //mergeSortBU(arr,n);
    //SortTestHelper::printArry(arr,n);
    SortTestHelper::testSort("自底向上的优化归并排序",mergeSortBU,arr,n);

    delete[] arr;
    return 0;
}