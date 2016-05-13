#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct Node {
    ElemType data;      // Data field
    struct Node * next; // Pointer field
} Node;

#define StackType Node *
#define MaxStackSize 32

typedef struct Stack {
    StackType base[MaxStackSize];
    unsigned int top;
} Stack;

void InitStack(Stack *S) {
    S->top = 0;
}
 
int Push(Stack *S, StackType e) {
    if(S->top >= MaxStackSize)
        return 0;
    S->base[S->top] = e;
    S->top++;
    return 1;
}

int Pop(Stack *S, StackType *e) {
    if(S->top <= 0)
        return 0;
    S->top--;
    *e = S->base[S->top];
    return 1;
}

int GetTop(Stack *S, StackType *e) {
    if(S->top) {
        *e = S->base[S->top];
        return 1;
    }
    return 0;
}

int StackEmpty(Stack *S) {
    return !S->top;
}

Node *BuildNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = 0;
    scanf("%d", &(p->data));
    return p; 
}

// Build a linklist from standard input
Node * BuildLinkList() {
    int count = 0;   // The count of node
    scanf("%d", &count);
    if(count < 1) // N must be great 1
        return 0;

    Node *head = 0, *p;
    for(int i = 1; i <= count; i++) {
        if(head) {
            p->next = BuildNode();
            p = p->next;
        } else {  // The first node
            p = BuildNode();
            head = p;
        }
    }

    return head;
}

Node *Converse(Node *P) {
    Stack S;
    InitStack(&S);

    Node *p, *pret;
    for(p = P; p; p = p->next)
        Push(&S, p);

    Pop(&S, &pret);

    for(p = pret; !StackEmpty(&S); p = p->next)
        Pop(&S, &(p->next));
    p->next = 0;

    return pret;
}

void PrintLinkList(Node *p) {
    for(; p; p = p->next) {
        printf("%d\t", p->data);
    }
    printf("\n");
}

int main()
{
    Node * head = 0;
    head = BuildLinkList();
    PrintLinkList(head);
    head = Converse(head);
    PrintLinkList(head);
    return 0;
}
