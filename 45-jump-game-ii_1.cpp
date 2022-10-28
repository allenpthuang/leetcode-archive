class Solution {
 public:
  int jump(vector<int>& nums) {
    if (nums.size() == 1) return 0;
    int cur_max_idx = nums[0];
    int next_max_idx = 0;
    int result = 1;
    
    for (int i = 1; i < nums.size(); i++) {
      next_max_idx = max(next_max_idx, i + nums[i]);
      if (cur_max_idx == nums.size() - 1) break;
      if (i == cur_max_idx) {
        result++;
        cur_max_idx = next_max_idx;
      }
    }
    return result;
  }
};

/* Runtime: 20 ms, faster than 74.03% of C++ online submissions for Jump Game II.
 * Memory Usage: 16.7 MB, less than 47.46% of C++ online submissions for Jump Game II.
 */

