class Solution {
 public:
  string breakPalindrome(string palindrome) {
    if (palindrome.size() == 1) {
      return "";
    }
    bool changed = false;
    for (int i = 0; i < palindrome.size() / 2; i++) {
      if (palindrome[i] > 'a') {
        palindrome[i] = 'a';
        changed = true;
        break;
      }
    }
    if (! changed) {
      palindrome[palindrome.size() - 1] = 'b';
    }
    return palindrome;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Break a Palindrome.
 * Memory Usage: 6.1 MB, less than 78.19% of C++ online submissions for Break a Palindrome.
 */

