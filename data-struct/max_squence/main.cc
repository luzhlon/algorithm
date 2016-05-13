/****************************************************************
 * File: max_squence/main.cc
 * Description: 最大子列和问题(分而治之)
 *
 * Version: 1.0
 * Author: luzhlon
 * Date: 2015/10/26
 * Description: 最大子列和问题(分而治之)
****************************************************************/

#include <iostream>

using namespace std;

struct Sequence {
    int *begin;
    int *end;
};

int max_sequence(int *array, int count, Sequence *sq) {
    if(1 == count) {
        sq->begin = array;
        sq->end = array;
        return *array;
    }
    int middle = count / 2;
    Sequence sq_left, sq_right;
    // get the left and right max sequence sum
    int max_left = max_sequence(array, middle,
                                &sq_left);
    int max_right = max_sequence(&array[middle],
                                 count - middle,
                                 &sq_right);
    // calculate the middle sequence sum
    int max_middle = 0;
    for(int *p = sq_left.begin;
             p <= sq_right.end; p++)
        max_middle += *p;
    // get the max sum
    int max = max_left;
    *sq = sq_left;
    if(max_right > max) {
        max = max_right;
        *sq = sq_right;
    }
    if(max_middle > max) {
        max = max_middle;
        sq->begin = sq_left.begin;
        sq->end = sq_right.end;
    }
    return max;
}

int main()
{
    int count = 0;
    cin >> count;

    int *array = new int[count];

    for(int i = 0; i < count; i++)
        cin >> array[i];

    Sequence sq;
    cout << max_sequence(array, count, &sq);

    delete[] array;
    return 0;
}

