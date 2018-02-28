//
// Created by aurora on 18-2-27.
//

#ifndef GRAPHTHEORY_SPARSEGRAPH_H
#define GRAPHTHEORY_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//稀疏图->领接表
class SparseGraph {
private:
    int n; //顶点数
    int m; //边数
    bool directed; //表示是否是有向图
    vector<vector<int>> graph; //二维数组来存储数据

public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; i++) {
            graph.push_back(vector<int>());
        }
    }

    ~SparseGraph() {

    }

    int V() { return n; }

    int E() { return m; }

    //没有考虑平行边的情况，增大了添加边操作的时间复杂度
    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        graph[v].push_back(w);
        if (v != w && !directed)
            graph[w].push_back(v);
        m++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        for (int i = 0; i < graph[v].size(); i++) {
            if (graph[v][i] == w)
                return true;
        }
        return false;
    }

    void display() const {
        int i = 0;
        for (vector<vector<int>>::const_iterator it = graph.begin(); it != graph.end(); ++it) {
            cout << i << ":\t";
            for (vector<int>::const_iterator itr = (*it).begin(); itr != (*it).end(); ++itr) {
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
        SparseGraph &G;
        int v;
        int index;
    public:
        Iterator(SparseGraph &G, int v) : G(G) {
            this->v = v;
            index = 0;
        }

        int begin() {
            index = 0;
            if (!G.graph[v].empty())
                return G.graph[v][index];
            return -1;
        }

        int next() {
            if (end()) {
                index++;
                return G.graph[v][index];
            }
            return -1;
        }

        bool hasNext(){
            return ( index + 1 ) < G.graph[v].size();
        }

        bool end() {
            return index < G.graph[v].size();
        }
    };
};

#endif //GRAPHTHEORY_SPARSEGRAPH_H
