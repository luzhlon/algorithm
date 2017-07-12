#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void output(ListNode *p) {
    for (ListNode *t = p; t; t = t->next)
        cout << t->val << ' ';
    cout << endl;
}

class Solution {
public:
    ListNode* reverse(ListNode* head, int k) {
        ListNode *c = head, *t,
                 *n = c->next;
        while (--k && n)
            t = n->next,        // save next of next to t
            n->next = c,        // let next->next = current
            c = n, n = t;       // switch current to next, next = real next
        head->next = NULL;
        nextg = n, restk = k;
        return c;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k < 2)
            return head;
        ListNode *ch = head,    // header of current group
                 *lh = NULL,    // header of last group
                 *r = NULL;     // header to return
        while (ch) {
            ListNode *t = reverse(ch, k);
            if (lh) lh->next = t;
            else r = t;
            if (restk)
                if (lh) {
                    lh->next = reverse(t, k);
                    return r;
                } else
                    return reverse(t, k);
            lh = ch, ch = nextg;
        }
        return r;
    }

    ListNode* Rev(vector<int> &v, int k) {
        ListNode *p = nullptr, **pp = &p;
        // init linked list
        for (int i = 0; i < v.size(); ++i)
            *pp = new ListNode(v[i]), pp = &(*pp)->next;
        return reverseKGroup(p, k);
    }

    ListNode *nextg;        // next group
    int restk  = 0;         // rest k
};


int main(int argc, char **argv) {
    vector<int> v = {1,2,3,4,5};
    vector<int> v0 = {1,2};

    Solution s;
    output(s.Rev(v, 3));

    getchar();
    return 0;
}
