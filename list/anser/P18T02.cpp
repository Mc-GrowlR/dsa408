/*================================================================
*   Copyright (C) 2022 IEucd Inc. All rights reserved.
*   
*   文件名称：P18T02.cpp
*   创 建 者：GrowlR 
*   创建日期：2022年08月25日
*   描    述：将列表元素倒置，并要求算法原地工作
*
================================================================*/

#include "../List.h"
#include <iostream>
using namespace std;
using namespace List::StaticSqList;
template <typename T>
bool travers(SqList<T>& L)
{
    int lo = 0, hi = L.length - 1;
    int mi = (lo + hi) / 2;
    T oldElem;
    for (; hi > mi; lo++, hi--) {
        oldElem = L.data[lo];
        L.data[lo] = L.data[hi];
        L.data[hi] = oldElem;
    }
    return true;
}
int main()
{
    const int n = 6;
    int a[n] = { 1, 2, 3, 4, 5, 6 };
    SqList<int> Sl;
    InitList(Sl, a, n);
    Display(Sl);
    cout << endl;
    //
    //测试
    //
    travers(Sl);
    Display(Sl);
    cout << endl;
    //销毁链表
    DestroyList(Sl);
    return 0;
}
