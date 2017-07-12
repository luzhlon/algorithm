#include <cstdio>
#include <iostream>
#include <fstream>
#include <stdarg.h>
#include <string>
#include <regex>
#include <stdint.h>
#include <limits.h>
#include <ctype.h>

using namespace std;

struct Heap {
    template <typename _T>
    static void adjust(_T *h, int s, int n) {
        do {
            int l = left(s), r = right(s);
            int min = s;
            // Select minimal node from s, l, r
            if (l < n && h[l] < h[s])
                min = l;
            if (r < n && h[r] < h[min])
                min = r;
            if (min == s)
                break;
            else        // adjust child recursively
                swap(h[min], h[s]), s = min;
        } while (1);
    }
    template <typename _T>
    static void build(_T *h, int size) {
        for (int i = size/2; i >= 0; i--)
            adjust(h, i, size);
    }
    template <typename _T>
    static void sort(_T *h, int size) {
        build(h, size);
        for (int i = size-1; i; --i)
            swap(h[0], h[i]), adjust(g_heap, 0, i);
    }

    static inline int left(int n) { return 2*n+1; }
    static inline int right(int n) { return 2*(n+1); }
    static inline int parent(int n) { return (n-1)/2; }
};

int g_heap[] = {49, 38, 13, 49, 76, 65, 27, 97};
int g_len = sizeof(g_heap) / sizeof(int);

string nodeid(int i) {
    string s("h");
    char buf[32];
    sprintf(buf, "%d", i);
    s += buf;
    return s;
}
void draw() {
    fstream out("a.dot", ios::out);
    if (out.is_open()) {
        out << "digraph {\n";

        for (int i = 0; i < g_len; ++i)
            out << "    " << nodeid(i) << "[label=\"" << g_heap[i] << "\"];\n";

        int m = g_len / 2;
        for (int i = 0; i < m; ++i) {
            int left = 2*i+1, right = left + 1;
            out << "    " << nodeid(i) << " -> " << nodeid(left) << ";\n";
            if (right < g_len)
            out << "    " << nodeid(i) << " -> " << nodeid(right) << ";\n";
        }

        out << "}";
    }
    out.close();
}

int main(int argc, char **argv) {
    Heap::sort(g_heap, g_len);

    for (int i = 0; i < g_len; ++i)
        cout << g_heap[i] << ' ';
    draw();
    getchar();
    return 0;
}
