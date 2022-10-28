class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    if (nums.size() != st.size()) {
      return true;
    } else {
      return false;
    }
  }
};

/* Runtime: 275 ms, faster than 7.98% of C++ online submissions for Contains Duplicate.
 * Memory Usage: 55.3 MB, less than 6.95% of C++ online submissions for Contains Duplicate.
 */

