class Solution {
 public:
  int rob(vector<int>& nums) {
    // you can either go up two or three steps but never one or
    // the cop will come get you!!
    
    // dp[i]: the max total money robbed after visiting the i-th house
    vector<int> dp(nums.size() + 1, 0);
    
    // dp[0]: the total money when you haven't robbed nothing
    dp[0] = 0;
    dp[1] = nums[0];
    if (nums.size() > 1) dp[2] = nums[1];
    if (nums.size() == 2) {
      return max(dp[1], dp[2]);
    }
    //dp[3] = max(dp[0] + nums[2], dp[1]);
    
    // walk thru
    for (int i = 3; i <= nums.size(); i++) {
      dp[i] = max({dp[i - 3] + nums[i - 1], dp[i - 2] + nums[i - 1], dp [i - 1]});
    }
    return dp[nums.size()];
  }
};

/* Runtime: 4 ms, faster than 35.12% of C++ online submissions for House Robber.
 * Memory Usage: 7.9 MB, less than 20.72% of C++ online submissions for House Robber.
 */


