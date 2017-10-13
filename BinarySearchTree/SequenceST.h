//
// Created by answer on 17-10-12.
//

#ifndef BINARYSEARCHTREE_SEQUENCEST_H
#define BINARYSEARCHTREE_SEQUENCEST_H

#include<iostream>

using namespace std ;


/**
 * 顺序表： 实质就是一个链表
 * 完成操作：
 * 插入，删除，查找
 */

template <typename K,typename  V>
class SequenceST {
private:
    struct Node {
        K key ;
        V value ;
        Node * next ;

        Node(K key ,V value){
            this->key = key ;
            this->value = value ;
            this->next = NULL ;
        }
    };

private:
    Node* head ;
    int count ;

public:

    SequenceST( ){
        head = NULL ;
        count = 0 ;
    }
    ~SequenceST(){
        //TODO
        while(head != NULL){
            head = head->next;
            delete head;
            count -- ;
        }
    }

    int size(){
        return this->count;
    }

    bool isEmpty(){
        return count == 0 ;
    }

    /**
     * 插入节点操作，插入节点时候，遍历顺序表，如果存在想等值，则更新value值，否则在顺序表的前面插入新节点
     * @param key  节点key值
     * @param value  节点value 值
     */
    void insertNode(K key ,V value){
        Node * node = head ;

        //遍历顺序表
        while(node != NULL){
            if(key == node->key){
                node->value = value ;
                return ;
            }
            node = node->next;
        }

        //没有重复值,插入新节点

        Node * newNode = new Node(key ,value );
        newNode->next = head ;
        head = newNode ;
        count++;
    }

    /**
     * 打印顺序节点
     */
    void print()const {
        Node* node = head ;

        while(node != NULL){
            cout<<"[  "<<node->key<<" : "<<node->value <<"  ]"<<endl ;
            node = node->next;
        }
    }

    /**
     * contain 操作，顺序表中是否存在key的节点，如果存在返回rue ,否则false
     * @param key
     * @return
     */
    bool contain(K key ){
        Node* node = head ;
        while(node != NULL){

            if(key == node->key){
                return true ;
            }
            node = node->next;
        }
        return false ;
    }

    /**
     * 查找操作，顺序表中存在key的节点，返回value值的地址，否则返回为NULL
     * @param key
     * @return
     */
    V* search(K key ){
        Node* node = head ;
        while(node != NULL){

            if(key == node->key){
                return &(node->value) ;
            }
            node = node->next;
        }
        return NULL ;
    }

    /**
     * 删除操作，如果 存在key的节点，则删除该节点，否则不做任何操作
     * @param key
     */
    void remove(K key){
        Node * node = head ;
        Node * pre = NULL ;

        //查找是否存在该节点
        while(node != NULL){
            pre = node ;
            if(key == node->key){
                break ;
            }
            node = node->next;
        }

        //特殊处理头结点
        if(key == head->key){
            node = head;
            head = head->next ;
            delete node ;
            count -- ;
        }

        //存在节点，但是是尾节点
        if(pre != NULL && node ==NULL){
            pre->next = NULL;
            delete node ;
            count-- ;
        }

        //存在节点，并且不是头结点和尾节点
        if(pre != NULL && node != NULL){
            pre->next = node->next;
            delete node ;
            count-- ;
        }
    }
};


#endif //BINARYSEARCHTREE_SEQUENCEST_H
