#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <functional>
#include <string.h>
#include "quene.h"

template <int M>
class BoolArray {
public:
    enum {
        COUNT = M / 8 + 1    // 布尔数组占的字节数
    };

    BoolArray() {
    }
    bool Set(int index) {    // index 位置1
        if(index >= M)
            return false;
        data[index/8] |= 1 << (index % 8);
        return true;
    }
    bool Reset(int index) {  // index 位清0
        if(index >= M)
            return false;
        data[index/8] &= ~(1 << (index % 8));
        return true;
    }
    bool operator[](int index) {
        if(index >= M)
            return false;
        return (bool)(data[index/8] & 1 << (index % 8));
    }
    void Clear() {
        for(int i = 0; i < COUNT; i++)
            data[i] = 0;
    }

private:
    char data[COUNT] = { 0 };
};

enum {
    Null = -1
};

template <typename T, int M = 32>
class Digraph {
public:
    typedef char Arc;
    typedef T Vertex;
    typedef std::function<void (T)> VisitFunc;

    VisitFunc visit = ((VisitFunc)([](T data) {
        std::cout << data << " ";
    }));

    Digraph() {
    }
    bool Create() {
        ::memset(arcs, 0, sizeof(arcs[M][M]));

        std::cout << "输入顶点个数：";
        std::cin >> vex_num;
        if(vex_num > M) {
            std::cout << "顶点数过大";
            return false;
        }
        std::cout << "输入顶点数据：\n";
        for(int i = 0; i < vex_num; i++) {
            std::cin >> vexs[i];
        }
        std::cout << "输入弧的个数：";
        std::cin >> arc_num;
        if(vex_num > M * M) {
            std::cout << "弧数过大";
            return false;
        }
        std::cout << "输入弧数据：\n";
        for(int i = 0; i < arc_num; i++) {
            int begin, end;
            std::cin >> begin >> end;
            if(!InsertArc(begin, end)) {
                std::cout << "插入弧失败";
                return false;
            }
        }
        return true;
    }
    int LocateVex(Vertex v) {
        for(int i = 0; i < vex_num; i++)
            if(vexs[i] == v)
                return i;
        return Null;
    }
    bool InsertArc(int vi, int wi) {
        if(vi >= vex_num || wi >= vex_num)
            return false;
        if(vi == wi)
            return false;
        arcs[vi][wi] = 1;
        return true;
    }
    // 广度优先遍历
    void BFSTraverse(int vi = 0) {
        typedef Quene<int, M> Quene;
        visited.Clear();

        Quene Q;
        Q.EnQuene(vi);

        int j = 0;
        do {
            while(!Q.IsEmpty()) {
                int n;
                Q.DeQuene(n);
                if(!visited[n])
                    visit(vexs[n]),
                    visited.Set(n);
                auto p = &arcs[n][0];
                for(int i = 0; i < vex_num; i++)
                    if(p[i] && !visited[i])
                        Q.EnQuene(i);
            }
            while(visited[j] && j < vex_num) // 检查是否已经全部遍历完
                j++;
            Q.EnQuene(j);
        } while(j < vex_num);
    }
    void DFS(int vi) {
        //Arc *p = &arcs[vi][0];
        if(visited[vi])
            return;
        visit(vexs[vi]);
        visited.Set(vi);

        auto p = &arcs[vi][0];
        for(int i = 0; i < vex_num; i++)
            if(p[i])
                DFS(i);

    }
    // 深度优先遍历
    void DFSTraverse() {
        visited.Clear();
        for(int i = 0; i < vex_num; i++)
            if(!visited[i])
                DFS(i);
    }


private:
    Arc arcs[M][M];        // 邻接矩阵
    Vertex vexs[M];  // 顶点向量
    int vex_num = 0;               // 当前顶点数
    int arc_num = 0;               // 当前弧数
    BoolArray<M> visited;          // 访问过的结点
};

template <typename T, int M = 32>
class Undigraph {
public:
    typedef T Vertex;
    typedef std::function<void (T)> VisitFunc;

    struct ArcNode {             // 边结点
        int i_vertex;
        ArcNode * next = nullptr;

        ArcNode(int vi) {
            i_vertex = vi;
        }
    };
    struct VexNode {             // 顶点结点
        Vertex data;
        ArcNode *first_arc = nullptr;
    };

    VisitFunc visit = ((VisitFunc)([](T data) {
        std::cout << data << " ";
    }));

    Undigraph() {
    }
    bool Create() {
        std::cout << "输入顶点个数：";
        std::cin >> vex_num;
        if(vex_num > M) {
            std::cout << "顶点数过大";
            return false;
        }
        std::cout << "输入顶点数据：\n";
        for(int i = 0; i < vex_num; i++) {
            std::cin >> vexs[i].data;
        }
        std::cout << "输入边的个数：";
        std::cin >> arc_num;
        if(arc_num > M * M) {
            std::cout << "边数过大";
            return false;
        }
        std::cout << "输入边数据：\n";
        for(int i = 0; i < arc_num; i++) {
            int begin, end;
            std::cin >> begin >> end;
            if(!InsertArc(begin, end)) {
                std::cout << "插入边失败";
                return false;
            }
        }
        return true;
    }
    int LocateVex(Vertex v) {
        for(int i = 0; i < vex_num; i++)
            if(vexs[i].data == v)
                return i;
        return Null;
    }
    bool InsertArc(int vi, int wi) {
        if(vi >= vex_num || wi >= vex_num)
            return false;
        auto p = vexs[vi].first_arc;
        if(p) {
            bool exist = false;
            for(; p->next; p = p->next)
                if(p->i_vertex == wi) {
                    exist = true;
                    break;
                }
            if(!exist) {
                p->next = new ArcNode(wi);
            }
        } else
            vexs[vi].first_arc = new ArcNode(wi);
        // 
        p = vexs[wi].first_arc;
        if(p) {
            bool exist = false;
            for(; p->next; p = p->next)
                if(p->i_vertex == vi) {
                    exist = true;
                    break;
                }
            if(!exist) {
                p->next = new ArcNode(vi);
            }
        } else
            vexs[wi].first_arc = new ArcNode(vi);
        return true;
    }
    // 广度优先遍历
    void BFSTraverse(int vi = 0) {
        typedef Quene<int, M> Quene;
        visited.Clear();

        Quene Q;
        Q.EnQuene(vi);

        int j = 0;
        do {
            while(!Q.IsEmpty()) {
                int n;
                Q.DeQuene(n);
                if(!visited[n])
                    visit(vexs[n].data),
                    visited.Set(n);
                auto p = vexs[n].first_arc;
                for(; p; p = p->next) {
                    int i = p->i_vertex;
                    if(!visited[i])
                        Q.EnQuene(i);
                }
            }
            while(visited[j] && j < vex_num) // 检查是否已经全部遍历完
                j++;
            Q.EnQuene(j);
        } while(j < vex_num);
    }
    void DFS(int vi = 0) {
        if(visited[vi])
            return;
        visit(vexs[vi].data);
        visited.Set(vi);
        auto p = vexs[vi].first_arc;
        for(; p; p = p->next) {
            int i = p->i_vertex;
            if(!visited[i])
                DFS(i);
        }
    }
    void DFSTraverse() {
        visited.Clear();
        for(int i = 0; i < vex_num; i++)
            if(!visited[i])
                DFS(i);
    }

private:
    VexNode vexs[M];
    int vex_num = 0;
    int arc_num = 0;
    BoolArray<M> visited;
};

#endif /* __GRAPH_H__ */
