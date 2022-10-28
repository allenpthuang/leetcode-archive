class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> st;
    for (const auto& num : nums) {
      if (st.find(num) != st.end()) {
        return true;
      }
      st.insert(num);
    }
    return false;
  }
};

/* Runtime: 116 ms, faster than 83.20% of C++ online submissions for Contains Duplicate.
 * Memory Usage: 51.5 MB, less than 52.55% of C++ online submissions for Contains Duplicate.
 */

