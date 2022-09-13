/*================================================================
*   Copyright (C) 2022 IEucd Inc. All rights reserved.
*   
*   文件名称：P18T08.cpp
*   创 建 者：GrowlR 
*   创建日期：2022年08月26日
*   描    述：给定范围，倒置数组。需注意的是编写函数时数组的下标
*            与顺序表位序的关系
*
================================================================*/

#include "../List.h"
#include <iostream>

using namespace std;
using namespace List::StaticSqList;
//逆置算法
template <typename T>
bool Reverse(T* A, int left, int right, int arraySize)
{
    //合法性检查
    if (left >= right || right >= arraySize) {
        return false;
    }
    int mid = (left + right) / 2;
    T temp = 0;
    cout << "mid: " << mid << endl;
    for (int i = 0; i <= mid - left; i++) {
        temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
    return true;
}
template <typename T>
void Exchange(T* A, int m, int n, int arraySize)
{
    Reverse(A, 0, m + n - 1, arraySize);
    Reverse(A, 0, n - 1, arraySize);
    Reverse(A, n, m + n - 1, arraySize);
}
int main()
{
    const int n = 6;
    SqList<int> L;
    int a[n] = { 1, 2, 4, 4, 5, 6 };
    InitList(L, a, n);
    Display(L);
    cout << endl;

    SqList<int> L1;
    int a1[n] = { 7, 8, 9, 10, 11, 12 };
    InitList(L1, a1, n);
    Display(L);
    cout << endl;
    int a2[n + n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    for (int i = 0; i < n + n; i++) {
        cout << a2[i] << " ";
    }
    cout << endl;
    Exchange(a2, 6, 6, 6);
    for (int i = 0; i < n + n; i++) {
        cout << a2[i] << " ";
    }
    cout << endl;
    return 0;
}
