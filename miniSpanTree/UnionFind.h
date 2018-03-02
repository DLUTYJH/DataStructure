//
// Created by aurora on 18-3-2.
//

#ifndef MINISPANTREE_UNIONFIND_H
#define MINISPANTREE_UNIONFIND_H
/**
 * UnionFind:
 * 存储结构，是一个数组，数组的索引代表元素，元素值代表元素之间的关系，值相同就代表元素相关联
 * find 操作：时间复杂度是O(1),比较数组元素值是否相等
 * isConnected操作:比较数组元素值是否相等
 * union操作：找到元素的值，遍历整个数组，更新元素值为另一个元素的值。需要遍历真个数组，所以时间复杂度是O(n)
 */

#include <cassert>
class UnionFind {
private:
    int *id;
    int count;
public:
    UnionFind(int n) {
        this->count = n;
        id = new int[n];
        for (int i = 0; i < n; i++)
            id[i] = i;
    }

    ~UnionFind() {
        delete[] id;
    }

    /**
     * 并查集的find操作,查找的是元素值
     * @param p
     * @return
     */
    int find(int p) {
        assert(p >= 0 && p < count);
        return id[p];
    }

    /**
     * 并查集的isConnected操作,判断两个元素是否连接
     * @param p
     * @param q
     * @return
     */
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    /**
     * 并查集的union操作
     * @param p
     * @param q
     */
    void unionElements(int p, int q) {
        int pid = find(p);
        int qid = find(q);

        if (pid == qid) return;

        for (int i = 0; i < count; i++) {
            if (id[i] == pid) id[i] = qid;
        }
    }
};
#endif //MINISPANTREE_UNIONFIND_H
