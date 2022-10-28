class Solution {
 public:
  void reverse_span(string& s, int start, int end) {
    for (int i = start; i < (((end - start) / 2) + start); i++) {
      swap(s[i], s[end - i - 1 + start]);
    }
  }

  string reverseStr(string s, int k) {
    int cur_pos = 0;
    for (int cur_pos = 0; cur_pos < s.size(); cur_pos += k * 2) {
      if (s.size() - cur_pos <= k) {
        reverse_span(s, cur_pos, s.size());
      } else {
        reverse_span(s, cur_pos, cur_pos + k);
      }
    }
    return s;
  }
};

/* Runtime: 6 ms, faster than 19.88% of C++ online submissions for Reverse String II.
 * Memory Usage: 7.4 MB, less than 31.20% of C++ online submissions for Reverse String II.
 */

