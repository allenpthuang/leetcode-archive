class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int cur_low_buy = INT_MAX;
    int cur_max_profit = INT_MIN;
    for (const auto& price : prices) {
      cur_low_buy = min(cur_low_buy, price);
      cur_max_profit = max(cur_max_profit,  price - cur_low_buy);
    }
    if (cur_max_profit > 0) {
      return cur_max_profit;
    } else {
      return 0;
    }
  }
};

/* Runtime: 108 ms, faster than 86.72% of C++ online submissions for Best Time to Buy and Sell Stock.
 * Memory Usage: 93.4 MB, less than 13.36% of C++ online submissions for Best Time to Buy and Sell Stock.
 */

