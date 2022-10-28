class Solution {
 public:
  bool isAnagram(string s, string t) {
    vector<int> tbs(26, 0);
    vector<int> tbt(26, 0);
    
    for (const auto& c : s) {
      tbs[c - 'a']++;
    }
    for (const auto& c : t) {
      tbt[c - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
      if (tbs[i] != tbt[i]) {
        return false;
      }
    }
    return true;
  }
};

/* Runtime: 6 ms, faster than 90.75% of C++ online submissions for Valid Anagram.
 * Memory Usage: 7.4 MB, less than 46.64% of C++ online submissions for Valid Anagram.
 */

