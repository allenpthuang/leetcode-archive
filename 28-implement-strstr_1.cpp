class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.size() > haystack.size()) {
      return -1;
    }
    
    for (int i = 0; i < haystack.size(); i++) {
      if (haystack.substr(i, needle.size()) == needle) {
        return i;
      }
    }
    return -1;
  }
};

/* Runtime: 2 ms, faster than 69.65% of C++ online submissions for Implement strStr().
 * Memory Usage: 6.3 MB, less than 77.99% of C++ online submissions for Implement strStr().
 */

