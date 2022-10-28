class Solution {
public:
  string worker(string s) {
    int n = s.size();
    int lparen_cnt = 0;
    int rparen_cnt = 0;
    int lmost_paren_idx = INT_MAX;
    int rmost_paren_idx = INT_MIN;
    vector<vector<int> > lr_idx;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        lparen_cnt++;
        lmost_paren_idx = min(lmost_paren_idx, i);
      } else if (s[i] == ')') {
        rparen_cnt++;
        rmost_paren_idx = max(rmost_paren_idx, i);
        if (lparen_cnt == rparen_cnt) {
          vector<int> indices {lmost_paren_idx, rmost_paren_idx};
          lr_idx.push_back(indices);
          // reset
          lparen_cnt = 0;
          rparen_cnt = 0;
          lmost_paren_idx = INT_MAX;
          rmost_paren_idx = INT_MIN;
        }
      }
    }

    string result = "";
    int cur_pos = 0;
    for (const auto& indices : lr_idx) {
      result += s.substr(cur_pos, indices[0] - cur_pos);
      string middle = s.substr(indices[0] + 1, indices[1] - indices[0] - 1);
      result += worker(middle);
      cur_pos = indices[1] + 1;
    }
    if (cur_pos < s.size()) {
      result += s.substr(cur_pos);
    }

    reverse(result.begin(), result.end());
    return result;
  }
  
  string reverseParentheses(string s) {
    string result = worker(s);
    reverse(result.begin(), result.end());
    return result;
  }
};

/* Runtime: 10 ms, faster than 6.28% of C++ online submissions for Reverse Substrings Between Each Pair of Parentheses.
 * Memory Usage: 7.7 MB, less than 9.73% of C++ online submissions for Reverse Substrings Between Each Pair of Parentheses.
 */

