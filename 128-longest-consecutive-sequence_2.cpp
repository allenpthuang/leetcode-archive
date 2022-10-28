class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set(nums.begin(), nums.end());
    unordered_set<int> seen;
    int cur_max = 0;
    
    for (const auto& num : nums) {
      if (seen.count(num) > 0) {
        continue;
      }
      int cur_cnt = 0;
      seen.insert(num);
      cur_cnt++;
      for (int i = 1; num_set.count(num + i) > 0; i++) {
        seen.insert(num + i);
        cur_cnt++;
      }
      for (int i = -1; num_set.count(num + i) > 0; i--) {
        seen.insert(num + i);
        cur_cnt++;
      }
      if (cur_cnt > cur_max) {
        cur_max = cur_cnt;
      }
    }
    
    return cur_max;
  }
};

/* Runtime: 439 ms, faster than 42.24% of C++ online submissions for Longest Consecutive Sequence.
 * Memory Usage: 61.8 MB, less than 5.05% of C++ online submissions for Longest Consecutive Sequence.
 */

