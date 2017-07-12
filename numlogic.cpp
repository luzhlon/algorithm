#include <iostream>
#include <cstdio>
#include <stdint.h>

using namespace std;

int main()  {
    int64_t n;
    while (scanf("%lld", &n) != EOF) {
        if (n < 0) {
            int64_t a = -n;
            printf("0x%016llx\n", 0x8000000000000000 | a);
            printf("0x%016llx\n", n-1);
            printf("0x%016llx\n", n);
        } else
            printf("0x%016llx\n0x%016llx\n0x%016llx\n", n, n, n);
    }
    return 0;
}
