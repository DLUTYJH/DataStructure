
#include <iostream>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "GraphSearch.h"
#include <ctime>
#include "Path.h"

int main() {

    int N = 4;
    int M = 5;
    DenseGraph dGraph(N, true);
    srand(time(NULL));
    for (int i = 0; i < M; i++) {
        int n = rand() % N;
        int m = rand() % N;
        dGraph.addEdge(n, m);
    }
    dGraph.display();
    cout<<endl<<endl;
    Path<DenseGraph> gs(dGraph,0);
    cout<<"环数： "<<gs.countRingNum(0)<<endl;
//    gs.displayPath(3);
//    GraphSearch<DenseGraph> gs(dGraph);
//    gs.BFS();
//    cout<<endl<<endl;
//    gs.DFS();
//    cout<<endl<<endl;
//    gs.DFSByRecursive();
//    cout<<endl<<"连通分量是:"<<gs.countComponent()<<endl ;

//
//    for (int i = 0; i < N; i++) {
//        cout << i << ":  ";
//        DenseGraph::Iterator it(dGraph, i);
//        for (int w = it.begin(); it.end(); w = it.next()) {
//            cout << w << "\t";
//        }
//        cout << endl;
//    }

    cout<<endl<<endl;
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
    sGraph.display();
    cout<<endl<<endl;
//    Path<SparseGraph> gss(sGraph,0);
//    gss.displayPath(3);
//    GraphSearch<SparseGraph> gss(sGraph);
//    gss.BFS();
//    cout<<endl<<endl;
//    gss.DFS();
//    cout<<endl<<endl;
//    gss.DFSByRecursive();
//    cout<<endl<<"连通分量是:"<<gss.countComponent()<<endl ;

    return 0;
}