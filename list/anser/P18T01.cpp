#include "../List.h"
#include <cstdlib>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace List::StaticSqList;
using List::StaticSqList::InitList;

template <typename T>
bool De_SL_Min(SqList<T>&, T& e);
int main()
{

    int a[5] = { 1, 2, 3, 4, 5 };
    SqList<int> L;
    InitList(L, 5);
    for (int i = 0; i < 5; i++) {
        L.data[i] = a[i];
        L.length++;
    }
    int e = 0;
    if (De_SL_Min(L, e)) {
        cout << "e = " << e << endl;
    } else {
        cout << "error" << endl;
    }
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
    return 0;
}

template <typename T>
bool De_SL_Min(SqList<T>& L, T& e)
{
    if (L.length == 0) {
        return false;
    }
    int nu = 0;
    e = L.data[0];
    for (int i = L.length - 1; i > 0; i--) {
        if (L.data[i] < e) {
            e = L.data[i];
            nu = i;
        }
    }
    L.data[nu] = L.data[L.length - 1];
    L.length--;
    return true;
}
