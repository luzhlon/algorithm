#include <iostream>
#include "huffman.h"

using namespace std;

int main(int argc, char *argv[]) {
    typedef HuffNode<string> MyHuffNode;

    MyHuffNode::List lst;

    MyHuffNode hfs[5] = {
        MyHuffNode(0.05f, "0-59"),
        MyHuffNode(0.15f, "60-69"),
        MyHuffNode(0.40f, "70-79"),
        MyHuffNode(0.30f, "80-89"),
        MyHuffNode(0.10f, "90-100")
    };
    for(int i = 0; i < 5; i++) {
        lst.push_back(&hfs[i]);
    }

    auto hufftree = MyHuffNode::Build(&lst);
    /*
    hufftree->traversal(
    MyHuffNode::Callback([](void *node) {
        auto n = static_cast<MyHuffNode *>(node);
        if(n->left() && n->right()) return;
        cout << "[Left]" << n->getString() << endl;
    }),

    MyHuffNode::Callback([](void *node) {
        auto n = static_cast<MyHuffNode *>(node);
        if(n->left() && n->right()) return;
        cout << "[Right]" << n->getString() << endl;
    })); // */

    hufftree->print();

    //cout << "Hello world" << endl;

    return 0;
}
