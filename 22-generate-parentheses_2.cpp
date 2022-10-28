class Solution {
 public:
  void worker(int lp_rem, int rp_rem, string cur_string, vector<string>& result) {
    // base case: we have used up all the parens
    if (lp_rem == 0 && rp_rem == 0) {
      result.push_back(cur_string);
      return;
    }
    
    if (lp_rem > 0) {
      worker(lp_rem - 1, rp_rem + 1, cur_string + "(", result);
    }
    if (rp_rem > 0) {
      worker(lp_rem, rp_rem - 1, cur_string + ")", result);
    }
  }
  
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string cur_string = "";
    worker(n, 0, cur_string, result);
    return result;
  }
};

/* Runtime: 16 ms, faster than 12.15% of C++ online submissions for Generate Parentheses.
 * Memory Usage: 13.8 MB, less than 37.25% of C++ online submissions for Generate Parentheses.
 */

