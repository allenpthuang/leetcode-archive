class Solution {
 public:
  int maxProfit(vector<int>& inventory, int orders) {
    long long int profit = 0;
    vector<int> inv = inventory;
    sort(inv.begin(), inv.end(), greater<int>());
    
    for (int i = 0; i < inv.size(); i++) {
      int cur_profit = 0;
      if (orders <= 0) break;
      if (i + 1 < inv.size() && inv[i] > inv[i+1]) {
        int diff = inv[i] - inv[i+1];
        int baskets = i - 0 + 1;
        profit += baskets * (long long int)(inv[i] + inv[i+1] + 1) * diff / 2;
        //inv[i] -= diff;
        orders -= diff * baskets;
        profit += cur_profit;
      } else if (i + 1 == inv.size()) {
        int baskets = inv.size();
        if (baskets >= orders) {
          profit += orders * inv[i];
          orders -= orders;
        } else {
          int rounds = orders / baskets;
          int cur_price = inv[i];
          while (rounds > 0 && cur_price > 0) {
            profit += baskets * cur_price;
            rounds--;
            cur_price--;
            orders -= baskets;
          }
          profit += orders * cur_price;
        }
      }
    }
    return profit % 1000000007;
  }
};

/* TLE & wrong answer */

