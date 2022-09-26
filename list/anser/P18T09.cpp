/*================================================================
*   Copyright (C) 2022 IEucd Inc. All rights reserved.
*   
*   文件名称：P18T09.cpp
*   创 建 者:GrowlR ,1824023734@qq.com
*   创建日期：2022年09月14日
*   描    述：查找插入
*
================================================================*/

#include "../List.h"
#include <iostream>

using namespace std;
using namespace List::StaticSqList;
template <typename T>
void SearchExchangeInsert(SqList<T>& L, T x)
{
    int low = 0, high = L.length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.data[mid] == x) {
            break;
        } else if (L.data[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (L.data[mid] == x && mid != L.length - 1) {
        T t = L.data[mid];
        L.data[mid] = L.data[mid + 1];
        L.data[mid + 1] = t;
    }
    if (low > high) {
        int i = 0;
        for (i = L.length - 1; i > high; i--) {
            L.data[i + 1] = L.data[i];
        }
        L.data[i + 1] = x;
        L.length += 1;
    }
}
int main()
{

    const int n = 6;
    SqList<int> L;
    int a[n] = { 1, 2, 4, 4, 5, 6 };
    InitList(L, a, n);
    Display(L);
    SearchExchangeInsert(L, 3);
    Display(L);
    return 0;
}
