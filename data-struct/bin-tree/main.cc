#include <stdio.h>
#include "bin-tree.h"

int main(void) {
    typedef BiTreeNode<char> BiTree;
    BiTree *p = BiTree::Create();
    p->InOrderTraverse();
    return 0;
}
