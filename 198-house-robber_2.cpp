class Solution {
 public:
  int rob(vector<int>& nums) {
    // dp[i]: the max amount you can rob when you go from 0 to
    // the i-1-th house.
    vector<int> dp(nums.size(), 0);
    
    // dp[0]
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    // walk thru
    for (int i = 2; i < nums.size(); i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    
    return dp[nums.size() - 1];
  }
};

/* Runtime: 4 ms, faster than 35.31% of C++ online submissions for House Robber.
 * Memory Usage: 7.8 MB, less than 20.69% of C++ online submissions for House Robber.
 */


