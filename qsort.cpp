#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

template<typename T>
void qsort(T a[], int b, int e) {
    if (b >= e) return;
    int i = b, j = e, k = b;
    T   t = a[k];
    while(1) {
        while (i < j && a[j] >= t)
            j--;
        if (i == j) break;
        a[k] = a[j], k = j;
        while (i < j && a[i] <= t)
            i++;
        if (i == j) break;
        a[k] = a[i], k = i;
    }
    a[i] = t;
    qsort(a, b, i-1);
    qsort(a, i+1, e);
}

template<typename T>
void qsort(T a[], size_t n) {
    qsort(a, 0, n-1);
}

int g_heap[] = {49, 38, 13, 49, 76, 65, 27, 97};
int g_len = sizeof(g_heap) / sizeof(int);
int main(int argc, char **argv) {
    char test[] = "0987631452";
    /* qsort(g_heap, g_len); */
    qsort(test, sizeof(test)-1);

    cout << test << endl;

    /* for (int i = 0; i < g_len; ++i) cout << g_heap[i] << ' '; */

    getchar();
    return 0;
}
