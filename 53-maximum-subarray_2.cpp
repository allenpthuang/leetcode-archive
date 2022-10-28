class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int cur_max = dp[0];
    for (int i = 1; i < nums.size(); i++) {
      // dp[i] stores the the max, which is one of the following:
      // a) nums[i] is part of the previous subarray;
      // b) nums[i] is not part of the previous subarray,
      // it is the beginning of a new one.
      dp[i] = max(nums[i] + dp[i - 1], nums[i]);
      cur_max = max(cur_max, dp[i]);
    }
    return cur_max;
  }
};

/* Runtime: 230 ms, faster than 10.82% of C++ online submissions for Maximum Subarray.
 * Memory Usage: 70.5 MB, less than 5.93% of C++ online submissions for Maximum Subarray.
 */

