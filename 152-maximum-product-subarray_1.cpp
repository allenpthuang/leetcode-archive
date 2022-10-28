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
    return cur_max;
  }
};

/* wrong answer [3,-1,4] */

