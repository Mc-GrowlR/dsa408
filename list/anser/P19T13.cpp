/*================================================================
*   Copyright (C) 2022 IEucd Inc. All rights reserved.
*   
*   文件名称：P19T13.cpp
*   创 建 者:GrowlR ,1824023734@qq.com
*   创建日期：2022年09月17日
*   描    述：
*
================================================================*/
int findMissMin(int A[], int n)
{
    int i, *B;
    B = new int[n]();
    for (i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] <= n) {
            B[A[i] - 1] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (B[i] == 0)
            break;
    }
    return i + 1;
}
 
