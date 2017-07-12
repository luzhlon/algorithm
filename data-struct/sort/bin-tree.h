
#ifndef __BIN_TREE_H__
#define __BIN_TREE_H__

#include <iostream>
#include <functional>
#include "stack.h"
#include "quene.h"

template<typename T>
class BTreeNode {
public:
    typedef BTreeNode<T> BTree;
    typedef std::function<void (T)> VisitFunc;

    T data;
    BTree  *lchild = nullptr;
    BTree  *rchild = nullptr;
    // VisitFunc visit;
    VisitFunc visit = (VisitFunc)([](T data) {
        std::cout << data << " ";
    }); // */

    static BTree *Create() {
        T data;
        std::cin >> data;
        if(data == '#')
            return nullptr;
        BTree *p = new BTree();
        p->data = data;
        p->lchild = BTree::Create();
        p->rchild = BTree::Create();
        return p;
    }

    void OrderTraverse() {
        if(this) {
            lchild->OrderTraverse();
            if(visit) visit(data);
            rchild->OrderTraverse();
        }
    }
    void InOrderTraverse() {
        BTree *p = this;
        Stack<BTree *> S;
        while(p || !S.IsEmpty()) {
            if(p) {
                S.Push(p);
                p = p->lchild;
            } else {
                S.Pop(p);
                if(p)
                    if(visit) visit(p->data);
                p = p->rchild;
            }
        }
    }
    // 层级遍历
    void LevelOrderTraverse() {
        Quene<BTree *> Q;
        Q.EnQuene(this);
        while(!Q.IsEmpty()) {
            BTree *p;
            Q.DeQuene(p);
            if(visit) visit(p->data);
            if(p->lchild)
                Q.EnQuene(p->lchild);
            if(p->rchild)
                Q.EnQuene(p->rchild);
        }
    }
    // 叶子结点的个数
    int LeavesCount() {
        // 自己是叶子结点,返回1
        if((lchild || rchild) == false)
            return 1;
        int ret = 0;
        if(lchild)
            ret = lchild->LeavesCount();
        if(rchild)
            ret += rchild->LeavesCount();
        return ret;
    }
    // 树的深度
    int Deepth() {
        int ret = 0;
        if(lchild)
            ret = lchild->Deepth();
        if(rchild) {
            int d = rchild->Deepth();
            if(d > ret)
                ret = d;
        }
        return ret + 1;
    }
};

#endif /* __BIN_TREE_H__ */
