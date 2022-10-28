class Solution {
 public:
  bool checkAlmostEquivalent(string word1, string word2) {
    vector<int> w1_freq(26, 0);
    vector<int> w2_freq(26, 0);
    for (const auto& ch : word1) {
      w1_freq[ch - 'a']++;
    }
    for (const auto& ch : word2) {
      w2_freq[ch - 'a']++;
    }
    for (int i = 0; i < w1_freq.size(); i++) {
      if (abs(w1_freq[i] - w2_freq[i]) > 3) {
        return false;
      }
    }
    return true;
  }
};

/* Runtime: 3 ms, faster than 75.00% of C++ online submissions for Check Whether Two Strings are Almost Equivalent.
 * Memory Usage: 6.2 MB, less than 83.95% of C++ online submissions for Check Whether Two Strings are Almost Equivalent.
 */

