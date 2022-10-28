class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int cur_max_reach = 0;
    for (int i = cur_max_reach; i < nums.size() && i <= cur_max_reach; i++) {
      cur_max_reach = max(cur_max_reach, i + nums[i]);
    }
    bool result = (cur_max_reach >= nums.size() - 1);
    return result;
  }
};

/* Runtime: 89 ms, faster than 61.71% of C++ online submissions for Jump Game.
 * Memory Usage: 48.4 MB, less than 28.02% of C++ online submissions for Jump Game.
 */

