#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int *find(int *b, int *e, int val) {
        for (int* p = b; p < e; ++p)
            if (*p == val)
                return p;
        return nullptr;
    }
    TreeNode* rebuild(int* pb, int* ib, int len) {
        if (len <= 0) return nullptr;
        int rd = *pb;       // root data
        int *mi = find(ib, ib+len, rd);
        int llen = mi - ib,
            rlen = len - llen - 1;
        int *plb = pb+1, *prb = plb+llen;
        int *ilb = mi - llen, *irb = mi+1;
        TreeNode *t = new TreeNode(rd);
        t->left = rebuild(plb, ilb, llen);
        t->right = rebuild(prb, irb, rlen);
        return t;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return rebuild(&pre.front(), &vin.front(), pre.size());
    }
    
    int* pre = nullptr;
    int* vin = nullptr;
};

void travel(TreeNode *t) {
    if (!t) return;
    cout << t->val << ' ';
    travel(t->left);
    travel(t->right);
}

int main(int argc, char **argv) {
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> vin = {4,7,2,1,5,3,8,6};

    Solution s;
    TreeNode *bt = s.reConstructBinaryTree(pre, vin);
    travel(bt);
    return 0;
}
