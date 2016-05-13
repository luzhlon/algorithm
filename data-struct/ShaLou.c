#include <stdio.h>

int sqrtint(int in)
{
    int i ;
    for(i = 0; i * i <= in; i++);
    return i - 1;
}

int main(int argc, char *argv[])
{
    /*
     * 中间列两侧各有N列
     * 经推算组成"沙漏"共需要4N+3个符号
     * 其中中间列有2N+1个符号
    */

    int i, n, y, f, count;
    scanf("%d", &count);
    //n = (count - 3) / 4;
    n = sqrtint(2 * (count - 1)) / 2 - 1;
    y = count - (2*n*n+4*n+3);
    f = 2 * n + 1;

    for(i = f; i > 1; i-=2)
    {
        int j;
        for(j = 0; j < (f - i) / 2; j++) putchar(' ');
        for(j = 0; j < i; j++) putchar('*');
        putchar('\n');
    }

    for(i = 1; i <= f; i+=2)
    {
        int j;
        for(j = 0; j < (f - i) / 2; j++) putchar(' ');
        for(j = 0; j < i; j++) putchar('*');
        putchar('\n');
    }

    printf("%d", y);

    return 0;
}
