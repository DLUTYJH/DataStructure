//
// Created by aurora on 18-3-2.
//

#ifndef MINISPANTREE_KRUSKAL_H
#define MINISPANTREE_KRUSKAL_H

#include <cassert>
#include "UnionFind.h"
#include <vector>
#include "Edge.h"
#include <algorithm>

using namespace std;

template<typename Graph, typename W>
class Kruskal {
private:
    vector<Edge<W>> mst;
    W weight;
    Graph &G;
public:
    Kruskal(Graph &G) : G(G) {
        weight = 0;
        UnionFind un(G.V());
        //将图中的所有边排序放入到集合中
        vector<Edge<W>> edge;
        for (int i = 0; i < G.V(); i++) {
            typename Graph::Iterator it(G, i);
            for (Edge<W> *e = it.begin(); it.end(); e = it.next()) {
                    edge.push_back(*e);
            }
        }
        sort(edge.begin(),edge.end());

        //kruskal 算法
        for(int i = 0 ; i < edge.size() ; i++){
            if(!un.isConnected(edge[i].getS(),edge[i].getW())){
                mst.push_back(edge[i]);
                un.unionElements(edge[i].getS(),edge[i].getW());
            }
        }

        //计算权重
        for (typename vector<Edge<W>>::const_iterator it = mst.begin() ; it != mst.end() ;++it){
            weight += (*it).getWeight();
        }
    }

    ~Kruskal(){

    }

    const vector<Edge<W>> &getMst() const {
        return mst;
    }

    W getWeight() const {
        return weight;
    }

};

#endif //MINISPANTREE_KRUSKAL_H
