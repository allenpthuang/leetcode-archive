class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) {
      return false;
    }
    unordered_map<char, int> hist;
    for (const auto& ch : s1) {
      hist[ch]++;
    }
    
    int found = 0;
    for (int i = 0; i < s1.size(); i++) {
      char ch = s2[i];
      if (hist.find(ch) != hist.end()) {
        hist[ch]--;
        if (hist[ch] == 0) {
          found++;
        }
      }
    }
    for (int i = s1.size(); i < s2.size(); i++) {
      if (found == hist.size()) {
        return true;
      }
      char left = s2[i - s1.size()];
      char right = s2[i];
      if (hist.find(left) != hist.end()) {
        hist[left]++;
        if (hist[left] == 1) {
          found--;
        }
      }
      if (hist.find(right) != hist.end()) {
        hist[right]--;
        if (hist[right] == 0) {
          found++;
        }
      }
    }
    if (found == hist.size()) {
      return true;
    }
    return false;
  }
};

/* Runtime: 28 ms, faster than 37.58% of C++ online submissions for Permutation in String.
 * Memory Usage: 7.3 MB, less than 42.95% of C++ online submissions for Permutation in String.
 */

