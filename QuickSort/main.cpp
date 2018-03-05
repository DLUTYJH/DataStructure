#include <iostream>
#include "SortTestHelper.h"
#include <ctime>
#include <cassert>

/**
 * 快速排序：
 * 时间复杂度： 最好： O(nlogn),平均;O(nlogn),最坏:O(n^2)（近乎有序的情况下）,虽然快速排序的最坏的时间复杂度是O(n^2)，但是在实际排序过程中，都是优于归并排序
 * 空间复杂度： O(nlogn )
 * 稳定性: 不稳定
 *
 */

/**
 * 快速排序的优化方法：
 * 1.当元素较少的情况下，使用插入排序减少地柜层次
 * 2.哨兵元素的选择，一般情况下选择首元素(当元素序列有序的情况下，选择首元素，快速排序退化为O(n^2))，可以随机选择哨兵元素来优化快速排序
 * 3.partition 过程中，容易导致递归树不平衡的情况而使得快速排序退化为O(n^2)算法，使用二路快速排序进行优化
 * 4.partition 过程中，针对存在相同元素的序列，可以使用三路快速排序进行优化
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

    swap(arr[l], arr[rand()%(r-l+1) +l ]);//随机化的方法优化快速排序，随机的从序列中选择哨兵元素
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

//二路快速排序算法的partition过程
template <typename  T >
int  __partition_2(T arr[] , int l , int r ){

    swap(arr[l], arr[rand()%(r-l+1) +l ]);//随机化的方法优化快速排序，随机的从序列中选择哨兵元素

    T v = arr[l] ;

    while (true){

        while( l <= r && arr[l] < v ) l ++ ;
        while(r >= l+1 && arr[r] >v ) r-- ;

        if(l > r ) break ;
        swap(arr[l], arr[r]);
        l++ ;
        r-- ;
    }
    swap(arr[l] , v );
    return l ;
}

//三路快速排序算法的
template <typename T>
void __quickSort3Ways(T arr[] , int l , int r ){

    if (l >= r )
        return;

    //partition 的过程
    swap(arr[l], arr[rand()%(r-l+1) +l ]);//随机化的方法优化快速排序，随机的从序列中选择哨兵元素
    T v = arr[l] ;
    int lt = l  ; // <v 序列的索引

    //int lt = l  或者 int lt = l+1 的区别在于，前者lt就是最后哨兵元素的位置，而后者需要-1才是哨兵元素最后的位置
    int gt = r +1 ; //>v 序列的索引
    int i = l+1 ; //未处理的序列的索引

    while(i < gt ){
        if(arr[i] < v ){
            swap(arr[i],arr[lt+1]);
            lt++ ;
            i++ ;
        }else if(arr[i] > v ){
            swap(arr[i], arr[gt-1]);
            gt-- ;
        }else{
            i++ ;
        }
    }
    swap(arr[lt-1],arr[l]);

    __quickSort3Ways(arr, l ,lt-1 );
    __quickSort3Ways(arr, gt,r );
}




//对[l,r]区间进行快速排序
template <typename  T>
void __quickSort(T arr[] ,int l ,int r){

    if(l >= r ) return ;  // 当元素较少的时候可以使用插入排序来进行优化

    int p = __partition(arr, l , r , true); //p的位置就是哨兵元素的最终位置
    __quickSort(arr, l ,p-1 );//对区间[l.p-1]进行递归
    __quickSort(arr, p+1 ,r);//对区间[p+1 , r]进行递归



}

template <typename T >
void quickSort(T arr[] , int len){

    srand(time(NULL)) ;
    __quickSort(arr, 0 ,len - 1 );
    //__quickSort3Ways(arr, 0,len-1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//利用快速排序的思想解决实际问题
//查找序列中第n大的元素
///////////////////////////////////////////////////////////////////////////////////////////////////

//通过排序来查找第n大的元素
int findValueBySort(int arr[] , int len ,int n ){

    //assert(n > len );
    if (n > len ) return  -1 ;
    clock_t  startTime = clock();
    quickSort(arr,len);
    clock_t  endTime = clock();
    cout<<"快速排序查找第n大的值 "<< " : "<< double(endTime - startTime )/CLOCKS_PER_SEC << "s" <<endl ;
    return arr[len-n] ;
}


int  __findValue(int arr[] , int l ,int r ,int n ) {

    //快速排序的分割办法
    int p = __partition_2(arr,l,r);

    //比较n 和partition的 返回值
    //n==p ,查找结束
    //n > p , 在右侧查找
    // n < p ，在左侧查找
    if (n == p ) return arr[p];
    else if (n > p ) __findValue(arr, p+1, r ,n );
    else __findValue(arr, l, p-1 ,n );


}

//利用快速排序的思想
int  findValue(int arr[] , int len ,int n ){
    //assert(n > len) ;
    if (n > len ) return  -1 ;
    clock_t  startTime = clock();

    int value =  __findValue(arr,0,len-1,len-n);

    clock_t  endTime = clock();
    cout<<"利用分治思想查找第n大的值 "<< " : "<< double(endTime - startTime )/CLOCKS_PER_SEC << "s" <<endl ;
    return value ;
}



int main() {
    int n = 10;
    int * arr = SortTestHelper::generateRandomArray(n,0,n);
    //int arr[] = {5,8,3,1,6,7,4,9};

    //quickSort(arr, n);

    SortTestHelper::printArry(arr, n );

    //SortTestHelper::testSort("自底向上的优化归并排序",quickSort,arr,n);

    int value = findValue(arr, n,4);

    cout<<"value = " <<value <<endl ;

    int value1 = findValueBySort(arr, n , 4);
    SortTestHelper::printArry(arr, n );

    cout<<"value1 = " <<value1 <<endl ;



    delete[] arr;
    return 0;
}