class Solution {
 public:
  int minStartValue(vector<int>& nums) {
    int cur_min_sum = INT_MAX;
    int cur_sum = 0;
    for (const auto& num : nums) {
      cur_sum += num;
      cur_min_sum = min(cur_min_sum, cur_sum);
    }
    if (cur_min_sum >= 0) {
      return 1;
    } else {
      return -cur_min_sum + 1;
    }
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Value to Get Positive Step by Step Sum.
 * Memory Usage: 7.4 MB, less than 78.64% of C++ online submissions for Minimum Value to Get Positive Step by Step Sum.
 */

