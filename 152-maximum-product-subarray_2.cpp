class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int cur_product = 1;
    int cur_max = INT_MIN;
    for (const auto& num : nums) {
      if (num == 0) {
        cur_product = 1;
        cur_max = max(0, cur_max);
        continue;
      }
      cur_product *= num;
      cur_max = max(cur_max, cur_product);
    }
    cur_product = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] == 0) {
        cur_product = 1;
        cur_max = max(0, cur_max);
        continue;
      }
      cur_product *= nums[i];
      cur_max = max(cur_max, cur_product);
    }
    return cur_max;
  }
};

/* Runtime: 4 ms, faster than 95.32% of C++ online submissions for Maximum Product Subarray.
 * Memory Usage: 13.9 MB, less than 25.23% of C++ online submissions for Maximum Product Subarray.
 */


