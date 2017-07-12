#include<stdio.h>

#define ElemType int

typedef struct Node {
    ElemType data;      // Data field
    struct Node * next; // Pointer field
} Node;

Node * BuildLinkList() {
    return 0;
}

#define X 3

int main()
{
    Node * head = 0;
    head = BuildLinkList();
    Node *p = head;
    int count = 0; // The count of which node data equals X
    for(; p != 0; p = p->next) {
        if(p->data == X)
            count++;
    }
    return 0;
}
