//
// Created by answer on 17-10-11.
//

#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H

/**
 * 二叉查找树的实现:
 * 插入操作：
 * 查找操作:(O(logn ))
 * 遍历操作： 广度优先，深度优先（前序，中序，后序）
 * 删除操作：
 * 查找最大值和最小值操作：
 * 删除最大值和最小值,时间复杂度(O(logn))
 * 删除任意节点操作,时间复杂度(O(logn))
 *
 *
 * 如果将有序的数据依次插入到二叉查找树中，此时二叉查找树的操作退化为链表，操作时间复杂度退化为O(n)
 *
 * */

#include <iostream>
#include <queue>
#include <stack>

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

        Node (Node * other){
            this->key = other->key;
            this->value = other->value;
            this->left = other->left;
            this->right = other ->right;
        }

        Node *operator = (Node * other){
            this->key = other->key;
            this->value = other->value;
            this->left = other->left;
            this->right = other ->right;
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
        destory(root); //通过后序遍历来释放空间
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

    ////////////////////////
    //前序遍历,根左右
    //中序遍历，左根右
    //后序遍历,左右根
    ////////////////////////
    //遍历的的递归实现方式
    ///////////////////////

    void preOrderByrecusion(){
         __preorder(root);
    }

    void inOrerByRecusion(){
        __inOrder(root);
    }

    void postOrderRecusion(){
        __postOrder(root);
    }
    ////////////////////////
    //遍历的的递归实现方式
    ///////////////////////
    void preOrderWithoutRecusion(){
        Node * p = root ;
        if(root == NULL ) return;
        stack<Node*> sta;

        while(!sta.empty() || p != NULL ){

            cout<<"[  "<<p->key<<" : "<<p->value <<"  ]"<<endl ;
            if(p->right != NULL ) sta.push(p->right);

            if (p->left != NULL){
                p = p ->left;
            }else{
                p = sta.top();
                sta.pop();
            }
        }
    }
    void inOrderWithoutRecusion(){

        Node * p = root ;
        if(root == NULL ) return ;
        stack<Node*> sta ;

        while(! sta.empty() || p != NULL ){

            if(p){
                sta.push(p );
                p = p->left;
            }else{
                p = sta.top();
                cout<<"[  "<<p->key<<" : "<<p->value <<"  ]"<<endl ;
                sta.pop();
                p = p->right;
            }
        }
    }

    void postOrderWithoutRecusion(){
        Node * p = root ;
        Node * pre = root ;
        if(root == NULL ) return ;
        stack<Node *>sta ;

        while(p ){

            while(p->left != NULL){
                sta.push(p);
                p= p->left;
            }

            //访问节点的条件是： 该节点的有孩子为空或者已经访问过
            while (p != NULL && (p->right == NULL  || p ->right == pre )){
                cout<<"[  "<<p->key<<" : "<<p->value <<"  ]"<<endl ;
                pre = p ;

                if(sta.empty())return;  //循环结束条件

                p =sta.top(); // 栈为空，再调用top 方法，好像会出问题
                sta.pop();
            }
            sta.push(p);
            p=p->right;
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


    ////////////////////////////////
    //查找最大值和最小值
    ///////////////////////////////

    V* min(){
        Node* p = root ;
        if(root == NULL ) return NULL;

        while (p->left != NULL){
            p=p->left;
        }
        return &(p->value);
    }

    V* max(){
        Node* p = root ;
        if(root == NULL ) return NULL;

        while (p->right != NULL){
            p=p->right;
        }
        return &(p->value);
    }

    ////////////////////////////////
    //删除最大值和最小值
    ///////////////////////////////

    //删除最大值和最小值的迭代实现
    void removeMin(){
        Node * p = root ;
        Node * pre = root ;
        if(root == NULL) return ;

        while(p->left != NULL) {
            pre = p ;
            p = p->left;
        }

//        if(p->right != NULL ) {
//            pre->left = p->right;
//            count-- ;
//            delete p ;
//        }else {
//            pre->left = NULL ;
//            count-- ;
//            delete p ;
//        }
        pre->left = p->right ;
        delete p ;
        count -- ;
    }

    void removeMax(){
        Node * p = root ;
        Node * pre = root ;
        if(root == NULL) return ;

        while(p->right != NULL) {
            pre = p ;
            p = p->right;
        }

//        if(p->left != NULL ) {
//            pre->right = p->left;
//            count-- ;
//            delete p ;
//        }else {
//            pre->right = NULL ;
//            count-- ;
//            delete p ;
//        }
        pre->right = p->left ;
        delete p ;
        count -- ;
    }

    //删除最大值和最小值的递归实现
    void removeMinByRecusion(){
       root =  __removeMin(root);
    }

    void removeMaxByRecusion(){
        root = __removeMax(root);
    }


    ////////////////////////////////
    //删除任意节点: 复制删除
    ///////////////////////////////
    void remove(K key ){

        Node * p = __search(key);
        Node * tmp = p ;
        if(p == NULL ) return ;

        if (p ->left == NULL) { //只有右孩子
            tmp = p->right ;
            //p = new Node(p->right);
            p->key = tmp->key;
            p->value = tmp->value;
            p->left = tmp->left;
            p->right = tmp->right;
        }else if(p->right ==NULL){ //只有左孩子
            tmp = p->left ;
            //p = new Node(p->left);
            p->key = tmp->key;
            p->value = tmp->value;
            p->left = tmp->left;
            p->right = tmp->right;
        } else{ //左右孩子都有

            //查找到右子树中最小值
            tmp = p ->right;
            Node* pre = p ;
            while (tmp->left != NULL){
                pre = tmp ;
                tmp=tmp->left;
            }

            //将查找到节点的data 赋值给删除节点
            p->key = tmp->key;
            p->value = tmp->value;

            //处理查找到节点的右孩子
            if(pre == p )  pre->right = tmp->right;
            else pre->left = tmp->right;

        }
        delete tmp ;
        count--;
    }

    ////////////////////////////////
    //删除任意节点: 合并删除
    ///////////////////////////////
    void removeByMerge(K key){
        root = __remove(root,key);
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

    Node* __search(K key ){

        Node * p = root ;
        while (p != NULL ){
            if (p ->key == key ) return p ;
            else if (p->key < key ) {
                p = p->right ;
            }else {
                p= p->left;
            }
        }
        return  NULL;
    }


    void __preorder (Node * node ){
        if(node != NULL ){
            cout<<"[  "<<node->key<<" : "<<node->value <<"  ]"<<endl ;
            __preorder(node->left);
            __preorder(node->right);
        }
    }

    void __inOrder(Node* node){
        if(node != NULL ){
            __inOrder(node->left);
            cout<<"[  "<<node->key<<" : "<<node->value <<"  ]"<<endl ;
            __inOrder(node->right);
        }
    }

    void __postOrder(Node * node){
        if(node != NULL ){
            __postOrder(node->left);
            __postOrder(node->right);
            cout<<"[  "<<node->key<<" : "<<node->value <<"  ]"<<endl ;
        }
    }

    void destory(Node * node){
        if(node != NULL){
            destory(node->left);
            destory(node->right);
            delete node ;
            count-- ;
        }
    }

   Node*  __removeMin(Node* node){

       if(node->left == NULL){
           Node* right = node->right;
           delete node ;
           count--;
           return right ;
       }
       node->left = __removeMin(node->left);
       return node ;
   }

    Node* __removeMax(Node * node){
        if(node->right == NULL){
            Node* left = node->left;
            delete node ;
            count--;
            return left ;
        }
        node->right = __removeMax(node->right);
        return node ;
    }

    Node* __remove(Node * node,K key ){
        if(node == NULL) return NULL ;

        if(key < node -> key){
            node->left = __remove(node->left,key);
            return  node ;
        }else if(key > node->key){
            node->right = __remove(node->right,key);
            return node ;
        }else { //找到了节点
            if(node->left == NULL){
                Node* right = node->right;
                delete node ;
                count -- ;
                return  right ;
            } else if(node->right == NULL){
                Node * left = node->left ;
                delete node ;
                count--;
                return left ;
            }else{ //有两个节点的情况
                Node* p = node->left;
                Node* tmp = node ;
                //右子树中找到最小值
                while (p->right != NULL){
                    tmp = p ;
                    p=p->right;
                }
                //合并操作
                p->right = node->right;
                //p->left = node->left;

                if(node == tmp ) tmp = p ;

                delete node ;
                count-- ;
                return tmp ;
            }
        }
    }

};

#endif //BINARYSEARCHTREE_BST_H
