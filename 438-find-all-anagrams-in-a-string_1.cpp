class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) {
      return {};
    }
    vector<int> hist(26, INT_MIN);
    int unique_chars = 0;
    for (const auto& ch : p) {
      if (hist[ch - 'a'] == INT_MIN) {
        hist[ch - 'a'] = 1;
        unique_chars++;
      } else {
        hist[ch - 'a']++;
      }
    }
    vector<int> result;
    int found = 0;
    int left = 0;
    int right = 0;
    for (right = 0; right < p.size(); right++) {
      int ch = s[right] - 'a';
      if (hist[ch] != INT_MIN) {
        hist[ch]--;
        if (hist[ch] == 0) {
          found++;
        }
      }
    }
    for (right = p.size(); right < s.size(); right++) {
      if (found == unique_chars) {
        result.push_back(left);
      }
      int ch_l = s[left] - 'a';
      int ch_r = s[right] - 'a';
      if (hist[ch_l] != INT_MIN) {
        hist[ch_l]++;
        if (hist[ch_l] == 1) {
          found--;
        }
      }
      if (hist[ch_r] != INT_MIN) {
        hist[ch_r]--;
        if (hist[ch_r] == 0) {
          found++;
        }
      }
      left++;
    }
    if (found == unique_chars) {
      result.push_back(left);
    }
    
    return result;
  }
};

/* Runtime: 14 ms, faster than 92.98% of C++ online submissions for Find All Anagrams in a String.
 * Memory Usage: 8.8 MB, less than 39.60% of C++ online submissions for Find All Anagrams in a String.
 */

