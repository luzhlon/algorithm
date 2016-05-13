#include<stdio.h>

#define ElemType int

typedef struct Node {
    ElemType data;      // Data field
    struct Node * next; // Pointer field
} Node;

int main()
{
    Node * head = 0;
    head = (Node *)malloc(sizeof(Node));
    head->data = 1;
    int N = 0;
    scanf("%d", &N);
    if(N <= 1) // N must be great 1
        return 1;
    Node * p = head;
    for(int i = 2; i <= N; i++) {
        p->data = i;
        p->next = (Node *)malloc(sizeof(Node));
        p = p->next;
        p->next = 0;
    }
    return 0;
}
