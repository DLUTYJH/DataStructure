//
// Created by aurora on 18-3-1.
//

#ifndef MINISPANTREE_DENSEGRAPH_H
#define MINISPANTREE_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

//稠密图->领接矩阵
template <typename W>
class DenseGraph {

private:
    int n; //顶点数
    int m; //边数
    bool directed; //表示是否是有向图
    vector<vector< Edge<W> *> > graph; //二维数组来存储数据

public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; i++) {
            graph.push_back(vector<Edge<W> *>(n, NULL));
        }
    }

    ~DenseGraph() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(graph[i][j] != NULL)
                    delete graph[i][j] ;
            }
        }

    }

    int V() { return n; }

    int E() { return m; }

    //没有考虑自环边的情况
    void addEdge(int v, int w,int weight) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        if (hasEdge(v, w)) return; //刨除平行边

        graph[v][w] = new Edge<W>(v,w,weight);
        if (!directed) {
            graph[w][v] = new Edge<W>(w,v,weight);// 无向图
        }
        m++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return graph[v][w] != NULL;
    }

    void display() const {
        int i = 0;
        for (typename  vector<vector<Edge<W> *>>::const_iterator it = graph.begin(); it != graph.end(); ++it) {
            cout << i << ":\t";
            for (typename vector<Edge<W> *>::const_iterator itr = (*it).begin(); itr != (*it).end(); ++itr) {
                if((*itr) != NULL)cout <<(*itr)->getWeight()<< "\t";
                else cout<<"*"<<"\t";
            }
            i++;
            cout << endl;
        }
        cout << endl;
    }

    //通过迭代器模式，找到一个顶点的所有领接点
    class Iterator {
    private :
        DenseGraph &G;
        int v;
        int index;
    public:
        Iterator(DenseGraph &G, int v) : G(G) {
            this->v = v;
            index = 0;
        }

        Edge<W> * begin() {
            index = -1;
            return next();
        }

        Edge<W> * next() {
            for (index += 1; index < G.n; index++) {
                if (G.graph[v][index] != NULL ) {
                    return G.graph[v][index];
                }
            }
            return NULL;
        }

        //是否存在另一个相互连接的顶点
        bool hasNext(){
            for (int  i = index + 1; i < G.n; i++) {
                if (G.graph[v][i] != NULL) {
                    return true;
                }
            }
            return false ;
        }

        bool end() {
            return index < G.n;
        }
    };

};

#endif //MINISPANTREE_DENSEGRAPH_H
