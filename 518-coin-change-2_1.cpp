class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    // dp[i]: how many ways to give the amount of i
    vector<int> dp(amount + 1, 0);
    
    // dp[0]: how many ways to give 0 dollar?
    dp[0] = 1;
    // walk thru the coins ('items') first 
    for (int i = 0; i < coins.size(); i++) {
      // walk thru the amounts ('capacity') later
      for (int j = coins[i]; j <= amount; j++) {
        dp[j] += dp[j - coins[i]];
      }
    }
    
    return dp[amount];
  }
};

/* Runtime: 8 ms, faster than 90.45% of C++ online submissions for Coin Change 2.
 * Memory Usage: 7.2 MB, less than 61.36% of C++ online submissions for Coin Change 2.
 */

