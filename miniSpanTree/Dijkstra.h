//
// Created by aurora on 18-3-2.
//

#ifndef MINISPANTREE_DIJKSTRA_H
#define MINISPANTREE_DIJKSTRA_H

#include <cassert>
#include <vector>
#include "Edge.h"
#include <algorithm>

using namespace std ;

template <typename Graph,typename W>
class Dijkstra{
private:
    W *weight ; //保存起始顶点到其余个点的路径
    Graph& G ;
    int  s ; //起始顶点
    bool *marked ;
    vector<Edge<W> *> from ;

public:
    Dijkstra(Graph &G,int  s) : G(G) {
        weight = new W[G.V()];
        this->s = s ;
        for (int i = 0; i < G.V(); ++i) {
            weight[i] = -1 ; //初始化，表示与其余任何一个顶点的距离都是-1
            marked[i] = false ;
        }

        vector<Edge<W>> ss;
        //Dijstra 算法

    }

    ~Dijkstra(){
        delete [] weight;
    }





};

#endif //MINISPANTREE_DIJKSTRA_H
