/*================================================================
*   Copyright (C) 2022 IEucd Inc. All rights reserved.
*   
*   文件名称：P18T06.cpp
*   创 建 者：GrowlR 
*   创建日期：2022年08月26日
*   描    述：删除有序顺序表中重复的元素，即唯一化。
*
*   思    路：可以采用双指针
*
================================================================*/
#include "../List.h"
#include <iostream>

using namespace std;
using namespace List::StaticSqList;
template <typename T>
void DeleteSame(SqList<T>& L)
{
    int i = 0, j = 1;
    for (; j < L.length; j++) {
        if (L.data[i] != L.data[j]) {
            L.data[++i] = L.data[j];
        }
    }
    L.length = ++i;
}
int main()
{
    const int n = 6;
    SqList<int> L;
    int a[n] = { 1, 2, 4, 4, 5, 6 };
    InitList(L, a, n);
    Display(L);
    cout << endl;
    DeleteSame(L);
    Display(L);
    cout << endl;
    return 0;
}
