class Solution {
 public:
  bool canPermutePalindrome(string s) {
    vector<int> hist(26, 0);
    for (const auto& c : s) {
      hist[c - 'a']++;
    }
    bool saw_odd = false;
    for (const auto& h : hist) {
      if (h % 2 != 0) {
        if (s.size() % 2 == 0) {
          return false;
        } else if (saw_odd) {
          return false;
        } else {
          saw_odd = true;
        }
      }
    }
    return true;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Palindrome Permutation.
 * Memory Usage: 6.2 MB, less than 33.18% of C++ online submissions for Palindrome Permutation.
 */

