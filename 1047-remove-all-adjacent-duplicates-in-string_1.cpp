class Solution {
 public:
  string removeDuplicates(string s) {
    stack<char> st;
    for (const auto& c : s) {
      if (! st.empty()) {
        if (st.top() == c) {
          st.pop();
        } else {
          st.push(c);
        }
      } else {
        st.push(c);
      }
    }
    string result = "";
    while (! st.empty()) {
      result = st.top() + result;
      st.pop();
    }
    return result;
  }
};

/* Runtime: 1112 ms, faster than 6.43% of C++ online submissions for Remove All Adjacent Duplicates In String.
 * Memory Usage: 780.3 MB, less than 6.82% of C++ online submissions for Remove All Adjacent Duplicates In String.
 */

