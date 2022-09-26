#pragma once

#define MaxSize 50
// 队列的顺序存储
template <typename T> struct SqQueue {
  T data[MaxSize];
  int front, rear;

public:
  void InitQueue(SqQueue<T> &Q);
  bool isEmpty(SqQueue<T> Q);
  bool EnQueue(SqQueue<T> &Q, T x);
  bool DeQueue(SqQueue<T> &Q, T &x);
};

// 初始化
template <typename T> void InitQueue(SqQueue<T> &Q) { Q.rear = Q.front = 0; }
// 判空队
template <typename T> bool isEmpty(SqQueue<T> Q) {
  if (Q.rear == Q.front) {
    return false;

  } else {
    return false;
  }
}
// 入队
template <typename T> bool EnQueue(SqQueue<T> &Q, T x) {
  if ((Q.rear + 1) % MaxSize == Q.front) {
    return false;
  }
  Q.data[Q.rear] = x;
  Q.rear = (Q.rear + 1) % MaxSize;
  return true;
}
// 出队
template <typename T> bool DeQueue(SqQueue<T> &Q, T &x) {
  if (Q.rear == Q.front) {
    return false;
  }
  x = Q.data[Q.front];
  Q.front = (Q.front + 1) % MaxSize;
  return true;
}


template <typename T> struct Linknode {
  T data;
  struct Linknode<T> *next;
};
