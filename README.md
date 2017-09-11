# 数据结构与算法

---

程序 = 数据结构 + 算法 。编程是一门艺术，而数据结构和算法，就是编程的灵魂，熟练掌握数据结构和算法是必须的。

---

一. 项目结构介绍
编码使用的IDE是CLion ，每个demo的主要包含的文件介绍：
```
 ./demo
    |
    +---CMakeLists.txt  //cmake 的配置文件，在CLion中自动生成
    |
    +---SortTestHelper.h //该头文件中包含测试数据的生成函数,性能测试函数，和打印函数。
    |
    +---main.cpp //具体的实现和main函数
```

---
二. Test Demo

 1. [直接选择排序算法](https://github.com/DLUTYJH/DataStructure/tree/master/SelectionSort)

算法思想：每次排序都是从[i,n)范围中找出最小的元素，和位置i的元素进行交换，每一趟排序都能保证某一元素放到最终的排序位置。

时间复杂度：  最好： O($n^2$)  ,   平均： O($n^2$)   ,   最坏：O($n^2$) 

空间复杂度：O(1)

稳定性：不稳定排序


 2. [直接插入排序算法](https://github.com/DLUTYJH/DataStructure/tree/master/InsertSort)

算法思想：每次将arr[i]和前面的元素比较， 将其插入到[0,i]合适的位置。

时间复杂度：  最好： O(n)元素序列已经是有序的 ,   平均： O($n^2$)   ,   最坏：O($n^2$) 

空间复杂度：O(1)

稳定性：稳定排序



