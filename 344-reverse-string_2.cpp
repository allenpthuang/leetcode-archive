class Solution {
 public:
  void reverseString(vector<char>& s) {
    for (int i = 0; i < s.size() / 2; i++) {
      swap(s[i], s[s.size() - 1 - i]);
    }
  }
};

/* Runtime: 37 ms, faster than 12.01% of C++ online submissions for Reverse String.
 * Memory Usage: 23.3 MB, less than 39.16% of C++ online submissions for Reverse String.
 */

