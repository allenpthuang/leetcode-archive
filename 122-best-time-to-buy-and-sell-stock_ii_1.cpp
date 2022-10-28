class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int cur_bought_price = prices[0];
    int cur_profit_sum = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i - 1] < prices[i]) {
        cur_profit_sum += prices[i] - prices[i - 1];
      } else {
        cur_profit_sum += prices[i - 1] - cur_bought_price;
      }
      cur_bought_price = prices[i];
    }
    return cur_profit_sum;
  }
};

/* Runtime: 16 ms, faster than 40.33% of C++ online submissions for Best Time to Buy and Sell Stock II.
 * Memory Usage: 13 MB, less than 59.51% of C++ online submissions for Best Time to Buy and Sell Stock II.
 */

