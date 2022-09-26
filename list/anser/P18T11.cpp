/*================================================================
*   Copyright (C) 2022 IEucd Inc. All rights reserved.
*   
*   文件名称：P18T11.cpp
*   创 建 者:GrowlR ,1824023734@qq.com
*   创建日期：2022年09月14日
*   描    述：求两个序列的中位数
*
================================================================*/

#include <iostream>

using namespace std;

int M_Search(int A[], int B[], int n)
{
    int s1 = 0, s2 = 0, d1 = n - 1, d2 = n - 1, m1, m2;
    while (s1 != d1 || s2 != d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (A[m1] == B[m2]) {
            return A[m1];
        } else if (A[m1] < B[m2]) {
            if ((s1 + d1) % 2 == 0) {
                d1 = m1;
                d2 = m2;
            } else {
                s1 = m1 + 1;
                d2 = m2;
            }
        } else {
            if ((s2 + d2) % 2 == 0) {
                d1 = m1;
                s2 = m2;
            } else {
                d1 = m1;
                d2 = m2 + 1;
            }
        }
    }
    return A[s1] < B[s2] ? A[s1] : B[s2];
}
