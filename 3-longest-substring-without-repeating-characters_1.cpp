class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> freq;
    int cur_max = 0;
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
      freq[s[right]]++;
      while (freq[s[right]] > 1) {
        freq[s[left]]--;
        left++;
      }
      cur_max = max(cur_max, right - left + 1);
    }
    return cur_max;
  }
};

/* Runtime: 37 ms, faster than 48.03% of C++ online submissions for Longest Substring Without Repeating Characters.
 * Memory Usage: 8.4 MB, less than 61.05% of C++ online submissions for Longest Substring Without Repeating Characters.
 */

