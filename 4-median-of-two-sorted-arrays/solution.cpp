#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKth(const vector<int>& nums1, int i, const vector<int>& nums2, int j, int k) {
        int m = nums1.size(); int n = nums2.size();

        if (i >= m) return nums2[j+k-1];
        if (j >= n) return nums1[i+k-1];
        if (k == 1) return min(nums1[i], nums2[j]);

        int mid = k / 2;
        int new_i = (i + mid - 1 < m) ? nums1[i + mid - 1] : INT_MAX;
        int new_j = (j + mid - 1 < n) ? nums2[j + mid - 1] : INT_MAX;

        if (new_i < new_j) {
            return findKth(nums1, i + mid, nums2, j, k - mid);
        } else {
            return findKth(nums1, i, nums2, j + mid, k - mid);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(); int n = nums2.size();
        int total = m + n;

        if (total % 2 == 0) {
            int l = findKth(nums1, 0, nums2, 0, (total / 2));
            int r = findKth(nums1, 0, nums2, 0, (total / 2 + 1));
            return (l + r) / 2.0;
        } else {
            return findKth(nums1, 0, nums2, 0, (total + 1) / 2);
        }
    }
};

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    Solution s;

    cout << fixed << setprecision(5) << s.findMedianSortedArrays(nums1, nums2) << "\n";
        
    return 0;
}
