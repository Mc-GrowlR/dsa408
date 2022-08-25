/*================================================================
*   Copyright (C) 2022 IEucd Inc. All rights reserved.
*   
*   文件名称：P18T03.cpp
*   创 建 者：GrowlR 
*   创建日期：2022年08月25日
*   描    述：删除顺序表中元素x，要求线性复杂度，原地工作
*
================================================================*/

#include "../List.h"
#include <iostream>

using namespace std;
using namespace List::StaticSqList;
void LToDeleteX(SqList<int>& L, int x)
{
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}
int main()
{
    const int n = 6;

    int a[n] = { 1, 2, 3, 4, 2, 2 };
    SqList<int> Sl;
    InitList(Sl, a, n);
    Display(Sl);
    cout << endl;
    LToDeleteX(Sl, 2);
    Display(Sl);
    cout << endl;
    return 0;
}
