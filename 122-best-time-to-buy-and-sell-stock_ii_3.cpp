class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int cur_held_price = prices[0];
    int cur_profit_sum = 0;

    for (auto i = 1u; i < prices.size(); i++) {
      if (prices[i] > prices[i - 1]) {
        cur_profit_sum += prices[i] - cur_held_price;
      }
      cur_held_price = prices[i];
    }

    return cur_profit_sum;
  }
};

/**
 * Idea: high-freq trades. We sell if we see any slight profits,
 * and re-buy it immediately for future sells. If no profits can
 * be generated, do nothing (don't hold, either) because any
 * available profit would already have been added to the sum
 * in the if block.
 */

/* Runtime
9 ms
Beats
70.7%
Memory
13.1 MB
Beats
63.20%
*/

