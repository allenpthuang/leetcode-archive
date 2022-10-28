class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;
    
    for (const auto& c : s) {
      if (! st.empty() && c == st.top()) {
        st.pop();
      } else if (c == '(') {
        st.push(')');
      } else if (c == '[') {
        st.push(']');
      } else if (c == '{') {
        st.push('}');
      } else {
        return false;
      }
    }
    return st.empty();
  }
};

/* Runtime: 6 ms, faster than 10.49% of C++ online submissions for Valid Parentheses.
 * Memory Usage: 6.4 MB, less than 51.45% of C++ online submissions for Valid Parentheses.
 */

