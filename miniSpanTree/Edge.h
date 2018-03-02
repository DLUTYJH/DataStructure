//
// Created by aurora on 18-3-1.
//

#ifndef MINISPANTREE_EDGE_H
#define MINISPANTREE_EDGE_H

#include <iostream>
#include <cassert>
using namespace std;

template<typename W>
class Edge {
private:
    int s;
    int w;  //规定，s代表起始顶点，w代表终止顶点
    W weight;
public:
    Edge(int s, int w, W weight) : s(s), w(w), weight(weight) {}

    Edge() {}

    virtual ~Edge() {

    }

    int getS() const {
        return s;
    }

    int getW() const {
        return w;
    }

    W getWeight() const {
        return weight;
    }

    /**
     * 获取相邻接顶点的另一个顶点
     * @param x
     * @return
     */
    int other(int x ){
        assert( x == s || x == w);
        return x == s ? w : s ;
    }

    bool operator < (Edge<W> & e){
        return weight < e.getWeight() ;
    }

    bool operator > (const Edge<W>& e){
        return weight > e.getWeight() ;
    }

};

#endif //MINISPANTREE_EDGE_H
