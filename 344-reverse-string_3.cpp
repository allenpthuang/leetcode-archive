class Solution {
 public:
  void reverseString(vector<char>& s) {
    for (int i = 0; i < s.size() / 2; i++) {
      swap(s[i], s[s.size() - i - 1]);
    }
  }
};

/* Runtime: 23 ms, faster than 89.62% of C++ online submissions for Reverse String.
 * Memory Usage: 23.3 MB, less than 41.08% of C++ online submissions for Reverse String.
 */

