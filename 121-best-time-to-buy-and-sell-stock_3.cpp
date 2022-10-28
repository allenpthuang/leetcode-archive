class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    vector<vector<int> > dp(prices.size(), vector<int>(2));
    dp[0][false] = -prices[0];
    dp[0][true] = 0;
    // walk thru
    for (int i = 1; i < prices.size(); i++) {
      dp[i][false] = max(dp[i - 1][false], -prices[i]);
      dp[i][true] = max(dp[i - 1][false] + prices[i], dp[i - 1][true]);
    }
    return dp[prices.size() - 1][true];
  }
};

/* Runtime: 666 ms, faster than 5.08% of C++ online submissions for Best Time to Buy and Sell Stock.
 * Memory Usage: 153.5 MB, less than 6.09% of C++ online submissions for Best Time to Buy and Sell Stock.
 */

