class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int cur_sum = 0;
    int cur_min = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      cur_sum += nums[i];
      while (cur_sum >= target) {
        cur_min = min(cur_min, i - left + 1);
        cur_sum -= nums[left];
        left++;
      }
    }
    if (cur_min == INT_MAX) {
      return 0;
    } else {
      return cur_min;
    }
  }
};

/* Runtime: 74 ms, faster than 27.37% of C++ online submissions for Minimum Size Subarray Sum.
 * Memory Usage: 28.3 MB, less than 52.45% of C++ online submissions for Minimum Size Subarray Sum.
 */

