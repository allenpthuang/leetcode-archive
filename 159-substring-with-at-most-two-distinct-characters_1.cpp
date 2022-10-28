class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    vector<int> freqs(63, 0);
    int cur_max_len = 0;
    int distinct_chars = 0;
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
      int ch = s[right] - 'A';
      freqs[ch]++;
      if (freqs[ch] == 1) {
        distinct_chars++;
      }
      while (distinct_chars > 2) {
        ch = s[left] - 'A';
        freqs[ch]--;
        if (freqs[ch] == 0) {
          distinct_chars--;
        }
        left++;
      }
      cur_max_len = max(cur_max_len, right - left + 1);
    }
    return cur_max_len;
  }
};

/* Runtime: 44 ms, faster than 84.84% of C++ online submissions for Longest Substring with At Most Two Distinct Characters.
 * Memory Usage: 9.6 MB, less than 79.00% of C++ online submissions for Longest Substring with At Most Two Distinct Characters.
 */

