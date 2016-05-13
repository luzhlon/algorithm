#include "list.h"

using namespace std;

int main(void) {
    typedef List<int> List;

    List list;

    list.Input();
    list.Output();
    cout << "输入要查找的数据：";
    int n, m;
    cin >> n;

    m = list.Search_Bin(n);
    cout << "二分查找：" << m << endl;

    m = list.Search_Seq(n);
    cout << "顺序查找：" << m << endl;

    return 0;
}
