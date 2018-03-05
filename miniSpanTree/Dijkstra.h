//
// Created by aurora on 18-3-2.
//

#ifndef MINISPANTREE_DIJKSTRA_H
#define MINISPANTREE_DIJKSTRA_H

#include <cassert>
#include <vector>
#include "Edge.h"
#include <algorithm>
#include <limits>
#include <stack>

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
    Dijkstra(Graph &G,int  s) : G(G),from(G.V()){
        weight = new W[G.V()];
        marked = new bool[G.V()];
        this->s = s ;
        for (int i = 0; i < G.V(); ++i) {
            weight[i] = numeric_limits<W> ::max(); //初始化，表示其实起始顶点与其余顶点的距离都是无穷大
            marked[i] = false ;
        }

        vector<Edge<W>> ss;
        //Dijstra 算法
        weight[s] = W() ;//起始顶点到起始顶点的距离为 0
        from[s] = new Edge<W>(s,s,W());
        ss.push_back(Edge<W>(s,s,W()));
        while(!ss.empty()){
            sort(ss.begin(),ss.end());
            int v = ss[0].getW();
            ss.erase(ss.begin());
            marked[v] = true ;
            typename Graph::Iterator adj(G, v);
            for( Edge<W>* e = adj.begin() ; adj.end() ; e = adj.next() ){
                int w = e->other(v);
                if(!marked[w]){
                    if(from[w] == NULL | weight[v] + e->getWeight() < weight[w]){
                        weight[w] = weight[v] + e->getWeight() ;
                        from[w] = e ;
                        ss.push_back(*e);
                    }
                }
            }

        }
    }

    ~Dijkstra(){
        delete [] weight;
        delete [] marked;
    }

    // 返回从s点到w点的最短路径长度
    W shortestPathTo( int w ){
        assert( w >= 0 && w < G.V() );
        assert( hasPathTo(w) == true );
        return weight[w];
    }

    // 判断从s点到w点是否联通
    bool hasPathTo( int w ){
        assert( w >= 0 && w < G.V() );
        return marked[w];
    }

    // 寻找从s到w的最短路径, 将整个路径经过的边存放在vec中
    void shortestPath( int w, vector<Edge<W>> &vec ){

        assert( w >= 0 && w < G.V() );
        assert( hasPathTo(w) );

        // 通过from数组逆向查找到从s到w的路径, 存放到栈中
        stack<Edge<W>*> s;
        Edge<W> *e = from[w];

        while( e->getS() != this->s ){
            s.push(e);
            e = from[e->getS()];
        }
        s.push(e);

        // 从栈中依次取出元素, 获得顺序的从s到w的路径
        while( !s.empty() ){
            e = s.top();
            vec.push_back( *e );
            s.pop();
        }
    }

    // 打印出从s点到w点的路径
    void showPath(int w){

        assert( w >= 0 && w < G.V() );
        assert( hasPathTo(w) );

        vector<Edge<W>> vec;
        shortestPath(w, vec);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i].getS()<<" -> ";
            if( i == vec.size()-1 )
                cout<<vec[i].getW()<<endl;
        }
    }
};

#endif //MINISPANTREE_DIJKSTRA_H
