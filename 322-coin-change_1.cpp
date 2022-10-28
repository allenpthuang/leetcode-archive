class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    // dp[i]: the fewest number of coins to give i amount
    vector<int> dp(amount + 1, INT_MAX - 1);
    
    // dp[0]
    dp[0] = 0;
    
    // walk thru
    for (int i = 0; i < coins.size(); i++) {
      for (int j = coins[i]; j <= amount; j++) {
        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
      }
    }
    
    if (dp[amount] == INT_MAX - 1) {
      return -1;
    } else {
      return dp[amount];
    }
  }
};

/* Runtime: 60 ms, faster than 82.23% of C++ online submissions for Coin Change.
 * Memory Usage: 14.4 MB, less than 48.37% of C++ online submissions for Coin Change.
 */

