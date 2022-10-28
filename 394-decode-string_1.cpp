class Solution {
 public:
  string decodeString(string s) {
    stack<pair<int, string> > st;
    int k = 0;
    string cur_str = "";
    
    for (const auto& c : s) {
      if (c == '[') {
        st.push({k, cur_str});
        k = 0;
        cur_str = "";
      } else if (c == ']') {
        auto [last_k, last_str] = st.top();
        st.pop();
        string tmp = cur_str;
        cur_str = last_str;
        while (last_k > 0) {
          cur_str += tmp;
          last_k--;
        }
        
      } else if (isdigit(c)) {
        k = k * 10 + (c - '0');
      } else {
        cur_str += c;
      }
    }
    return cur_str;
  }
};

/* Runtime: 6 ms, faster than 19.64% of C++ online submissions for Decode String.
 * Memory Usage: 6.4 MB, less than 87.29% of C++ online submissions for Decode String.
 */

