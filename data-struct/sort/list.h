#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include <functional>

template <typename T, int M = 100>
class List {
    static void Swap(T& a, T& b) {
        T tmp = a;
        a = b;
        b = tmp;
    }

public:
    // 冒泡排序
    static void Bubble_Sort(T A[], int N) {
        int flag = 0;           // 发生交换 标志
        for(int p = N; p >= 1; p--) {
            flag = 0;
            for(int i = 1; i < p; i++) {
                if(A[i] > A[i+1]) {
                    Swap(A[i], A[i+1]);
                    flag = 1;
                }
            }
            if(!flag) // 此次无交换，剩余的数据顺序已经排好
                break;
        }
    }
    // 插入排序
    static void Insert_Sort(T A[], int N) {
        for(int i = 2; i <= N; i++) {
            if(A[i] < A[i-1]) {
                A[0] = A[i];
                A[i] = A[i-1];
                int j = i - 2;
                for(; A[j] > A[0]; j--)
                    A[j+1] = A[j];
                A[j+1] = A[0];
            }
        }
    }
    // 自顶向下调整大顶堆
    static void HeapAdjust(T A[], int S,int E) {
        int p = S;        // 父结点索引
        int c = p * 2;    // 子结点索引 2p,2p+1
        T top = A[S];     // 保存最顶部记录
        for(; c <= E; p = c, c *= 2) {
            if(c < E && A[c+1] > A[c])
                c++;      // 比较选择记录较大的子结点[索引]
            if(top > A[c])
                break;    // 找到比top小的子结点，调整完毕
            A[p] = A[c];  // 上移大记录
        }
        A[p] = top;
    }
    // 堆排序
    static void Heap_Sort(T A[], int N) {
        // 将无序A[N]
        // 从第一个非终端结点开始
        // 到top结点 调整成大顶堆
        for(int i = N / 2; i; i--)
            HeapAdjust(A, i, N);
        for(int i = N; i > 1; i--) {
            Swap(A[1], A[i]);
            HeapAdjust(A, 1, i-1);
        }
    }
    // 快速排序一波
    static int Quick_Part(T A[], int low, int high) {
        //T judge = A[0] = A[low]; // 暂存judge
        T judge = A[low]; // 暂存judge
        while(low < high) {
            while(low < high && A[high] >= judge)
                high--;
            A[low] = A[high];
            while(low < high && A[low] <= judge)
                low++;
            A[high] = A[low];
        }
        A[low] = judge;
        return low;
    }
    // 对A[low..high]快速排序
    static void QSort(T A[], int low, int high) {
        if(low < high) {
            int judge = Quick_Part(A, low, high);
            QSort(A, low, judge - 1);
            QSort(A, judge + 1, high);
        }
    }
    // 快速排序
    static void Quick_Sort(T A[], int N) {
        QSort(A, 1, N);
    }
    // 以m为分水岭归并一波:将A[s..m]与A[m+1..e]归并到B[s..e]中
    static void Merge_Part(T A[], int s, int m, int e) {
        int i = s, j = m + 1;
        //auto p = &B[s];
        auto P = new T[e - s + 1];
        auto p = P;
        // merge
        for(; i <= m && j <= e;) {
            //if(A[i] < A[j])
            if(A[i] <= A[j])
                *p++ = A[i++];
            else
                *p++ = A[j++];
        }
        // copy the rest
        while(i <= m)
            *p++ = A[i++];
        while(j <= e)
            *p++ = A[j++];
        // 
        for(p = P, i = s; i <= e; i++)
            A[i] = *p++;
        delete P;
    }
    // 将A[s..e]归并排序一波
    static void MSort(T A[], int s, int e) {
        if(s == e)
            return;
        int m = (s + e) / 2;
        //auto p = new T[e - s + 1];
        MSort(A, s, m);
        MSort(A, m+1, e);
        Merge_Part(A, s, m, e);
    }
    // 归并排序
    static void Merge_Sort(T A[], int N) {
        MSort(A, 1, N);
    }

    typedef std::function<void (T A[], int N)> SortFunc;

    List() {
        InitSqList();
    }
    // 创建一个列表
    bool InitSqList() {
        return true;
    }
    // 获取指定位置的元素
    bool GetElem(int i, T& e) {
        if(i < 1 || i > len)
            return false;
        e = base[i];
        return true;
    }
    // 删除指定位置的元素
    bool DeleteElem(int i, T& e) {
        if(i < 1 || i > len)
            return false;
        e = base[i];
        for(int j = i; j < len; j++)
            base[j] = base[j+1];
        this->len--;
        return true;
    }
    // 返回列表当前的长度
    int Length() {
        return len;
    }
    // 查找指定元素
    int SearchElem(T e) {
        int i = len;
        while(base[i] != e)
            i--;
        return i;
    }
    // 插入一个元素
    bool InsertElem(T e, int i = 0) {
        if(len >= M)             // 已经达到最大长度
            return false;
        if(!i) {                    // 默认插在最后
            base[++len] = e;
            return true;
        } else {
            if(i > len) {           // 目标位置大于当前长度则插在最后
                base[++len] = e;
                return true;
            }
            this->len++;
            for(int j = len; j > i; j--)
                base[j] = base[j-1];
            this->base[i] = e;
            return true;
        }
    }
    // 是否为空
    bool IsEmpty() {
        return (bool)!len;
    }
    // 排序
    void Sort(SortFunc sort = Quick_Sort) {
        sort(base, len);
    }
    // 顺序查找
    int Search_Seq(T& data) {
        int i = len;
        for(; base[i] != data; i--);
        return i;
    }
    // 二分查找
    int Search_Bin(T& data) {
        Sort();
        int low = 1, high = len;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(data == base[mid])
                return mid;
            if(base[mid] < data)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return 0;
    }
    // 输出
    void Output() {
        for(int i = 1; i <= len; i++)
            std::cout << base[i] << " ";
        std::cout << std::endl;
    }

    void Input() {
        std::cout << "输入个数:";
        std::cin >> len;
        std::cout << "输入列表数据:";
        for(int i = 1; i <= len; i++)
            std::cin >> base[i];
    }

private:
    T base[M+1];
    int len = 0;
};

#endif /* __LIST_H__ */
