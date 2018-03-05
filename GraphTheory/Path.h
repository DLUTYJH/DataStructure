//
// Created by aurora on 18-2-28.
//

#ifndef GRAPHTHEORY_PATH_H
#define GRAPHTHEORY_PATH_H

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
 * 利用深度优先遍历，寻找路径
 *
 * 深度优先遍历的时间复杂度：
 * 邻接表：0（v + e ）
 * 邻接矩阵： 0（V^2）
 *
 * @tparam Graph
 */
template<typename Graph>
class Path {
private:
    Graph &G;
    int s; //起始定点
    bool *visited;
    int *from;//存储路径

private:
    void dfs(int v) {
        visited[v] = true;
        typename Graph::Iterator it(G, v);
        for (int w = it.begin(); it.end(); w = it.next()) {
            if (!visited[w]) {
                from[w] = v; //从结点 v-> w 存在一条路径
                dfs(w);
            }
        }
    }

    void dfs(int v , int* count,int flag ){
        visited[v] = true;
        typename Graph::Iterator it(G, v);
        for (int w = it.begin(); it.end(); w = it.next()) {
            if (!visited[w]) {
                dfs(w,count,flag);
            }else if(w == flag ){
                (*count) ++;
            }
        }
    }

public:
    Path(Graph &G, int s) : G(G) {

        //初始化
        assert(s >= 0 && s < G.V());
        visited = new bool[G.V()];
        from = new int[G.V()];

        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
        }
        this->s = s;

        //寻路算法
        dfs(s);
    }

    ~Path() {
        delete[] visited;
        delete[] from;
    }

    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return visited[w];
    }

    void pathBySelf(int w, vector<int> &vec) {
        if(hasPath(w)){
            int i = w ;
            vec.push_back(i);
            while (true){
                if( from [i] != s ){
                    i = from[i] ;
                    vec.push_back(i);
                }else if(from[i] == s ){
                    vec.push_back(s);
                    break ;
                }
            }
        }
    }
    void path(int w , vector<int> &vec){
        stack<int > sta;
        if(hasPath(w)){
            sta.push(w);
            int i = w ;
            while (from[i] != s ){
                i = from[i] ;
                sta.push(i);
            }
            sta.push(s);
            while (!sta.empty()){
                vec.push_back(sta.top());
                sta.pop();
            }
        }
    }

    void displayPath(int w) {
        vector<int> vec ;
        pathBySelf(w,vec);
        //path(w,vec);
        cout<<s<<"->"<<w<<":\t";
        for(vector<int>::reverse_iterator it = vec.rbegin() ; it != vec.rend() ; ++it){
            cout<<(*it)<<"\t";
        }
        cout<<endl;
    }

    bool hasRing(int  v ){
        return countRingNum(v) > 0 ;
    }
    int countRingNum(int v){
        assert( v >= 0 && v <G.V());
        int count = 0 ;

        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
        }
        dfs(v ,&count,v);
        return count ;
    }
};

#endif //GRAPHTHEORY_PATH_H
