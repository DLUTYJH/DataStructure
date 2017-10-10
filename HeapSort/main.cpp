#include <iostream>
#include "SortTestHelper.h"

/**
 * 最大堆和最小堆：
 * STL库中，实现了make_heap,push_heap,pop_heap,sort_heap ，是以vector为底层容器实现的。
 *
 * 最大堆的定义：堆是一个完全二叉树，每颗子树根节点大于子节点
 * 堆的数组存储：使用数组
 * 以最大堆为例，堆的操作：插入操作，删除操作，构建最大堆（筛选法）
 *
 *
 * 优先队列: priority_queue<int,vector<int>,less<int> >（默认的情况），底层实现机制是max_heap
 *
 *
 * 堆排序： 最坏(O(nlogn )),最好(O(nlogn )),平均(O(nlogn ))，不稳定排序算法。。
 *
 *
 */

using namespace std ;

template <typename T>
class MaxHeap{
private:
    T * data ;
    int count ; //count = 1 k开始
    int capacity ;

private:

    //最大堆的插入实现： 向上回溯
    void shifUp(int k ){
        while (k > 1 && data[k/2] < data[k]){
            swap(data[k/2],data[k]);
            k/=2 ;
        }
    }

    //最大堆的删除操作，向下回溯
    void shifDown(int k ){

        int i = k ;
        int j = 2*k ;

        while(j < count ){

            if(j +1 <= count && data[j+1] > data[j]) j ++;

            if(data[i] < data[j]){
                swap(data[i],data[j]);
                i = j ;
                j = 2*i ;
            }else break ;
        }
    }
public:
    MaxHeap(int capacity){
        data = new T[capacity +1 ];
        this->capacity = capacity ;
        count = 0 ;
    }

    ~MaxHeap(){
        if(data != NULL) delete [] data ;
    }

    int size(){
        return count ;
    }

    bool isEmpty(){
        return count == 0 ;
    }

    //插入操作
    void push_heap(T value ){

        if(count +1 > capacity ) return ;
        data[count+1] = value ;
        count ++ ;
        shifUp(count) ;
    }

    //删除操作
    void pop_heap(){
        swap(data[1] ,data[count]);
        int len = count ;
        count -- ;
        shifDown(1);
        count = len ;
    }

    //最大堆的排序: 原地堆排序，减少空间复杂度
    void sort_heap(){

        int len = count ;
        for (int i = 1; i <len  ; ++i) {
//            swap(data[1] ,data[count]);
//            count -- ;
//            shifDown(1);
            pop_heap();
            count-= 1 ;
        }
        count = len ;
    }

    //构建最大堆：筛选法(O(n))
    void buildHeap(){
        for(int i = count/2 ; i >=1 ; i-- )
            shifDown(i);
    }

    void print() const {

        for (int i = 1; i <= count; ++i) {
            cout<<data[i]<<"\t" ;
        }
        cout<<endl ;
    }
};


int main() {

    int n = 10000000 ;
    MaxHeap<int> maxHeap(n );

    //maxHeap.print();

    //maxHeap.pop_heap();
    //maxHeap.sort_heap();

    //maxHeap.print();

    int *arr = SortTestHelper::generateRandomArray(n,0,n);

    for (int i = 0; i < n; ++i) {
        maxHeap.push_heap(arr[i]);
    }

    clock_t  startTime = clock();
    maxHeap.sort_heap();
    clock_t  endTime = clock();

    cout<<"堆排序算法 "<< " : "<< double(endTime - startTime )/CLOCKS_PER_SEC << "s" <<endl ;




    return 0;
}