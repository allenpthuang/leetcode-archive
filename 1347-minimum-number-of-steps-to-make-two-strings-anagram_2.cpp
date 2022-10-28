class Solution {
 public:
  int minSteps(string s, string t) {
    // count the frequencies of each characters in the two strings
    // since they are both consisting of only lowercase English letters
    // we can use vectors
    vector<int> freqs(26, 0);
    vector<int> freqt(26, 0);
    for (const auto& c : s) {
      freqs[c - 'a']++;
    }
    for (const auto& c : t) {
      freqt[c - 'a']++;
    }
    
    // how many ops?
    int diff = 0;
    for (int i = 0; i < freqs.size(); i++) {
      diff += abs(freqs[i] - freqt[i]);
    }
    
    return diff / 2;
  }
};

/* Runtime: 110 ms, faster than 50.60% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
 * Memory Usage: 16.6 MB, less than 38.38% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
 */

