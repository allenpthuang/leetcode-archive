class Solution {
 public:
  int countPalindromicSubsequence(string s) {
    vector<int> hist_l(26, 0);
    vector<int> hist_r(26, 0);
    // put everything except s[0], s[1] into hist_r first
    hist_l[s[0] - 'a']++;
    for (int i = 2; i < s.size(); i++) {
      hist_r[s[i] - 'a']++;
    }
    
    unordered_set<string> result;
    string tmp = "  ";
    // traversal starts from s[1]
    for (int i = 1; i < s.size() - 1; i++) {
      for (int j = 0; j < hist_l.size(); j++) {
        if (hist_l[j] > 0 && hist_r[j] > 0) {
          char aux = j + 'a';
          tmp[0] = aux;
          tmp[1] = s[i];
          result.insert(tmp);
        }
      }
      // add current to left; remove current right from right
      hist_l[s[i] - 'a']++;
      hist_r[s[i + 1] - 'a']--;
    }
    return result.size();
  }
};

/* Runtime: 1152 ms, faster than 22.74% of C++ online submissions for Unique Length-3 Palindromic Subsequences.
 * Memory Usage: 14.1 MB, less than 42.12% of C++ online submissions for Unique Length-3 Palindromic Subsequences.
 */

