class Solution {
 public:
  int characterReplacement(string s, int k) {
    // choose one from A-Z to be the dominant letter
    int cur_longest = 0;
    for (char cur_ch = 'A'; cur_ch <= 'Z'; cur_ch++) {
      int left = 0;
      int non_cur_ch_cnt = 0;
      for (int right = 0; right < s.size(); right++) {
        if (s[right] != cur_ch) {
          non_cur_ch_cnt++;
        }
        while (non_cur_ch_cnt > k) {
          if (s[left] != cur_ch) {
            non_cur_ch_cnt--;
          }
          left++;
        }
        cur_longest = max(cur_longest, right - left + 1);
      }
    }
    return cur_longest;
  }
};

/* Runtime: 24 ms, faster than 46.28% of C++ online submissions for Longest Repeating Character Replacement.
 * Memory Usage: 7 MB, less than 52.33% of C++ online submissions for Longest Repeating Character Replacement.
 */

