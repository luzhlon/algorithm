#include "graph.h"

using namespace std;

int main(void) {
    typedef Digraph<int> GraphD;
    typedef Undigraph<int> GraphUD;

    GraphD gd;
    GraphUD gud;

    cout << "-----------------测试有向图(邻接矩阵)-----------------\n";
    gd.Create();
    cout << "深度优先搜索遍历：\n";
    gd.DFSTraverse();
    cout << "\n广度优先搜索遍历：\n";
    gd.BFSTraverse();
    cout << "\n-----------------测试无向图(邻接表)-----------------\n";
    gud.Create();
    cout << "\n深度优先搜索遍历：\n";
    gud.DFSTraverse();
    cout << "\n广度优先搜索遍历：\n";
    gud.BFSTraverse();

    return 0;
}
