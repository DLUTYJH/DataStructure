//
// Created by answer on 17-10-18.
//

#ifndef UNIONFIND_QUICKUNION_H
#define UNIONFIND_QUICKUNION_H
/**
 * QuickFind:
 * 存储结构是一个数组，数组索引代表元素本身，数组值代表父节点元素
 * find 操作：查找的是一个元素的父节点(当一个元素p, p == parent[p]，就代表该元素是父节点)
 * isConnected操作:比较元素父节点是否相等
 * union操作：找到两个元素的父节点，并将其中一个元素的父节点指向另一个元素
 */

#include <cassert>

//基于size对并查集进行的优化，sz[i]代表的就是以i为根节点的元素的个数
namespace  SIZE{
    class QuickFind {
    private:
        int *parent;
        int * sz ; //sz[i]代表的就是以i为根节点的元素的个数
        int count;
    public:
        QuickFind(int n) {
            this->count = n;
            parent = new int[n];
            sz = new int [n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                sz[i] = 1 ;
            }
        }

        ~QuickFind() {
            delete[] parent;
            delete[] sz;
        }

        /**
         * QuickFind的查找操作:找到根结点
         * @param p
         * @return
         */
        int find (int p ){
            assert( p >= 0 && p < count);
            while(p != parent[p])
                p = parent[p];
            return  p ;
        }

        /**
         * QuickFind的isConnected操作:通过判断两个元素是否有共同的根来判断两个元素是否连接在一起
         * @param p
         * @param q
         * @return
         */
        bool isConnected(int p ,int q){
            return find(p) == find(q);
        }

        /**
         * QuickFind的union操作:将给定的两个元素连接在一起
         * @param p
         * @param q
         */
        void unionElements(int p , int q){
            int pParent = find(p);
            int qParent = find(q);

            if(pParent == qParent ) return ;


            //将p元素的根连接到q元素的根
            //parent[pParent] = qParent;

            //优化，通过sz记录以i为根节点的个数，在union的时候，为了减小树的层数，总是将个数少的连接到个数多的
            if(sz[pParent] < sz[qParent]){
                parent[pParent] = qParent ;
                sz[qParent] +=sz[pParent];
            }else{
                parent[qParent] = pParent;
                sz[pParent]+=sz[qParent];
            }
        }
    };
}

//基于rank的优化，rank[i]代表的是以i为根节点的树的高度
namespace  RANK{
    class QuickFind {
    private:
        int *parent;
        int * rank ; //rank[i]代表的是以i为根节点的树的层数
        int count;
    public:
        QuickFind(int n) {
            this->count = n;
            parent = new int[n];
            rank = new int [n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 1 ;
            }
        }

        ~QuickFind() {
            delete[] parent;
            delete[] rank;
        }

        /**
         * QuickFind的查找操作:找到根结点
         * @param p
         * @return
         */
        int find (int p ){
            assert( p >= 0 && p < count);
            while(p != parent[p])
                p = parent[p];
            return  p ;
        }

        /**
         * QuickFind的isConnected操作:通过判断两个元素是否有共同的根来判断两个元素是否连接在一起
         * @param p
         * @param q
         * @return
         */
        bool isConnected(int p ,int q){
            return find(p) == find(q);
        }

        /**
         * QuickFind的union操作:将给定的两个元素连接在一起
         * @param p
         * @param q
         */
        void unionElements(int p , int q){
            int pParent = find(p);
            int qParent = find(q);

            if(pParent == qParent ) return ;


            //将p元素的根连接到q元素的根
            //parent[pParent] = qParent;

            //优化:通过rank[i]记录以i为根节点的树的层数，
            //rank[pParent] > rank[qParent] 或者rank[pParent] < rank[qParent]时候，都是将矮的树指向高的树，所以不用更新rank
            //rank[pParent] == rank[qParent]的时候，两棵树高度相等，此时无论谁指向谁，但是指向后树的层数+1
            if(rank[pParent] < rank[qParent]){
                parent[pParent] = qParent ;
            }else if (rank[pParent] > rank[qParent]){
                parent[qParent] = pParent;
            }else {
                parent[pParent] = qParent ;
                rank[qParent]+= 1 ;
            }
        }
    };
}

//union 优化：路径压缩
namespace  PATH{
    class QuickFind {
    private:
        int *parent;
        int * rank ; //rank[i]代表的是以i为根节点的树的层数
        int count;
    public:
        QuickFind(int n) {
            this->count = n;
            parent = new int[n];
            rank = new int [n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 1 ;
            }
        }

        ~QuickFind() {
            delete[] parent;
            delete[] rank;
        }

        /**
         * QuickFind的查找操作:找到根结点
         * @param p
         * @return
         */
        int find (int p ){
            assert( p >= 0 && p < count);

            //基于路径压缩的优化：在执行find的操作的时候，在查找根节点的同时，减少树的层数
            //parent[p] = parent[parent[p]],让当前节点指向父节点的父节点
//            while(p != parent[p]){
//                parent[p] = parent[parent[p]];
//                p = parent[p];
//            }
//            return  p ;

            //最理想的查找，就是树只有两层,find 的时间复杂度接近于O(1)
            if (p != parent[p])
                parent[p] = find(parent[p]);
            return parent[p];

        }

        /**
         * QuickFind的isConnected操作:通过判断两个元素是否有共同的根来判断两个元素是否连接在一起
         * @param p
         * @param q
         * @return
         */
        bool isConnected(int p ,int q){
            return find(p) == find(q);
        }

        /**
         * QuickFind的union操作:将给定的两个元素连接在一起
         * @param p
         * @param q
         */
        void unionElements(int p , int q){
            int pParent = find(p);
            int qParent = find(q);

            if(pParent == qParent ) return ;


            //将p元素的根连接到q元素的根
            //parent[pParent] = qParent;

            //优化:通过rank[i]记录以i为根节点的树的层数，
            //rank[pParent] > rank[qParent] 或者rank[pParent] < rank[qParent]时候，都是将矮的树指向高的树，所以不用更新rank
            //rank[pParent] == rank[qParent]的时候，两棵树高度相等，此时无论谁指向谁，但是指向后树的层数+1
            if(rank[pParent] < rank[qParent]){
                parent[pParent] = qParent ;
            }else if (rank[pParent] > rank[qParent]){
                parent[qParent] = pParent;
            }else {
                parent[pParent] = qParent ;
                rank[qParent]+= 1 ;
            }
        }
    };
}
#endif //UNIONFIND_QUICKUNION_H
