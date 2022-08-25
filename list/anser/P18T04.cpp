/*================================================================
*   Copyright (C) 2022 IEucd Inc. All rights reserved.
*   
*   文件名称：P18T04.cpp
*   创 建 者：GrowlR 
*   创建日期：2022年08月25日
*   描    述：
*
================================================================*/
#include "../List.h"
#include <iostream>

using namespace std;
using namespace List::StaticSqList;
template <typename T>
void LToDeletest(SqList<T>& L, T s, T t)
{
    if (Empty(L)) {
        cout << "error: L is empty" << endl;
        return;
    }
    if (s < L.data[0] || t > L.data[L.length - 1]) {
        cout << "值过大或是值过小" << endl;
        return;
    }
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] <= s || L.data[i] >= t) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
    return;
}
int main()
{
    const int n = 6;
    SqList<int> L;
    int a[n] = { 1, 2, 3, 4, 5, 6 };
    InitList(L, a, n);
    int i = 2, j = 4;
    Display(L);
    cout << endl;
    LToDeletest(L, i, j);
    Display(L);
    cout << endl;
    return 0;
}
