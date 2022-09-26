#pragma once
#define MaxSize 50
template <typename T> struct SqStack {
  T data[MaxSize];
  int top;
  public:
  void InitStack(SqStack<T> &S);
  bool StackEmpty(SqStack<T> S);
  bool Push(SqStack<T> &S, T x);
  bool Pop(SqStack<T> &S, T &x);
  bool GetTop(SqStack<T> S, T &x);
};

//初始化
template <typename T> void InitStack(SqStack<T> &S) {
  S.top = -1; // 初始化栈顶指针
}

//判空栈
template <typename T> bool StackEmpty(SqStack<T> S) {
  if (S.top == -1) {
    return true;
  } else {
    return false;
  }
}

//进栈
template <typename T> bool Push(SqStack<T> &S, T x) {
  if (S.top == MaxSize - 1) {
    return false;
  }
  S.data[++S.top] = x;
}

//出栈
template <typename T> bool Pop(SqStack<T> &S, T &x) {
  if (S.top == -1) {
    return false;
  }
  x = S.data[S.top--];
  return true;
}

//读栈顶元素
template <typename T> bool GetTop(SqStack<T> S, T &x) {
  if (S.top == -1) {
    return false;
  }
  x = S.data[S.top];
  return true;
  ;
}
