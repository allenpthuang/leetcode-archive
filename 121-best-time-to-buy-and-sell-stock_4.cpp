class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // record the lowest price (that we can buy with) so far
    // and compare the diff with the current price
    // with the cur_max_profit.
    
    int cur_low_buy = INT_MAX;
    int cur_max_profit = INT_MIN;
    for (const auto& price : prices) {
      cur_low_buy = min(cur_low_buy, price);
      cur_max_profit = max(cur_max_profit, price - cur_low_buy);
    }
    if (cur_max_profit > 0) {
      return cur_max_profit;
    } else {
      return 0;
    }
  }
};

/* Runtime: 302 ms, faster than 27.17% of C++ online submissions for Best Time to Buy and Sell Stock.
 * Memory Usage: 93.3 MB, less than 51.12% of C++ online submissions for Best Time to Buy and Sell Stock.
 */

