class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;
    for (const auto& c : s) {
      if (c == '(' || c == '{' || c == '[') {
        st.push(c);
      } else if (c == ')' || c == '}' || c == ']') {
        if (st.size() == 0) {
          return false;
        }
        char top_ch = st.top();
        if ((top_ch == '(' && c == ')')
           || (top_ch == '{' && c == '}')
           || (top_ch == '[' && c == ']')) {
          st.pop();
        } else {
          return false;
        }
      }
    }
    if (st.size() == 0) {
      return true;
    } else {
      return false;
    }
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
 * Memory Usage: 6.4 MB, less than 51.50% of C++ online submissions for Valid Parentheses.
 */
