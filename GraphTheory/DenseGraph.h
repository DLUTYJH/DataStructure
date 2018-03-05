//
// Created by aurora on 18-2-27.
//

#ifndef GRAPHTHEORY_DENSEGRAPH_H
#define GRAPHTHEORY_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//稠密图->领接矩阵
class DenseGraph {

private:
    int n; //顶点数
    int m; //边数
    bool directed; //表示是否是有向图
    vector<vector<bool>> graph; //二维数组来存储数据

public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; i++) {
            graph.push_back(vector<bool>(n, false));
        }
    }

    ~DenseGraph() {

    }

    int V() { return n; }

    int E() { return m; }

    //没有考虑自环边的情况
    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        if (hasEdge(v, w)) return;

        graph[v][w] = true;
        if (!directed) {
            graph[w][v] = true;// 无向图
        }
        m++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return graph[v][w];
    }

    void display() const {
        int i = 0;
        for (vector<vector<bool>>::const_iterator it = graph.begin(); it != graph.end(); ++it) {
            cout << i << ":\t";
            for (vector<bool>::const_iterator itr = (*it).begin(); itr != (*it).end(); ++itr) {
                cout << (*itr) << "\t";
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

        int begin() {
            index = -1;
            return next();
        }

        int next() {
            for (index += 1; index < G.n; index++) {
                if (G.graph[v][index]) {
                    return index;
                }
            }
            return -1;
        }

        //是否存在另一个相互连接的顶点
        bool hasNext(){
            for (int  i = index + 1; i < G.n; i++) {
                if (G.graph[v][i]) {
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

#endif //GRAPHTHEORY_DENSEGRAPH_H
