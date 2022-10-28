class Solution {
 public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    vector<int> result(queries.size(), 0);
    
    vector<int> candle_idx;
    // count the candles and record their indices
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '|') candle_idx.push_back(i);
    }
    
    for (int i = 0; i < queries.size(); i++) {
      int q_left = queries[i][0];
      int q_right = queries[i][1];
      
      int left_candle_idx_idx = 
        lower_bound(candle_idx.begin(), candle_idx.end(), q_left)
          - candle_idx.begin();
      int right_candle_idx_idx =
        upper_bound(candle_idx.begin(), candle_idx.end(), q_right)
          - candle_idx.begin() - 1;
      
      if (right_candle_idx_idx > left_candle_idx_idx) {
        int candle_cnt = right_candle_idx_idx - left_candle_idx_idx + 1;
        int slot_cnt =
          candle_idx[right_candle_idx_idx] - candle_idx[left_candle_idx_idx] + 1;
        int plate_cnt = slot_cnt - candle_cnt;

        result[i] = plate_cnt;
      }
    }
    
    return result;
  }
};

/* Runtime: 630 ms, faster than 61.44% of C++ online submissions for Plates Between Candles.
 * Memory Usage: 137.6 MB, less than 97.99% of C++ online submissions for Plates Between Candles.
 */

