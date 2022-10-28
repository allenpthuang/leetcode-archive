class Solution {
 public:
  void reverseString(vector<char>& s) {
    for (int i = 0; i < s.size() / 2; i++) {
      char tmp = s[i];
      s[i] = s[s.size() - 1 - i];
      s[s.size() - 1 - i] = tmp;
    }
  }
};

/* Runtime: 53 ms, faster than 5.01% of C++ online submissions for Reverse String.
 * Memory Usage: 23.3 MB, less than 39.16% of C++ online submissions for Reverse String.
 */

