//
// Created by answer on 17-10-11.
//

#ifndef BINARYSEARCHTREE_BINARYSEARCH_H
#define BINARYSEARCHTREE_BINARYSEARCH_H

/**
 * 二分查找:
 * 时间复杂度： O(logn )
 *
 *
 * 顺序查找：
 *
 * 时间复杂度： O(n)
 */

namespace  BinarySearch {

    //二分查找:迭代实现
    template<typename T>
    int binarySearch(T arr[] , int len , T target ){
        int l = 0 ;
        int r = len -1 ;
        while (l <= r ){
            int mid = l + (r- l )/2   ;
            if(target ==  arr[mid]  ) return  mid ;
            else if(target <  arr[mid]) r = mid -1 ;
            else l = mid +1 ;
        }
        return -1 ;
    }


///////////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    int __binarySerach(T arr[] , int l , int r ,T target){

        if(l > r ) return  -1 ;
        int mid = l + (r - l ) /2 ;

        if(target == arr[mid]) return  mid ;
        else if ( target <  arr[mid]) __binarySerach(arr, l , mid - 1 , target );
        else __binarySerach(arr, mid + 1  , r , target) ;

    }

//二分查找：递归实现
    template <typename T >
    int binarySearchByRecusion(T arr[] , int len , T target ){

        return  __binarySerach(arr, 0 , len - 1, target);
    }

}// BinarySearch


#endif //BINARYSEARCHTREE_BINARYSEARCH_H
