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
    string result;
    result.resize(st.size());
    for (int i = result.size() - 1; i >= 0; i--) {
      result[i] = st.top();
      st.pop();
    }
    return result;
  }
};

/* Runtime: 35 ms, faster than 44.07% of C++ online submissions for Remove All Adjacent Duplicates In String.
 * Memory Usage: 10.9 MB, less than 79.90% of C++ online submissions for Remove All Adjacent Duplicates In String.
 */

