
#include <iostream>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "GraphSearch.h"
#include <ctime>

int main() {

    int N = 4;
    int M = 5;
    DenseGraph dGraph(N, false);
    srand(time(NULL));
    for (int i = 0; i < M; i++) {
        int n = rand() % N;
        int m = rand() % N;
        dGraph.addEdge(n, m);
    }
    dGraph.display();
    GraphSearch<DenseGraph> gs(dGraph);
    //gs.BFS();
    cout<<endl<<endl;
    //gs.DFS();
    cout<<endl<<endl;
    gs.DFSByRecursive();
    //cout<<endl<<"连通分量是:"<<gs.countComponent()<<endl ;

//
//    for (int i = 0; i < N; i++) {
//        cout << i << ":  ";
//        DenseGraph::Iterator it(dGraph, i);
//        for (int w = it.begin(); it.end(); w = it.next()) {
//            cout << w << "\t";
//        }
//        cout << endl;
//    }

    //////////////////////////////////////////////////////////////
    SparseGraph sGraph(N, false);
    for (int i = 0; i < M; i++) {
        int n = rand() % N;
        int m = rand() % N;
        sGraph.addEdge(n, m);
    }
//    for (int i = 0; i < N; i++) {
//        cout << i << ":  ";
//        SparseGraph::Iterator it(sGraph, i);
//        for (int w = it.begin(); it.end(); w = it.next()) {
//            cout << w << "\t";
//        }
//        cout << endl;
//    }
    cout<<endl<<endl;

    sGraph.display();
    GraphSearch<SparseGraph> gss(sGraph);
    //gss.BFS();
    cout<<endl<<endl;
    //ss.DFS();
    cout<<endl<<endl;
    gss.DFSByRecursive();
    //cout<<endl<<"连通分量是:"<<gss.countComponent()<<endl ;

    return 0;
}