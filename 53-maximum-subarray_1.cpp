class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int cur_max = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      int cur_sum = 0;
      for (int j = i; j < nums.size(); j++) {
        cur_sum += nums[j];
        cur_max = max(cur_max, cur_sum);
      }
    }
    return cur_max;
  }
};

/* TLE */

