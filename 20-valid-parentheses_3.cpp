class Solution {
 public:
  bool isValid(string s) {
    if (s.size() % 2 != 0) {
      return false;
    }
    stack<char> char_to_pair;
    for (const auto& c : s) {
      if (! char_to_pair.empty() && char_to_pair.top() == c) {
        char_to_pair.pop();
      } else if (c == '(') {
        char_to_pair.push(')');
      } else if (c == '[') {
        char_to_pair.push(']');
      } else if (c == '{') {
        char_to_pair.push('}');
      } else {
        return false;
      }
    }
    if (char_to_pair.empty()) {
      return true;
    } else {
      return false;
    }
  }
};

/* Runtime: 7 ms, faster than 9.28% of C++ online submissions for Valid Parentheses.
 * Memory Usage: 6.3 MB, less than 79.92% of C++ online submissions for Valid Parentheses.
 */


