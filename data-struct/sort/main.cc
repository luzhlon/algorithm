#include "list.h"

using namespace std;

int main(void) {
    typedef List<int> List;

    List list;

    list.Input();
    list.Output();

    cout << "----------选择排序方式:------------\n";
    cout << "-----------1、冒泡排序-------------\n";
    cout << "-----------2、插入排序-------------\n";
    cout << "-----------3、快速排序-------------\n";
    cout << "-----------4、归并排序-------------\n";
    cout << "-----------5、堆排序-------------\n";

    int n;
    cin >> n;

    switch(n) {
    case 1:
        list.Sort(List::Bubble_Sort);
        break;
    case 2:
        list.Sort(List::Insert_Sort);
        break;
    case 3:
        list.Sort(List::Quick_Sort);
        break;
    case 4:
        list.Sort(List::Merge_Sort);
        break;
    case 5:
        list.Sort(List::Heap_Sort);
        break;
    default:
        cout << "Error.";
        exit(-1);
    }

    list.Output();

    return 0;
}
