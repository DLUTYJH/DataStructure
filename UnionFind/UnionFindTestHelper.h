//
// Created by answer on 17-10-18.
//

#ifndef UNIONFIND_UNIONFINDTESTHELPER_H
#define UNIONFIND_UNIONFINDTESTHELPER_H

#include <iostream>
#include <ctime>
#include "UnionFind.h"
#include "QuickUnion.h"

namespace  UnionFindTestHelper {

    void testUnionFind(int n ){

        srand(time(NULL));

        UnionFind uf(n) ;

        time_t  start = clock();

        for (int i = 0; i < n; ++i) {
            int a = rand()%n ;
            int b = rand()%n ;
            uf.unionElements(a,b);
        }

        time_t  end = clock();
        std::cout<<"UnionFind time =  "<<double(end-start)/CLOCKS_PER_SEC<<" S "<<std::endl ;
    }

    void testQuickUnionBySize(int n ){
        srand(time(NULL));

        SIZE::QuickFind qf(n);

        time_t  start = clock();

        for (int i = 0; i < n; ++i) {
            int a = rand()%n ;
            int b = rand()%n ;
            qf.unionElements(a,b);
        }

        time_t  end = clock();
        std::cout<<"QuickFindBySize time =  "<<double(end-start)/CLOCKS_PER_SEC<<" S "<<std::endl ;
    }

    void testQuickUnionByRank(int n ){
        srand(time(NULL));

        RANK::QuickFind qf(n);

        time_t  start = clock();

        for (int i = 0; i < n; ++i) {
            int a = rand()%n ;
            int b = rand()%n ;
            qf.unionElements(a,b);
        }

        time_t  end = clock();
        std::cout<<"QuickFindByRank time =  "<<double(end-start)/CLOCKS_PER_SEC<<" S "<<std::endl ;
    }

    void testQuickUnionByPath(int n ){
        srand(time(NULL));

        PATH::QuickFind qf(n);

        time_t  start = clock();

        for (int i = 0; i < n; ++i) {
            int a = rand()%n ;
            int b = rand()%n ;
            qf.unionElements(a,b);
        }

        time_t  end = clock();
        std::cout<<"QuickFindByPath time =  "<<double(end-start)/CLOCKS_PER_SEC<<" S "<<std::endl ;
    }
}//UnionFindTestHelper


#endif //UNIONFIND_UNIONFINDTESTHELPER_H
