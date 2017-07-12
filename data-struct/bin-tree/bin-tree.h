/**
 * @file bin-tree.h
 * @brief 
 * @author luzhlon
 * @version 0.1.0
 * @date 2015-11-26
 */

#ifndef __BIN_TREE_H__
#define __BIN_TREE_H__

#include <iostream>
#include <functional>

#ifndef NULL
#define NULL 0
#endif

#define EndChar '#'

template <typename ElemType, unsigned int StackSize = 32>
class Stack {
public:
    Stack() {
        this->base = new ElemType[StackSize];
    }
    ~Stack() {
        delete [] base;
    }

    bool Push(ElemType data) {
        if(top >= size)
            return false;
        base[top++] = data;
        return true;
    }

    bool Pop(ElemType *data) {
        if(top) {
            *data = base[--top];
            return true;
        }
        *data = nullptr;
        return false;
    }

    bool GetTop(ElemType *data) {
        if(top) {
            *data = base[top-1];
            return true;
        }
        *data = nullptr;
        return false;
    }

    bool IsEmpty() {
        return !top;
    }

private:
    ElemType *base = nullptr;
    unsigned int top = 0;
    unsigned int size = StackSize;
};

void g_visit(char e) {
    std::cout << e << '\t';
}

template<typename ElemType>
class BiTreeNode {
public:
    typedef BiTreeNode<ElemType> BiTree;
    typedef std::function<void (ElemType)> VisitFunc;

    // static VisitFunc s_fn_visit;

    ElemType data;
    BiTree  *lchild;
    BiTree  *rchild;

    static BiTree *Create() {
        ElemType data;

        std::cin >> data;

        if(data == EndChar)
            return nullptr;

        BiTree *p = new BiTree();

        p->data = data;
        p->lchild = BiTree::Create();
        p->rchild = BiTree::Create();
        return p;
    }

    static void OrderTraverse(BiTree *T) {
        if(T) {
            OrderTraverse(T->lchild);
            g_visit(T->data);
            OrderTraverse(T->rchild);
        }
    }
    inline void OrderTraverse() {
        OrderTraverse(this);
    }

    static void InOrderTraverse(BiTree *T) {
        BiTree *p = T;
        Stack<BiTree *> S;
        while(p || !S.IsEmpty()) {
            if(p) {
                S.Push(p);
                p = p->lchild;
            } else {
                S.Pop(&p);
                if(p)
                    g_visit(p->data);
                p = p->rchild;
            }
        }
    }
    inline void InOrderTraverse() {
        InOrderTraverse(this);
    }

};

/*
template <typename ElemType>
BiTreeNode<ElemType>::VisitFunc
    BiTreeNode<ElemType>::s_fn_visit = 
        [](ElemType e) {
            std::cout << e << '\t';
        }; // */

#endif /* __BIN_TREE_H__ */
