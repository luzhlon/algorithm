#ifndef __QUENE_H__
#define __QUENE_H__

#include <iostream>

template <typename T, int M = 100>
class Quene {
public:
    bool EnQuene(T e) {
        if((head + 1) % M == tail)  // 队列已満
            return false;
        base[head] = e;
        head = (head + 1) % M;
        return true;
    }
    bool DeQuene(T& e) {
        if(IsEmpty())
            return false;
        e = base[tail];
        tail = (tail + 1) % M;
        return true;
    }
    bool GetTail(T& e) {
        if(IsEmpty())
            return false;
        e = base[tail];
    }
    int Length() {
        return ((head + M) - tail) % M;
    }
    bool IsEmpty() {
        return head == tail;
    }

private:
    T base[M];
    int head = 0;
    int tail = 0;
};

#endif /* __QUENE_H__ */
