class Solution {
 private:
  bool check_palindrome(string& cur_str) {
    if (cur_str.size() == 0) {
      return false;
    }
    for (int i = 0; i < cur_str.size() / 2; i++) {
      if (cur_str[i] != cur_str[cur_str.size() - i - 1]) {
        return false;
      }
    }
    return true;
  }

  void worker(vector<vector<string> >& result, vector<string>& cur_res,
              const string& s, int cur_idx = 0) {
    if (cur_idx == s.size()) {
      result.push_back(cur_res);
      return;
    }
    for (int i = cur_idx; i < s.size(); i++) {
      string cur_str = s.substr(cur_idx, i - cur_idx + 1);
      if (check_palindrome(cur_str)) {
        cur_res.push_back(cur_str);
      } else {
        continue;
      }
      worker(result, cur_res, s, i + 1);
      cur_res.pop_back();
    }
  }
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string> > result;
    vector<string> cur_res;
    worker(result, cur_res, s);
    return result;
  }
};

/* Runtime: 179 ms, faster than 53.10% of C++ online submissions for Palindrome Partitioning.
 * Memory Usage: 49.3 MB, less than 91.00% of C++ online submissions for Palindrome Partitioning.
 */

