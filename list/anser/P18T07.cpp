/*================================================================
*   Copyright (C) 2022 IEucd Inc. All rights reserved.
*   
*   文件名称：P18T07.cpp
*   创 建 者：GrowlR 
*   创建日期：2022年08月26日
*   描    述：将两个有序顺序表合成一个顺序表，并由函数返回值返回
*
*   思路：将两个表并列方式，不断比较表头节点，将较小的放入新表中。
*           然后将剩下的表单独处理，以
*
================================================================*/

#include "../List.h"
#include <iostream>

using namespace std;
using namespace List::StaticSqList;
template <typename T>
bool twoToOne(SqList<T>& L, SqList<T>& L1, SqList<T>& L2)
{
    int i = 0, j = 0, k = 0;
    while (i < L.length && j < L1.length) {
        if (L.data[i] <= L1.data[j]) {
            L2.data[k++] = L.data[i++];

        } else {
            L2.data[k++] = L1.data[j++];
        }
    }
    while (i < L.length) {
        L2.data[k++] = L.data[i++];
    }
    while (j < L1.length) {
        L2.data[k++] = L1.data[j++];
    }
    L2.length = k;
    return true;
}
int main()
{

    const int n = 6;
    SqList<int> L;
    SqList<int> L1;
    SqList<int> L2;
    int a[n] = { 1, 2, 4, 4, 5, 6 };
    InitList(L, a, n);
    InitList(L1, a, n);

    //第一次发生了栈溢出，原因在这，初始化时，给予的空间过小
    //InitList(L1, a, n);
    InitList(L2, n + n);
    Display(L);
    cout << endl;

    Display(L1);
    cout << endl;
    int x = 0;
    cin >> x;
    cout << x;
    Display(L2);
    cout << endl;
    twoToOne(L, L1, L2);
    Display(L2);
    cout << endl;
    return 0;
}
