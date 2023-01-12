class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int cur_max_profit = 0;
    int cur_low_price = INT_MAX;
    for (const auto& price : prices) {
      cur_low_price = min(cur_low_price, price);
      cur_max_profit = max(cur_max_profit, price - cur_low_price);
    }
    return cur_max_profit;
  }
};

/** Idea: Keep track of the lowest price we have seen,
 * and calc the current profit (as if we bought it at
 * the lowest price we have seen) by cur_price - cur_low.
 * If the current profit is better than cur_max_profit,
 * update it.
 */

/* Runtime
132 ms
Beats
91.67%
Memory
93.3 MB
Beats
54.15%
*/

