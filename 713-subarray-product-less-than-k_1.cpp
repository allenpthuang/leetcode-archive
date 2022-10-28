class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k == 0) {
      return 0;
    }
    // sliding window
    int count = 0;
    int left = 0;
    int cur_product = 1;
    for (int right = 0; right < nums.size(); right++) {
      cur_product *= nums[right];
      while (cur_product >= k && left <= right) {
        cur_product /= nums[left];
        left++;
      }
      if (cur_product < k) {
        count += right - left + 1;
      }
    }
    return count;
  }
};

/* Runtime: 168 ms, faster than 37.57% of C++ online submissions for Subarray Product Less Than K.
 * Memory Usage: 61.3 MB, less than 19.82% of C++ online submissions for Subarray Product Less Than K.
 */

