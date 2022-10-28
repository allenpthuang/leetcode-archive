class Solution {
 public:
  int twoSumLessThanK(vector<int>& nums, int k) {
    int cur_max = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        int tmp_sum = nums[i] + nums[j];
        if (i != j && tmp_sum < k) {
          cur_max = max(cur_max, tmp_sum);
        }
      }
    }
    if (cur_max == INT_MIN) {
      return -1;
    } else {
      return cur_max;
    }
  }
};

/* Runtime: 14 ms, faster than 5.54% of C++ online submissions for Two Sum Less Than K.
 * Memory Usage: 9.1 MB, less than 30.38% of C++ online submissions for Two Sum Less Than K.
 */

