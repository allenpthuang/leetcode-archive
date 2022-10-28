class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.rbegin(), nums.rend());
    return nums[k - 1];
  }
};

/* Runtime: 12 ms, faster than 28.47% of C++ online submissions for Kth Largest Element in an Array.
 * Memory Usage: 10 MB, less than 83.39% of C++ online submissions for Kth Largest Element in an Array.
 */

