/*================================================================
*   Copyright (C) 2022 IEucd Inc. All rights reserved.
*   
*   文件名称：P18T05.cpp
*   创 建 者：GrowlR 
*   创建日期：2022年08月26日
*   描    述：删除顺序表中在s和t之间的值，并显示错误信息
*
================================================================*/
#include "../List.h"
#include <iostream>
using namespace std;
using namespace List::StaticSqList;
template <typename T>
void Ldelete(SqList<T>& L, T s, T t)
{
    int k = 0;
    if (Empty(L) || s >= t) {
        cout << "error ";
        return;
    }
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] <= s || L.data[i] >= t) {
            L.data[k++] = L.data[i];
        }
    }
    L.length = k;
}
int main()
{
    const int n = 6;
    int a[n] = { 1, 2, 3, 4, 5, 6 };
    SqList<int> L;
    InitList(L, a, n);
    Display(L);
    cout << endl;
    int s = 2, t = 5;
    Ldelete(L, s, t);
    Display(L);
    cout << endl;
    return 0;
}
