class Solution {
 public:
  int maxTurbulenceSize(vector<int>& arr) {
    int cur_longest = 0;
    int cur_sign = 1;
    int cur_pos_cnt = 0;
    int cur_neg_cnt = 0;
    for (int i = 1; i < arr.size(); i++) {
      // arr[i] - arr[i - 1]
      int diff = (arr[i] - arr[i - 1]) * cur_sign;
      cur_sign *= -1;
      if (diff > 0) {
        cur_pos_cnt++;
        cur_neg_cnt = 0;
      } else if (diff < 0) {
        cur_neg_cnt++;
        cur_pos_cnt = 0;
      } else {
        cur_pos_cnt = 0;
        cur_neg_cnt = 0;
      }
      cur_longest = max(cur_longest, max(cur_pos_cnt, cur_neg_cnt));
    }
    return cur_longest + 1;
  }
};

/* Runtime: 233 ms, faster than 20.76% of C++ online submissions for Longest Turbulent Subarray.
 * Memory Usage: 40.3 MB, less than 60.49% of C++ online submissions for Longest Turbulent Subarray.
 */

