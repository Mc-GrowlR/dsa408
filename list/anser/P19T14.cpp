/*================================================================
*   Copyright (C) 2022 IEucd Inc. All rights reserved.
*   
*   文件名称：P19T14.cpp
*   创 建 者:GrowlR ,1824023734@qq.com
*   创建日期：2022年09月17日
*   描    述：
*
================================================================*/

#define INT_MAX 0x7fffffff
int abs_(int a)
{
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}
bool xls_min(int a, int b, int c)
{
    if (a <= b && a <= c) {
        return true;
    }
    return false;
}
int findMinofTrip(int A[], int n, int* B, int m, int C[], int p)
{
    int i = 0, j = 0, k = 0, D_min = INT_MAX, D;
    while (i < n && j < m && k < p && D_min > 0) {
        D = abs_(A[i] - B[i]) + abs_(B[j] - C[k]) + abs_(C[k] - A[i]);
        if (D < D_min) {
            D_min = D;
        }
        if (xls_min(A[i], B[j], C[k]))
            i++;
        else if (xls_min(A[i], B[j], C[k]))
            j++;
        else {
            k++;
        }
    }
    return D_min;
}
