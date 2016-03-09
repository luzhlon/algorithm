#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 2048

void get_jump_table(char *p, int plen, int *table) {
    table[0] = 0;
    table[1] = 0;
    for (int i = 2; i < plen; i++) {
        int j = 1;
        int k = 0;
        for(; j < i; j++) {
            int e = i - j;
            for(k = 0; k < e; k++)
                if (p[j+k] != p[k])
                    break;
            if(k == e) {
                table[i] = e;
                break;
            }
        }
        if(j == i)
            table[i] = 0;
    }
}

int find(char *m, int mlen, char *p, int plen) {
    int table[MAX_STRING_LENGTH];
    get_jump_table(p, plen, table);
    int i = 0, j = 0;
    while (i < mlen && j < plen) {
        if (j == 0 || m[i] == p[j])
            i++, j++;
        else
            j = table[j];
    }
    if (j == plen)
        return i - plen;
    else
        return -1;
}

int main(int argc, const char *argv[]) {
    char *m = "ababcabcacbab";
    char *p = "abcac";
    printf("%d\n", find(m, strlen(m), p, strlen(p)));
    return 0;
}
