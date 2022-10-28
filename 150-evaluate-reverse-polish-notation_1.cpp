class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (const auto& t : tokens) {
      if (t == "+" || t == "-" || t == "*" || t == "/") {
        int opr2 = st.top();
        st.pop();
        int opr1 = st.top();
        st.pop();
        
        int result = 0;
        if (t == "+") {
          result = opr1 + opr2;
        } else if (t == "-") {
          result = opr1 - opr2;
        } else if (t == "*") {
          result = opr1 * opr2;
        } else {
          result = opr1 / opr2;
        }
        st.push(result);
      } else {
        st.push(stoi(t));
      }
    }
    return st.top();
  }
};

/* Runtime: 11 ms, faster than 75.46% of C++ online submissions for Evaluate Reverse Polish Notation.
 * Memory Usage: 12 MB, less than 21.30% of C++ online submissions for Evaluate Reverse Polish Notation.
 */

