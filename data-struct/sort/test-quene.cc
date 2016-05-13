#include "quene.h"

using namespace std;

typedef Quene<char> MQ;  // 男人队列
typedef Quene<int> WMQ;  // 女人队列

void ManQuene(MQ& q, int m) {
    char c;
    cout << "输入男人队列:";
    for(int i = 0; i < m; i++) {
        cin >> c;
        q.EnQuene(c);
    }
}

void WomanQuene(WMQ& q, int n) {
    int j;
    cout << "输入女人队列:";
    for(int i = 0; i < n; i++) {
        cin >> j;
        q.EnQuene(j);
    }
}

void PeiDui(MQ& q1, WMQ& q2, int m, int n, int k) {
    ManQuene(q1, m);
    WomanQuene(q2, n);
    char m1;
    int  m2;
    //cout << "配对名单为:" << endl;
    for(int i = 0; i < k; i++) {
        cout << "第" << i + 1 << "轮:" << endl;
        int min = m > n ? n : m;
        for(int j = 0; j < min; j++) {
            q1.DeQuene(m1);
            q2.DeQuene(m2);
            cout << m1 << " " << m2 << endl;
            q1.EnQuene(m1);
            q2.EnQuene(m2);
        }
        if(m == n)        // 两队人数相等
            continue;
        cout << "下一轮第一个是:";
        if(m < n)
            q2.GetTail(m2), cout << m2 << endl;
        else
            q1.GetTail(m1), cout << m1 << endl;
    }
}

int main(void) {
    MQ mq;
    WMQ wmq;
    int m = 3, n = 5, k;
    /*
    cout << "输入男人数:";
    cin >> m;
    cout << "输入女人数:";
    cin >> n;
    cout << "输入轮数:";
    cin >> k;
    PeiDui(mq, wmq, m, n, k); // */

    cout << "输入轮数:";
    cin >> k;
    PeiDui(mq, wmq, m, n, k); // */

    return 0;
}
