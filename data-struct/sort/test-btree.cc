#include "bin-tree.h"

using namespace std;

int main(void) {
    typedef BTreeNode<char> BTree;

    cout << "输入数据:";
    BTree *bt = BTree::Create();

    cout << "\n递归遍历:";
    bt->OrderTraverse();
    cout << "\n非递归遍历:";
    bt->InOrderTraverse();
    cout << "\n层级遍历:";
    bt->LevelOrderTraverse();

    cout << "\n叶子结点数:" << bt->LeavesCount() << endl;
    cout << "深度:" << bt->Deepth() << endl;

    return 0;
}
