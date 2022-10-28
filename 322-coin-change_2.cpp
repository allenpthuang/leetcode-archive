class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    // dp[cur_amount]: the minimal number of coins to sum to cur_amount
    // dp[cur_amount] = min(use the cur_coin, keep it the same)
    // dp[cur_amount] = min(dp[cur_amount], 1 + dp[cur_amount - cur_coin_value]);
    //                                      ^--- one (current) coin
    
    sort(coins.begin(), coins.end());
    // e.g. amount = 7, we need that dp[7] and also the base case dp[0].
    vector<int> dp(amount + 1, amount + 1);
    // Init the base case dp[0]. We need 0 coins to make the amount = 0
    dp[0] = 0;
    for (int amt = 1; amt <= amount; amt++) {
      for (const auto& coin : coins) {
        if (amt - coin < 0) {
          break;
        }
        dp[amt] = min(dp[amt], 1 + dp[amt - coin]);
      }
    }
    
    if (dp[amount] == amount + 1) {
      return -1;
    } else {
      return dp[amount];
    }
  }
};

/* Runtime: 155 ms, faster than 49.95% of C++ online submissions for Coin Change.
 * Memory Usage: 14.4 MB, less than 76.19% of C++ online submissions for Coin Change.
 */

