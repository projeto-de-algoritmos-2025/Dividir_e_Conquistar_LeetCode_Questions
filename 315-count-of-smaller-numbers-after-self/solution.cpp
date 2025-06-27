#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct Node {
        int val, idx;
    };

    vector<int> ans;
    vector<Node> aux;
    
    void mergeCount(vector<Node>& V, int l, int mid, int r) {
        int i = l, j = mid+1, k = l;
        int elemRight = 0;

        while (i <= mid && j <= r) {
            if (V[i].val <= V[j].val) {
                ans[V[i].idx] += elemRight;
                aux[k++] = V[i++];
            } else {
                elemRight++;
                aux[k++] = V[j++];
            }
        }

        while (i <= mid) {
            ans[V[i].idx] += elemRight;
            aux[k++] = V[i++];
        }

        while (j <= r) {
            aux[k++] = V[j++];
        }

        for (int t = l; t <= r; ++t)
            V[t] = aux[t];
    }

    void sortCount(vector<Node>& V, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        sortCount(V, l, mid);
        sortCount(V, mid+1, r);
        mergeCount(V, l, mid, r);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.assign(n, 0);
        aux.resize(n);

        vector<Node> V(n);
        for (int i = 0; i < n; ++i)
            V[i] = { nums[i], i };

        sortCount(V, 0, n-1);

        return ans;
    }
};

int main() {
    vector<int> nums = {5,2,6,1}, nums2 = {-1,-1};
    Solution s;
    auto res = s.countSmaller(nums);

    for (int x : res) cout << x << " ";
    cout << "\n";

    return 0;
}
