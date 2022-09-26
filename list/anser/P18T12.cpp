/*================================================================
*   Copyright (C) 2022 IEucd Inc. All rights reserved.
*   
*   文件名称：P18T12.cpp
*   创 建 者:GrowlR ,1824023734@qq.com
*   创建日期：2022年09月14日
*   描    述：求主元素并返回此元素，若不存在则返回-1
*
================================================================*/
#include <iostream>

int Majority(int* A, int n)
{
    int i, c, count = 1;
    c = A[0];
    for (i = 1; i < n; i++) {
        if (A[i] == c) {
            count++;
        } else {
            if (count > 0) {
                count--;
            } else {
                c = A[i];
                count = 1;
            }
        }
    }
    if (count > 0) {
        for (i = count = 0; i < n; i++) {
            if (A[i] == c) {
                count++;
            }
        }
    }
    if (count > n / 2) {
        return c;
    } else {
        return -1;
    }
}
