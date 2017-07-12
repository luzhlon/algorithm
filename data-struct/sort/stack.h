#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

template <typename T, int M = 100>
class Stack {
public:
    bool Push(T e) {
        if(top >= M)
            return false;
        base[top++] = e;
        return true;
    }
    bool Pop(T& e) {
        if(top) {
            e = base[--top];
            return true;
        } else
            return false;
    }
    bool GetTop(T& e) {
        if(top) {
            e = base[top-1];
            return true;
        } else
            return false;
    }
    bool IsEmpty() {
        return !top;
    }

private:
    T base[M];
    int top = 0;
};

#endif /* __STACK_H__ */
