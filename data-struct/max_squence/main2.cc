/****************************************************************
 * File: max_squence/main2.cc
 * Description: 最大子列和问题(在线处理)
 *
 * Version: 1.0
 * Author: luzhlon
 * Date: 2015/10/26
 * Description: 最大子列和问题(在线处理)
****************************************************************/

#include <iostream>

using namespace  std;

int max_sequence(int A[], int N) {
    int i;
    int ThisSum, MaxSum;
    ThisSum = MaxSum = 0;
    for(i = 0; i < N; i++) {
        ThisSum += A[i]; /* 加 向右累加 */
        if(ThisSum > MaxSum)
            MaxSum = ThisSum; /* 果 发现更大和则更新当前结果 */
        else if(ThisSum < 0) /* 负 如果当前子列和为负 */
            ThisSum = 0; /* 之 则不可能使后面的部分和增大，抛弃之 */
    }
    return MaxSum;
}

int main()
{
    int count = 0;
    cin >> count;

    int *array = new int[count];

    for(int i = 0; i < count; i++)
        cin >> array[i];

    cout << max_sequence(array, count);

    delete[] array;
    return 0;
}
