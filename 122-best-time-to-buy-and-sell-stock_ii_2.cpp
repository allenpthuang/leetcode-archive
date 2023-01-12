class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int cur_held_price = prices[0];
    int cur_profit_sum = 0;

    for (auto i = 1u; i < prices.size(); i++) {
      if (prices[i] < prices[i - 1]) {
        cur_profit_sum += prices[i - 1] - cur_held_price;
      } else {
        cur_profit_sum += prices[i] - cur_held_price;
      }
      cur_held_price = prices[i];
    }

    return cur_profit_sum;
  }
};

/**
 * Idea: we sell the current-held stock if tomorrow's price
 * is falling.
 *
 * How I eventually did it:
 * Look at the i-th price, compare it with i-1-price, and if today
 * is a bad day (falling), sell it with yesterday's price (which
 * yields zero, so the first if branch is completely unneccessary...).
 * And if there's any profit, sell and re-buy at i-th time.
 */

/* Runtime
10 ms
Beats
64.65%
Memory
13 MB
Beats
63.20%
*/

