#include <iostream>
#include <ctime>
#include "binarysearch.h"
#include "BST.h"
#include <stack>
#include "SequenceST.h"
#include <string>
#include "FileReader.h"
#include <algorithm>

using namespace std ;


int main() {

    int n = 10 ;
    int *arr = new int [n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i ;
    }

//    clock_t start = clock();
//
//    int index =  BinarySearch::binarySearch(arr, n , 2) ;
//
//    clock_t  end = clock();
//    cout << "Binary Search (Without Recursion): " << double(end - start) / CLOCKS_PER_SEC << " s"<<"  index = " << index <<endl;
//
//    index = -1 ;
//    clock_t start1 = clock();
//
//    index = BinarySearch::binarySearchByRecusion(arr, n , 2) ;
//
//    clock_t  end1 = clock();
//    cout << "Binary Search (By Recursion): " << double(end1 - start1) / CLOCKS_PER_SEC << " s"<<"  index = " << index <<endl;

//    BST<int ,int > bst ;
//    bst.insertNodeByRecusion(2,2);
//    bst.insertNodeByRecusion(1,2);
//    bst.insertNodeByRecusion(0,-3);
//    bst.insertNodeByRecusion(9,2);
//    bst.insertNodeByRecusion(10,444);
//    bst.insertNodeByRecusion(8,2);
//
//    bst.levelOrder();
//    cout<<"**************"<<endl ;
    //bst.preOrderByrecusion();
    //bst.preOrderWithoutRecusion();
   // cout<<"**************"<<endl ;
    //bst.inOrerByRecusion();
   // bst.inOrderWithoutRecusion();
    //cout<<"**************"<<endl ;
    ///bst.postOrderRecusion();
    //bst.postOrderWithoutRecusion();

   // cout<< " 是否找到 key  : "<<bst.containWithoutRecusion(0)<<endl ;
    //cout<< " 是否找到 key  : "<<bst.containByRecusion(0)<<endl ;

    //cout<< " value =  : "<<*bst.searchWithoutRecusion(0)<<endl ;
    //cout<< " value =  : "<<*bst.searchByRecsion(0)<<endl ;

    //cout<<"min = "<<*bst.min()<<endl ;
    //out<<"max = "<<*bst.max()<<endl ;

    //bst.removeMin();
    //bst.removeMinByRecusion();
   // bst.levelOrder();

    //cout<<"**************"<<endl ;
    //bst.removeMax();
    //bst.removeMaxByRecusion();
   // bst.levelOrder();

    //bst.remove(2);
    //bst.removeByMerge(9);
    //bst.levelOrder();
   // cout<<"dfaaa"<<endl ;
    //   SequenceST<string ,int> sst ;

//    sst.insertNode("hello ",1);
//    sst.insertNode("hello ",11);
//    sst.insertNode("hello11",2);
//    sst.insertNode("hello11",22);
//    sst.insertNode("hello22",3);
//    sst.insertNode("hello22",33);
//    sst.insertNode("hello33",4);
//    sst.insertNode("hello33",44);
//    sst.insertNode("hello44",5);
//    sst.insertNode("hello44",55);
//    sst.insertNode("hello55",6);
//    sst.insertNode("hello55",66);
//    sst.insertNode("hello66",7);
//    sst.insertNode("hello66",77);
//    sst.insertNode("hello77",8);
//    sst.insertNode("hello77",88);
//    sst.insertNode("hello88",9);
//    sst.insertNode("hello88",99);
//
//    sst.print();
//
//    cout<<"**************"<<endl ;
//    cout<< "是否存在 key = hello11 的值 ： "<<sst.contain("hello11")<<endl ;
//
//    cout<<"**************"<<endl ;
//    cout<< "是否存在 key = hello11 ,value =  ： "<<*sst.search("hello11")<<endl ;
//
//    cout<<"**************"<<endl ;
//    sst.remove("hello11");
//    sst.print();


    /**
     * 读取一个文件，将文件简单的分词后，将单词放入vecor中，分别用二分搜索树，顺序表，和将单词进行排序后构造二分搜索书，分别统计词频
     */
    string fileName = "../bible.txt";
    vector<string > words ;
    if(FileReader::readFile(fileName,words)){

        //构建二叉查找树
        clock_t start = clock();
        BST<string ,int >bst ;
        for (vector<string>::iterator it = words.begin(); it != words.end(); ++it){
            int *tmp = bst.searchByRecsion(*it);
            if (tmp == NULL) bst.insertNodeByRecusion(*it,1);
            else (*tmp)++;
        }

        //统计词频
        if( bst.containByRecusion("god") )
            cout << "'god' : " << *(bst.searchByRecsion("god"))<< endl;
        else
            cout << "No word 'god' in " + fileName << endl;
        clock_t end = clock();
        cout << "BST , time: " << double(end - start) / CLOCKS_PER_SEC << " s." << endl;


        //构建顺序表
        start = clock();
        SequenceST<string ,int> sst ;
        for (vector<string>::iterator it = words.begin(); it != words.end(); ++it){
            int *tmp = sst.search(*it);
            if (tmp == NULL) sst.insertNode(*it,1);
            else (*tmp)++;
        }

        //统计词频
        if( sst.contain("god") )
            cout << "'unite' : " << *(sst.search("god"))<< endl;
        else
            cout << "No word 'god' in " + fileName << endl;
         end = clock();
        cout << "SST , time: " << double(end - start) / CLOCKS_PER_SEC << " s." << endl;


        //单词进行排序后构造二分搜索书，分别统计词频
        start = clock();
        BST<string ,int >sbst ;
        sort(words.begin(),words.end());
        for (vector<string>::iterator it = words.begin(); it != words.end(); ++it){
            int *tmp = sbst.searchByRecsion(*it);
            if (tmp == NULL) sbst.insertNodeByRecusion(*it,1);
            else (*tmp)++;
        }

        //统计词频
        if( sbst.containByRecusion("god") )
            cout << "'god' : " << *(sbst.searchByRecsion("god"))<< endl;
        else
            cout << "No word 'god' in " + fileName << endl;
         end = clock();
        cout << "SBST , time: " << double(end - start) / CLOCKS_PER_SEC << " s." << endl;

    }


    delete [] arr;
    return 0;
}