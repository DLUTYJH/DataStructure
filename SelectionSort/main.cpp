#include <iostream>
#include "SortTestHelper.h"
/**
 * 选择排序
 */

using namespace std ;

template<typename T>
void selectionSort(T arr[] ,int len ){

    for(int i = 0 ; i < len ; i ++){

        //寻找[i ,len) 范围中的最小值
        int minIndex = i ;

        for(int j = i+1 ; j < len ; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j ;
        }

        // 交换i位置和minIndex位置的值
        swap(arr[i],arr[minIndex]);
    }
}



int main() {

    //int arr[] = {9,6,10,8,7,3,2,1,0,5};
    int n = 100000 ;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);

   // selectionSort(arr, 10);

    //SortTestHelper::printArry(arr,n);

    SortTestHelper::testSort("选择排序",selectionSort,arr ,n);

    delete[] arr ;
    return 0;
}