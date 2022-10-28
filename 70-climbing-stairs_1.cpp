class Solution {
 public:
  int climbStairs(int n) {
    // dp[i]: how many distinct ways to climb n steps
    vector<int> dp(n + 1, 0);
    
    // dp[0]
    dp[0] = 1;
    
    int steps[2] = {1, 2};
    // walk the amount ('capacity') first to get permutation
    for (int i = 0; i <= n; i++) {
      // walk the steps ('items')
      for (const int& step : steps) {
        if (i - step >= 0) {
          dp[i] += dp[i - step];
        }
      }
    }
    return dp[n];
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
 * Memory Usage: 6.2 MB, less than 27.03% of C++ online submissions for Climbing Stairs.
 */

