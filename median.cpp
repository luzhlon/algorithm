#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int last = 0, cur, m = total/2, n = 0;
        int i = 0, j = 0;
        while (1) {
            // get a minimum
            if (i < nums1.size())
                cur = j < nums2.size() ?
                    nums2[j] < nums1[i] ? nums2[j++] : nums1[i++] : nums1[i++];
            else
                cur = j < nums2.size() ? nums2[j++] : 0;
            if (n++ == m) break;
            last = cur;
        }
        return total % 2 ? (double)cur: ((double)(last+cur))/2;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> n1 = {1,3};
    vector<int> n2 = {2};
    cout << s.findMedianSortedArrays(n1, n2);
    getchar();
    return 0;
}
