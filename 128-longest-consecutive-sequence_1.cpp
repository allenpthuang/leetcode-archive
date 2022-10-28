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
      unordered_set<int> cur_seen;
      cur_seen.insert(num);
      for (int i = 1; num_set.count(num + i) > 0; i++) {
        cur_seen.insert(num + i);
      }
      for (int i = -1; num_set.count(num + i) > 0; i--) {
        cur_seen.insert(num + i);
      }
      if (cur_seen.size() > cur_max) {
        cur_max = cur_seen.size();
        seen = cur_seen;
      }
    }
    
    return cur_max;
  }
};

/* Runtime: 657 ms, faster than 35.95% of C++ online submissions for Longest Consecutive Sequence.
 * Memory Usage: 173.3 MB, less than 5.05% of C++ online submissions for Longest Consecutive Sequence.
 */

