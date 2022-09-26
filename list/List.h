#pragma once
#include <iostream>
namespace List {
namespace StaticSqList {
    // const int MaxSize = 50; //最大长度
    template <typename T>
    struct SqList {
        int length, MaxSize; //当前长度和最大容量
        T* data;             //数据区
    };
    //显示列表
    template <typename T>
    void Display(const SqList<T>& L)
    {
        using std::cout;
        for (int i = 0; i < L.length; i++) {
            cout << "i" << i << ": " << L.data[i] << " ";
        }
        cout << std::endl;
    }

    // 列表初始化
    template <typename T>
    bool InitList(SqList<T>& L, int e)
    {
        L.data = new T[e];
        L.MaxSize = e;
        L.length = 0;
        return true;
    }
    // 列表初始化
    template <typename T>
    bool InitList(SqList<T>& L, T* a, int n)
    {
        InitList(L, n);
        for (int i = 0; i < n; i++) {
            L.data[i] = a[i];
            L.length++;
        }
        return true;
    }
    // 取得列表长度
    template <typename T>
    int Length(SqList<T>& L)
    {

        return L.length;
    }

    //将列表中的值同一赋予e
    template <typename T>
    int LocateElem(SqList<T>& L, T e)
    {
        for (int i = 0; i < L.data; i++) {
            if (L.data[i] == e) {
                return i + 1;
            }
        }
        return 0; //因为线性表的位置是从0开始
    }
    template <typename T>
    T GetElem(const SqList<T>& L, int i)
    {
        return L.data[--i];
    }
    template <typename T>
    bool ListInsert(SqList<T>& L, int i, T e)
    {
        if (i < 1 || i > L.length + 1) {
            return false;
        }
        if (L.length >= L.MaxSize) {
            return false;
        }
        for (int j = L.length; j >= i; j--) {
            L.data[j] = L.data[j - 1];
        }
        L.data[i - 1] = e;
        L.length++;
        return true;
    }
    template <typename T>
    bool ListDelete(SqList<T>& L, int i, T e)
    {
        if (i < 1 || i > L.length + 1) {
            return false;
        }
        e = L.data[i - 1];
        for (int j = i; j < L.length; j++) {
            L.data[j - 1] = L.data[j];
        }
        L.length--;
        return true;
    }
    template <typename T>
    bool Empty(SqList<T>& L)
    {
        return L.length <= 0;
    }
    template <typename T>
    bool DestroyList(SqList<T>& L)
    {
        delete[] L.data;
        L.length = 0;
        return true;
    }
}
}
