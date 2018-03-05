//
// Created by aurora on 18-3-1.
//

#ifndef GRAPHTHEORY_SHORTESTPATH_H
#define GRAPHTHEORY_SHORTESTPATH_H
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

template<typename Graph>
class ShortestPath {
private:
    Graph &G;
    int s; //起始定点
    bool *visited;
    int *from;//存储路径
    int *dis ;//保存距离

private:
    void bfs(int v){
        queue<int> que ;
        que.push(v);
        visited[v] = true ;
        dis[v] =  0 ;

        while (!que.empty()){
            int w = que.front() ;
            que.pop();

            typename Graph::Iterator it(G,w);
            for (int i = it.begin(); it.end(); i = it.next()) {
                if(!visited[i]){
                    visited[i] = true ;
                    dis[i] = dis[w] + 1 ;
                    from[i] = w ;
                    que.push(i);
                }
            }
        }
    }

public:
    ShortestPath(Graph &G ,int s ):G(G){
        this->s = s ;
        visited = new bool[G.V()];
        from = new int[G.V()];
        dis = new int[G.V()];

        //初始化
        for(int i = 0 ;  i < G.V() ; i++){
            visited[i] = false ;
            from[i] = -1 ;
            dis[i] = -1 ;
        }

        //计算路径算法
        bfs(s);
    }

    int disLength(int w){
        assert(w >= 0 && w < G.V());
        return dis[w] ;
    }

    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return visited[w];
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
        path(w,vec);
        //path(w,vec);
        cout<<s<<"->"<<w<<":\t";
        for(vector<int>::const_iterator it = vec.begin() ; it != vec.end() ; ++it){
            cout<<(*it)<<"\t";
        }
        cout<<endl;
    }

};

#endif //GRAPHTHEORY_SHORTESTPATH_H
