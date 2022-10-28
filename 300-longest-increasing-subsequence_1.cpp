class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i-1]) {
        dp[i] = dp[i-1] + 1;
      } else {
        dp[i] = dp[i-1];
      }
    }
    return dp[nums.size() - 1];
  }
};

/* not working */

