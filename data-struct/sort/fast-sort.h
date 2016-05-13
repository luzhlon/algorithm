#ifndef __FAST_SORT_H__
#define __FAST_SORT_H__

static void QSort(ElemType A[], int low, int high) {
    if(low < high) {
        int judge = Partition(A, low, high);
        QSort(A, low, judge - 1);
        QSort(A, judge + 1, high);
    }
}

void Fast_Sort(ElemType A[], int N) {
    return QSort(A, 0, N-1);
}


#endif /* __FAST_SORT_H__ */
