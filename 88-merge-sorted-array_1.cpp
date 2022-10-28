class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0) {
      if (nums2[j] > nums1[i]) {
        nums1[k] = nums2[j];
        k--;
        j--;
      } else {
        nums1[k] = nums1[i];
        k--;
        i--;
      }
    }
    while (j >= 0) {
      nums1[k] = nums2[j];
      k--;
      j--;
    }
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
 * Memory Usage: 9.1 MB, less than 30.37% of C++ online submissions for Merge Sorted Array.
 */

