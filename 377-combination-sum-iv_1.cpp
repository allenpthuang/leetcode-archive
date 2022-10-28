class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    // dp[i]: the number of possible combinations to
    // form number i with nums
    vector<double> dp(target + 1, 0);
    
    // there is one way to form 0
    dp[0] = 1;
    
    // walk thru the amount ('capacity') first
    for (int i = 0; i <= target; i++) {
      // then walk thru the nums ('items')
      for (int j = 0; j < nums.size(); j++) {
        if (i - nums[j] >= 0) {
          dp[i] += dp[i - nums[j]];
        }
      }
    }
    
    return dp[target];
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum IV.
 * Memory Usage: 6.8 MB, less than 30.77% of C++ online submissions for Combination Sum IV.
 */

