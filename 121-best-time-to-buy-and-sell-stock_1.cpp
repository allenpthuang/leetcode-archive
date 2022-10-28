class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int cur_max = INT_MIN;
    for (int i = 0; i < prices.size() - 1; i++) {
      vector<int> sliced(prices.begin() + i + 1, prices.end());
      int buy = prices[i];
      for (auto& sell : sliced) {
        sell -= buy;
      }
      int slice_max = INT_MIN;
      for (const auto& profit : sliced) {
        slice_max = max(slice_max, profit);
      }
      cur_max = max(cur_max, slice_max);
    }
    if (cur_max > 0) {
      return cur_max;
    } else {
      return 0;
    }
  }
};

// TLE
//
