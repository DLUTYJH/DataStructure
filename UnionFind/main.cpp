#include <iostream>
#include "UnionFind.h"
#include "UnionFindTestHelper.h"


using namespace std ;
int main() {

    int n = 100000;
    UnionFindTestHelper::testUnionFind(n);

    UnionFindTestHelper::testQuickUnionBySize(n);
    UnionFindTestHelper::testQuickUnionByRank(n);

    return 0;
}