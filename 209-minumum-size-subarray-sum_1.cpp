class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int l_idx = 0;
    int cur_sum = 0;
    int cur_min_len = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      cur_sum += nums[i];
      while (cur_sum >= target) {
        int cur_len = i - l_idx + 1;
        cur_min_len = min(cur_min_len, cur_len);
        cur_sum -= nums[l_idx];
        l_idx++;
      }
    }
    if (cur_min_len == INT_MAX) {
      return 0;
    } else {
      return cur_min_len;
    }
  }
};

/* Runtime: 8 ms, faster than 79.55% of C++ online submissions for Minimum Size Subarray Sum.
 * Memory Usage: 10.6 MB, less than 15.02% of C++ online submissions for Minimum Size Subarray Sum.
 */

