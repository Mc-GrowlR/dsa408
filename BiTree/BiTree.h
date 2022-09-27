/*================================================================
*   Copyright (C) 2022 IEucd Inc. All rights reserved.
*   
*   文件名称：BiTree.h
*   创 建 者:GrowlR ,1824023734@qq.com
*   创建日期：2022年09月27日
*   描    述：
*
================================================================*/


#pragma once
#include "../Stack/Stack.h"
template <typename T> 
struct BiNode
{
    T data;
    struct BiNode<T> *lchild,*rchild;
};

template <typename T> 
using BiTree = BiNode<T>; 

template <typename Temp> 
void InOrder(BiTree<Temp>* &T)
{
    SqStack<Temp> S;
    InitStack(S);
    BiTree<Temp> p = T;
    while (p||IsEmpty(S)) {
        if (p) {
            Push(S, p);
            p=p->lchild;
        }
        else {
            Pop(S, p);
            visit(p);
            p=p->rchild;
        }
    }
}
