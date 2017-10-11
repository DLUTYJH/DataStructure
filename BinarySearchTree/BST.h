//
// Created by answer on 17-10-11.
//

#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H

/**
 * 二叉查找树的实现:
 *
 *
 *
 */

#include <iostream>
#include <queue>

using namespace std ;


template <typename K,typename  V >
class BST {

private:
    //二叉查找树的节点类型
    struct Node {
        K key ;
        V value ;
        Node * left ;
        Node * right ;

        Node (K key , V value){
            this->key = key ;
            this->value = value ;
            left = NULL ;
            right = NULL ;
        }
    };

private:
    Node * root ;//根节点
    int count ; //节点数量

public:
    BST(){
        root = NULL ;
        count = 0 ;
    }

    ~BST(){
        //TODO : ~BST ()
    }

    int size(){
        return count ;
    }

    bool isEmpty(){
        return count == 0 ;
    }

    //插入节点:没有递归的实现版本
    void insertNodeWithoutRecusion(K key ,V value ){
        Node * p = root , *pre = NULL ;

        while (p != NULL ){
            pre = p ;
            if (p->key == key ){
                p->value = value ;
                return;
            }else if (p->key < key){
                p = p->right ;
            }else p = p->left ;
        }

        if (root == NULL ) {
            root = new Node(key ,value);
            count++ ;
        }
        else if (pre -> key < key ){
            pre->right = new Node(key,value );
            count++ ;
        }
        else {
            pre->left = new Node(key ,value);
            count++ ;
        }
    }

    //插入节点，用 递归实现
    void  insertNodeByRecusion(K key ,V value){
        root = __insertNodeByRecusion(root ,key ,value);

    }


    //二叉树广度遍历,利用队列的先进先出的性质
    void levelOrder() const {
        Node * p = root ;
        queue<Node *> q ;

        if(p != NULL )q.push(p ) ;
        while (! q.empty() ){
            p = q.front() ;
            cout<<"[  "<<p->key<<" : "<<p->value <<"  ]"<<endl ;
            q.pop();

            if (p->left != NULL) q.push(p->left);
            if (p->right != NULL )q.push(p->right);
        }
    }

    //二叉树中是否包含key 的节点:迭代实现
    bool containWithoutRecusion(K key ){
        Node * p = root ;
        while (p != NULL ){

            if (p ->key == key ) return true ;
            else if (p->key < key ) {
                p = p->right ;
            }else {
                p= p->left;
            }
        }
        return false ;
    }

    //二叉树中是否包含key 的节点:递归实现
    bool containByRecusion(K key ){
        return  __contain(root ,key );
    }

    //二叉树的查找：迭代实现
    //search 方法的实现难点在于返回值的定义，
    V* searchWithoutRecusion(K key ){
        Node * p = root ;
        while (p != NULL ){

            if (p ->key == key ) return &(p->value) ;
            else if (p->key < key ) {
                p = p->right ;
            }else {
                p= p->left;
            }
        }
        return  NULL;
    }

    //二叉树的查找： 递归的实现
    V* searchByRecsion(K key){
        return  __search(root ,key );
    }

private:
    Node * __insertNodeByRecusion(Node * node , K key , V value ){

        if (node == NULL ){
            return new Node(key ,value );
            count ++ ;
        }

        if( key == node->key){node ->value = value;}
        else if(key > node->key ) {
            node->right =   __insertNodeByRecusion(node->right,key ,value);
        }else {
            node->left = __insertNodeByRecusion(node->left,key ,value);
        }
        return  node ;
    }

    bool __contain(Node * node ,K key ){

        if (node == NULL ) return false ;

        if (node->key == key ) return true;
        else if(node -> key < key )return __contain(node->right , key );
        else return __contain(node->left , key );
    }

    V* __search(Node* node ,K key){
        if (node == NULL ) return NULL ;

        if (node->key == key ) return &(node->value);
        else if(node -> key < key )return __search(node->right , key );
        else return __search(node->left , key );
    }
};




#endif //BINARYSEARCHTREE_BST_H
