#include "list.h"
#include "linklist.h"

using namespace std;

int main(void) {
    //typedef LinkList<int> SqList;
    typedef List<int> SqList;
    SqList l;
    int n, m;

    l.InitSqList();
    // 输入初始数据
    cout << "输入整数的个数：";
    cin >> n;
    cout << "输入一组整数：";
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        l.InsertElem(num);
    }
    // 遍历线性表
    cout << "遍历线性表：" << endl;
    l.Output();
    cout << "输入要查找的元素：";
    cin >> n;
    // 查找某个元素
    n = l.SearchElem(n);
    if(n)
        cout << "查找成功，在第" << n
             << "个位置" << endl;
    else
        cout << "查找失败" << endl;
    // 删除元素
    cout << "输入要删除的元素的位置:";
    cin >> n;
    if(l.DeleteElem(n, m)) {
        cout << "删除" << m
             << "成功" << endl;
    } else
        cout << "删除失败" << endl;
    cout << "线性表当前的长度为:" << l.Length() << endl;
    cout << "遍历线性表：" << endl;
    l.Output();
    // 插入元素
    cout << "输入要插入的元素:";
    cin >> n;
    cout << "输入要插入的元素的位置:";
    cin >> m;
    l.InsertElem(n, m);
    cout << "线性表当前的长度为:" << l.Length() << endl;
    cout << "遍历线性表：" << endl;
    l.Output();

    return 0;
}
