#include <iostream>
#include "DenseGraph.h"
#include <ctime>
#include "SparseGraph.h"
#include "lazyPrim.h"
#include "Kruskal.h"

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
    SparseGraph<int> sGraph(N,false);
    for (int i = 0; i < M; i++) {
        int n = rand() % N;
        int m = rand() % N;
        int weight = rand() % 10 + 1 ;
        sGraph.addEdge(n, m,weight);
    }
    sGraph.display();
    cout << endl << endl;

    return 0;
}