//
// Created by aurora on 18-3-2.
//

#ifndef MINISPANTREE_LAZYPRIM_H
#define MINISPANTREE_LAZYPRIM_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Edge.h"

using namespace std;


//prim算法比较适合稠密图中查找最小生成树
template <typename Graph ,typename W>
class LazyPrim{

private:
    Graph& G ;
    vector<Edge<W>> vec ; //最小堆的底层存储
    bool *marked ;//已经添加到最小生成树中的顶点
    vector<Edge<W>>mst ; //最小生成树中边顶点集合
    W weight ; //最小生产树的权值

private:
    void visited(int v){
        assert( !marked[v] );
        marked[v] = true ;
        typename Graph::Iterator it(G,v);
        for(Edge<W> * e = it.begin() ; it.end() ; e = it.next()){
            if(!marked[e->other(v)]){
                vec.push_back(*e);
            }
        }
        //make_heap(vec.begin(),vec.end(),greater<Edge<W>>());
        sort(vec.begin(),vec.end());
    }

public:
    LazyPrim(Graph & G ):G(G){

        //初始化算法啊
        marked = new bool[G.V()];
        weight  = 0 ;

        for(int i = 0 ; i < G.V() ; i ++)
            marked[i] = false ;
        vec.clear();
        mst.clear();

        //prim 算法
        visited(0); //顶点0作为起始点
        while(!vec.empty()){ //将所有的边查找一遍作为循环停止条件
            //从集合vec中找到权值最小的边
            Edge<W> e = vec[0];
            vec.erase(vec.begin());

            //判断这条边的另一个顶点是否已经在最小树的集合中
            if(marked[e.getS()]  && marked[e.getW()]){
                //make_heap(vec.begin(),vec.end(),greater<Edge<W>>());
                sort(vec.begin(),vec.end());
                continue;
            }

            //这条边没有在最小生成树集合中，则将这条边加入到集合中
            mst.push_back(e);

            //访问新加入的点，将起边加入到横切边的集合中
            if(marked[e.getS()])
                visited(e.getW());
            else visited(e.getS());
        }

        //计算权重
        for (typename vector<Edge<W>>::const_iterator it = mst.begin() ; it != mst.end() ;++it){
            weight += (*it).getWeight();
        }

    }
    ~LazyPrim(){
        delete[] marked ;
    }

    const vector<Edge<W>> &getMst() const {
        return mst;
    }

    W getWeight() const {
        return weight;
    }

};

#endif //MINISPANTREE_LAZYPRIM_H
