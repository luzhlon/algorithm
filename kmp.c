#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 2048

void get_jump_table(char *p, int plen, int *table) {
    table[0] = -1;
    if (plen < 2)
        return;
    int i = 0, j = -1;
    while (i < plen)
        if (j == -1 || p[i] == p[j]) {
            ++i; ++j;
            table[i] = j;
        }
        else
            j = table[j];
}

/**
 * 查找模式串p在主串m中第一次出现的位置
 */
int find(char *m, int mlen, char *p, int plen) {
    int table[MAX_STRING_LENGTH];
    get_jump_table(p, plen, table);

    for(int i = 0; i < plen; i++)
        printf("%c ", p[i]);
    printf("\n");
    // print the jump table
    for(int i = 0; i < plen; i++)
        printf("%d ", table[i]);
    printf("\n");

    int i = 0, j = 0;
    while (i < mlen && j < plen)
        if (m[i] == p[j])
            i++, j++;
        else if (j == 0)   // 如果才比到模式串的第一个字符，就只移动主串指针
            i++;
        else
            j = table[j];

    if (j == plen)
        return i - plen;
    else
        return -1;
}

int main(int argc, const char *argv[]) {
    char m[MAX_STRING_LENGTH];
    char p[MAX_STRING_LENGTH];
    gets(m);
    gets(p);
    printf("%d\n", find(m, strlen(m), p, strlen(p)));
    return 0;
}
