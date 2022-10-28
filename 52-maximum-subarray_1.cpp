class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = max(nums[i] + dp[i-1], nums[i]);
    }
    auto it = max_element(dp.begin(), dp.end());
    return *it;
  }
};

/* Runtime: 254 ms, faster than 5.16% of C++ online submissions for Maximum Subarray.
 * Memory Usage: 70.4 MB, less than 6.58% of C++ online submissions for Maximum Subarray.
 */

