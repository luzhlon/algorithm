#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template<typename T>
void print(T const &v1, T const &v2);

template<>
void print<char const *>(char const * const &str) {
    cout << "NONCONST:" << str << endl;
}
 
int main() {
    print("aaa");
    return 0;
}
