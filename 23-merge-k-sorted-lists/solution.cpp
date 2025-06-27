#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        ListNode aux;
        ListNode* tail = &aux;
        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return aux.next;
    }

    ListNode* mergeK(vector<ListNode*>& lists, int l, int r) {
        if (l > r)
            return nullptr;
        if (l == r)
            return lists[l];
        int mid = l + (r - l) / 2;

        ListNode* left = mergeK(lists, l, mid);
        ListNode* right = mergeK(lists, mid+1, r);

        return merge2Lists(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeK(lists, 0, (int)lists.size() - 1);
    }
};

int main() {
    Solution s;

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);
   
    vector<ListNode*> lists = {l1, l2, l3}, nullList = {};

    ListNode* res = s.mergeKLists(nullList);

    for (ListNode* p = res; p; p = p->next) {
        cout << p->val << " ";
    }
    cout << "\n";

    while (res) {
        ListNode* next = res->next;
        delete res;
        res = next;
    }

    return 0;
}
