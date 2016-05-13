#include "stack.h"

using namespace std;

int main(void) {
    typedef Stack<char, 100> Stack;

    Stack s;
    char str[100];
    cout << "输入一个算术表达式：";
    cin >> str;

    bool match = true;
    for(char *p = str; *p; p++) {
        char c;
        switch(*p) {
        case '{':
        case '[':
        case '(':
            s.Push(*p);
            break;
        case '}':
            if(!(s.Pop(c) && c=='{'))
                match = false;
            break;
        case ']':
            if(!(s.Pop(c) && c=='['))
                match = false;
            break;
        case ')':
            if(!(s.Pop(c) && c=='('))
                match = false;
            break;
        }
        if(!match)
            break;
    }
    if(!s.IsEmpty())
        match = false;
    if(match)
        cout << "括号匹配";
    else
        cout << "括号不匹配";
    
    return 0;
}
