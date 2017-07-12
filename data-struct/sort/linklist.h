#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <iostream>

template <typename T>
class LinkList {
public:
    struct Node {
        T data;
        Node *next = nullptr;

        Node() {}
        Node(T data) { this->data = data; }
    };

    LinkList() {
        InitSqList();
    }
    ~LinkList() {
        for(Node *p = head; p;) {
            Node *tmp = p;
            p = p->next;
            delete tmp;
        }
    }
    // 创建一个链表
    bool InitSqList() {
        if(!head)
            head = new Node;
        return true;
    }
    // 获取指定位置的元素
    bool GetElem(int i, T& e) {
        Node *p = head->next;
        int j = 1;
        for(; p && j<i; j++, p = p->next);
        if(p && j==i) {
            e = p->data;
            return true;
        } else
            return false;
    }
    // 寻找指定元素的位置
    int SearchElem(T e) {
        Node *p = head->next;
        // 遍历寻找e所在结点
        int i = 1;
        for(; p; p = p->next, i++)
            if(p->data == e)
                break;
        if(p)
            return i;
        else
            return 0;
    }
    // 删除指定位置的元素
    bool DeleteElem(int i, T& e) {
        Node *p = head;
        // 找到i-1个结点
        int j = 1;
        for(; j<i && p->next;
                j++, p = p->next);
        if(j == i) {
            Node *temp = p->next;
            p->next = temp->next;
            e = temp->data;    // 返回被删除的结点的数据
            delete temp;       // 释放结点
            return true;
        } else                 // 指定结点不存在
            return false;
    }
    // 返回列表当前的长度
    int Length() {
        int len = 0;
        for(Node *p = head->next; p; p = p->next)
            len++;
        return len;
    }
    // 插入一个元素
    bool InsertElem(T e, int i = 0) {
        Node *p = head;
        if(i) {
            // 找到i-1个结点
            int j = 1;
            for(; j<i && p->next;
                    j++, p = p->next);
            if(j != i)
                return false;
        } else {
            // 找到最后一个结点
            for(; p->next; p = p->next);
        }
        Node *temp = new Node(e);
        temp->next = p->next;
        p->next = temp;
        return true;
    }
    // 是否为空
    bool IsEmpty() {
        return (bool)head->next;
    }

    void Output() {
        for(Node *p = head->next; p; p = p->next)
            std::cout << p->data << " ";
        std::cout << std::endl;
    }

private:
    Node *head = nullptr;
};

#endif /* __LINKLIST_H__ */
