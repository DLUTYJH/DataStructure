#include <iostream>
#include "DenseGraph.h"
#include <ctime>
#include "SparseGraph.h"
#include "lazyPrim.h"
#include "Kruskal.h"
#include <limits>
#include "Dijkstra.h"

using namespace std ;

int main() {
    int N = 4;
    int M = 6;
    DenseGraph<int>dGraph(N, false);

    srand(time(NULL));
    for (int i = 0; i < M; i++) {
        int n = rand() % N;
        int m = rand() % N;
        int weight = rand() % 10 + 1 ;
        dGraph.addEdge(n, m,weight);
    }

    dGraph.display();
    cout << endl << endl;
    LazyPrim<DenseGraph<int>,int> dprim(dGraph);
    cout<<"prim  weight = "<<dprim.getWeight()<<endl;

    Kruskal<DenseGraph<int>,int> kprim(dGraph);
    cout<<"kruskal weight = "<<kprim.getWeight()<<endl;

    /////////////////////////////////////
    cout << endl << endl;
    ////////////////////////////////////
    SparseGraph<int> sGraph(5, true);
    sGraph.addEdge(0,1,5);
    sGraph.addEdge(0,2,2);
    sGraph.addEdge(0,3,6);
    sGraph.addEdge(1,4,1);
    sGraph.addEdge(2,1,1);
    sGraph.addEdge(2,3,3);
    sGraph.addEdge(2,4,5);
    sGraph.addEdge(3,4,2);

    sGraph.display();
    cout << endl << endl;
    Dijkstra<SparseGraph<int>,int> dij(sGraph,0);
    cout<<"shortest path = "<<dij.shortestPathTo(3)<<endl ;

    return 0;
}