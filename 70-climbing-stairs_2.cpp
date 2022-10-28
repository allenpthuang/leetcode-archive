class Solution {
 public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 2] + dp [i - 1];
    }
    return dp[n];
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
 * Memory Usage: 6.2 MB, less than 31.49% of C++ online submissions for Climbing Stairs.
 */

