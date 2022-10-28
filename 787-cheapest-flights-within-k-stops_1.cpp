class Solution {
 private:
  int worker(unordered_map<int, unordered_map<int , int> >& prices, int src, int dst, int cur_cost, int rem_legs) {
    if (src == dst) {
      return cur_cost;
    }
    if (rem_legs == 0 || prices.find(src) == prices.end()) {
      return INT_MAX;
    }
    int cur_min = INT_MAX;
    for (const auto& [next_dst, price] : prices[src]) {
      cur_min = min(cur_min, worker(prices, next_dst, dst, cur_cost + price, rem_legs - 1));
    }
    return cur_min;
  }
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    unordered_map<int, unordered_map<int, int> > prices;  // src -> (dst -> price)
    for (const auto& flight : flights) {
      prices[flight[0]][flight[1]] = flight[2];
    }
    int result = worker(prices, src, dst, 0, k + 1);
    if (result == INT_MAX) {
      return -1;
    } else {
      return worker(prices, src, dst, 0, k + 1);
    }
  }
};

/* TLE */

