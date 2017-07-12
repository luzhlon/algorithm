#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        for (auto it = array.begin(); it != array.end(); ++it)
            if (binary_search((*it).begin(), (*it).end(), target))
                return true;
        return false;
    }

};

int main(int argc, char **argv) {
    vector<vector<int>> v = {
        {1, 2,  6,  9},
        {2, 4,  7,  10},
        {3, 6,  11, 20}
    };
    Solution s;
    cout << s.Find(3, v);
    return 0;
}
