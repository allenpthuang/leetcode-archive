class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int cur_max_sum = INT_MIN;
    int local_max = 0;
    for (const auto& num : nums) {
      local_max = max(local_max + num, num);
      cur_max_sum = max(cur_max_sum, local_max);
    }
    return cur_max_sum;
  }
};

/* Runtime: 230 ms, faster than 38.98% of C++ online submissions for Maximum Subarray.
 * Memory Usage: 67.6 MB, less than 90.32% of C++ online submissions for Maximum Subarray.
 */

