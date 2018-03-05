//
// Created by aurora on 18-2-27.
//

#ifndef GRAPHTHEORY_GRAPHSEARCH_H
#define GRAPHTHEORY_GRAPHSEARCH_H

#include <iostream>
#include <stack>
#include <queue>
#include <cassert>

using namespace std;

template<typename Graph>
class GraphSearch {

private:
    Graph &G;

private:
    void dfs(int v, bool *visited) {
        cout << v << "\t";
        visited[v] = true;
        typename Graph::Iterator it(G, v);
        for (int w = it.begin(); it.end(); w = it.next()) {
            if (!visited[w]) {
                dfs(w, visited);
            }
        }
    }

private:
    void bfs(int v,bool *visited){
        queue<int> que ;
        que.push(v);
        visited[v] = true ;

        while (!que.empty()){
            int w = que.front() ;
            cout<<w<<"\t";
            que.pop();

            typename Graph::Iterator it(G,w);
            for (int i = it.begin(); it.end(); i = it.next()) {
                if(!visited[i]){
                    visited[i] = true ;
                    que.push(i);
                }
            }
        }
    }

public:
    GraphSearch(Graph &G) : G(G) {

    }

    ~GraphSearch() {

    }

    /**
     * 深度优先遍历的递归实现
     */
    void DFSByRecursive() {
        bool *visited = new bool[G.V()];
        for (int i = 0; i < G.V(); i++)
            visited[i] = false;

        for (int i = 0; i < G.V(); i++) {
            if (!visited[i]) {
                dfs(i, visited);
            }
        }
        delete[] visited;
    }

    /**
     * 深度优先遍历的非递归实现
     */
    void DFS() {
        bool *visited = new bool[G.V()];
        for (int i = 0; i < G.V(); i++)
            visited[i] = false;

        stack<int> sta;
        for (int i = 0; i < G.V(); i++) {
            if (!visited[i]) {

                cout << i << "\t";
                visited[i] = true;
                sta.push(i);

                while (!sta.empty()) {
                    int k = sta.top();

                    typename Graph::Iterator it(G, k);

                    if(!it.hasNext()){ //针对单独一个结点，没有结点与之相连接的情况，
                        sta.pop();
                        break;
                    }

                    for (int w = it.begin(); it.end(); w = it.next()) {
                        if (!visited[w]) {
                            cout << w << "\t";
                            visited[w] = true;
                            sta.push(w);
                            break;
                        } else if (!it.hasNext()) { //当该结点的所有相连接的结点都已经标记过，并且没有想连接的结点时候，执行出栈
                            sta.pop();
                        }
                    }
                }
            }
        }
        delete[] visited;
    }

    /**
     * 统计连通分量:通过深度优先遍历来统计连通分量
     * @return
     */
    int countComponent() {
        int count = 0;
        bool *visited = new bool[G.V()];
        for (int i = 0; i < G.V(); i++)
            visited[i] = false;

        for (int i = 0; i < G.V(); i++) {
            if (!visited[i]) {
                dfs(i, visited);
                count++;
            }
        }
        delete[] visited;
        return count;
    }

    /**
     * 广度优先遍历实现
     */
    void BFS() {
        bool *visited = new bool[G.V()];
        for (int i = 0; i < G.V(); i++)
            visited[i] = false;

        for (int i = 0; i < G.V(); i++) {
            if (!visited[i]) {
                bfs(i,visited);
            }
        }
    }
};

#endif //GRAPHTHEORY_GRAPHSEARCH_H
