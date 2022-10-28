class Solution {
 public:
  string decodeString(string s) {
    stack<pair<string, int> > st;  // (prev_str, k_count)
    int k = 0;
    string cur_str = "";
    
    for (const auto& c : s) {
      if (c == '[') {
        // starting a new bracket-surronding area:
        // pushing the previous completed string
        // and the count of the starting span k onto stack
        st.push({cur_str, k});  // cur_str becomes prev_str here
        k = 0;
        cur_str = "";
      } else if (c == ']') {
        // the area has ended; pop out the recently-stored pair of
        // prev_str: to be appended;
        // k-count: repeat k times of cur_str and append to prev_str
        auto [prev_str, k_count] = st.top();
        st.pop();
        string to_append = "";
        while (k_count > 0) {
          to_append += cur_str;
          k_count--;
        }
        cur_str = prev_str + to_append;
      } else if (isdigit(c)) {
        k = k * 10 + (c - '0');
      } else {
        cur_str += c;
      }
    }
    
    return cur_str;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
 * Memory Usage: 6.6 MB, less than 37.02% of C++ online submissions for Decode String. 
 */

